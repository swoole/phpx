#ifndef TYPEPHP_SAPI_H
#define TYPEPHP_SAPI_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Prepare the argv consumed by PHP CLI. The options pointer is PHP CLI's own
 * opt_struct table, kept opaque here so this ABI does not expose PHP internals.
 * allocated_argv is non-null only when an application entry was inserted.
 */
int typephp_cli_prepare_arguments(int *argc, char ***argv, const void *options, char ***allocated_argv);
void typephp_cli_release_arguments(char **allocated_argv);

#ifdef __cplusplus
}
#endif

#endif
