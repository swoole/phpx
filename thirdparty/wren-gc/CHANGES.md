# TypePHP changes

- Replaced Wren Value and Obj scanning with opaque payloads and trace callbacks.
- Replaced VM stack roots with an embedder-provided precise root enumerator.
- Added per-object type metadata and finalize/destroy callbacks.
- Added finalizer resurrection handling and at-most-once finalization.
- Added aligned payload allocation while preserving a stable object address.
- Kept Wren's explicit gray worklist and adaptive heap growth threshold.
- Compressed the per-object header to two pointer-sized words. Trace, finalize,
  destroy and size metadata now live in heap/type callbacks instead of being
  duplicated in every object; mark/finalizer state uses tagged bits in the
  object-list pointer.
