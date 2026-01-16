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

#pragma once

#include <utility>
#include <type_traits>

template <typename F>
class ScopeGuard {
  public:
    explicit ScopeGuard(F &&f) noexcept : func_(std::forward<F>(f)), active_(true) {}

    ScopeGuard(const ScopeGuard &) = delete;
    ScopeGuard &operator=(const ScopeGuard &) = delete;

    ScopeGuard(ScopeGuard &&other) noexcept : func_(std::move(other.func_)), active_(other.active_) {
        other.active_ = false;
    }

    ~ScopeGuard() noexcept {
        if (active_) {
            func_();
        }
    }

    void dismiss() noexcept {
        active_ = false;
    }

  private:
    F func_;
    bool active_;
};

template <typename F>
ScopeGuard<typename std::decay<F>::type> make_scope_guard(F &&f) noexcept {
    return ScopeGuard<typename std::decay<F>::type>(std::forward<F>(f));
}

#define CONCAT_IMPL(x, y) x##y
#define CONCAT(x, y) CONCAT_IMPL(x, y)

#define ON_SCOPE_EXIT(code) auto CONCAT(__scope_guard_, __LINE__) = make_scope_guard([&]() noexcept { code; })
