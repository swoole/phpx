# PHPX WASI SDK

PHPX is the canonical installation root for the TypePHP `wasm32-wasip2` SDK:

```text
phpx/wasm/wasm32-wasip2/
├── include/
├── lib/
└── .typephp-wasi-sdk-abi
```

Release packages populate this directory with the PHP, PHPX, GMP, MPFR, and
mpdecimal headers and static archives. Locally built SDK artifacts are ignored
by Git. TypePHP locates this directory through the existing PHPX resolution
rules (`PHPX_HOME`, Composer package metadata, then `vendor/swoole/phpx`) and
does not define a separate WASI SDK environment variable.
