#!/usr/bin/env bash

phpx_find_wasi_tool()
{
    local variable=$1
    local command_name=$2
    local configured=${!variable:-}

    if [[ -n "${configured}" ]]; then
        if [[ ! -x "${configured}" ]]; then
            echo "Configured WASI tool is not executable: ${configured}" >&2
            return 1
        fi
    else
        configured=$(command -v "${command_name}" || true)
        if [[ -z "${configured}" ]]; then
            echo "Required WASI tool '${command_name}' was not found in PATH" >&2
            return 1
        fi
    fi

    printf -v "${variable}" '%s' "${configured}"
    export "${variable}"
}

phpx_find_wasi_tool TYPEPHP_WASI_CC wasm32-wasip2-clang
phpx_find_wasi_tool TYPEPHP_WASI_CXX wasm32-wasip2-clang++
phpx_find_wasi_tool TYPEPHP_WASI_AR llvm-ar
phpx_find_wasi_tool TYPEPHP_WASI_RANLIB llvm-ranlib
phpx_find_wasi_tool TYPEPHP_WASI_NM llvm-nm

wasi_cc=${TYPEPHP_WASI_CC}
wasi_cxx=${TYPEPHP_WASI_CXX}
wasi_ar=${TYPEPHP_WASI_AR}
wasi_ranlib=${TYPEPHP_WASI_RANLIB}
wasi_nm=${TYPEPHP_WASI_NM}
