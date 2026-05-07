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

#include "phpx.h"

#include <array>
#include <initializer_list>
#include <stdexcept>

namespace php {
static inline Int safeIndex(Int index, Int size) {
    if (UNEXPECTED(index < 0 || index >= size)) {
        throwError("Array index out of bounds: index %ld, size %ld", (long) index, (long) size);
        return -1;
    }
    return index;
}

template <typename T, std::size_t N>
class StdArray {
  private:
    std::array<T, N> data_;

  public:
    StdArray() = default;

    StdArray(std::initializer_list<T> init) {
        if (init.size() > N) {
            throw std::out_of_range("too many initializers");
        }

        std::copy(init.begin(), init.end(), data_.begin());
    }

    void offsetSet(std::size_t index, const T &value) {
        data_[safeIndex(index, N)] = value;
    }

    const T &offsetGet(std::size_t index) const {
        return data_[safeIndex(index, N)];
    }

    T &offsetGet(std::size_t index) {
        return data_[safeIndex(index, N)];
    }

    constexpr std::size_t size() const noexcept {
        return N;
    }

    T &operator[](std::size_t index) {
        return data_[index];
    }

    const T &operator[](std::size_t index) const {
        return data_[index];
    }

    T &at(std::size_t index) {
        return offsetGet(index);
    }

    const T &at(std::size_t index) const {
        return offsetGet(index);
    }
};

template <typename T>
struct is_std_array : std::false_type {};

template <typename T, std::size_t N>
struct is_std_array<StdArray<T, N>> : std::true_type {};

template <typename T>
static inline typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, bool>::value, Variant>::type
toVariant(const T &value) {
    return Variant(static_cast<zend_long>(value));
}

template <typename T>
static inline typename std::enable_if<std::is_same<T, bool>::value, Variant>::type toVariant(const T &value) {
    return Variant(value);
}

template <typename T>
static inline typename std::enable_if<std::is_floating_point<T>::value, Variant>::type toVariant(const T &value) {
    return Variant(static_cast<double>(value));
}

static inline Variant toVariant(const std::string &value) {
    return Variant(value.c_str(), value.length());
}

static inline Variant toVariant(const char *value) {
    return Variant(value);
}

static inline Variant toVariant(const Variant &value) {
    return value;
}

static inline Variant toVariant(const String &value) {
    return Variant(value);
}

template <typename T, std::size_t N>
static inline Array toArray(const StdArray<T, N> &arr) {
    Array result;

    for (std::size_t i = 0; i < N; ++i) {
        if constexpr (is_std_array<T>::value) {
            result.set(i, toArray(arr[i]));
        } else {
            result.set(i, toVariant(arr[i]));
        }
    }

    return result;
}
}  // namespace php
