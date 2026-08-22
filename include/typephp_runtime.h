#pragma once

#include <phpx.h>

#define TYPEPHP_PROJECT_SYMBOL_INNER(prefix, project, suffix) prefix##project##suffix
#define TYPEPHP_PROJECT_SYMBOL(prefix, project, suffix) TYPEPHP_PROJECT_SYMBOL_INNER(prefix, project, suffix)

/* Follow PHP_MINIT()/PHP_MINIT_FUNCTION(): one macro names a symbol and the
 * matching *_FUNCTION macro declares or defines it. */
#define TYPEPHP_EMBED_GET_MODULE(project) TYPEPHP_PROJECT_SYMBOL(php_, project, _embed_get_module)
#define TYPEPHP_EMBED_GET_MODULE_FUNCTION(project) zend_module_entry *TYPEPHP_EMBED_GET_MODULE(project)(void)

#define TYPEPHP_RUNTIME_INIT(project) TYPEPHP_PROJECT_SYMBOL(typephp_, project, _runtime_init)
#define TYPEPHP_RUNTIME_SHUTDOWN(project) TYPEPHP_PROJECT_SYMBOL(typephp_, project, _runtime_shutdown)

#ifdef _WIN32
#ifdef TYPEPHP_RUNTIME_EXPORTS
#define TYPEPHP_RUNTIME_API extern "C" __declspec(dllexport)
#else
#define TYPEPHP_RUNTIME_API extern "C" __declspec(dllimport)
#endif
#else
#define TYPEPHP_RUNTIME_API extern "C" __attribute__((visibility("default")))
#endif

#define TYPEPHP_RUNTIME_INIT_FUNCTION(project)                                                                         \
    TYPEPHP_RUNTIME_API int TYPEPHP_RUNTIME_INIT(project)(int argc, char **argv)
#define TYPEPHP_RUNTIME_SHUTDOWN_FUNCTION(project) TYPEPHP_RUNTIME_API void TYPEPHP_RUNTIME_SHUTDOWN(project)(void)
