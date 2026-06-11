/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Implementation of complex URL wrappers                   |
  +----------------------------------------------------------------------+
*/

#include "php_std_url.h"

namespace php::std {

Variant parse_url(const String &url, Int component) {
    php_url *resource = php_url_parse(url.data());
    if (resource == nullptr) {
        return Variant(false);
    }

    // Return a single component
    if (component > -1) {
        Variant result;
        switch (component) {
        case PHP_URL_SCHEME:
            if (resource->scheme) {
                result = Variant(String(resource->scheme, php::Ctor::Copy));
            }
            break;
        case PHP_URL_HOST:
            if (resource->host) {
                result = Variant(String(resource->host, php::Ctor::Copy));
            }
            break;
        case PHP_URL_PORT:
            if (resource->port != 0) {
                result = Variant(static_cast<Int>(resource->port));
            }
            break;
        case PHP_URL_USER:
            if (resource->user) {
                result = Variant(String(resource->user, php::Ctor::Copy));
            }
            break;
        case PHP_URL_PASS:
            if (resource->pass) {
                result = Variant(String(resource->pass, php::Ctor::Copy));
            }
            break;
        case PHP_URL_PATH:
            if (resource->path) {
                result = Variant(String(resource->path, php::Ctor::Copy));
            }
            break;
        case PHP_URL_QUERY:
            if (resource->query) {
                result = Variant(String(resource->query, php::Ctor::Copy));
            }
            break;
        case PHP_URL_FRAGMENT:
            if (resource->fragment) {
                result = Variant(String(resource->fragment, php::Ctor::Copy));
            }
            break;
        default:
            php::throwException(
                zend_ce_value_error,
                "parse_url(): Argument #2 ($component) must be a valid URL "
                "component identifier, " ZEND_LONG_FMT " given",
                component);
            php_url_free(resource);
            return Variant(false);
        }
        php_url_free(resource);
        return result;
    }

    // Build the full components array
    Array result;
    if (resource->scheme) {
        result.set(ZSTR_KNOWN(ZEND_STR_SCHEME),
                   String(resource->scheme, php::Ctor::Copy));
    }
    if (resource->host) {
        result.set(ZSTR_KNOWN(ZEND_STR_HOST),
                   String(resource->host, php::Ctor::Copy));
    }
    if (resource->port != 0) {
        result.set(ZSTR_KNOWN(ZEND_STR_PORT),
                   Variant(static_cast<Int>(resource->port)));
    }
    if (resource->user) {
        result.set(ZSTR_KNOWN(ZEND_STR_USER),
                   String(resource->user, php::Ctor::Copy));
    }
    if (resource->pass) {
        result.set(ZSTR_KNOWN(ZEND_STR_PASS),
                   String(resource->pass, php::Ctor::Copy));
    }
    if (resource->path) {
        result.set(ZSTR_KNOWN(ZEND_STR_PATH),
                   String(resource->path, php::Ctor::Copy));
    }
    if (resource->query) {
        result.set(ZSTR_KNOWN(ZEND_STR_QUERY),
                   String(resource->query, php::Ctor::Copy));
    }
    if (resource->fragment) {
        result.set(ZSTR_KNOWN(ZEND_STR_FRAGMENT),
                   String(resource->fragment, php::Ctor::Copy));
    }

    php_url_free(resource);
    return Variant(result);
}

}  // namespace php::std
