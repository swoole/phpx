export PHPX_HOME="$PWD"

WASI_RESOURCE_DIR="$(wasm32-wasip2-clang++ --print-resource-dir)"
WASI_SDK_ROOT="$(cd "$WASI_RESOURCE_DIR/../../.." && pwd)"
WASI_CMAKE_TOOLCHAIN="$WASI_SDK_ROOT/share/cmake/wasi-sdk-p2.cmake"

cmake \
    -S "$PHPX_HOME/wasm" \
    -B "$PHPX_HOME/build/wasm32-wasip2-wasi" \
    -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE="$WASI_CMAKE_TOOLCHAIN" \
    -DCMAKE_BUILD_TYPE=Release \
    -DPHPX_WASI_SDK_DIR="$PHPX_HOME/wasm/wasm32-wasip2" \
    -DCMAKE_INSTALL_PREFIX="$PHPX_HOME/wasm/wasm32-wasip2"

cmake --build "$PHPX_HOME/build/wasm32-wasip2-wasi" --parallel 16
cmake --install "$PHPX_HOME/build/wasm32-wasip2-wasi"
