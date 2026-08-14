# TypePHP changes

- Replaced Wren Value and Obj scanning with opaque payloads and trace callbacks.
- Replaced VM stack roots with an embedder-provided precise root enumerator.
- Added per-object type metadata and finalize/destroy callbacks.
- Added finalizer resurrection handling and at-most-once finalization.
- Added aligned payload allocation while preserving a stable object address.
- Kept Wren's explicit gray worklist and adaptive heap growth threshold.
