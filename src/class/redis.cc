#include "phpx.h"
#include "class/redis.h"

namespace php {
Redis::Redis(const Variant &options) {
    this_ = newObject(LITERAL_STRING[1099], {options});
}
Variant Redis::_compress(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1100]);
    }
    return this_.call(_method_fn, {value});
}
Variant Redis::_uncompress(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1101]);
    }
    return this_.call(_method_fn, {value});
}
Variant Redis::_prefix(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1102]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::_serialize(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1103]);
    }
    return this_.call(_method_fn, {value});
}
Variant Redis::_unserialize(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1104]);
    }
    return this_.call(_method_fn, {value});
}
Variant Redis::_pack(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1105]);
    }
    return this_.call(_method_fn, {value});
}
Variant Redis::_unpack(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1106]);
    }
    return this_.call(_method_fn, {value});
}
Variant Redis::append(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Redis::auth(const Variant &credentials) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1108]);
    }
    return this_.call(_method_fn, {credentials});
}
Variant Redis::bgSave() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1109]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::bgrewriteaof() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1110]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::waitaof(const Variant &numlocal, const Variant &numreplicas, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1111]);
    }
    return this_.call(_method_fn, {numlocal, numreplicas, timeout});
}
Variant Redis::bitcount(const Variant &key, const Variant &start, const Variant &end, const Variant &bybit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1112]);
    }
    return this_.call(_method_fn, {key, start, end, bybit});
}
Variant Redis::bitpos(
    const Variant &key, const Variant &bit, const Variant &start, const Variant &end, const Variant &bybit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1114]);
    }
    return this_.call(_method_fn, {key, bit, start, end, bybit});
}
Variant Redis::brpoplpush(const Variant &src, const Variant &dst, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1117]);
    }
    return this_.call(_method_fn, {src, dst, timeout});
}
Variant Redis::bzmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1120]);
    }
    return this_.call(_method_fn, {timeout, keys, from, count});
}
Variant Redis::zmpop(const Variant &keys, const Variant &from, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1121]);
    }
    return this_.call(_method_fn, {keys, from, count});
}
Variant Redis::blmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1122]);
    }
    return this_.call(_method_fn, {timeout, keys, from, count});
}
Variant Redis::lmpop(const Variant &keys, const Variant &from, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1123]);
    }
    return this_.call(_method_fn, {keys, from, count});
}
Variant Redis::clearLastError() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1124]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1126]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::config(const Variant &operation, const Variant &key_or_settings, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1128]);
    }
    return this_.call(_method_fn, {operation, key_or_settings, value});
}
Variant Redis::connect(const Variant &host,
                       const Variant &port,
                       const Variant &timeout,
                       const Variant &persistent_id,
                       const Variant &retry_interval,
                       const Variant &read_timeout,
                       const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[861]);
    }
    return this_.call(_method_fn, {host, port, timeout, persistent_id, retry_interval, read_timeout, context});
}
Variant Redis::copy(const Variant &src, const Variant &dst, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[917]);
    }
    return this_.call(_method_fn, {src, dst, options});
}
Variant Redis::dbSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1129]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::debug(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1130]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::decr(const Variant &key, const Variant &by) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1131]);
    }
    return this_.call(_method_fn, {key, by});
}
Variant Redis::decrBy(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1132]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Redis::discard() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1134]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::dump(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1135]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::echo(const Variant &str) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1136]);
    }
    return this_.call(_method_fn, {str});
}
Variant Redis::eval(const Variant &script, const Variant &args, const Variant &num_keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1137]);
    }
    return this_.call(_method_fn, {script, args, num_keys});
}
Variant Redis::eval_ro(const Variant &script_sha, const Variant &args, const Variant &num_keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1138]);
    }
    return this_.call(_method_fn, {script_sha, args, num_keys});
}
Variant Redis::evalsha(const Variant &sha1, const Variant &args, const Variant &num_keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1139]);
    }
    return this_.call(_method_fn, {sha1, args, num_keys});
}
Variant Redis::evalsha_ro(const Variant &sha1, const Variant &args, const Variant &num_keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1140]);
    }
    return this_.call(_method_fn, {sha1, args, num_keys});
}
Variant Redis::exec() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[866]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::expire(const Variant &key, const Variant &timeout, const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1142]);
    }
    return this_.call(_method_fn, {key, timeout, mode});
}
Variant Redis::expireAt(const Variant &key, const Variant &timestamp, const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1143]);
    }
    return this_.call(_method_fn, {key, timestamp, mode});
}
Variant Redis::failover(const Variant &to, const Variant &abort, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1144]);
    }
    return this_.call(_method_fn, {to, abort, timeout});
}
Variant Redis::expiretime(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1145]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::pexpiretime(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1146]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::fcall(const Variant &fn, const Variant &keys, const Variant &args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1147]);
    }
    return this_.call(_method_fn, {fn, keys, args});
}
Variant Redis::fcall_ro(const Variant &fn, const Variant &keys, const Variant &args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1148]);
    }
    return this_.call(_method_fn, {fn, keys, args});
}
Variant Redis::flushAll(const Variant &sync) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1149]);
    }
    return this_.call(_method_fn, {sync});
}
Variant Redis::flushDB(const Variant &sync) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1150]);
    }
    return this_.call(_method_fn, {sync});
}
Variant Redis::geodist(const Variant &key, const Variant &src, const Variant &dst, const Variant &unit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1153]);
    }
    return this_.call(_method_fn, {key, src, dst, unit});
}
Variant Redis::georadius(const Variant &key,
                         const Variant &lng,
                         const Variant &lat,
                         const Variant &radius,
                         const Variant &unit,
                         const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1156]);
    }
    return this_.call(_method_fn, {key, lng, lat, radius, unit, options});
}
Variant Redis::georadius_ro(const Variant &key,
                            const Variant &lng,
                            const Variant &lat,
                            const Variant &radius,
                            const Variant &unit,
                            const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1157]);
    }
    return this_.call(_method_fn, {key, lng, lat, radius, unit, options});
}
Variant Redis::georadiusbymember(
    const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1158]);
    }
    return this_.call(_method_fn, {key, member, radius, unit, options});
}
Variant Redis::georadiusbymember_ro(
    const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1159]);
    }
    return this_.call(_method_fn, {key, member, radius, unit, options});
}
Variant Redis::geosearch(
    const Variant &key, const Variant &position, const Variant &shape, const Variant &unit, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1160]);
    }
    return this_.call(_method_fn, {key, position, shape, unit, options});
}
Variant Redis::geosearchstore(const Variant &dst,
                              const Variant &src,
                              const Variant &position,
                              const Variant &shape,
                              const Variant &unit,
                              const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1161]);
    }
    return this_.call(_method_fn, {dst, src, position, shape, unit, options});
}
Variant Redis::get(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[134]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::getWithMeta(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1162]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::getAuth() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1163]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::getBit(const Variant &key, const Variant &idx) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1164]);
    }
    return this_.call(_method_fn, {key, idx});
}
Variant Redis::getEx(const Variant &key, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1165]);
    }
    return this_.call(_method_fn, {key, options});
}
Variant Redis::getDBNum() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1166]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::getDel(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1167]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::getHost() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1168]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::getLastError() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1169]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::getMode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1170]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::getOption(const Variant &option) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1171]);
    }
    return this_.call(_method_fn, {option});
}
Variant Redis::getPersistentID() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1172]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::getPort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1173]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::serverName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1174]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::serverVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1175]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::getRange(const Variant &key, const Variant &start, const Variant &end) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1176]);
    }
    return this_.call(_method_fn, {key, start, end});
}
Variant Redis::lcs(const Variant &key1, const Variant &key2, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1177]);
    }
    return this_.call(_method_fn, {key1, key2, options});
}
Variant Redis::getReadTimeout() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1178]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::getset(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1179]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Redis::getTimeout() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1180]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::getTransferredBytes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1181]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::clearTransferredBytes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1182]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::hExists(const Variant &key, const Variant &field) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1184]);
    }
    return this_.call(_method_fn, {key, field});
}
Variant Redis::hGet(const Variant &key, const Variant &member) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1185]);
    }
    return this_.call(_method_fn, {key, member});
}
Variant Redis::hGetAll(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1186]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::hIncrBy(const Variant &key, const Variant &field, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1187]);
    }
    return this_.call(_method_fn, {key, field, value});
}
Variant Redis::hIncrByFloat(const Variant &key, const Variant &field, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1188]);
    }
    return this_.call(_method_fn, {key, field, value});
}
Variant Redis::hKeys(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1189]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::hLen(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1190]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::hMget(const Variant &key, const Variant &fields) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1191]);
    }
    return this_.call(_method_fn, {key, fields});
}
Variant Redis::hMset(const Variant &key, const Variant &fieldvals) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1192]);
    }
    return this_.call(_method_fn, {key, fieldvals});
}
Variant Redis::hRandField(const Variant &key, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1193]);
    }
    return this_.call(_method_fn, {key, options});
}
Variant Redis::hSetNx(const Variant &key, const Variant &field, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1195]);
    }
    return this_.call(_method_fn, {key, field, value});
}
Variant Redis::hStrLen(const Variant &key, const Variant &field) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1196]);
    }
    return this_.call(_method_fn, {key, field});
}
Variant Redis::hVals(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1197]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::hscan(const Variant &key, const Reference &iterator, const Variant &pattern, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1198]);
    }
    return this_.call(_method_fn, {key, &iterator, pattern, count});
}
Variant Redis::expiremember(const Variant &key, const Variant &field, const Variant &ttl, const Variant &unit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1199]);
    }
    return this_.call(_method_fn, {key, field, ttl, unit});
}
Variant Redis::expirememberat(const Variant &key, const Variant &field, const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1200]);
    }
    return this_.call(_method_fn, {key, field, timestamp});
}
Variant Redis::incr(const Variant &key, const Variant &by) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1201]);
    }
    return this_.call(_method_fn, {key, by});
}
Variant Redis::incrBy(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1202]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Redis::incrByFloat(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1203]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Redis::isConnected() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1205]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::keys(const Variant &pattern) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1206]);
    }
    return this_.call(_method_fn, {pattern});
}
Variant Redis::lInsert(const Variant &key, const Variant &pos, const Variant &pivot, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1207]);
    }
    return this_.call(_method_fn, {key, pos, pivot, value});
}
Variant Redis::lLen(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1208]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::lMove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1209]);
    }
    return this_.call(_method_fn, {src, dst, wherefrom, whereto});
}
Variant Redis::blmove(
    const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1210]);
    }
    return this_.call(_method_fn, {src, dst, wherefrom, whereto, timeout});
}
Variant Redis::lPop(const Variant &key, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1211]);
    }
    return this_.call(_method_fn, {key, count});
}
Variant Redis::lPos(const Variant &key, const Variant &value, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1212]);
    }
    return this_.call(_method_fn, {key, value, options});
}
Variant Redis::lPushx(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1215]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Redis::rPushx(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1216]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Redis::lSet(const Variant &key, const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1217]);
    }
    return this_.call(_method_fn, {key, index, value});
}
Variant Redis::lastSave() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1218]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::lindex(const Variant &key, const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1219]);
    }
    return this_.call(_method_fn, {key, index});
}
Variant Redis::lrange(const Variant &key, const Variant &start, const Variant &end) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1220]);
    }
    return this_.call(_method_fn, {key, start, end});
}
Variant Redis::lrem(const Variant &key, const Variant &value, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1221]);
    }
    return this_.call(_method_fn, {key, value, count});
}
Variant Redis::ltrim(const Variant &key, const Variant &start, const Variant &end) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1222]);
    }
    return this_.call(_method_fn, {key, start, end});
}
Variant Redis::mget(const Variant &keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1223]);
    }
    return this_.call(_method_fn, {keys});
}
Variant Redis::migrate(const Variant &host,
                       const Variant &port,
                       const Variant &key,
                       const Variant &dstdb,
                       const Variant &timeout,
                       const Variant &copy,
                       const Variant &replace,
                       const Variant &credentials) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1224]);
    }
    return this_.call(_method_fn, {host, port, key, dstdb, timeout, copy, replace, credentials});
}
Variant Redis::move(const Variant &key, const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1225]);
    }
    return this_.call(_method_fn, {key, index});
}
Variant Redis::mset(const Variant &key_values) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1226]);
    }
    return this_.call(_method_fn, {key_values});
}
Variant Redis::msetnx(const Variant &key_values) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1227]);
    }
    return this_.call(_method_fn, {key_values});
}
Variant Redis::multi(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1228]);
    }
    return this_.call(_method_fn, {value});
}
Variant Redis::object(const Variant &subcommand, const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1229]);
    }
    return this_.call(_method_fn, {subcommand, key});
}
Variant Redis::open(const Variant &host,
                    const Variant &port,
                    const Variant &timeout,
                    const Variant &persistent_id,
                    const Variant &retry_interval,
                    const Variant &read_timeout,
                    const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1230]);
    }
    return this_.call(_method_fn, {host, port, timeout, persistent_id, retry_interval, read_timeout, context});
}
Variant Redis::pconnect(const Variant &host,
                        const Variant &port,
                        const Variant &timeout,
                        const Variant &persistent_id,
                        const Variant &retry_interval,
                        const Variant &read_timeout,
                        const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1231]);
    }
    return this_.call(_method_fn, {host, port, timeout, persistent_id, retry_interval, read_timeout, context});
}
Variant Redis::persist(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1232]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::pexpire(const Variant &key, const Variant &timeout, const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1233]);
    }
    return this_.call(_method_fn, {key, timeout, mode});
}
Variant Redis::pexpireAt(const Variant &key, const Variant &timestamp, const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1234]);
    }
    return this_.call(_method_fn, {key, timestamp, mode});
}
Variant Redis::pfadd(const Variant &key, const Variant &elements) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1235]);
    }
    return this_.call(_method_fn, {key, elements});
}
Variant Redis::pfcount(const Variant &key_or_keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1236]);
    }
    return this_.call(_method_fn, {key_or_keys});
}
Variant Redis::pfmerge(const Variant &dst, const Variant &srckeys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1237]);
    }
    return this_.call(_method_fn, {dst, srckeys});
}
Variant Redis::ping(const Variant &message) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1238]);
    }
    return this_.call(_method_fn, {message});
}
Variant Redis::pipeline() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1239]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::popen(const Variant &host,
                     const Variant &port,
                     const Variant &timeout,
                     const Variant &persistent_id,
                     const Variant &retry_interval,
                     const Variant &read_timeout,
                     const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1240]);
    }
    return this_.call(_method_fn, {host, port, timeout, persistent_id, retry_interval, read_timeout, context});
}
Variant Redis::psetex(const Variant &key, const Variant &expire, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1241]);
    }
    return this_.call(_method_fn, {key, expire, value});
}
Variant Redis::psubscribe(const Variant &patterns, const Variant &cb) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1242]);
    }
    return this_.call(_method_fn, {patterns, cb});
}
Variant Redis::pttl(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1243]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::publish(const Variant &channel, const Variant &message) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1244]);
    }
    return this_.call(_method_fn, {channel, message});
}
Variant Redis::pubsub(const Variant &command, const Variant &arg) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1245]);
    }
    return this_.call(_method_fn, {command, arg});
}
Variant Redis::punsubscribe(const Variant &patterns) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1246]);
    }
    return this_.call(_method_fn, {patterns});
}
Variant Redis::rPop(const Variant &key, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1247]);
    }
    return this_.call(_method_fn, {key, count});
}
Variant Redis::randomKey() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1248]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::rename(const Variant &old_name, const Variant &new_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[457]);
    }
    return this_.call(_method_fn, {old_name, new_name});
}
Variant Redis::renameNx(const Variant &key_src, const Variant &key_dst) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1250]);
    }
    return this_.call(_method_fn, {key_src, key_dst});
}
Variant Redis::reset() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1251]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::restore(const Variant &key, const Variant &ttl, const Variant &value, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1252]);
    }
    return this_.call(_method_fn, {key, ttl, value, options});
}
Variant Redis::role() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1253]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::rpoplpush(const Variant &srckey, const Variant &dstkey) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1254]);
    }
    return this_.call(_method_fn, {srckey, dstkey});
}
Variant Redis::sAddArray(const Variant &key, const Variant &values) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1256]);
    }
    return this_.call(_method_fn, {key, values});
}
Variant Redis::sintercard(const Variant &keys, const Variant &limit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1260]);
    }
    return this_.call(_method_fn, {keys, limit});
}
Variant Redis::sMembers(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1262]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::sMove(const Variant &src, const Variant &dst, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1264]);
    }
    return this_.call(_method_fn, {src, dst, value});
}
Variant Redis::sPop(const Variant &key, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1265]);
    }
    return this_.call(_method_fn, {key, count});
}
Variant Redis::sRandMember(const Variant &key, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1266]);
    }
    return this_.call(_method_fn, {key, count});
}
Variant Redis::save() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[399]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::scan(const Reference &iterator, const Variant &pattern, const Variant &count, const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1269]);
    }
    return this_.call(_method_fn, {&iterator, pattern, count, type});
}
Variant Redis::scard(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1270]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::select(const Variant &db) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1272]);
    }
    return this_.call(_method_fn, {db});
}
Variant Redis::set(const Variant &key, const Variant &value, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1273]);
    }
    return this_.call(_method_fn, {key, value, options});
}
Variant Redis::setBit(const Variant &key, const Variant &idx, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1274]);
    }
    return this_.call(_method_fn, {key, idx, value});
}
Variant Redis::setRange(const Variant &key, const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1275]);
    }
    return this_.call(_method_fn, {key, index, value});
}
Variant Redis::setOption(const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1276]);
    }
    return this_.call(_method_fn, {option, value});
}
Variant Redis::setex(const Variant &key, const Variant &expire, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1277]);
    }
    return this_.call(_method_fn, {key, expire, value});
}
Variant Redis::setnx(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1278]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Redis::sismember(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1279]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Redis::slaveof(const Variant &host, const Variant &port) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1280]);
    }
    return this_.call(_method_fn, {host, port});
}
Variant Redis::replicaof(const Variant &host, const Variant &port) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1281]);
    }
    return this_.call(_method_fn, {host, port});
}
Variant Redis::slowlog(const Variant &operation, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1283]);
    }
    return this_.call(_method_fn, {operation, length});
}
Variant Redis::sort(const Variant &key, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1284]);
    }
    return this_.call(_method_fn, {key, options});
}
Variant Redis::sort_ro(const Variant &key, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1285]);
    }
    return this_.call(_method_fn, {key, options});
}
Variant Redis::sortAsc(const Variant &key,
                       const Variant &pattern,
                       const Variant &get,
                       const Variant &offset,
                       const Variant &count,
                       const Variant &store) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1286]);
    }
    return this_.call(_method_fn, {key, pattern, get, offset, count, store});
}
Variant Redis::sortAscAlpha(const Variant &key,
                            const Variant &pattern,
                            const Variant &get,
                            const Variant &offset,
                            const Variant &count,
                            const Variant &store) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1287]);
    }
    return this_.call(_method_fn, {key, pattern, get, offset, count, store});
}
Variant Redis::sortDesc(const Variant &key,
                        const Variant &pattern,
                        const Variant &get,
                        const Variant &offset,
                        const Variant &count,
                        const Variant &store) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1288]);
    }
    return this_.call(_method_fn, {key, pattern, get, offset, count, store});
}
Variant Redis::sortDescAlpha(const Variant &key,
                             const Variant &pattern,
                             const Variant &get,
                             const Variant &offset,
                             const Variant &count,
                             const Variant &store) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1289]);
    }
    return this_.call(_method_fn, {key, pattern, get, offset, count, store});
}
Variant Redis::sscan(const Variant &key, const Reference &iterator, const Variant &pattern, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1291]);
    }
    return this_.call(_method_fn, {key, &iterator, pattern, count});
}
Variant Redis::ssubscribe(const Variant &channels, const Variant &cb) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1292]);
    }
    return this_.call(_method_fn, {channels, cb});
}
Variant Redis::strlen(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1293]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::subscribe(const Variant &channels, const Variant &cb) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1294]);
    }
    return this_.call(_method_fn, {channels, cb});
}
Variant Redis::sunsubscribe(const Variant &channels) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1295]);
    }
    return this_.call(_method_fn, {channels});
}
Variant Redis::swapdb(const Variant &src, const Variant &dst) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1296]);
    }
    return this_.call(_method_fn, {src, dst});
}
Variant Redis::time() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[226]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::ttl(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1297]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::type(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1298]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::unsubscribe(const Variant &channels) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1300]);
    }
    return this_.call(_method_fn, {channels});
}
Variant Redis::unwatch() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1301]);
    }
    return this_.call(_method_fn, {});
}
Variant Redis::wait(const Variant &numreplicas, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1303]);
    }
    return this_.call(_method_fn, {numreplicas, timeout});
}
Variant Redis::xack(const Variant &key, const Variant &group, const Variant &ids) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1304]);
    }
    return this_.call(_method_fn, {key, group, ids});
}
Variant Redis::xadd(const Variant &key,
                    const Variant &id,
                    const Variant &values,
                    const Variant &maxlen,
                    const Variant &approx,
                    const Variant &nomkstream) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1305]);
    }
    return this_.call(_method_fn, {key, id, values, maxlen, approx, nomkstream});
}
Variant Redis::xautoclaim(const Variant &key,
                          const Variant &group,
                          const Variant &consumer,
                          const Variant &min_idle,
                          const Variant &start,
                          const Variant &count,
                          const Variant &justid) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1306]);
    }
    return this_.call(_method_fn, {key, group, consumer, min_idle, start, count, justid});
}
Variant Redis::xclaim(const Variant &key,
                      const Variant &group,
                      const Variant &consumer,
                      const Variant &min_idle,
                      const Variant &ids,
                      const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1307]);
    }
    return this_.call(_method_fn, {key, group, consumer, min_idle, ids, options});
}
Variant Redis::xdel(const Variant &key, const Variant &ids) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1308]);
    }
    return this_.call(_method_fn, {key, ids});
}
Variant Redis::xgroup(const Variant &operation,
                      const Variant &key,
                      const Variant &group,
                      const Variant &id_or_consumer,
                      const Variant &mkstream,
                      const Variant &entries_read) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1309]);
    }
    return this_.call(_method_fn, {operation, key, group, id_or_consumer, mkstream, entries_read});
}
Variant Redis::xinfo(const Variant &operation, const Variant &arg1, const Variant &arg2, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1310]);
    }
    return this_.call(_method_fn, {operation, arg1, arg2, count});
}
Variant Redis::xlen(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1311]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::xpending(const Variant &key,
                        const Variant &group,
                        const Variant &start,
                        const Variant &end,
                        const Variant &count,
                        const Variant &consumer) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1312]);
    }
    return this_.call(_method_fn, {key, group, start, end, count, consumer});
}
Variant Redis::xrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1313]);
    }
    return this_.call(_method_fn, {key, start, end, count});
}
Variant Redis::xread(const Variant &streams, const Variant &count, const Variant &block) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1314]);
    }
    return this_.call(_method_fn, {streams, count, block});
}
Variant Redis::xreadgroup(
    const Variant &group, const Variant &consumer, const Variant &streams, const Variant &count, const Variant &block) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1315]);
    }
    return this_.call(_method_fn, {group, consumer, streams, count, block});
}
Variant Redis::xrevrange(const Variant &key, const Variant &end, const Variant &start, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1316]);
    }
    return this_.call(_method_fn, {key, end, start, count});
}
Variant Redis::xtrim(
    const Variant &key, const Variant &threshold, const Variant &approx, const Variant &minid, const Variant &limit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1317]);
    }
    return this_.call(_method_fn, {key, threshold, approx, minid, limit});
}
Variant Redis::zCard(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1319]);
    }
    return this_.call(_method_fn, {key});
}
Variant Redis::zCount(const Variant &key, const Variant &start, const Variant &end) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1320]);
    }
    return this_.call(_method_fn, {key, start, end});
}
Variant Redis::zIncrBy(const Variant &key, const Variant &value, const Variant &member) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1321]);
    }
    return this_.call(_method_fn, {key, value, member});
}
Variant Redis::zLexCount(const Variant &key, const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1322]);
    }
    return this_.call(_method_fn, {key, min, max});
}
Variant Redis::zPopMax(const Variant &key, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1324]);
    }
    return this_.call(_method_fn, {key, count});
}
Variant Redis::zPopMin(const Variant &key, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1325]);
    }
    return this_.call(_method_fn, {key, count});
}
Variant Redis::zRange(const Variant &key, const Variant &start, const Variant &end, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1326]);
    }
    return this_.call(_method_fn, {key, start, end, options});
}
Variant Redis::zRangeByLex(
    const Variant &key, const Variant &min, const Variant &max, const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1327]);
    }
    return this_.call(_method_fn, {key, min, max, offset, count});
}
Variant Redis::zRangeByScore(const Variant &key, const Variant &start, const Variant &end, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1328]);
    }
    return this_.call(_method_fn, {key, start, end, options});
}
Variant Redis::zrangestore(
    const Variant &dstkey, const Variant &srckey, const Variant &start, const Variant &end, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1329]);
    }
    return this_.call(_method_fn, {dstkey, srckey, start, end, options});
}
Variant Redis::zRandMember(const Variant &key, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1330]);
    }
    return this_.call(_method_fn, {key, options});
}
Variant Redis::zRank(const Variant &key, const Variant &member) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1331]);
    }
    return this_.call(_method_fn, {key, member});
}
Variant Redis::zRemRangeByLex(const Variant &key, const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1333]);
    }
    return this_.call(_method_fn, {key, min, max});
}
Variant Redis::zRemRangeByRank(const Variant &key, const Variant &start, const Variant &end) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1334]);
    }
    return this_.call(_method_fn, {key, start, end});
}
Variant Redis::zRemRangeByScore(const Variant &key, const Variant &start, const Variant &end) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1335]);
    }
    return this_.call(_method_fn, {key, start, end});
}
Variant Redis::zRevRange(const Variant &key, const Variant &start, const Variant &end, const Variant &scores) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1336]);
    }
    return this_.call(_method_fn, {key, start, end, scores});
}
Variant Redis::zRevRangeByLex(
    const Variant &key, const Variant &max, const Variant &min, const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1337]);
    }
    return this_.call(_method_fn, {key, max, min, offset, count});
}
Variant Redis::zRevRangeByScore(const Variant &key, const Variant &max, const Variant &min, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1338]);
    }
    return this_.call(_method_fn, {key, max, min, options});
}
Variant Redis::zRevRank(const Variant &key, const Variant &member) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1339]);
    }
    return this_.call(_method_fn, {key, member});
}
Variant Redis::zScore(const Variant &key, const Variant &member) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1340]);
    }
    return this_.call(_method_fn, {key, member});
}
Variant Redis::zdiff(const Variant &keys, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1341]);
    }
    return this_.call(_method_fn, {keys, options});
}
Variant Redis::zdiffstore(const Variant &dst, const Variant &keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1342]);
    }
    return this_.call(_method_fn, {dst, keys});
}
Variant Redis::zinter(const Variant &keys, const Variant &weights, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1343]);
    }
    return this_.call(_method_fn, {keys, weights, options});
}
Variant Redis::zintercard(const Variant &keys, const Variant &limit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1344]);
    }
    return this_.call(_method_fn, {keys, limit});
}
Variant Redis::zinterstore(const Variant &dst, const Variant &keys, const Variant &weights, const Variant &aggregate) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1345]);
    }
    return this_.call(_method_fn, {dst, keys, weights, aggregate});
}
Variant Redis::zscan(const Variant &key, const Reference &iterator, const Variant &pattern, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1346]);
    }
    return this_.call(_method_fn, {key, &iterator, pattern, count});
}
Variant Redis::zunion(const Variant &keys, const Variant &weights, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1347]);
    }
    return this_.call(_method_fn, {keys, weights, options});
}
Variant Redis::zunionstore(const Variant &dst, const Variant &keys, const Variant &weights, const Variant &aggregate) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1348]);
    }
    return this_.call(_method_fn, {dst, keys, weights, aggregate});
}
Variant RedisArray::__call(const Variant &function_name, const Variant &arguments) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1349]);
    }
    return this_.call(_method_fn, {function_name, arguments});
}
RedisArray::RedisArray(const Variant &name_or_hosts, const Variant &options) {
    this_ = newObject(LITERAL_STRING[1350], {name_or_hosts, options});
}
Variant RedisArray::_continuum() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1351]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::_distributor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1352]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::_function() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1353]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::_hosts() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1354]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::_instance(const Variant &host) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1355]);
    }
    return this_.call(_method_fn, {host});
}
Variant RedisArray::_rehash(const Variant &fn) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1356]);
    }
    return this_.call(_method_fn, {fn});
}
Variant RedisArray::_target(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1357]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisArray::bgsave() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1358]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::discard() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1134]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::exec() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[866]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::flushall() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1359]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::flushdb() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1360]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::getOption(const Variant &opt) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1171]);
    }
    return this_.call(_method_fn, {opt});
}
Variant RedisArray::hscan(const Variant &key, const Reference &iterator, const Variant &pattern, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1198]);
    }
    return this_.call(_method_fn, {key, &iterator, pattern, count});
}
Variant RedisArray::info() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1204]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::keys(const Variant &pattern) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1206]);
    }
    return this_.call(_method_fn, {pattern});
}
Variant RedisArray::mget(const Variant &keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1223]);
    }
    return this_.call(_method_fn, {keys});
}
Variant RedisArray::mset(const Variant &pairs) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1226]);
    }
    return this_.call(_method_fn, {pairs});
}
Variant RedisArray::multi(const Variant &host, const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1228]);
    }
    return this_.call(_method_fn, {host, mode});
}
Variant RedisArray::ping() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1238]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::save() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[399]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::scan(const Reference &iterator, const Variant &node, const Variant &pattern, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1269]);
    }
    return this_.call(_method_fn, {&iterator, node, pattern, count});
}
Variant RedisArray::select(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1272]);
    }
    return this_.call(_method_fn, {index});
}
Variant RedisArray::setOption(const Variant &opt, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1276]);
    }
    return this_.call(_method_fn, {opt, value});
}
Variant RedisArray::sscan(const Variant &key, const Reference &iterator, const Variant &pattern, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1291]);
    }
    return this_.call(_method_fn, {key, &iterator, pattern, count});
}
Variant RedisArray::unwatch() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1301]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisArray::zscan(const Variant &key, const Reference &iterator, const Variant &pattern, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1346]);
    }
    return this_.call(_method_fn, {key, &iterator, pattern, count});
}
RedisCluster::RedisCluster(const Variant &name,
                           const Variant &seeds,
                           const Variant &timeout,
                           const Variant &read_timeout,
                           const Variant &persistent,
                           const Variant &auth,
                           const Variant &context) {
    this_ = newObject(LITERAL_STRING[1361], {name, seeds, timeout, read_timeout, persistent, auth, context});
}
Variant RedisCluster::_compress(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1100]);
    }
    return this_.call(_method_fn, {value});
}
Variant RedisCluster::_uncompress(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1101]);
    }
    return this_.call(_method_fn, {value});
}
Variant RedisCluster::_serialize(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1103]);
    }
    return this_.call(_method_fn, {value});
}
Variant RedisCluster::_unserialize(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1104]);
    }
    return this_.call(_method_fn, {value});
}
Variant RedisCluster::_pack(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1105]);
    }
    return this_.call(_method_fn, {value});
}
Variant RedisCluster::_unpack(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1106]);
    }
    return this_.call(_method_fn, {value});
}
Variant RedisCluster::_prefix(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1102]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::_masters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1362]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisCluster::_redir() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1363]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisCluster::append(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::bgrewriteaof(const Variant &key_or_address) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1110]);
    }
    return this_.call(_method_fn, {key_or_address});
}
Variant RedisCluster::waitaof(const Variant &key_or_address,
                              const Variant &numlocal,
                              const Variant &numreplicas,
                              const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1111]);
    }
    return this_.call(_method_fn, {key_or_address, numlocal, numreplicas, timeout});
}
Variant RedisCluster::bgsave(const Variant &key_or_address) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1358]);
    }
    return this_.call(_method_fn, {key_or_address});
}
Variant RedisCluster::bitcount(const Variant &key, const Variant &start, const Variant &end, const Variant &bybit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1112]);
    }
    return this_.call(_method_fn, {key, start, end, bybit});
}
Variant RedisCluster::bitpos(
    const Variant &key, const Variant &bit, const Variant &start, const Variant &end, const Variant &bybit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1114]);
    }
    return this_.call(_method_fn, {key, bit, start, end, bybit});
}
Variant RedisCluster::brpoplpush(const Variant &srckey, const Variant &deskey, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1117]);
    }
    return this_.call(_method_fn, {srckey, deskey, timeout});
}
Variant RedisCluster::lmove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1366]);
    }
    return this_.call(_method_fn, {src, dst, wherefrom, whereto});
}
Variant RedisCluster::blmove(
    const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1210]);
    }
    return this_.call(_method_fn, {src, dst, wherefrom, whereto, timeout});
}
Variant RedisCluster::bzmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1120]);
    }
    return this_.call(_method_fn, {timeout, keys, from, count});
}
Variant RedisCluster::zmpop(const Variant &keys, const Variant &from, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1121]);
    }
    return this_.call(_method_fn, {keys, from, count});
}
Variant RedisCluster::blmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1122]);
    }
    return this_.call(_method_fn, {timeout, keys, from, count});
}
Variant RedisCluster::lmpop(const Variant &keys, const Variant &from, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1123]);
    }
    return this_.call(_method_fn, {keys, from, count});
}
Variant RedisCluster::clearlasterror() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1369]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisCluster::client(const Variant &key_or_address, const Variant &subcommand, const Variant &arg) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1125]);
    }
    return this_.call(_method_fn, {key_or_address, subcommand, arg});
}
Variant RedisCluster::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1126]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisCluster::dbsize(const Variant &key_or_address) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1371]);
    }
    return this_.call(_method_fn, {key_or_address});
}
Variant RedisCluster::copy(const Variant &src, const Variant &dst, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[917]);
    }
    return this_.call(_method_fn, {src, dst, options});
}
Variant RedisCluster::decr(const Variant &key, const Variant &by) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1131]);
    }
    return this_.call(_method_fn, {key, by});
}
Variant RedisCluster::decrby(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1372]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::decrbyfloat(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1373]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::discard() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1134]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisCluster::dump(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1135]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::echo(const Variant &key_or_address, const Variant &msg) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1136]);
    }
    return this_.call(_method_fn, {key_or_address, msg});
}
Variant RedisCluster::eval(const Variant &script, const Variant &args, const Variant &num_keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1137]);
    }
    return this_.call(_method_fn, {script, args, num_keys});
}
Variant RedisCluster::eval_ro(const Variant &script, const Variant &args, const Variant &num_keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1138]);
    }
    return this_.call(_method_fn, {script, args, num_keys});
}
Variant RedisCluster::evalsha(const Variant &script_sha, const Variant &args, const Variant &num_keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1139]);
    }
    return this_.call(_method_fn, {script_sha, args, num_keys});
}
Variant RedisCluster::evalsha_ro(const Variant &script_sha, const Variant &args, const Variant &num_keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1140]);
    }
    return this_.call(_method_fn, {script_sha, args, num_keys});
}
Variant RedisCluster::exec() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[866]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisCluster::expire(const Variant &key, const Variant &timeout, const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1142]);
    }
    return this_.call(_method_fn, {key, timeout, mode});
}
Variant RedisCluster::expireat(const Variant &key, const Variant &timestamp, const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1374]);
    }
    return this_.call(_method_fn, {key, timestamp, mode});
}
Variant RedisCluster::expiretime(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1145]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::pexpiretime(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1146]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::flushall(const Variant &key_or_address, const Variant &async) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1359]);
    }
    return this_.call(_method_fn, {key_or_address, async});
}
Variant RedisCluster::flushdb(const Variant &key_or_address, const Variant &async) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1360]);
    }
    return this_.call(_method_fn, {key_or_address, async});
}
Variant RedisCluster::geodist(const Variant &key, const Variant &src, const Variant &dest, const Variant &unit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1153]);
    }
    return this_.call(_method_fn, {key, src, dest, unit});
}
Variant RedisCluster::georadius(const Variant &key,
                                const Variant &lng,
                                const Variant &lat,
                                const Variant &radius,
                                const Variant &unit,
                                const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1156]);
    }
    return this_.call(_method_fn, {key, lng, lat, radius, unit, options});
}
Variant RedisCluster::georadius_ro(const Variant &key,
                                   const Variant &lng,
                                   const Variant &lat,
                                   const Variant &radius,
                                   const Variant &unit,
                                   const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1157]);
    }
    return this_.call(_method_fn, {key, lng, lat, radius, unit, options});
}
Variant RedisCluster::georadiusbymember(
    const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1158]);
    }
    return this_.call(_method_fn, {key, member, radius, unit, options});
}
Variant RedisCluster::georadiusbymember_ro(
    const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1159]);
    }
    return this_.call(_method_fn, {key, member, radius, unit, options});
}
Variant RedisCluster::geosearch(
    const Variant &key, const Variant &position, const Variant &shape, const Variant &unit, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1160]);
    }
    return this_.call(_method_fn, {key, position, shape, unit, options});
}
Variant RedisCluster::geosearchstore(const Variant &dst,
                                     const Variant &src,
                                     const Variant &position,
                                     const Variant &shape,
                                     const Variant &unit,
                                     const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1161]);
    }
    return this_.call(_method_fn, {dst, src, position, shape, unit, options});
}
Variant RedisCluster::get(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[134]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::getdel(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1375]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::getWithMeta(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1162]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::getex(const Variant &key, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1376]);
    }
    return this_.call(_method_fn, {key, options});
}
Variant RedisCluster::getbit(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1377]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::getlasterror() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1378]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisCluster::getmode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1379]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisCluster::getoption(const Variant &option) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1380]);
    }
    return this_.call(_method_fn, {option});
}
Variant RedisCluster::getrange(const Variant &key, const Variant &start, const Variant &end) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1381]);
    }
    return this_.call(_method_fn, {key, start, end});
}
Variant RedisCluster::lcs(const Variant &key1, const Variant &key2, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1177]);
    }
    return this_.call(_method_fn, {key1, key2, options});
}
Variant RedisCluster::getset(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1179]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::gettransferredbytes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1382]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisCluster::cleartransferredbytes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1383]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisCluster::hexists(const Variant &key, const Variant &member) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1385]);
    }
    return this_.call(_method_fn, {key, member});
}
Variant RedisCluster::hget(const Variant &key, const Variant &member) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1386]);
    }
    return this_.call(_method_fn, {key, member});
}
Variant RedisCluster::hgetall(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1387]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::hincrby(const Variant &key, const Variant &member, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1388]);
    }
    return this_.call(_method_fn, {key, member, value});
}
Variant RedisCluster::hincrbyfloat(const Variant &key, const Variant &member, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1389]);
    }
    return this_.call(_method_fn, {key, member, value});
}
Variant RedisCluster::hkeys(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1390]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::hlen(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1391]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::hmget(const Variant &key, const Variant &keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1392]);
    }
    return this_.call(_method_fn, {key, keys});
}
Variant RedisCluster::hmset(const Variant &key, const Variant &key_values) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1393]);
    }
    return this_.call(_method_fn, {key, key_values});
}
Variant RedisCluster::hscan(const Variant &key,
                            const Reference &iterator,
                            const Variant &pattern,
                            const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1198]);
    }
    return this_.call(_method_fn, {key, &iterator, pattern, count});
}
Variant RedisCluster::expiremember(const Variant &key, const Variant &field, const Variant &ttl, const Variant &unit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1199]);
    }
    return this_.call(_method_fn, {key, field, ttl, unit});
}
Variant RedisCluster::expirememberat(const Variant &key, const Variant &field, const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1200]);
    }
    return this_.call(_method_fn, {key, field, timestamp});
}
Variant RedisCluster::hrandfield(const Variant &key, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1394]);
    }
    return this_.call(_method_fn, {key, options});
}
Variant RedisCluster::hset(const Variant &key, const Variant &member, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1395]);
    }
    return this_.call(_method_fn, {key, member, value});
}
Variant RedisCluster::hsetnx(const Variant &key, const Variant &member, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1396]);
    }
    return this_.call(_method_fn, {key, member, value});
}
Variant RedisCluster::hstrlen(const Variant &key, const Variant &field) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1397]);
    }
    return this_.call(_method_fn, {key, field});
}
Variant RedisCluster::hvals(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1398]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::incr(const Variant &key, const Variant &by) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1201]);
    }
    return this_.call(_method_fn, {key, by});
}
Variant RedisCluster::incrby(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1399]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::incrbyfloat(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1400]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::keys(const Variant &pattern) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1206]);
    }
    return this_.call(_method_fn, {pattern});
}
Variant RedisCluster::lastsave(const Variant &key_or_address) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1401]);
    }
    return this_.call(_method_fn, {key_or_address});
}
Variant RedisCluster::lget(const Variant &key, const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1402]);
    }
    return this_.call(_method_fn, {key, index});
}
Variant RedisCluster::lindex(const Variant &key, const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1219]);
    }
    return this_.call(_method_fn, {key, index});
}
Variant RedisCluster::linsert(const Variant &key, const Variant &pos, const Variant &pivot, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1403]);
    }
    return this_.call(_method_fn, {key, pos, pivot, value});
}
Variant RedisCluster::llen(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1404]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::lpop(const Variant &key, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1405]);
    }
    return this_.call(_method_fn, {key, count});
}
Variant RedisCluster::lpos(const Variant &key, const Variant &value, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1406]);
    }
    return this_.call(_method_fn, {key, value, options});
}
Variant RedisCluster::lpushx(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1408]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::lrange(const Variant &key, const Variant &start, const Variant &end) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1220]);
    }
    return this_.call(_method_fn, {key, start, end});
}
Variant RedisCluster::lrem(const Variant &key, const Variant &value, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1221]);
    }
    return this_.call(_method_fn, {key, value, count});
}
Variant RedisCluster::lset(const Variant &key, const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1409]);
    }
    return this_.call(_method_fn, {key, index, value});
}
Variant RedisCluster::ltrim(const Variant &key, const Variant &start, const Variant &end) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1222]);
    }
    return this_.call(_method_fn, {key, start, end});
}
Variant RedisCluster::mget(const Variant &keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1223]);
    }
    return this_.call(_method_fn, {keys});
}
Variant RedisCluster::mset(const Variant &key_values) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1226]);
    }
    return this_.call(_method_fn, {key_values});
}
Variant RedisCluster::msetnx(const Variant &key_values) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1227]);
    }
    return this_.call(_method_fn, {key_values});
}
Variant RedisCluster::multi(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1228]);
    }
    return this_.call(_method_fn, {value});
}
Variant RedisCluster::object(const Variant &subcommand, const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1229]);
    }
    return this_.call(_method_fn, {subcommand, key});
}
Variant RedisCluster::persist(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1232]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::pexpire(const Variant &key, const Variant &timeout, const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1233]);
    }
    return this_.call(_method_fn, {key, timeout, mode});
}
Variant RedisCluster::pexpireat(const Variant &key, const Variant &timestamp, const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1410]);
    }
    return this_.call(_method_fn, {key, timestamp, mode});
}
Variant RedisCluster::pfadd(const Variant &key, const Variant &elements) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1235]);
    }
    return this_.call(_method_fn, {key, elements});
}
Variant RedisCluster::pfcount(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1236]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::pfmerge(const Variant &key, const Variant &keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1237]);
    }
    return this_.call(_method_fn, {key, keys});
}
Variant RedisCluster::ping(const Variant &key_or_address, const Variant &message) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1238]);
    }
    return this_.call(_method_fn, {key_or_address, message});
}
Variant RedisCluster::psetex(const Variant &key, const Variant &timeout, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1241]);
    }
    return this_.call(_method_fn, {key, timeout, value});
}
Variant RedisCluster::psubscribe(const Variant &patterns, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1242]);
    }
    return this_.call(_method_fn, {patterns, callback});
}
Variant RedisCluster::pttl(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1243]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::publish(const Variant &channel, const Variant &message) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1244]);
    }
    return this_.call(_method_fn, {channel, message});
}
Variant RedisCluster::randomkey(const Variant &key_or_address) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1411]);
    }
    return this_.call(_method_fn, {key_or_address});
}
Variant RedisCluster::rename(const Variant &key_src, const Variant &key_dst) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[457]);
    }
    return this_.call(_method_fn, {key_src, key_dst});
}
Variant RedisCluster::renamenx(const Variant &key, const Variant &newkey) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1412]);
    }
    return this_.call(_method_fn, {key, newkey});
}
Variant RedisCluster::restore(const Variant &key,
                              const Variant &timeout,
                              const Variant &value,
                              const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1252]);
    }
    return this_.call(_method_fn, {key, timeout, value, options});
}
Variant RedisCluster::role(const Variant &key_or_address) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1253]);
    }
    return this_.call(_method_fn, {key_or_address});
}
Variant RedisCluster::rpop(const Variant &key, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1413]);
    }
    return this_.call(_method_fn, {key, count});
}
Variant RedisCluster::rpoplpush(const Variant &src, const Variant &dst) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1254]);
    }
    return this_.call(_method_fn, {src, dst});
}
Variant RedisCluster::rpushx(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1415]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::saddarray(const Variant &key, const Variant &values) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1417]);
    }
    return this_.call(_method_fn, {key, values});
}
Variant RedisCluster::save(const Variant &key_or_address) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[399]);
    }
    return this_.call(_method_fn, {key_or_address});
}
Variant RedisCluster::scan(const Reference &iterator,
                           const Variant &key_or_address,
                           const Variant &pattern,
                           const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1269]);
    }
    return this_.call(_method_fn, {&iterator, key_or_address, pattern, count});
}
Variant RedisCluster::scard(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1270]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::set(const Variant &key, const Variant &value, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1273]);
    }
    return this_.call(_method_fn, {key, value, options});
}
Variant RedisCluster::_setbit(const Variant &key, const Variant &offset, const Variant &onoff) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1420]);
    }
    return this_.call(_method_fn, {key, offset, onoff});
}
Variant RedisCluster::setex(const Variant &key, const Variant &expire, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1277]);
    }
    return this_.call(_method_fn, {key, expire, value});
}
Variant RedisCluster::setnx(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1278]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::setoption(const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1421]);
    }
    return this_.call(_method_fn, {option, value});
}
Variant RedisCluster::setrange(const Variant &key, const Variant &offset, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1422]);
    }
    return this_.call(_method_fn, {key, offset, value});
}
Variant RedisCluster::sintercard(const Variant &keys, const Variant &limit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1260]);
    }
    return this_.call(_method_fn, {keys, limit});
}
Variant RedisCluster::sismember(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1279]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::smembers(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1426]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::smove(const Variant &src, const Variant &dst, const Variant &member) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1427]);
    }
    return this_.call(_method_fn, {src, dst, member});
}
Variant RedisCluster::sort(const Variant &key, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1284]);
    }
    return this_.call(_method_fn, {key, options});
}
Variant RedisCluster::sort_ro(const Variant &key, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1285]);
    }
    return this_.call(_method_fn, {key, options});
}
Variant RedisCluster::spop(const Variant &key, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1428]);
    }
    return this_.call(_method_fn, {key, count});
}
Variant RedisCluster::srandmember(const Variant &key, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1429]);
    }
    return this_.call(_method_fn, {key, count});
}
Variant RedisCluster::sscan(const Variant &key,
                            const Reference &iterator,
                            const Variant &pattern,
                            const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1291]);
    }
    return this_.call(_method_fn, {key, &iterator, pattern, count});
}
Variant RedisCluster::strlen(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1293]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::subscribe(const Variant &channels, const Variant &cb) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1294]);
    }
    return this_.call(_method_fn, {channels, cb});
}
Variant RedisCluster::time(const Variant &key_or_address) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[226]);
    }
    return this_.call(_method_fn, {key_or_address});
}
Variant RedisCluster::ttl(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1297]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::type(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1298]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::unsubscribe(const Variant &channels) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1300]);
    }
    return this_.call(_method_fn, {channels});
}
Variant RedisCluster::unwatch() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1301]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisCluster::xack(const Variant &key, const Variant &group, const Variant &ids) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1304]);
    }
    return this_.call(_method_fn, {key, group, ids});
}
Variant RedisCluster::xadd(
    const Variant &key, const Variant &id, const Variant &values, const Variant &maxlen, const Variant &approx) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1305]);
    }
    return this_.call(_method_fn, {key, id, values, maxlen, approx});
}
Variant RedisCluster::xclaim(const Variant &key,
                             const Variant &group,
                             const Variant &consumer,
                             const Variant &min_iddle,
                             const Variant &ids,
                             const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1307]);
    }
    return this_.call(_method_fn, {key, group, consumer, min_iddle, ids, options});
}
Variant RedisCluster::xdel(const Variant &key, const Variant &ids) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1308]);
    }
    return this_.call(_method_fn, {key, ids});
}
Variant RedisCluster::xgroup(const Variant &operation,
                             const Variant &key,
                             const Variant &group,
                             const Variant &id_or_consumer,
                             const Variant &mkstream,
                             const Variant &entries_read) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1309]);
    }
    return this_.call(_method_fn, {operation, key, group, id_or_consumer, mkstream, entries_read});
}
Variant RedisCluster::xautoclaim(const Variant &key,
                                 const Variant &group,
                                 const Variant &consumer,
                                 const Variant &min_idle,
                                 const Variant &start,
                                 const Variant &count,
                                 const Variant &justid) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1306]);
    }
    return this_.call(_method_fn, {key, group, consumer, min_idle, start, count, justid});
}
Variant RedisCluster::xinfo(const Variant &operation, const Variant &arg1, const Variant &arg2, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1310]);
    }
    return this_.call(_method_fn, {operation, arg1, arg2, count});
}
Variant RedisCluster::xlen(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1311]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::xpending(const Variant &key,
                               const Variant &group,
                               const Variant &start,
                               const Variant &end,
                               const Variant &count,
                               const Variant &consumer) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1312]);
    }
    return this_.call(_method_fn, {key, group, start, end, count, consumer});
}
Variant RedisCluster::xrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1313]);
    }
    return this_.call(_method_fn, {key, start, end, count});
}
Variant RedisCluster::xread(const Variant &streams, const Variant &count, const Variant &block) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1314]);
    }
    return this_.call(_method_fn, {streams, count, block});
}
Variant RedisCluster::xreadgroup(
    const Variant &group, const Variant &consumer, const Variant &streams, const Variant &count, const Variant &block) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1315]);
    }
    return this_.call(_method_fn, {group, consumer, streams, count, block});
}
Variant RedisCluster::xrevrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1316]);
    }
    return this_.call(_method_fn, {key, start, end, count});
}
Variant RedisCluster::xtrim(
    const Variant &key, const Variant &maxlen, const Variant &approx, const Variant &minid, const Variant &limit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1317]);
    }
    return this_.call(_method_fn, {key, maxlen, approx, minid, limit});
}
Variant RedisCluster::zcard(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1433]);
    }
    return this_.call(_method_fn, {key});
}
Variant RedisCluster::zcount(const Variant &key, const Variant &start, const Variant &end) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1434]);
    }
    return this_.call(_method_fn, {key, start, end});
}
Variant RedisCluster::zincrby(const Variant &key, const Variant &value, const Variant &member) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1435]);
    }
    return this_.call(_method_fn, {key, value, member});
}
Variant RedisCluster::zinterstore(const Variant &dst,
                                  const Variant &keys,
                                  const Variant &weights,
                                  const Variant &aggregate) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1345]);
    }
    return this_.call(_method_fn, {dst, keys, weights, aggregate});
}
Variant RedisCluster::zintercard(const Variant &keys, const Variant &limit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1344]);
    }
    return this_.call(_method_fn, {keys, limit});
}
Variant RedisCluster::zlexcount(const Variant &key, const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1436]);
    }
    return this_.call(_method_fn, {key, min, max});
}
Variant RedisCluster::zpopmax(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::zpopmin(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1438]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RedisCluster::zrange(const Variant &key, const Variant &start, const Variant &end, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1439]);
    }
    return this_.call(_method_fn, {key, start, end, options});
}
Variant RedisCluster::zrangestore(
    const Variant &dstkey, const Variant &srckey, const Variant &start, const Variant &end, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1329]);
    }
    return this_.call(_method_fn, {dstkey, srckey, start, end, options});
}
Variant RedisCluster::zrandmember(const Variant &key, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1440]);
    }
    return this_.call(_method_fn, {key, options});
}
Variant RedisCluster::zrangebylex(
    const Variant &key, const Variant &min, const Variant &max, const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1441]);
    }
    return this_.call(_method_fn, {key, min, max, offset, count});
}
Variant RedisCluster::zrangebyscore(const Variant &key,
                                    const Variant &start,
                                    const Variant &end,
                                    const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1442]);
    }
    return this_.call(_method_fn, {key, start, end, options});
}
Variant RedisCluster::zrank(const Variant &key, const Variant &member) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1443]);
    }
    return this_.call(_method_fn, {key, member});
}
Variant RedisCluster::zremrangebylex(const Variant &key, const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1445]);
    }
    return this_.call(_method_fn, {key, min, max});
}
Variant RedisCluster::zremrangebyrank(const Variant &key, const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1446]);
    }
    return this_.call(_method_fn, {key, min, max});
}
Variant RedisCluster::zremrangebyscore(const Variant &key, const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1447]);
    }
    return this_.call(_method_fn, {key, min, max});
}
Variant RedisCluster::zrevrange(const Variant &key, const Variant &min, const Variant &max, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1448]);
    }
    return this_.call(_method_fn, {key, min, max, options});
}
Variant RedisCluster::zrevrangebylex(const Variant &key,
                                     const Variant &min,
                                     const Variant &max,
                                     const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1449]);
    }
    return this_.call(_method_fn, {key, min, max, options});
}
Variant RedisCluster::zrevrangebyscore(const Variant &key,
                                       const Variant &min,
                                       const Variant &max,
                                       const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1450]);
    }
    return this_.call(_method_fn, {key, min, max, options});
}
Variant RedisCluster::zrevrank(const Variant &key, const Variant &member) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1451]);
    }
    return this_.call(_method_fn, {key, member});
}
Variant RedisCluster::zscan(const Variant &key,
                            const Reference &iterator,
                            const Variant &pattern,
                            const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1346]);
    }
    return this_.call(_method_fn, {key, &iterator, pattern, count});
}
Variant RedisCluster::zscore(const Variant &key, const Variant &member) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1452]);
    }
    return this_.call(_method_fn, {key, member});
}
Variant RedisCluster::zunionstore(const Variant &dst,
                                  const Variant &keys,
                                  const Variant &weights,
                                  const Variant &aggregate) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1348]);
    }
    return this_.call(_method_fn, {dst, keys, weights, aggregate});
}
Variant RedisCluster::zinter(const Variant &keys, const Variant &weights, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1343]);
    }
    return this_.call(_method_fn, {keys, weights, options});
}
Variant RedisCluster::zdiffstore(const Variant &dst, const Variant &keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1342]);
    }
    return this_.call(_method_fn, {dst, keys});
}
Variant RedisCluster::zunion(const Variant &keys, const Variant &weights, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1347]);
    }
    return this_.call(_method_fn, {keys, weights, options});
}
Variant RedisCluster::zdiff(const Variant &keys, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1341]);
    }
    return this_.call(_method_fn, {keys, options});
}
RedisClusterException::RedisClusterException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1454], {message, code, previous});
}
Variant RedisClusterException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisClusterException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisClusterException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisClusterException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisClusterException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisClusterException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisClusterException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisClusterException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisClusterException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
RedisSentinel::RedisSentinel(const Variant &options) {
    this_ = newObject(LITERAL_STRING[1455], {options});
}
Variant RedisSentinel::ckquorum(const Variant &master) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1456]);
    }
    return this_.call(_method_fn, {master});
}
Variant RedisSentinel::failover(const Variant &master) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1144]);
    }
    return this_.call(_method_fn, {master});
}
Variant RedisSentinel::flushconfig() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1457]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisSentinel::getMasterAddrByName(const Variant &master) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1458]);
    }
    return this_.call(_method_fn, {master});
}
Variant RedisSentinel::master(const Variant &master) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1459]);
    }
    return this_.call(_method_fn, {master});
}
Variant RedisSentinel::masters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1460]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisSentinel::myid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1461]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisSentinel::ping() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1238]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisSentinel::reset(const Variant &pattern) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1251]);
    }
    return this_.call(_method_fn, {pattern});
}
Variant RedisSentinel::sentinels(const Variant &master) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1462]);
    }
    return this_.call(_method_fn, {master});
}
Variant RedisSentinel::slaves(const Variant &master) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1463]);
    }
    return this_.call(_method_fn, {master});
}
RedisException::RedisException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1464], {message, code, previous});
}
Variant RedisException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant RedisException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php
