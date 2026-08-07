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
*/

#pragma once

#include "phpx.h"

namespace php {

/**
 * Temporarily replace Zend's property visibility scope and restore it on C++ scope exit.
 * A Zend bailout uses longjmp and does not run C++ destructors; code spanning a
 * bailout boundary must call restore() from its zend_catch path before rethrowing.
 */
class FakeScopeGuard final {
  public:
    explicit FakeScopeGuard(zend_class_entry *scope) noexcept : previous_(current()) {
        EG(fake_scope) = scope;
    }

    FakeScopeGuard(const FakeScopeGuard &) = delete;
    FakeScopeGuard &operator=(const FakeScopeGuard &) = delete;
    FakeScopeGuard(FakeScopeGuard &&) = delete;
    FakeScopeGuard &operator=(FakeScopeGuard &&) = delete;

    ~FakeScopeGuard() noexcept {
        restore();
    }

    static zend_class_entry *current() noexcept {
        return EG(fake_scope);
    }

    void restore() noexcept {
        if (active_) {
            EG(fake_scope) = previous_;
            active_ = false;
        }
    }

  private:
    zend_class_entry *previous_;
    bool active_ = true;
};

}  // namespace php
