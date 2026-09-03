#!/usr/bin/env bash
# 构建全静态 libphpx.a
#
# 依赖路径通过环境变量传入（swoole-cli 集成时由外部构建脚本设置）：
#   PHPX_PHP_INCLUDE_DIR   PHP 源码头文件根目录（如 /work）
#   PHPX_GMP_INCLUDE_DIR   GMP 头文件目录
#   PHPX_GMP_LIB_DIR       GMP 库目录
#   PHPX_MPFR_INCLUDE_DIR  MPFR 头文件目录
#   PHPX_MPFR_LIB_DIR      MPFR 库目录
#
# 也可直接以命令行参数覆盖：./build.sh /work /path/gmp/include ...

set -e

PHPX_HOME="$(cd "$(dirname "$0")/.." && pwd)"

PHP_INCLUDE_DIR="${1:-${PHPX_PHP_INCLUDE_DIR:?PHPX_PHP_INCLUDE_DIR is required}}"
GMP_INCLUDE_DIR="${2:-${PHPX_GMP_INCLUDE_DIR:?PHPX_GMP_INCLUDE_DIR is required}}"
GMP_LIB_DIR="${3:-${PHPX_GMP_LIB_DIR:?PHPX_GMP_LIB_DIR is required}}"
MPFR_INCLUDE_DIR="${4:-${PHPX_MPFR_INCLUDE_DIR:?PHPX_MPFR_INCLUDE_DIR is required}}"
MPFR_LIB_DIR="${5:-${PHPX_MPFR_LIB_DIR:?PHPX_MPFR_LIB_DIR is required}}"

cmake \
    -S "$PHPX_HOME/full-static" \
    -B "$PHPX_HOME/build/full-static" \
    -DCMAKE_BUILD_TYPE=Release \
    -DPHPX_PHP_INCLUDE_DIR="$PHP_INCLUDE_DIR" \
    -DPHPX_GMP_INCLUDE_DIR="$GMP_INCLUDE_DIR" \
    -DPHPX_GMP_LIB_DIR="$GMP_LIB_DIR" \
    -DPHPX_MPFR_INCLUDE_DIR="$MPFR_INCLUDE_DIR" \
    -DPHPX_MPFR_LIB_DIR="$MPFR_LIB_DIR"

cmake --build "$PHPX_HOME/build/full-static" --parallel "$(nproc 2>/dev/null || echo 4)"

echo ""
echo "libphpx.a: $PHPX_HOME/build/full-static/libphpx.a"
