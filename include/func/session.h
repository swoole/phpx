#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant session_name(const Variant &name = {});
Variant session_module_name(const Variant &module = {});
Variant session_save_path(const Variant &path = {});
Variant session_id(const Variant &id = {});
Variant session_create_id(const Variant &prefix = "");
Variant session_regenerate_id(const Variant &delete_old_session = false);
Variant session_decode(const Variant &data);
Variant session_encode();
Variant session_destroy();
Variant session_unset();
Variant session_gc();
Variant session_get_cookie_params();
Variant session_write_close();
Variant session_abort();
Variant session_reset();
Variant session_status();
Variant session_register_shutdown();
Variant session_commit();
Variant session_set_save_handler(const Variant &open,
                                 const Variant &close = {},
                                 const Variant &read = {},
                                 const Variant &write = {},
                                 const Variant &destroy = {},
                                 const Variant &gc = {},
                                 const Variant &create_sid = {},
                                 const Variant &validate_sid = {},
                                 const Variant &update_timestamp = {});
Variant session_cache_limiter(const Variant &value = {});
Variant session_cache_expire(const Variant &value = {});
Variant session_set_cookie_params(const Variant &lifetime_or_options,
                                  const Variant &path = {},
                                  const Variant &domain = {},
                                  const Variant &secure = {},
                                  const Variant &httponly = {});
Variant session_start(const Variant &options = Array{});
}  // namespace php
