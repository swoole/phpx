#include <typephp_opcode_table.h>
#include <typephp_sapi.h>

extern "C" {
#include "php.h"
#include "php_getopt.h"
}

#include <cstdio>
#include <cstdlib>
#include <cstring>

extern "C" int typephp_cli_prepare_arguments(int *argc, char ***argv, const void *options, char ***allocated_argv) {
    *allocated_argv = nullptr;

    bool php_cli_mode = false;
    if (*argc > 1) {
        php_cli_mode = strcmp((*argv)[1], "-") == 0 || strcmp((*argv)[1], "--") == 0;
        if (!php_cli_mode) {
            char *option_argument = nullptr;
            int option_index = 1;
            int option = php_getopt(
                *argc, *argv, static_cast<const opt_struct *>(options), &option_argument, &option_index, 0, 2);
            php_cli_mode = option != EOF;
        }
    }
    if (php_cli_mode) {
        return SUCCESS;
    }

    const char *entry = typephp_project_entry_file();
    if (entry == nullptr || *entry == '\0') {
        return FAILURE;
    }

    char **application_argv = static_cast<char **>(calloc(static_cast<size_t>(*argc) + 2, sizeof(char *)));
    if (application_argv == nullptr) {
        return FAILURE;
    }
    application_argv[0] = (*argv)[0];
    application_argv[1] = const_cast<char *>(entry);
    for (int i = 1; i < *argc; ++i) {
        application_argv[i + 1] = (*argv)[i];
    }
    *argv = application_argv;
    *allocated_argv = application_argv;
    ++*argc;
    return SUCCESS;
}

extern "C" void typephp_cli_release_arguments(char **allocated_argv) {
    free(allocated_argv);
}
