/*
 * OPcache file-cache decoder excerpt from php-src ext/opcache/zend_file_cache.c.
 * Copyright (c) The PHP Group. PHP License 3.01; see LICENSE.PHP.
 * Source: PHP 8.4.25, only the process-memory unserialization routines.
 */
#include "opcode_unserialize.h"

#if PHP_VERSION_ID >= 80400 && PHP_VERSION_ID < 80500

#include "zend_compile.h"
#include "zend_vm.h"
#include "zend_attributes.h"
#include "zend_enum.h"
#include "zend_interfaces.h"
#include "zend_inheritance.h"
#include "Optimizer/zend_optimizer.h"
#include "ext/standard/php_filestat.h"
#include <stdint.h>
#include <string.h>

typedef struct {
    zend_string *lcname;
    zend_string *rtd_key;
    zend_string *lc_parent_name;
    uint32_t cache_slot;
} zend_early_binding;

typedef struct {
    zend_script script;
    zend_long compiler_halt_offset;
    int ping_auto_globals_mask;
    time_t timestamp;
    bool corrupted;
    bool is_phar;
    bool empty;
    uint32_t num_warnings;
    uint32_t num_early_bindings;
    zend_error_info **warnings;
    zend_early_binding *early_bindings;
    void *mem;
    size_t size;
    struct {
        time_t last_used;
        zend_ulong hits;
        unsigned int memory_consumption;
        time_t revalidate;
    } dynamic_members;
} zend_persistent_script;

typedef struct {
    char magic[8];
    char system_id[32];
    size_t mem_size;
    size_t str_size;
    size_t script_offset;
    time_t timestamp;
    uint32_t checksum;
} typephp_opcache_metainfo;

ZEND_TLS char *typephp_strings_mem;
ZEND_TLS size_t typephp_blob_total_size;

#define IS_SERIALIZED_INTERNED(ptr) ((size_t)(ptr) & Z_UL(1))
#define IS_SERIALIZED(ptr) ((char*)(ptr) <= (char*)script->size)
#define IS_UNSERIALIZED(ptr) ((char*)(ptr) >= (char*)script->mem && \
    (char*)(ptr) <= (char*)script->mem + typephp_blob_total_size)
#define UNSERIALIZE_PTR(ptr) do { \
    if (ptr) { \
        ZEND_ASSERT(IS_SERIALIZED(ptr)); \
        (ptr) = (void*)((char*)buf + (size_t)(ptr)); \
    } \
} while (0)

static void *zend_file_cache_unserialize_interned(zend_string *str, bool in_shm) {
    (void)in_shm;
    return typephp_strings_mem + ((size_t)str & ~Z_UL(1));
}

#define UNSERIALIZE_STR(ptr) do { \
    if (ptr) { \
        if (IS_SERIALIZED_INTERNED(ptr)) { \
            (ptr) = (void*)zend_file_cache_unserialize_interned((zend_string*)(ptr), false); \
        } else { \
            ZEND_ASSERT(IS_SERIALIZED(ptr)); \
            (ptr) = (void*)((char*)buf + (size_t)(ptr)); \
            GC_ADD_FLAGS(ptr, IS_STR_INTERNED); \
            GC_DEL_FLAGS(ptr, IS_STR_PERMANENT | IS_STR_CLASS_NAME_MAP_PTR); \
        } \
    } \
} while (0)

static void zend_file_cache_unserialize_hash(HashTable *, zend_persistent_script *, void *,
    void (*)(zval *, zend_persistent_script *, void *), dtor_func_t);
static void zend_file_cache_unserialize_attribute(zval *, zend_persistent_script *, void *);
#define UNSERIALIZE_ATTRIBUTES(attributes) do { \
    if ((attributes) && !IS_UNSERIALIZED(attributes)) { \
        HashTable *ht; \
        UNSERIALIZE_PTR(attributes); \
        ht = (attributes); \
        zend_file_cache_unserialize_hash(ht, script, buf, zend_file_cache_unserialize_attribute, NULL); \
    } \
} while (0)

#define HOOKED_ITERATOR_PLACEHOLDER ((void*)1)
static const uint32_t uninitialized_bucket[-HT_MIN_MASK] = {HT_INVALID_IDX, HT_INVALID_IDX};
typedef void (*unserialize_callback_t)(zval *, zend_persistent_script *, void *);
static void zend_file_cache_unserialize_zval(zval *, zend_persistent_script *, void *);

static void zend_file_cache_unserialize_hash(HashTable               *ht,
                                             zend_persistent_script  *script,
                                             void                    *buf,
                                             unserialize_callback_t   func,
                                             dtor_func_t              dtor)
{
	ht->pDestructor = dtor;
	if (HT_FLAGS(ht) & HASH_FLAG_UNINITIALIZED) {
		HT_SET_DATA_ADDR(ht, &uninitialized_bucket);
		return;
	}
	if (IS_UNSERIALIZED(ht->arData)) {
		return;
	}
	UNSERIALIZE_PTR(ht->arData);
	if (HT_IS_PACKED(ht)) {
		zval *p, *end;

		p = ht->arPacked;
		end = p + ht->nNumUsed;
		while (p < end) {
			if (Z_TYPE_P(p) != IS_UNDEF) {
				func(p, script, buf);
			}
			p++;
		}
	} else {
		Bucket *p, *end;

		p = ht->arData;
		end = p + ht->nNumUsed;
		while (p < end) {
			if (Z_TYPE(p->val) != IS_UNDEF) {
				UNSERIALIZE_STR(p->key);
				func(&p->val, script, buf);
			}
			p++;
		}
	}
}

static void zend_file_cache_unserialize_ast(zend_ast                *ast,
                                            zend_persistent_script  *script,
                                            void                    *buf)
{
	uint32_t i;

	if (ast->kind == ZEND_AST_ZVAL || ast->kind == ZEND_AST_CONSTANT) {
		zend_file_cache_unserialize_zval(&((zend_ast_zval*)ast)->val, script, buf);
	} else if (zend_ast_is_list(ast)) {
		zend_ast_list *list = zend_ast_get_list(ast);
		for (i = 0; i < list->children; i++) {
			if (list->child[i] && !IS_UNSERIALIZED(list->child[i])) {
				UNSERIALIZE_PTR(list->child[i]);
				zend_file_cache_unserialize_ast(list->child[i], script, buf);
			}
		}
	} else {
		uint32_t children = zend_ast_get_num_children(ast);
		for (i = 0; i < children; i++) {
			if (ast->child[i] && !IS_UNSERIALIZED(ast->child[i])) {
				UNSERIALIZE_PTR(ast->child[i]);
				zend_file_cache_unserialize_ast(ast->child[i], script, buf);
			}
		}
	}
}

static void zend_file_cache_unserialize_zval(zval                    *zv,
                                             zend_persistent_script  *script,
                                             void                    *buf)
{
	switch (Z_TYPE_P(zv)) {
		case IS_STRING:
			/* We can't use !IS_UNSERIALIZED here, because that does not recognize unserialized
			 * interned strings in non-shm mode. */
			if (IS_SERIALIZED(Z_STR_P(zv)) || IS_SERIALIZED_INTERNED(Z_STR_P(zv))) {
				UNSERIALIZE_STR(Z_STR_P(zv));
			}
			break;
		case IS_ARRAY:
			if (!IS_UNSERIALIZED(Z_ARR_P(zv))) {
				HashTable *ht;

				UNSERIALIZE_PTR(Z_ARR_P(zv));
				ht = Z_ARR_P(zv);
				zend_file_cache_unserialize_hash(ht,
						script, buf, zend_file_cache_unserialize_zval, ZVAL_PTR_DTOR);
			}
			break;
		case IS_CONSTANT_AST:
			if (!IS_UNSERIALIZED(Z_AST_P(zv))) {
				UNSERIALIZE_PTR(Z_AST_P(zv));
				zend_file_cache_unserialize_ast(Z_ASTVAL_P(zv), script, buf);
			}
			break;
		case IS_INDIRECT:
			/* Used by static properties. */
			UNSERIALIZE_PTR(Z_INDIRECT_P(zv));
			break;
		default:
			ZEND_ASSERT(Z_TYPE_P(zv) < IS_STRING);
			break;
	}
}

static void zend_file_cache_unserialize_attribute(zval *zv, zend_persistent_script *script, void *buf)
{
	zend_attribute *attr;
	uint32_t i;

	UNSERIALIZE_PTR(Z_PTR_P(zv));
	attr = Z_PTR_P(zv);

	UNSERIALIZE_STR(attr->name);
	UNSERIALIZE_STR(attr->lcname);

	for (i = 0; i < attr->argc; i++) {
		UNSERIALIZE_STR(attr->args[i].name);
		zend_file_cache_unserialize_zval(&attr->args[i].value, script, buf);
	}
}

static void zend_file_cache_unserialize_type(
		zend_type *type, zend_class_entry *scope, zend_persistent_script *script, void *buf)
{
	if (ZEND_TYPE_HAS_LIST(*type)) {
		zend_type_list *list = ZEND_TYPE_LIST(*type);
		UNSERIALIZE_PTR(list);
		ZEND_TYPE_SET_PTR(*type, list);

		zend_type *list_type;
		ZEND_TYPE_LIST_FOREACH(list, list_type) {
			zend_file_cache_unserialize_type(list_type, scope, script, buf);
		} ZEND_TYPE_LIST_FOREACH_END();
	} else if (ZEND_TYPE_HAS_NAME(*type)) {
		zend_string *type_name = ZEND_TYPE_NAME(*type);
		UNSERIALIZE_STR(type_name);
		ZEND_TYPE_SET_PTR(*type, type_name);
		zend_alloc_ce_cache(type_name);
	}
}

static void zend_file_cache_unserialize_op_array(zend_op_array           *op_array,
                                                 zend_persistent_script  *script,
                                                 void                    *buf)
{
	op_array->fn_flags &= ~ZEND_ACC_IMMUTABLE;
	ZEND_MAP_PTR_INIT(op_array->static_variables_ptr, NULL);
	ZEND_MAP_PTR_INIT(op_array->run_time_cache, NULL);

	/* Check whether this op_array has already been unserialized. */
	if (IS_UNSERIALIZED(op_array->opcodes)) {
		ZEND_ASSERT(op_array->scope && "Only method op_arrays should be shared");
		return;
	}

	if (op_array->refcount) {
		op_array->refcount = NULL;
		UNSERIALIZE_PTR(op_array->static_variables);
		UNSERIALIZE_PTR(op_array->literals);
		UNSERIALIZE_PTR(op_array->opcodes);
		UNSERIALIZE_PTR(op_array->arg_info);
		UNSERIALIZE_PTR(op_array->vars);
		UNSERIALIZE_STR(op_array->function_name);
		UNSERIALIZE_STR(op_array->filename);
		UNSERIALIZE_PTR(op_array->live_range);
		UNSERIALIZE_PTR(op_array->scope);
		UNSERIALIZE_STR(op_array->doc_comment);
		UNSERIALIZE_ATTRIBUTES(op_array->attributes);
		UNSERIALIZE_PTR(op_array->try_catch_array);
		UNSERIALIZE_PTR(op_array->prototype);
		UNSERIALIZE_PTR(op_array->prop_info);
		return;
	}

	if (op_array->static_variables) {
		HashTable *ht;

		UNSERIALIZE_PTR(op_array->static_variables);
		ht = op_array->static_variables;
		zend_file_cache_unserialize_hash(ht,
				script, buf, zend_file_cache_unserialize_zval, ZVAL_PTR_DTOR);
	}

	if (op_array->literals) {
		zval *p, *end;

		UNSERIALIZE_PTR(op_array->literals);
		p = op_array->literals;
		end = p + op_array->last_literal;
		while (p < end) {
			zend_file_cache_unserialize_zval(p, script, buf);
			p++;
		}
	}

	{
		zend_op *opline, *end;

		UNSERIALIZE_PTR(op_array->opcodes);
		opline = op_array->opcodes;
		end = opline + op_array->last;
		while (opline < end) {
#if ZEND_USE_ABS_CONST_ADDR
			if (opline->op1_type == IS_CONST) {
				UNSERIALIZE_PTR(opline->op1.zv);
			}
			if (opline->op2_type == IS_CONST) {
				UNSERIALIZE_PTR(opline->op2.zv);
			}
#else
			if (opline->op1_type == IS_CONST) {
				ZEND_PASS_TWO_UPDATE_CONSTANT(op_array, opline, opline->op1);
			}
			if (opline->op2_type == IS_CONST) {
				ZEND_PASS_TWO_UPDATE_CONSTANT(op_array, opline, opline->op2);
			}
#endif
#if ZEND_USE_ABS_JMP_ADDR
			switch (opline->opcode) {
				case ZEND_JMP:
				case ZEND_FAST_CALL:
					UNSERIALIZE_PTR(opline->op1.jmp_addr);
					break;
				case ZEND_JMPZ:
				case ZEND_JMPNZ:
				case ZEND_JMPZ_EX:
				case ZEND_JMPNZ_EX:
				case ZEND_JMP_SET:
				case ZEND_COALESCE:
				case ZEND_FE_RESET_R:
				case ZEND_FE_RESET_RW:
				case ZEND_ASSERT_CHECK:
				case ZEND_JMP_NULL:
				case ZEND_BIND_INIT_STATIC_OR_JMP:
				case ZEND_JMP_FRAMELESS:
					UNSERIALIZE_PTR(opline->op2.jmp_addr);
					break;
				case ZEND_CATCH:
					if (!(opline->extended_value & ZEND_LAST_CATCH)) {
						UNSERIALIZE_PTR(opline->op2.jmp_addr);
					}
					break;
				case ZEND_FE_FETCH_R:
				case ZEND_FE_FETCH_RW:
				case ZEND_SWITCH_LONG:
				case ZEND_SWITCH_STRING:
					/* relative extended_value don't have to be changed */
					break;
			}
#endif
			zend_deserialize_opcode_handler(opline);
			opline++;
		}

		UNSERIALIZE_PTR(op_array->scope);

		if (op_array->arg_info) {
			zend_arg_info *p, *end;
			UNSERIALIZE_PTR(op_array->arg_info);
			p = op_array->arg_info;
			end = p + op_array->num_args;
			if (op_array->fn_flags & ZEND_ACC_HAS_RETURN_TYPE) {
				p--;
			}
			if (op_array->fn_flags & ZEND_ACC_VARIADIC) {
				end++;
			}
			while (p < end) {
				if (!IS_UNSERIALIZED(p->name)) {
					UNSERIALIZE_STR(p->name);
				}
				zend_file_cache_unserialize_type(&p->type, (op_array->fn_flags & ZEND_ACC_CLOSURE) ? NULL : op_array->scope, script, buf);
				p++;
			}
		}

		if (op_array->vars) {
			zend_string **p, **end;

			UNSERIALIZE_PTR(op_array->vars);
			p = op_array->vars;
			end = p + op_array->last_var;
			while (p < end) {
				if (!IS_UNSERIALIZED(*p)) {
					UNSERIALIZE_STR(*p);
				}
				p++;
			}
		}

		if (op_array->num_dynamic_func_defs) {
			UNSERIALIZE_PTR(op_array->dynamic_func_defs);
			for (uint32_t i = 0; i < op_array->num_dynamic_func_defs; i++) {
				UNSERIALIZE_PTR(op_array->dynamic_func_defs[i]);
				zend_file_cache_unserialize_op_array(op_array->dynamic_func_defs[i], script, buf);
			}
		}

		UNSERIALIZE_STR(op_array->function_name);
		UNSERIALIZE_STR(op_array->filename);
		UNSERIALIZE_PTR(op_array->live_range);
		UNSERIALIZE_STR(op_array->doc_comment);
		UNSERIALIZE_ATTRIBUTES(op_array->attributes);
		UNSERIALIZE_PTR(op_array->try_catch_array);
		UNSERIALIZE_PTR(op_array->prototype);
		UNSERIALIZE_PTR(op_array->prop_info);
	}
}

static void zend_file_cache_unserialize_func(zval                    *zv,
                                             zend_persistent_script  *script,
                                             void                    *buf)
{
	zend_function *func;
	UNSERIALIZE_PTR(Z_PTR_P(zv));
	func = Z_PTR_P(zv);
	ZEND_ASSERT(func->type == ZEND_USER_FUNCTION);
	zend_file_cache_unserialize_op_array(&func->op_array, script, buf);
}

static void zend_file_cache_unserialize_prop_info(zval                    *zv,
                                                  zend_persistent_script  *script,
                                                  void                    *buf)
{
	if (!IS_UNSERIALIZED(Z_PTR_P(zv))) {
		zend_property_info *prop;

		UNSERIALIZE_PTR(Z_PTR_P(zv));
		prop = Z_PTR_P(zv);

		ZEND_ASSERT(prop->ce != NULL && prop->name != NULL);
		if (!IS_UNSERIALIZED(prop->ce)) {
			UNSERIALIZE_PTR(prop->ce);
			UNSERIALIZE_STR(prop->name);
			if (prop->doc_comment) {
				UNSERIALIZE_STR(prop->doc_comment);
			}
			UNSERIALIZE_ATTRIBUTES(prop->attributes);
			UNSERIALIZE_PTR(prop->prototype);
			if (prop->hooks) {
				UNSERIALIZE_PTR(prop->hooks);
				for (uint32_t i = 0; i < ZEND_PROPERTY_HOOK_COUNT; i++) {
					if (prop->hooks[i]) {
						UNSERIALIZE_PTR(prop->hooks[i]);
						zend_file_cache_unserialize_op_array(&prop->hooks[i]->op_array, script, buf);
					}
				}
			}
			zend_file_cache_unserialize_type(&prop->type, prop->ce, script, buf);
		}
	}
}

static void zend_file_cache_unserialize_class_constant(zval                    *zv,
                                                       zend_persistent_script  *script,
                                                       void                    *buf)
{
	if (!IS_UNSERIALIZED(Z_PTR_P(zv))) {
		zend_class_constant *c;

		UNSERIALIZE_PTR(Z_PTR_P(zv));
		c = Z_PTR_P(zv);

		ZEND_ASSERT(c->ce != NULL);
		if (!IS_UNSERIALIZED(c->ce)) {
			UNSERIALIZE_PTR(c->ce);

			zend_file_cache_unserialize_zval(&c->value, script, buf);

			if (c->doc_comment) {
				UNSERIALIZE_STR(c->doc_comment);
			}
			UNSERIALIZE_ATTRIBUTES(c->attributes);
			zend_file_cache_unserialize_type(&c->type, c->ce, script, buf);
		}
	}
}

static void zend_file_cache_unserialize_class(zval                    *zv,
                                              zend_persistent_script  *script,
                                              void                    *buf)
{
	zend_class_entry *ce;

	UNSERIALIZE_PTR(Z_PTR_P(zv));
	ce = Z_PTR_P(zv);

	UNSERIALIZE_STR(ce->name);
	if (!(ce->ce_flags & ZEND_ACC_ANON_CLASS)) {
		zend_alloc_ce_cache(ce->name);
	}
	if (ce->parent) {
		if (!(ce->ce_flags & ZEND_ACC_LINKED)) {
			UNSERIALIZE_STR(ce->parent_name);
		} else {
			UNSERIALIZE_PTR(ce->parent);
		}
	}
	zend_file_cache_unserialize_hash(&ce->function_table,
			script, buf, zend_file_cache_unserialize_func, ZEND_FUNCTION_DTOR);
	if (ce->default_properties_table) {
		zval *p, *end;

		UNSERIALIZE_PTR(ce->default_properties_table);
		p = ce->default_properties_table;
		end = p + ce->default_properties_count;
		while (p < end) {
			zend_file_cache_unserialize_zval(p, script, buf);
			p++;
		}
	}
	if (ce->default_static_members_table) {
		zval *p, *end;
		UNSERIALIZE_PTR(ce->default_static_members_table);
		p = ce->default_static_members_table;
		end = p + ce->default_static_members_count;
		while (p < end) {
			zend_file_cache_unserialize_zval(p, script, buf);
			p++;
		}
	}
	zend_file_cache_unserialize_hash(&ce->constants_table,
			script, buf, zend_file_cache_unserialize_class_constant, NULL);
	UNSERIALIZE_STR(ce->info.user.filename);
	UNSERIALIZE_STR(ce->doc_comment);
	UNSERIALIZE_ATTRIBUTES(ce->attributes);
	zend_file_cache_unserialize_hash(&ce->properties_info,
			script, buf, zend_file_cache_unserialize_prop_info, NULL);

	if (ce->properties_info_table) {
		uint32_t i;
		UNSERIALIZE_PTR(ce->properties_info_table);

		for (i = 0; i < ce->default_properties_count; i++) {
			UNSERIALIZE_PTR(ce->properties_info_table[i]);
		}
	}

	if (ce->num_interfaces) {
		uint32_t i;

		ZEND_ASSERT(!(ce->ce_flags & ZEND_ACC_LINKED));
		UNSERIALIZE_PTR(ce->interface_names);

		for (i = 0; i < ce->num_interfaces; i++) {
			UNSERIALIZE_STR(ce->interface_names[i].name);
			UNSERIALIZE_STR(ce->interface_names[i].lc_name);
		}
	}

	if (ce->num_traits) {
		uint32_t i;

		UNSERIALIZE_PTR(ce->trait_names);

		for (i = 0; i < ce->num_traits; i++) {
			UNSERIALIZE_STR(ce->trait_names[i].name);
			UNSERIALIZE_STR(ce->trait_names[i].lc_name);
		}

		if (ce->trait_aliases) {
			zend_trait_alias **p, *q;

			UNSERIALIZE_PTR(ce->trait_aliases);
			p = ce->trait_aliases;

			while (*p) {
				UNSERIALIZE_PTR(*p);
				q = *p;

				if (q->trait_method.method_name) {
					UNSERIALIZE_STR(q->trait_method.method_name);
				}
				if (q->trait_method.class_name) {
					UNSERIALIZE_STR(q->trait_method.class_name);
				}

				if (q->alias) {
					UNSERIALIZE_STR(q->alias);
				}
				p++;
			}
		}

		if (ce->trait_precedences) {
			zend_trait_precedence **p, *q;
			uint32_t j;

			UNSERIALIZE_PTR(ce->trait_precedences);
			p = ce->trait_precedences;

			while (*p) {
				UNSERIALIZE_PTR(*p);
				q = *p;

				if (q->trait_method.method_name) {
					UNSERIALIZE_STR(q->trait_method.method_name);
				}
				if (q->trait_method.class_name) {
					UNSERIALIZE_STR(q->trait_method.class_name);
				}

				for (j = 0; j < q->num_excludes; j++) {
					UNSERIALIZE_STR(q->exclude_class_names[j]);
				}
				p++;
			}
		}
	}

	UNSERIALIZE_PTR(ce->constructor);
	UNSERIALIZE_PTR(ce->destructor);
	UNSERIALIZE_PTR(ce->clone);
	UNSERIALIZE_PTR(ce->__get);
	UNSERIALIZE_PTR(ce->__set);
	UNSERIALIZE_PTR(ce->__call);
	UNSERIALIZE_PTR(ce->__serialize);
	UNSERIALIZE_PTR(ce->__unserialize);
	UNSERIALIZE_PTR(ce->__isset);
	UNSERIALIZE_PTR(ce->__unset);
	UNSERIALIZE_PTR(ce->__tostring);
	UNSERIALIZE_PTR(ce->__callstatic);
	UNSERIALIZE_PTR(ce->__debugInfo);

	if (ce->iterator_funcs_ptr) {
		UNSERIALIZE_PTR(ce->iterator_funcs_ptr);
		UNSERIALIZE_PTR(ce->iterator_funcs_ptr->zf_new_iterator);
		UNSERIALIZE_PTR(ce->iterator_funcs_ptr->zf_rewind);
		UNSERIALIZE_PTR(ce->iterator_funcs_ptr->zf_valid);
		UNSERIALIZE_PTR(ce->iterator_funcs_ptr->zf_key);
		UNSERIALIZE_PTR(ce->iterator_funcs_ptr->zf_current);
		UNSERIALIZE_PTR(ce->iterator_funcs_ptr->zf_next);
	}
	if (ce->arrayaccess_funcs_ptr) {
		UNSERIALIZE_PTR(ce->arrayaccess_funcs_ptr);
		UNSERIALIZE_PTR(ce->arrayaccess_funcs_ptr->zf_offsetget);
		UNSERIALIZE_PTR(ce->arrayaccess_funcs_ptr->zf_offsetexists);
		UNSERIALIZE_PTR(ce->arrayaccess_funcs_ptr->zf_offsetset);
		UNSERIALIZE_PTR(ce->arrayaccess_funcs_ptr->zf_offsetunset);
	}

	ce->ce_flags &= ~ZEND_ACC_IMMUTABLE;
	ce->ce_flags |= ZEND_ACC_FILE_CACHED;
	ZEND_MAP_PTR_INIT(ce->mutable_data, NULL);
	ZEND_MAP_PTR_INIT(ce->static_members_table, NULL);

	if (ce->get_iterator) {
		ZEND_ASSERT(ce->get_iterator == HOOKED_ITERATOR_PLACEHOLDER);
		ce->get_iterator = zend_hooked_object_get_iterator;
	}

	// Memory addresses of object handlers are not stable. They can change due to ASLR or order of linking dynamic. To
	// avoid pointing to invalid memory we relink default_object_handlers here.
	ce->default_object_handlers = ce->ce_flags & ZEND_ACC_ENUM ? &zend_enum_object_handlers : &std_object_handlers;
}

static void zend_file_cache_unserialize_warnings(zend_persistent_script *script, void *buf)
{
	if (script->warnings) {
		UNSERIALIZE_PTR(script->warnings);
		for (uint32_t i = 0; i < script->num_warnings; i++) {
			UNSERIALIZE_PTR(script->warnings[i]);
			UNSERIALIZE_STR(script->warnings[i]->filename);
			UNSERIALIZE_STR(script->warnings[i]->message);
		}
	}
}

static void zend_file_cache_unserialize_early_bindings(zend_persistent_script *script, void *buf)
{
	if (script->early_bindings) {
		UNSERIALIZE_PTR(script->early_bindings);
		for (uint32_t i = 0; i < script->num_early_bindings; i++) {
			UNSERIALIZE_STR(script->early_bindings[i].lcname);
			UNSERIALIZE_STR(script->early_bindings[i].rtd_key);
			UNSERIALIZE_STR(script->early_bindings[i].lc_parent_name);
		}
	}
}

static void zend_file_cache_unserialize(zend_persistent_script  *script,
                                        void                    *buf)
{
	script->mem = buf;

	UNSERIALIZE_STR(script->script.filename);

	zend_file_cache_unserialize_hash(&script->script.class_table,
			script, buf, zend_file_cache_unserialize_class, ZEND_CLASS_DTOR);
	zend_file_cache_unserialize_hash(&script->script.function_table,
			script, buf, zend_file_cache_unserialize_func, ZEND_FUNCTION_DTOR);
	zend_file_cache_unserialize_op_array(&script->script.main_op_array, script, buf);
	zend_file_cache_unserialize_warnings(script, buf);
	zend_file_cache_unserialize_early_bindings(script, buf);
}

static uint32_t typephp_adler32(const unsigned char *data, size_t length) {
    uint32_t a = 1, b = 0;
    while (length != 0) {
        size_t chunk = length > 5552 ? 5552 : length;
        length -= chunk;
        while (chunk--) {
            a += *data++;
            b += a;
        }
        a %= 65521;
        b %= 65521;
    }
    return (b << 16) | a;
}

/* The remaining script memory belongs to the request arena, like OPcache's
 * process-memory file-cache path. Zend destroys the returned main op_array. */
zend_op_array *typephp_opcache_load(const typephp_opcode_blob *blob) {
    typephp_opcache_metainfo info;
    void *memory;
    zend_persistent_script *script;
    zend_op_array *result;
    Bucket *entry;

    if (blob->size < sizeof(info)) {
        zend_error(E_ERROR, "Embedded opcode blob is truncated");
        return NULL;
    }
    memcpy(&info, blob->data, sizeof(info));
    if (memcmp(info.magic, "OPCACHE", 8) != 0 ||
        info.mem_size > blob->size - sizeof(info) ||
        info.str_size > blob->size - sizeof(info) - info.mem_size ||
        info.script_offset > info.mem_size ||
        info.mem_size - info.script_offset < sizeof(zend_persistent_script)) {
        zend_error(E_ERROR, "Embedded opcode blob has an invalid header");
        return NULL;
    }
    if (typephp_adler32(blob->data + sizeof(info), info.mem_size + info.str_size) != info.checksum) {
        zend_error(E_ERROR, "Embedded opcode blob checksum mismatch");
        return NULL;
    }
    /* The build tool records this identifier verbatim. It is not compared to
     * zend_system_id here: that ID includes which compile hooks were installed
     * during startup, and the build CLI uses OPcache while this binary does not. */
    memory = zend_arena_alloc(&CG(arena), info.mem_size + info.str_size);
    memcpy(memory, blob->data + sizeof(info), info.mem_size + info.str_size);
    typephp_strings_mem = (char *)memory + info.mem_size;
    typephp_blob_total_size = info.mem_size + info.str_size;
    script = (zend_persistent_script *)((char *)memory + info.script_offset);
    script->corrupted = true;
    script->size = info.mem_size;
    zend_file_cache_unserialize(script, memory);
    script->corrupted = false;

    result = (zend_op_array *)emalloc(sizeof(zend_op_array));
    *result = script->script.main_op_array;

    ZEND_HASH_FOREACH_BUCKET(&script->script.function_table, entry) {
        if (Z_TYPE(entry->val) == IS_UNDEF) continue;
        if (zend_hash_add_ptr(CG(function_table), entry->key, Z_PTR(entry->val)) == NULL) {
            zend_error_noreturn(E_ERROR, "Cannot redeclare function %s", ZSTR_VAL(entry->key));
        }
    } ZEND_HASH_FOREACH_END();

    ZEND_HASH_FOREACH_BUCKET(&script->script.class_table, entry) {
        if (Z_TYPE(entry->val) == IS_UNDEF) continue;
        if (zend_hash_add_ptr(CG(class_table), entry->key, Z_PTR(entry->val)) == NULL &&
            (ZSTR_LEN(entry->key) == 0 || ZSTR_VAL(entry->key)[0] != '\0')) {
            zend_class_redeclaration_error(E_ERROR, Z_PTR(entry->val));
        }
    } ZEND_HASH_FOREACH_END();

    return result;
}

#endif /* PHP 8.4 */
