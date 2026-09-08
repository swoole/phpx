# PHPX SDK release pipeline

PHPX is the single download location for complete TypePHP development SDKs.
The native SDK workflow downloads an immutable PHP Runtime Layer from a
`swoole/swoole-cli` release, builds the matching `libphpx.a`, validates the
combined prefix, and publishes the final archive on the PHPX release page.

The repository variable `SWOOLE_CLI_RUNTIME_REF` must name the exact
`swoole-cli` release tag containing these three assets:

- `php-runtime-layer_swoole-cli-<ref>_php*_linux-x64.tar.xz`
- `php-runtime-layer_swoole-cli-<ref>_php*_linux-arm64.tar.xz`
- `php-runtime-layer_swoole-cli-<ref>_php*_iphoneos-arm64.tar.xz`

For a manual build, pass the same tag through the `swoole_cli_ref` workflow
input. Runtime archive checksums and manifest target fields are verified before
PHPX is compiled, so files from different PHP versions or platforms cannot be
silently mixed.
