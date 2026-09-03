#include <typephp_helper.h>

#include <exception>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace {

struct TraitMetadata final {
    int module_number;
    bool is_trait;
    std::vector<std::string> traits;
};

struct TraitMetadataSnapshot final {
    bool is_trait;
    std::vector<std::string> traits;
};

std::unordered_map<std::string, TraitMetadata> trait_metadata;
std::shared_mutex trait_metadata_mutex;
zend_internal_function *class_uses_function = nullptr;
zif_handler original_class_uses = nullptr;

std::string normalize_name(std::string_view name) {
    if (!name.empty() && name.front() == '\\') {
        name.remove_prefix(1);
    }
    std::string normalized{name};
    for (char &ch : normalized) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = static_cast<char>(ch + ('a' - 'A'));
        }
    }
    return normalized;
}

bool find_metadata(std::string_view name, TraitMetadataSnapshot &snapshot) {
    const std::string normalized = normalize_name(name);
    std::shared_lock lock{trait_metadata_mutex};
    const auto it = trait_metadata.find(normalized);
    if (it == trait_metadata.end()) {
        return false;
    }
    snapshot.is_trait = it->second.is_trait;
    snapshot.traits = it->second.traits;
    return true;
}

zend_class_entry *find_loaded_class(zend_string *name) {
    const std::string normalized = normalize_name({ZSTR_VAL(name), ZSTR_LEN(name)});
    return static_cast<zend_class_entry *>(
        zend_hash_str_find_ptr(EG(class_table), normalized.data(), normalized.size()));
}

bool find_class_metadata(zend_class_entry *class_entry, TraitMetadataSnapshot &snapshot) {
    if (class_entry == nullptr ||
        !find_metadata({ZSTR_VAL(class_entry->name), ZSTR_LEN(class_entry->name)}, snapshot)) {
        return false;
    }
    return !snapshot.is_trait;
}

void set_trait_array(zval *return_value, const TraitMetadataSnapshot &metadata) {
    array_init_size(return_value, metadata.traits.size());
    for (const std::string &name : metadata.traits) {
        zend_string *trait_name = zend_string_init(name.data(), name.size(), false);
        zval value;
        ZVAL_STR_COPY(&value, trait_name);
        if (zend_hash_add_new(Z_ARRVAL_P(return_value), trait_name, &value) == nullptr) {
            zval_ptr_dtor(&value);
        }
        zend_string_release(trait_name);
    }
}

void typephp_class_uses_handler_impl(INTERNAL_FUNCTION_PARAMETERS) {
    zval *target = ZEND_NUM_ARGS() >= 1 ? ZEND_CALL_ARG(execute_data, 1) : nullptr;
    if (target != nullptr && Z_TYPE_P(target) == IS_STRING && find_loaded_class(Z_STR_P(target)) == nullptr) {
        TraitMetadataSnapshot metadata{};
        if (find_metadata({Z_STRVAL_P(target), Z_STRLEN_P(target)}, metadata) && metadata.is_trait) {
            zval *validated_target;
            bool autoload = true;
            if (zend_parse_parameters(ZEND_NUM_ARGS(), "z|b", &validated_target, &autoload) == FAILURE) {
                RETURN_THROWS();
            }
            set_trait_array(return_value, metadata);
            return;
        }
    }

    original_class_uses(INTERNAL_FUNCTION_PARAM_PASSTHRU);
    if (UNEXPECTED(EG(exception)) || Z_TYPE_P(return_value) != IS_ARRAY) {
        return;
    }

    zend_class_entry *class_entry = target != nullptr && Z_TYPE_P(target) == IS_OBJECT ? Z_OBJCE_P(target) : nullptr;
    if (class_entry == nullptr && Z_TYPE_P(target) == IS_STRING) {
        // The original handler may have invoked an autoloader.
        class_entry = find_loaded_class(Z_STR_P(target));
    }

    TraitMetadataSnapshot metadata{};
    if (find_class_metadata(class_entry, metadata)) {
        zval_ptr_dtor(return_value);
        set_trait_array(return_value, metadata);
    }
}

void typephp_class_uses_handler(INTERNAL_FUNCTION_PARAMETERS) {
    try {
        typephp_class_uses_handler_impl(INTERNAL_FUNCTION_PARAM_PASSTHRU);
    } catch (const std::exception &error) {
        if (Z_TYPE_P(return_value) != IS_UNDEF) {
            zval_ptr_dtor(return_value);
            ZVAL_UNDEF(return_value);
        }
        zend_throw_error(nullptr, "TypePHP class_uses metadata lookup failed: %s", error.what());
    } catch (...) {
        if (Z_TYPE_P(return_value) != IS_UNDEF) {
            zval_ptr_dtor(return_value);
            ZVAL_UNDEF(return_value);
        }
        zend_throw_error(nullptr, "TypePHP class_uses metadata lookup failed");
    }
}

zend_internal_function *find_class_uses_function() {
    auto *function = static_cast<zend_function *>(zend_hash_str_find_ptr(CG(function_table), ZEND_STRL("class_uses")));
    if (function == nullptr || function->type != ZEND_INTERNAL_FUNCTION) {
        return nullptr;
    }
    return reinterpret_cast<zend_internal_function *>(function);
}

}  // namespace

zend_result typephp_register_trait_metadata(int module_number,
                                            const typephp_trait_metadata_entry *entries,
                                            size_t entry_count) noexcept {
    try {
        if (entry_count == 0) {
            return SUCCESS;
        }
        if (UNEXPECTED(entries == nullptr)) {
            zend_error(E_WARNING, "TypePHP trait metadata entries cannot be null");
            return FAILURE;
        }

        std::vector<std::pair<std::string, TraitMetadata>> pending;
        pending.reserve(entry_count);
        std::unordered_set<std::string> names;
        names.reserve(entry_count);

        for (size_t i = 0; i < entry_count; i++) {
            const auto &entry = entries[i];
            if (UNEXPECTED(entry.name.empty()) || UNEXPECTED(entry.trait_count != 0 && entry.traits == nullptr)) {
                zend_error(E_WARNING, "Invalid TypePHP trait metadata entry at index %zu", i);
                return FAILURE;
            }

            std::string normalized = normalize_name(entry.name);
            if (!names.emplace(normalized).second) {
                zend_error(E_WARNING,
                           "Duplicate TypePHP trait metadata for %.*s in module %d",
                           static_cast<int>(entry.name.size()),
                           entry.name.data(),
                           module_number);
                return FAILURE;
            }

            TraitMetadata metadata{module_number, entry.is_trait, {}};
            metadata.traits.reserve(entry.trait_count);
            for (size_t trait_index = 0; trait_index < entry.trait_count; trait_index++) {
                metadata.traits.emplace_back(entry.traits[trait_index]);
            }
            pending.emplace_back(std::move(normalized), std::move(metadata));
        }

        std::unique_lock lock{trait_metadata_mutex};
        for (const auto &[name, metadata] : pending) {
            const auto existing = trait_metadata.find(name);
            if (existing != trait_metadata.end()) {
                zend_error(E_WARNING,
                           "TypePHP trait metadata for %s is already registered by module %d",
                           name.c_str(),
                           existing->second.module_number);
                return FAILURE;
            }
        }

        zend_internal_function *function_to_hook = nullptr;
        if (trait_metadata.empty()) {
            function_to_hook = find_class_uses_function();
            if (function_to_hook == nullptr || function_to_hook->handler == nullptr) {
                zend_error(E_WARNING, "Unable to install TypePHP class_uses metadata handler");
                return FAILURE;
            }
        }
        for (auto &[name, metadata] : pending) {
            trait_metadata.emplace(std::move(name), std::move(metadata));
        }
        if (function_to_hook != nullptr) {
            // A compiler-only call rewrite would miss framework helpers still
            // running in ZendVM. Proxy the internal handler so both execution
            // paths observe the same AOT trait metadata.
            class_uses_function = function_to_hook;
            original_class_uses = function_to_hook->handler;
            function_to_hook->handler = reinterpret_cast<zif_handler>(typephp_class_uses_handler);
        }
        return SUCCESS;
    } catch (const std::exception &error) {
        typephp_unregister_trait_metadata(module_number);
        zend_error(E_WARNING, "Failed to register TypePHP trait metadata: %s", error.what());
        return FAILURE;
    } catch (...) {
        typephp_unregister_trait_metadata(module_number);
        zend_error(E_WARNING, "Failed to register TypePHP trait metadata");
        return FAILURE;
    }
}

void typephp_unregister_trait_metadata(int module_number) noexcept {
    try {
        std::unique_lock lock{trait_metadata_mutex};
        for (auto it = trait_metadata.begin(); it != trait_metadata.end();) {
            if (it->second.module_number == module_number) {
                it = trait_metadata.erase(it);
            } else {
                ++it;
            }
        }
        if (trait_metadata.empty() && class_uses_function != nullptr) {
            if (class_uses_function->handler == reinterpret_cast<zif_handler>(typephp_class_uses_handler)) {
                class_uses_function->handler = original_class_uses;
            }
            class_uses_function = nullptr;
            original_class_uses = nullptr;
        }
    } catch (...) {
        // Module shutdown cannot surface a C++ exception through Zend.
    }
}
