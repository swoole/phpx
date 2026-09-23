#include "phpx_test.h"
#include "typephp_sapi.h"

extern "C" {
#include "php_getopt.h"
}

namespace {
const char *project_entry = "/app/index.php";

const opt_struct cli_options[] = {
    {'d', 1, const_cast<char *>("define")},
    {'i', 0, const_cast<char *>("info")},
    {'m', 0, const_cast<char *>("modules")},
    {'S', 1, const_cast<char *>("server")},
    {'-', 0, nullptr},
};

struct PreparedArguments {
    int argc;
    char **argv;
    char **allocated = nullptr;

    PreparedArguments(int argument_count, char **arguments) : argc(argument_count), argv(arguments) {}

    ~PreparedArguments() {
        typephp_cli_release_arguments(allocated);
    }

    int prepare() {
        return typephp_cli_prepare_arguments(&argc, &argv, cli_options, &allocated);
    }
};
}  // namespace

extern "C" const char *typephp_project_entry_file(void) {
    return project_entry;
}

TEST(typephp_sapi, prepends_project_entry_to_application_arguments) {
    char executable[] = "app";
    char first[] = "first";
    char second[] = "second";
    char *arguments[] = {executable, first, second, nullptr};
    PreparedArguments prepared(3, arguments);

    ASSERT_EQ(prepared.prepare(), SUCCESS);
    ASSERT_NE(prepared.allocated, nullptr);
    EXPECT_EQ(prepared.argc, 4);
    EXPECT_EQ(prepared.argv, prepared.allocated);
    EXPECT_STREQ(prepared.argv[0], "app");
    EXPECT_STREQ(prepared.argv[1], "/app/index.php");
    EXPECT_STREQ(prepared.argv[2], "first");
    EXPECT_STREQ(prepared.argv[3], "second");
    EXPECT_EQ(prepared.argv[4], nullptr);
}

TEST(typephp_sapi, prepends_project_entry_when_no_arguments_are_given) {
    char executable[] = "app";
    char *arguments[] = {executable, nullptr};
    PreparedArguments prepared(1, arguments);

    ASSERT_EQ(prepared.prepare(), SUCCESS);
    ASSERT_NE(prepared.allocated, nullptr);
    EXPECT_EQ(prepared.argc, 2);
    EXPECT_STREQ(prepared.argv[1], "/app/index.php");
    EXPECT_EQ(prepared.argv[2], nullptr);
}

TEST(typephp_sapi, preserves_php_cli_short_and_long_options) {
    for (char *option : {const_cast<char *>("-m"), const_cast<char *>("--modules")}) {
        char executable[] = "app";
        char *arguments[] = {executable, option, nullptr};
        PreparedArguments prepared(2, arguments);

        ASSERT_EQ(prepared.prepare(), SUCCESS);
        EXPECT_EQ(prepared.argc, 2);
        EXPECT_EQ(prepared.argv, arguments);
        EXPECT_EQ(prepared.allocated, nullptr);
    }
}

TEST(typephp_sapi, preserves_php_cli_options_with_values) {
    char executable[] = "app";
    char server[] = "-S";
    char address[] = "127.0.0.1:8080";
    char *arguments[] = {executable, server, address, nullptr};
    PreparedArguments prepared(3, arguments);

    ASSERT_EQ(prepared.prepare(), SUCCESS);
    EXPECT_EQ(prepared.argc, 3);
    EXPECT_EQ(prepared.argv, arguments);
    EXPECT_EQ(prepared.allocated, nullptr);
}

TEST(typephp_sapi, preserves_stdin_and_end_of_options_markers) {
    for (char *marker : {const_cast<char *>("-"), const_cast<char *>("--")}) {
        char executable[] = "app";
        char *arguments[] = {executable, marker, nullptr};
        PreparedArguments prepared(2, arguments);

        ASSERT_EQ(prepared.prepare(), SUCCESS);
        EXPECT_EQ(prepared.argv, arguments);
        EXPECT_EQ(prepared.allocated, nullptr);
    }
}

TEST(typephp_sapi, preserves_invalid_php_cli_options_for_php_to_report) {
    char executable[] = "app";
    char invalid[] = "--invalid-option";
    char *arguments[] = {executable, invalid, nullptr};
    PreparedArguments prepared(2, arguments);

    ASSERT_EQ(prepared.prepare(), SUCCESS);
    EXPECT_EQ(prepared.argv, arguments);
    EXPECT_EQ(prepared.allocated, nullptr);
}

TEST(typephp_sapi, rejects_application_mode_without_a_valid_entry) {
    const char *saved_entry = project_entry;
    for (const char *invalid_entry : {static_cast<const char *>(nullptr), ""}) {
        project_entry = invalid_entry;
        char executable[] = "app";
        char argument[] = "value";
        char *arguments[] = {executable, argument, nullptr};
        PreparedArguments prepared(2, arguments);

        EXPECT_EQ(prepared.prepare(), FAILURE);
        EXPECT_EQ(prepared.argv, arguments);
        EXPECT_EQ(prepared.allocated, nullptr);
    }
    project_entry = saved_entry;
}
