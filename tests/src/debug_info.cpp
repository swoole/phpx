#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

// Test enable/disable toggle
TEST(debug_info, enable) {
    enableDebugInfo(false);
    debug_info.depth = 0;

    pushDebugFrame("a.cpp", 1, "func_a");
    ASSERT_EQ(debug_info.depth, 0);

    enableDebugInfo(true);
    pushDebugFrame("a.cpp", 1, "func_a");
    ASSERT_EQ(debug_info.depth, 1);
    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test push and pop maintain correct depth
TEST(debug_info, push_pop_depth) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    pushDebugFrame("a.cpp", 10, "func_a");
    ASSERT_EQ(debug_info.depth, 1);

    pushDebugFrame("b.cpp", 20, "func_b");
    ASSERT_EQ(debug_info.depth, 2);

    pushDebugFrame("c.cpp", 30, "func_c");
    ASSERT_EQ(debug_info.depth, 3);

    popDebugFrame();
    ASSERT_EQ(debug_info.depth, 2);

    popDebugFrame();
    ASSERT_EQ(debug_info.depth, 1);

    popDebugFrame();
    ASSERT_EQ(debug_info.depth, 0);

    // popping empty stack is safe
    popDebugFrame();
    ASSERT_EQ(debug_info.depth, 0);

    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test frame data is stored correctly
TEST(debug_info, frame_data) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    pushDebugFrame("test.php", 42, "my_function");
    ASSERT_EQ(debug_info.depth, 1);

    auto &frame = debug_info.frames[0];
    ASSERT_STREQ(frame.file, "test.php");
    ASSERT_EQ(frame.line, 42);
    ASSERT_STREQ(frame.function, "my_function");

    pushDebugFrame("other.php", 99, "Class::method");
    ASSERT_EQ(debug_info.depth, 2);

    auto &frame2 = debug_info.frames[1];
    ASSERT_STREQ(frame2.file, "other.php");
    ASSERT_EQ(frame2.line, 99);
    ASSERT_STREQ(frame2.function, "Class::method");

    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test traceDebugInfo updates current top frame
TEST(debug_info, trace_updates_top_frame) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    pushDebugFrame("start.php", 1, "outer");
    ASSERT_EQ(debug_info.depth, 1);

    traceDebugInfo("start.php", 5);
    ASSERT_EQ(debug_info.depth, 1);
    ASSERT_STREQ(debug_info.frames[0].file, "start.php");
    ASSERT_EQ(debug_info.frames[0].line, 5);

    pushDebugFrame("inner.php", 10, "inner");
    ASSERT_EQ(debug_info.depth, 2);

    traceDebugInfo("inner.php", 15);
    ASSERT_EQ(debug_info.depth, 2);
    ASSERT_STREQ(debug_info.frames[1].file, "inner.php");
    ASSERT_EQ(debug_info.frames[1].line, 15);

    // outer frame should be unchanged
    ASSERT_STREQ(debug_info.frames[0].function, "outer");
    ASSERT_EQ(debug_info.frames[0].line, 5);

    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test traceDebugInfo auto-pushes when stack is empty (backward compat)
TEST(debug_info, trace_auto_push_empty_stack) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    traceDebugInfo("legacy.php", 888);
    ASSERT_EQ(debug_info.depth, 1);
    ASSERT_STREQ(debug_info.frames[0].file, "legacy.php");
    ASSERT_EQ(debug_info.frames[0].line, 888);
    ASSERT_TRUE(debug_info.frames[0].function == nullptr);

    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test traceDebugInfo is no-op when disabled
TEST(debug_info, trace_disabled_noop) {
    enableDebugInfo(false);
    debug_info.depth = 0;

    traceDebugInfo("x.php", 1);
    ASSERT_EQ(debug_info.depth, 0);

    pushDebugFrame("x.php", 1, "x");
    ASSERT_EQ(debug_info.depth, 0);
}

// Test pushDebugFrame with nullptr function name
TEST(debug_info, push_null_function) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    pushDebugFrame("f.cpp", 77, nullptr);
    ASSERT_EQ(debug_info.depth, 1);
    ASSERT_TRUE(debug_info.frames[0].function == nullptr);

    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test max depth limit
TEST(debug_info, max_depth) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    for (int i = 0; i < PHPX_MAX_DEBUG_DEPTH; i++) {
        pushDebugFrame("deep.cpp", i, "deep");
    }
    ASSERT_EQ(debug_info.depth, PHPX_MAX_DEBUG_DEPTH);

    // should not exceed max
    pushDebugFrame("overflow.cpp", 999, "overflow");
    ASSERT_EQ(debug_info.depth, PHPX_MAX_DEBUG_DEPTH);

    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test augmentException on exception with single frame
TEST(debug_info, set_debug_info_single_frame) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    pushDebugFrame("single.php", 100, "single_func");
    traceDebugInfo("single.php", 105);

    try {
        throwError("test error single");
    } catch (zend_object *ex) {
        auto e = catchException();
        auto f = e.call("getFile");
        auto l = e.call("getLine");

        ASSERT_STREQ(f.toCString(), "single.php");
        ASSERT_EQ(l.toInt(), 105);

        // Verify trace property is set as array
        auto trace = e.call("getTrace");
        ASSERT_TRUE(trace.isArray());
    }

    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test augmentException on exception with nested frames
TEST(debug_info, set_debug_info_nested_frames) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    pushDebugFrame("outer.php", 10, "outer_function");
    traceDebugInfo("outer.php", 15);
    pushDebugFrame("inner.php", 20, "inner_function");
    traceDebugInfo("inner.php", 25);

    try {
        throwError("test error nested");
    } catch (zend_object *ex) {
        auto e = catchException();
        auto f = e.call("getFile");
        auto l = e.call("getLine");

        // Should report innermost frame
        ASSERT_STREQ(f.toCString(), "inner.php");
        ASSERT_EQ(l.toInt(), 25);

        // trace should contain both frames in getTraceAsString
        auto traceStr = e.call("getTraceAsString");
        ASSERT_TRUE(traceStr.isString());
        ASSERT_GT(traceStr.length(), 0);
        ASSERT_TRUE(strstr(traceStr.toCString(), "outer_function") != nullptr);
        ASSERT_TRUE(strstr(traceStr.toCString(), "inner_function") != nullptr);
    }

    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test augmentException is no-op when disabled
TEST(debug_info, set_debug_info_disabled) {
    enableDebugInfo(false);
    debug_info.depth = 0;

    try {
        throwError("test error disabled");
    } catch (zend_object *ex) {
        auto e = catchException();
        auto f = e.call("getFile");
        auto l = e.call("getLine");

        // File/line from the generated C++ code, NOT from debug_info
        // (just verify no crash and reasonable values)
        ASSERT_TRUE(f.isString());
        ASSERT_GT(l.toInt(), 0);
    }
}

// Test augmentException with empty stack is no-op
TEST(debug_info, set_debug_info_empty_stack) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    try {
        throwError("test error empty stack");
    } catch (zend_object *ex) {
        auto e = catchException();
        auto f = e.call("getFile");

        // Should keep original exception file, not crash
        ASSERT_TRUE(f.isString());
    }
}

// Test pushDebugFrame with empty function string
TEST(debug_info, push_empty_function_string) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    pushDebugFrame("e.cpp", 50, "");
    ASSERT_EQ(debug_info.depth, 1);
    ASSERT_STREQ(debug_info.frames[0].function, "");

    // Verify trace output handles empty function name gracefully
    try {
        throwError("test empty function");
    } catch (zend_object *ex) {
        auto e = catchException();
        auto traceArr = e.call("getTrace");
        ASSERT_TRUE(traceArr.isArray());
    }

    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test Class::method format in function name
TEST(debug_info, class_method_name_format) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    pushDebugFrame("class_test.php", 1, "MyClass::myMethod");
    pushDebugFrame("class_test.php", 10, "OtherClass::otherMethod");

    try {
        throwError("test class method format");
    } catch (zend_object *ex) {
        auto e = catchException();
        auto traceStr = e.call("getTraceAsString");
        ASSERT_TRUE(traceStr.isString());
        ASSERT_TRUE(strstr(traceStr.toCString(), "MyClass::myMethod") != nullptr);
        ASSERT_TRUE(strstr(traceStr.toCString(), "OtherClass::otherMethod") != nullptr);
    }

    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test trace format: "#N function() at file:line"
TEST(debug_info, trace_format) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    pushDebugFrame("app.php", 5, "main");
    pushDebugFrame("lib.php", 20, "helper");

    try {
        throwError("test trace format");
    } catch (zend_object *ex) {
        auto e = catchException();
        auto traceStr = e.call("getTraceAsString");
        ASSERT_TRUE(traceStr.isString());

        // PHP backtrace format: #N file(line): function()
        ASSERT_TRUE(strstr(traceStr.toCString(), "#0") != nullptr);
        ASSERT_TRUE(strstr(traceStr.toCString(), "#1") != nullptr);
        ASSERT_TRUE(strstr(traceStr.toCString(), "main") != nullptr);
        ASSERT_TRUE(strstr(traceStr.toCString(), "helper") != nullptr);
    }

    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test nested push/pop with trace interleaving (simulates real call stack)
TEST(debug_info, simulated_call_stack) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    // Simulate: main() calls foo(), foo() calls bar()
    pushDebugFrame("main.php", 1, "main");
    traceDebugInfo("main.php", 3);  // line inside main

    pushDebugFrame("foo.php", 1, "foo");
    traceDebugInfo("foo.php", 5);  // line inside foo

    pushDebugFrame("bar.php", 1, "bar");
    traceDebugInfo("bar.php", 3);  // line inside bar - exception thrown here

    try {
        throwError("error in bar");
    } catch (zend_object *ex) {
        auto e = catchException();
        auto f = e.call("getFile");
        auto l = e.call("getLine");

        ASSERT_STREQ(f.toCString(), "bar.php");
        ASSERT_EQ(l.toInt(), 3);

        auto traceStr = e.call("getTraceAsString");
        ASSERT_TRUE(traceStr.isString());
        // Should show all 3 levels
        ASSERT_TRUE(strstr(traceStr.toCString(), "main") != nullptr);
        ASSERT_TRUE(strstr(traceStr.toCString(), "foo") != nullptr);
        ASSERT_TRUE(strstr(traceStr.toCString(), "bar") != nullptr);
    }

    popDebugFrame();  // bar returns
    ASSERT_EQ(debug_info.depth, 2);

    popDebugFrame();  // foo returns
    ASSERT_EQ(debug_info.depth, 1);

    popDebugFrame();  // main returns
    ASSERT_EQ(debug_info.depth, 0);

    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test exception thrown after pop returns correct frame
TEST(debug_info, exception_after_pop) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    pushDebugFrame("outer.php", 1, "outer");
    traceDebugInfo("outer.php", 5);

    pushDebugFrame("inner.php", 1, "inner");
    traceDebugInfo("inner.php", 8);
    popDebugFrame();  // inner returns successfully

    // Now at outer level
    traceDebugInfo("outer.php", 12);

    try {
        throwError("error after inner returned");
    } catch (zend_object *ex) {
        auto e = catchException();
        auto f = e.call("getFile");

        ASSERT_STREQ(f.toCString(), "outer.php");
    }

    popDebugFrame();
    debug_info.depth = 0;
    enableDebugInfo(false);
}

// Test rapid push/pop cycles
TEST(debug_info, rapid_push_pop) {
    enableDebugInfo(true);
    debug_info.depth = 0;

    for (int i = 0; i < 20; i++) {
        pushDebugFrame("cycle.php", i, "cycle_func");
        ASSERT_EQ(debug_info.depth, i + 1);
    }
    for (int i = 19; i >= 0; i--) {
        ASSERT_EQ(debug_info.depth, i + 1);
        popDebugFrame();
    }
    ASSERT_EQ(debug_info.depth, 0);

    debug_info.depth = 0;
    enableDebugInfo(false);
}
