#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant curl_close(const Variant &handle);
Variant curl_copy_handle(const Variant &handle);
Variant curl_errno(const Variant &handle);
Variant curl_error(const Variant &handle);
Variant curl_escape(const Variant &handle, const Variant &string);
Variant curl_unescape(const Variant &handle, const Variant &string);
Variant curl_multi_setopt(const Variant &multi_handle, const Variant &option, const Variant &value);
Variant curl_exec(const Variant &handle);
Variant curl_file_create(const Variant &filename, const Variant &mime_type = {}, const Variant &posted_filename = {});
Variant curl_getinfo(const Variant &handle, const Variant &option = {});
Variant curl_init(const Variant &url = {});
Variant curl_upkeep(const Variant &handle);
Variant curl_multi_add_handle(const Variant &multi_handle, const Variant &handle);
Variant curl_multi_close(const Variant &multi_handle);
Variant curl_multi_errno(const Variant &multi_handle);
Variant curl_multi_exec(const Variant &multi_handle, const Reference &still_running);
Variant curl_multi_getcontent(const Variant &handle);
Variant curl_multi_info_read(const Variant &multi_handle, const Reference &queued_messages = {});
Variant curl_multi_init();
Variant curl_multi_remove_handle(const Variant &multi_handle, const Variant &handle);
Variant curl_multi_select(const Variant &multi_handle, const Variant &timeout = 1);
Variant curl_multi_strerror(const Variant &error_code);
Variant curl_pause(const Variant &handle, const Variant &flags);
Variant curl_reset(const Variant &handle);
Variant curl_setopt_array(const Variant &handle, const Variant &options);
Variant curl_setopt(const Variant &handle, const Variant &option, const Variant &value);
Variant curl_share_close(const Variant &share_handle);
Variant curl_share_errno(const Variant &share_handle);
Variant curl_share_init();
Variant curl_share_setopt(const Variant &share_handle, const Variant &option, const Variant &value);
Variant curl_share_strerror(const Variant &error_code);
Variant curl_strerror(const Variant &error_code);
Variant curl_version();
}  // namespace php
