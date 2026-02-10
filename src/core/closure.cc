/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <rango@swoole.com>                             |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"

#if PHP_VERSION_ID >= 80200
#include "zend_closures.h"

namespace php {
class ClosureBox : public Box {
    ~ClosureBox() override {
        efree(zf_);
    }

  public:
    Object this_;
    ClosureFn fn_;
    Array vars_;
    zend_function *zf_;

    ClosureBox(const ClosureFn &fn, const Object &_this, const Array &vars, zend_function *zf) {
        fn_ = fn;
        this_ = _this;
        zf_ = zf;
        vars_ = vars;
    }
};

Object newClosure(const ClosureFn &fn, const ArgList &uses, const Object &_this) {
    auto func = (zend_function *) emalloc(sizeof(zend_internal_function));
    memset(func, 0, sizeof(zend_internal_function));

    String fnName("{closure}");
    Array vars;
    for (auto useItem : uses) {
        vars.append(useItem);
    }
    auto box_ptr = new ClosureBox(fn, _this, vars, func);

    func->type = ZEND_INTERNAL_FUNCTION;
    func->internal_function.handler = [](INTERNAL_FUNCTION_PARAMETERS) {
        Object this_(ZEND_THIS);
        auto box = this_.get("box").toBox<ClosureBox>();
        box->fn_(INTERNAL_FUNCTION_PARAM_PASSTHRU, box->this_, box->vars_);
    };
    func->internal_function.function_name = fnName.str();
    func->common.scope = zend_standard_class_def;

    Variant box(box_ptr);
    Object obj = newObject(zend_standard_class_def);
    obj.setProperty("box", box);

    zval closure;
    zend_create_fake_closure(&closure, func, zend_standard_class_def, NULL, obj.ptr());

    return {&closure, Ctor::Move};
}
}  // namespace php
#endif
