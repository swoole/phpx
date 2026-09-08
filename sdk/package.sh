#!/usr/bin/env bash

set -euo pipefail

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
phpx_root=$(cd "${script_dir}/.." && pwd)

usage()
{
    echo "Usage: sdk/package.sh --prefix <assembled-sdk-dir> --target <target> [--output-dir <dir>]" >&2
}

prefix=
target=
output_dir=${phpx_root}/dist

while [[ $# -gt 0 ]]; do
    case "$1" in
        --prefix) prefix=${2:?}; shift 2 ;;
        --prefix=*) prefix=${1#*=}; shift ;;
        --target) target=${2:?}; shift 2 ;;
        --target=*) target=${1#*=}; shift ;;
        --output-dir) output_dir=${2:?}; shift 2 ;;
        --output-dir=*) output_dir=${1#*=}; shift ;;
        -h|--help) usage; exit 0 ;;
        *) echo "Unknown option: $1" >&2; usage; exit 2 ;;
    esac
done

if [[ -z "${prefix}" || -z "${target}" ]]; then
    usage
    exit 2
fi

for file in \
    manifest.json .typephp-php-runtime-abi .typephp-sdk-abi \
    include/php/main/php.h include/phpx/phpx.h \
    lib/libphp.a lib/libphpx.a; do
    if [[ ! -s "${prefix}/${file}" ]]; then
        echo "Assembled SDK is incomplete: ${prefix}/${file}" >&2
        exit 1
    fi
done

manifest_target=$(sed -n 's/.*"target": "\([^"]*\)".*/\1/p' \
    "${prefix}/manifest.json")
php_version=$(sed -n 's/.*"php_version": "\([^"]*\)".*/\1/p' \
    "${prefix}/manifest.json")
if [[ "${manifest_target}" != "${target}" || -z "${php_version}" ]]; then
    echo "Invalid runtime manifest for ${target}." >&2
    exit 1
fi

phpx_version=${PHPX_SDK_VERSION:-${GITHUB_REF_NAME:-$(git -C "${phpx_root}" describe --tags --always)}}
phpx_version=${phpx_version//\//-}
package_name="phpx-sdk_${phpx_version}_php${php_version}_${target}"
package_root="${output_dir}/${package_name}"
archive="${output_dir}/${package_name}.tar.xz"

rm -rf "${package_root}"
mkdir -p "${package_root}" "${package_root}/LICENSES"
cp -Rp "${prefix}/." "${package_root}/"
cp -p "${phpx_root}/LICENSE" "${package_root}/LICENSES/PHPX-LICENSE"

phpx_revision=${GITHUB_SHA:-$(git -C "${phpx_root}" rev-parse HEAD)}
cat > "${package_root}/sdk-manifest.json" <<EOF
{
  "schema": "typephp-phpx-sdk-v1",
  "phpx_version": "${phpx_version}",
  "phpx_revision": "${phpx_revision}",
  "php_version": "${php_version}",
  "target": "${target}",
  "runtime_manifest": "manifest.json"
}
EOF

checksum_file()
{
    if command -v sha256sum >/dev/null 2>&1; then
        sha256sum "$1"
    else
        digest=$(shasum -a 256 "$1" | awk '{ print $1 }')
        printf '%s  %s\n' "${digest}" "$1"
    fi
}

(
    cd "${package_root}"
    find . -type f ! -name FILES.SHA256 -print | LC_ALL=C sort \
        | while IFS= read -r file; do checksum_file "${file}"; done \
        > FILES.SHA256
)

mkdir -p "${output_dir}"
tar -C "${output_dir}" -cJf "${archive}" "${package_name}"
(
    cd "${output_dir}"
    checksum_file "${package_name}.tar.xz" > "${package_name}.tar.xz.sha256"
)

if [[ -n "${GITHUB_OUTPUT:-}" ]]; then
    echo "name=${package_name}" >> "${GITHUB_OUTPUT}"
    echo "archive=${archive}" >> "${GITHUB_OUTPUT}"
fi

echo "Packaged PHPX SDK: ${archive}"
