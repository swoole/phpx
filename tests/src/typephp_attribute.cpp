#include "phpx_test.h"
#include "typephp_helper.h"

TEST(typephp_attribute, reflection_handlers_are_reference_counted_and_restored) {
    ASSERT_EQ(typephp_install_reflection_attribute_handlers(), SUCCESS);
    ASSERT_EQ(typephp_install_reflection_attribute_handlers(), SUCCESS);

    typephp_uninstall_reflection_attribute_handlers();
    typephp_uninstall_reflection_attribute_handlers();

    // An extra uninstall is intentionally harmless. This also protects module
    // shutdown paths when initialization stopped before installing the hooks.
    typephp_uninstall_reflection_attribute_handlers();
}
