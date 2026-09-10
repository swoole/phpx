/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | Hosted process entry for the VM-less php-nano runtime.               |
  +----------------------------------------------------------------------+
*/

#include "php_nano_extension.h"

#include <cstdio>
#include <exception>

extern "C" int typephp_nano_project_main();

int main(int argc, char **argv)
{
    php_nano_set_cli_arguments(argc, argv);
    if (php_nano_startup_composer_extensions() != SUCCESS) {
        std::fputs("Unable to start PHP Nano extensions\n", stderr);
        return 1;
    }

    int exit_code = 1;
    try {
        exit_code = typephp_nano_project_main();
    } catch (const std::exception &exception) {
        std::fprintf(stderr, "Unhandled TypePHP exception: %s\n", exception.what());
    } catch (...) {
        std::fputs("Unhandled TypePHP exception\n", stderr);
    }

    php_nano_shutdown_composer_extensions();
    return exit_code;
}
