#include "phpx.h"
#include "class/redis.h"

namespace php {
Redis::Redis(const Variant &options) {
    _this = newObject("Redis", options);
}

Variant Redis::_compress(const Variant &value) {
    return _this.exec("_compress", value);
}

Variant Redis::_uncompress(const Variant &value) {
    return _this.exec("_uncompress", value);
}

Variant Redis::_prefix(const Variant &key) {
    return _this.exec("_prefix", key);
}

Variant Redis::_serialize(const Variant &value) {
    return _this.exec("_serialize", value);
}

Variant Redis::_unserialize(const Variant &value) {
    return _this.exec("_unserialize", value);
}

Variant Redis::_pack(const Variant &value) {
    return _this.exec("_pack", value);
}

Variant Redis::_unpack(const Variant &value) {
    return _this.exec("_unpack", value);
}

Variant Redis::acl(const Variant &subcmd, const Variant &args) {
    return _this.exec("acl", subcmd, args);
}

Variant Redis::append(const Variant &key, const Variant &value) {
    return _this.exec("append", key, value);
}

Variant Redis::auth(const Variant &credentials) {
    return _this.exec("auth", credentials);
}

Variant Redis::bgSave() {
    return _this.exec("bgSave");
}

Variant Redis::bgrewriteaof() {
    return _this.exec("bgrewriteaof");
}

Variant Redis::bitcount(const Variant &key, const Variant &start, const Variant &end, const Variant &bybit) {
    return _this.exec("bitcount", key, start, end, bybit);
}

Variant Redis::bitop(const Variant &operation, const Variant &deskey, const Variant &srckey, const Variant &other_keys) {
    return _this.exec("bitop", operation, deskey, srckey, other_keys);
}

Variant Redis::bitpos(const Variant &key, const Variant &bit, const Variant &start, const Variant &end, const Variant &bybit) {
    return _this.exec("bitpos", key, bit, start, end, bybit);
}

Variant Redis::blPop(const Variant &key_or_keys, const Variant &timeout_or_key, const Variant &extra_args) {
    return _this.exec("blPop", key_or_keys, timeout_or_key, extra_args);
}

Variant Redis::brPop(const Variant &key_or_keys, const Variant &timeout_or_key, const Variant &extra_args) {
    return _this.exec("brPop", key_or_keys, timeout_or_key, extra_args);
}

Variant Redis::brpoplpush(const Variant &src, const Variant &dst, const Variant &timeout) {
    return _this.exec("brpoplpush", src, dst, timeout);
}

Variant Redis::bzPopMax(const Variant &key, const Variant &timeout_or_key, const Variant &extra_args) {
    return _this.exec("bzPopMax", key, timeout_or_key, extra_args);
}

Variant Redis::bzPopMin(const Variant &key, const Variant &timeout_or_key, const Variant &extra_args) {
    return _this.exec("bzPopMin", key, timeout_or_key, extra_args);
}

Variant Redis::bzmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    return _this.exec("bzmpop", timeout, keys, from, count);
}

Variant Redis::zmpop(const Variant &keys, const Variant &from, const Variant &count) {
    return _this.exec("zmpop", keys, from, count);
}

Variant Redis::blmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    return _this.exec("blmpop", timeout, keys, from, count);
}

Variant Redis::lmpop(const Variant &keys, const Variant &from, const Variant &count) {
    return _this.exec("lmpop", keys, from, count);
}

Variant Redis::clearLastError() {
    return _this.exec("clearLastError");
}

Variant Redis::client(const Variant &opt, const Variant &args) {
    return _this.exec("client", opt, args);
}

Variant Redis::close() {
    return _this.exec("close");
}

Variant Redis::command(const Variant &opt, const Variant &args) {
    return _this.exec("command", opt, args);
}

Variant Redis::config(const Variant &operation, const Variant &key_or_settings, const Variant &value) {
    return _this.exec("config", operation, key_or_settings, value);
}

Variant Redis::connect(const Variant &host, const Variant &port, const Variant &timeout, const Variant &persistent_id, const Variant &retry_interval, const Variant &read_timeout, const Variant &context) {
    return _this.exec("connect", host, port, timeout, persistent_id, retry_interval, read_timeout, context);
}

Variant Redis::copy(const Variant &src, const Variant &dst, const Variant &options) {
    return _this.exec("copy", src, dst, options);
}

Variant Redis::dbSize() {
    return _this.exec("dbSize");
}

Variant Redis::debug(const Variant &key) {
    return _this.exec("debug", key);
}

Variant Redis::decr(const Variant &key, const Variant &by) {
    return _this.exec("decr", key, by);
}

Variant Redis::decrBy(const Variant &key, const Variant &value) {
    return _this.exec("decrBy", key, value);
}

Variant Redis::del(const Variant &key, const Variant &other_keys) {
    return _this.exec("del", key, other_keys);
}

Variant Redis::_delete(const Variant &key, const Variant &other_keys) {
    return _this.exec("delete", key, other_keys);
}

Variant Redis::discard() {
    return _this.exec("discard");
}

Variant Redis::dump(const Variant &key) {
    return _this.exec("dump", key);
}

Variant Redis::echo(const Variant &str) {
    return _this.exec("echo", str);
}

Variant Redis::eval(const Variant &script, const Array &args, const Variant &num_keys) {
    return _this.exec("eval", script, args, num_keys);
}

Variant Redis::eval_ro(const Variant &script_sha, const Array &args, const Variant &num_keys) {
    return _this.exec("eval_ro", script_sha, args, num_keys);
}

Variant Redis::evalsha(const Variant &sha1, const Array &args, const Variant &num_keys) {
    return _this.exec("evalsha", sha1, args, num_keys);
}

Variant Redis::evalsha_ro(const Variant &sha1, const Array &args, const Variant &num_keys) {
    return _this.exec("evalsha_ro", sha1, args, num_keys);
}

Variant Redis::exec() {
    return _this.exec("exec");
}

Variant Redis::exists(const Variant &key, const Variant &other_keys) {
    return _this.exec("exists", key, other_keys);
}

Variant Redis::expire(const Variant &key, const Variant &timeout, const Variant &mode) {
    return _this.exec("expire", key, timeout, mode);
}

Variant Redis::expireAt(const Variant &key, const Variant &timestamp, const Variant &mode) {
    return _this.exec("expireAt", key, timestamp, mode);
}

Variant Redis::failover(const Variant &to, const Variant &abort, const Variant &timeout) {
    return _this.exec("failover", to, abort, timeout);
}

Variant Redis::expiretime(const Variant &key) {
    return _this.exec("expiretime", key);
}

Variant Redis::pexpiretime(const Variant &key) {
    return _this.exec("pexpiretime", key);
}

Variant Redis::fcall(const Variant &fn, const Array &keys, const Array &args) {
    return _this.exec("fcall", fn, keys, args);
}

Variant Redis::fcall_ro(const Variant &fn, const Array &keys, const Array &args) {
    return _this.exec("fcall_ro", fn, keys, args);
}

Variant Redis::flushAll(const Variant &sync) {
    return _this.exec("flushAll", sync);
}

Variant Redis::flushDB(const Variant &sync) {
    return _this.exec("flushDB", sync);
}

Variant Redis::function(const Variant &operation, const Variant &args) {
    return _this.exec("function", operation, args);
}

Variant Redis::geoadd(const Variant &key, const Variant &lng, const Variant &lat, const Variant &member, const Variant &other_triples_and_options) {
    return _this.exec("geoadd", key, lng, lat, member, other_triples_and_options);
}

Variant Redis::geodist(const Variant &key, const Variant &src, const Variant &dst, const Variant &unit) {
    return _this.exec("geodist", key, src, dst, unit);
}

Variant Redis::geohash(const Variant &key, const Variant &member, const Variant &other_members) {
    return _this.exec("geohash", key, member, other_members);
}

Variant Redis::geopos(const Variant &key, const Variant &member, const Variant &other_members) {
    return _this.exec("geopos", key, member, other_members);
}

Variant Redis::georadius(const Variant &key, const Variant &lng, const Variant &lat, const Variant &radius, const Variant &unit, const Array &options) {
    return _this.exec("georadius", key, lng, lat, radius, unit, options);
}

Variant Redis::georadius_ro(const Variant &key, const Variant &lng, const Variant &lat, const Variant &radius, const Variant &unit, const Array &options) {
    return _this.exec("georadius_ro", key, lng, lat, radius, unit, options);
}

Variant Redis::georadiusbymember(const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Array &options) {
    return _this.exec("georadiusbymember", key, member, radius, unit, options);
}

Variant Redis::georadiusbymember_ro(const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Array &options) {
    return _this.exec("georadiusbymember_ro", key, member, radius, unit, options);
}

Variant Redis::geosearch(const Variant &key, const Variant &position, const Variant &shape, const Variant &unit, const Array &options) {
    return _this.exec("geosearch", key, position, shape, unit, options);
}

Variant Redis::geosearchstore(const Variant &dst, const Variant &src, const Variant &position, const Variant &shape, const Variant &unit, const Array &options) {
    return _this.exec("geosearchstore", dst, src, position, shape, unit, options);
}

Variant Redis::get(const Variant &key) {
    return _this.exec("get", key);
}

Variant Redis::getAuth() {
    return _this.exec("getAuth");
}

Variant Redis::getBit(const Variant &key, const Variant &idx) {
    return _this.exec("getBit", key, idx);
}

Variant Redis::getEx(const Variant &key, const Array &options) {
    return _this.exec("getEx", key, options);
}

Variant Redis::getDBNum() {
    return _this.exec("getDBNum");
}

Variant Redis::getDel(const Variant &key) {
    return _this.exec("getDel", key);
}

Variant Redis::getHost() {
    return _this.exec("getHost");
}

Variant Redis::getLastError() {
    return _this.exec("getLastError");
}

Variant Redis::getMode() {
    return _this.exec("getMode");
}

Variant Redis::getOption(const Variant &option) {
    return _this.exec("getOption", option);
}

Variant Redis::getPersistentID() {
    return _this.exec("getPersistentID");
}

Variant Redis::getPort() {
    return _this.exec("getPort");
}

Variant Redis::getRange(const Variant &key, const Variant &start, const Variant &end) {
    return _this.exec("getRange", key, start, end);
}

Variant Redis::lcs(const Variant &key1, const Variant &key2, const Variant &options) {
    return _this.exec("lcs", key1, key2, options);
}

Variant Redis::getReadTimeout() {
    return _this.exec("getReadTimeout");
}

Variant Redis::getset(const Variant &key, const Variant &value) {
    return _this.exec("getset", key, value);
}

Variant Redis::getTimeout() {
    return _this.exec("getTimeout");
}

Variant Redis::getTransferredBytes() {
    return _this.exec("getTransferredBytes");
}

Variant Redis::clearTransferredBytes() {
    return _this.exec("clearTransferredBytes");
}

Variant Redis::hDel(const Variant &key, const Variant &field, const Variant &other_fields) {
    return _this.exec("hDel", key, field, other_fields);
}

Variant Redis::hExists(const Variant &key, const Variant &field) {
    return _this.exec("hExists", key, field);
}

Variant Redis::hGet(const Variant &key, const Variant &member) {
    return _this.exec("hGet", key, member);
}

Variant Redis::hGetAll(const Variant &key) {
    return _this.exec("hGetAll", key);
}

Variant Redis::hIncrBy(const Variant &key, const Variant &field, const Variant &value) {
    return _this.exec("hIncrBy", key, field, value);
}

Variant Redis::hIncrByFloat(const Variant &key, const Variant &field, const Variant &value) {
    return _this.exec("hIncrByFloat", key, field, value);
}

Variant Redis::hKeys(const Variant &key) {
    return _this.exec("hKeys", key);
}

Variant Redis::hLen(const Variant &key) {
    return _this.exec("hLen", key);
}

Variant Redis::hMget(const Variant &key, const Variant &fields) {
    return _this.exec("hMget", key, fields);
}

Variant Redis::hMset(const Variant &key, const Variant &fieldvals) {
    return _this.exec("hMset", key, fieldvals);
}

Variant Redis::hRandField(const Variant &key, const Variant &options) {
    return _this.exec("hRandField", key, options);
}

Variant Redis::hSet(const Variant &key, const Variant &member, const Variant &value) {
    return _this.exec("hSet", key, member, value);
}

Variant Redis::hSetNx(const Variant &key, const Variant &field, const Variant &value) {
    return _this.exec("hSetNx", key, field, value);
}

Variant Redis::hStrLen(const Variant &key, const Variant &field) {
    return _this.exec("hStrLen", key, field);
}

Variant Redis::hVals(const Variant &key) {
    return _this.exec("hVals", key);
}

Variant Redis::hscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return _this.exec("hscan", key, iterator, pattern, count);
}

Variant Redis::incr(const Variant &key, const Variant &by) {
    return _this.exec("incr", key, by);
}

Variant Redis::incrBy(const Variant &key, const Variant &value) {
    return _this.exec("incrBy", key, value);
}

Variant Redis::incrByFloat(const Variant &key, const Variant &value) {
    return _this.exec("incrByFloat", key, value);
}

Variant Redis::info(const Variant &sections) {
    return _this.exec("info", sections);
}

Variant Redis::isConnected() {
    return _this.exec("isConnected");
}

Variant Redis::keys(const Variant &pattern) {
    return _this.exec("keys", pattern);
}

Variant Redis::lInsert(const Variant &key, const Variant &pos, const Variant &pivot, const Variant &value) {
    return _this.exec("lInsert", key, pos, pivot, value);
}

Variant Redis::lLen(const Variant &key) {
    return _this.exec("lLen", key);
}

Variant Redis::lMove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto) {
    return _this.exec("lMove", src, dst, wherefrom, whereto);
}

Variant Redis::blmove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto, const Variant &timeout) {
    return _this.exec("blmove", src, dst, wherefrom, whereto, timeout);
}

Variant Redis::lPop(const Variant &key, const Variant &count) {
    return _this.exec("lPop", key, count);
}

Variant Redis::lPos(const Variant &key, const Variant &value, const Variant &options) {
    return _this.exec("lPos", key, value, options);
}

Variant Redis::lPush(const Variant &key, const Variant &elements) {
    return _this.exec("lPush", key, elements);
}

Variant Redis::rPush(const Variant &key, const Variant &elements) {
    return _this.exec("rPush", key, elements);
}

Variant Redis::lPushx(const Variant &key, const Variant &value) {
    return _this.exec("lPushx", key, value);
}

Variant Redis::rPushx(const Variant &key, const Variant &value) {
    return _this.exec("rPushx", key, value);
}

Variant Redis::lSet(const Variant &key, const Variant &index, const Variant &value) {
    return _this.exec("lSet", key, index, value);
}

Variant Redis::lastSave() {
    return _this.exec("lastSave");
}

Variant Redis::lindex(const Variant &key, const Variant &index) {
    return _this.exec("lindex", key, index);
}

Variant Redis::lrange(const Variant &key, const Variant &start, const Variant &end) {
    return _this.exec("lrange", key, start, end);
}

Variant Redis::lrem(const Variant &key, const Variant &value, const Variant &count) {
    return _this.exec("lrem", key, value, count);
}

Variant Redis::ltrim(const Variant &key, const Variant &start, const Variant &end) {
    return _this.exec("ltrim", key, start, end);
}

Variant Redis::mget(const Variant &keys) {
    return _this.exec("mget", keys);
}

Variant Redis::migrate(const Variant &host, const Variant &port, const Variant &key, const Variant &dstdb, const Variant &timeout, const Variant &copy, const Variant &replace, const Variant &credentials) {
    return _this.exec("migrate", host, port, key, dstdb, timeout, copy, replace, credentials);
}

Variant Redis::move(const Variant &key, const Variant &index) {
    return _this.exec("move", key, index);
}

Variant Redis::mset(const Variant &key_values) {
    return _this.exec("mset", key_values);
}

Variant Redis::msetnx(const Variant &key_values) {
    return _this.exec("msetnx", key_values);
}

Variant Redis::multi(const Variant &value) {
    return _this.exec("multi", value);
}

Variant Redis::object(const Variant &subcommand, const Variant &key) {
    return _this.exec("object", subcommand, key);
}

Variant Redis::open(const Variant &host, const Variant &port, const Variant &timeout, const Variant &persistent_id, const Variant &retry_interval, const Variant &read_timeout, const Variant &context) {
    return _this.exec("open", host, port, timeout, persistent_id, retry_interval, read_timeout, context);
}

Variant Redis::pconnect(const Variant &host, const Variant &port, const Variant &timeout, const Variant &persistent_id, const Variant &retry_interval, const Variant &read_timeout, const Variant &context) {
    return _this.exec("pconnect", host, port, timeout, persistent_id, retry_interval, read_timeout, context);
}

Variant Redis::persist(const Variant &key) {
    return _this.exec("persist", key);
}

Variant Redis::pexpire(const Variant &key, const Variant &timeout, const Variant &mode) {
    return _this.exec("pexpire", key, timeout, mode);
}

Variant Redis::pexpireAt(const Variant &key, const Variant &timestamp, const Variant &mode) {
    return _this.exec("pexpireAt", key, timestamp, mode);
}

Variant Redis::pfadd(const Variant &key, const Variant &elements) {
    return _this.exec("pfadd", key, elements);
}

Variant Redis::pfcount(const Variant &key_or_keys) {
    return _this.exec("pfcount", key_or_keys);
}

Variant Redis::pfmerge(const Variant &dst, const Variant &srckeys) {
    return _this.exec("pfmerge", dst, srckeys);
}

Variant Redis::ping(const Variant &message) {
    return _this.exec("ping", message);
}

Variant Redis::pipeline() {
    return _this.exec("pipeline");
}

Variant Redis::popen(const Variant &host, const Variant &port, const Variant &timeout, const Variant &persistent_id, const Variant &retry_interval, const Variant &read_timeout, const Variant &context) {
    return _this.exec("popen", host, port, timeout, persistent_id, retry_interval, read_timeout, context);
}

Variant Redis::psetex(const Variant &key, const Variant &expire, const Variant &value) {
    return _this.exec("psetex", key, expire, value);
}

Variant Redis::psubscribe(const Variant &patterns, const Variant &cb) {
    return _this.exec("psubscribe", patterns, cb);
}

Variant Redis::pttl(const Variant &key) {
    return _this.exec("pttl", key);
}

Variant Redis::publish(const Variant &channel, const Variant &message) {
    return _this.exec("publish", channel, message);
}

Variant Redis::pubsub(const Variant &command, const Variant &arg) {
    return _this.exec("pubsub", command, arg);
}

Variant Redis::punsubscribe(const Variant &patterns) {
    return _this.exec("punsubscribe", patterns);
}

Variant Redis::rPop(const Variant &key, const Variant &count) {
    return _this.exec("rPop", key, count);
}

Variant Redis::randomKey() {
    return _this.exec("randomKey");
}

Variant Redis::rawcommand(const Variant &command, const Variant &args) {
    return _this.exec("rawcommand", command, args);
}

Variant Redis::rename(const Variant &old_name, const Variant &new_name) {
    return _this.exec("rename", old_name, new_name);
}

Variant Redis::renameNx(const Variant &key_src, const Variant &key_dst) {
    return _this.exec("renameNx", key_src, key_dst);
}

Variant Redis::reset() {
    return _this.exec("reset");
}

Variant Redis::restore(const Variant &key, const Variant &ttl, const Variant &value, const Variant &options) {
    return _this.exec("restore", key, ttl, value, options);
}

Variant Redis::role() {
    return _this.exec("role");
}

Variant Redis::rpoplpush(const Variant &srckey, const Variant &dstkey) {
    return _this.exec("rpoplpush", srckey, dstkey);
}

Variant Redis::sAdd(const Variant &key, const Variant &value, const Variant &other_values) {
    return _this.exec("sAdd", key, value, other_values);
}

Variant Redis::sAddArray(const Variant &key, const Variant &values) {
    return _this.exec("sAddArray", key, values);
}

Variant Redis::sDiff(const Variant &key, const Variant &other_keys) {
    return _this.exec("sDiff", key, other_keys);
}

Variant Redis::sDiffStore(const Variant &dst, const Variant &key, const Variant &other_keys) {
    return _this.exec("sDiffStore", dst, key, other_keys);
}

Variant Redis::sInter(const Variant &key, const Variant &other_keys) {
    return _this.exec("sInter", key, other_keys);
}

Variant Redis::sintercard(const Variant &keys, const Variant &limit) {
    return _this.exec("sintercard", keys, limit);
}

Variant Redis::sInterStore(const Variant &key, const Variant &other_keys) {
    return _this.exec("sInterStore", key, other_keys);
}

Variant Redis::sMembers(const Variant &key) {
    return _this.exec("sMembers", key);
}

Variant Redis::sMisMember(const Variant &key, const Variant &member, const Variant &other_members) {
    return _this.exec("sMisMember", key, member, other_members);
}

Variant Redis::sMove(const Variant &src, const Variant &dst, const Variant &value) {
    return _this.exec("sMove", src, dst, value);
}

Variant Redis::sPop(const Variant &key, const Variant &count) {
    return _this.exec("sPop", key, count);
}

Variant Redis::sRandMember(const Variant &key, const Variant &count) {
    return _this.exec("sRandMember", key, count);
}

Variant Redis::sUnion(const Variant &key, const Variant &other_keys) {
    return _this.exec("sUnion", key, other_keys);
}

Variant Redis::sUnionStore(const Variant &dst, const Variant &key, const Variant &other_keys) {
    return _this.exec("sUnionStore", dst, key, other_keys);
}

Variant Redis::save() {
    return _this.exec("save");
}

Variant Redis::scan(const Variant &iterator, const Variant &pattern, const Variant &count, const Variant &type) {
    return _this.exec("scan", iterator, pattern, count, type);
}

Variant Redis::scard(const Variant &key) {
    return _this.exec("scard", key);
}

Variant Redis::script(const Variant &command, const Variant &args) {
    return _this.exec("script", command, args);
}

Variant Redis::select(const Variant &db) {
    return _this.exec("select", db);
}

Variant Redis::set(const Variant &key, const Variant &value, const Variant &options) {
    return _this.exec("set", key, value, options);
}

Variant Redis::setBit(const Variant &key, const Variant &idx, const Variant &value) {
    return _this.exec("setBit", key, idx, value);
}

Variant Redis::setRange(const Variant &key, const Variant &index, const Variant &value) {
    return _this.exec("setRange", key, index, value);
}

Variant Redis::setOption(const Variant &option, const Variant &value) {
    return _this.exec("setOption", option, value);
}

Variant Redis::setex(const Variant &key, const Variant &expire, const Variant &value) {
    return _this.exec("setex", key, expire, value);
}

Variant Redis::setnx(const Variant &key, const Variant &value) {
    return _this.exec("setnx", key, value);
}

Variant Redis::sismember(const Variant &key, const Variant &value) {
    return _this.exec("sismember", key, value);
}

Variant Redis::slaveof(const Variant &host, const Variant &port) {
    return _this.exec("slaveof", host, port);
}

Variant Redis::replicaof(const Variant &host, const Variant &port) {
    return _this.exec("replicaof", host, port);
}

Variant Redis::touch(const Variant &key_or_array, const Variant &more_keys) {
    return _this.exec("touch", key_or_array, more_keys);
}

Variant Redis::slowlog(const Variant &operation, const Variant &length) {
    return _this.exec("slowlog", operation, length);
}

Variant Redis::sort(const Variant &key, const Variant &options) {
    return _this.exec("sort", key, options);
}

Variant Redis::sort_ro(const Variant &key, const Variant &options) {
    return _this.exec("sort_ro", key, options);
}

Variant Redis::sortAsc(const Variant &key, const Variant &pattern, const Variant &get, const Variant &offset, const Variant &count, const Variant &store) {
    return _this.exec("sortAsc", key, pattern, get, offset, count, store);
}

Variant Redis::sortAscAlpha(const Variant &key, const Variant &pattern, const Variant &get, const Variant &offset, const Variant &count, const Variant &store) {
    return _this.exec("sortAscAlpha", key, pattern, get, offset, count, store);
}

Variant Redis::sortDesc(const Variant &key, const Variant &pattern, const Variant &get, const Variant &offset, const Variant &count, const Variant &store) {
    return _this.exec("sortDesc", key, pattern, get, offset, count, store);
}

Variant Redis::sortDescAlpha(const Variant &key, const Variant &pattern, const Variant &get, const Variant &offset, const Variant &count, const Variant &store) {
    return _this.exec("sortDescAlpha", key, pattern, get, offset, count, store);
}

Variant Redis::srem(const Variant &key, const Variant &value, const Variant &other_values) {
    return _this.exec("srem", key, value, other_values);
}

Variant Redis::sscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return _this.exec("sscan", key, iterator, pattern, count);
}

Variant Redis::ssubscribe(const Variant &channels, const Variant &cb) {
    return _this.exec("ssubscribe", channels, cb);
}

Variant Redis::strlen(const Variant &key) {
    return _this.exec("strlen", key);
}

Variant Redis::subscribe(const Variant &channels, const Variant &cb) {
    return _this.exec("subscribe", channels, cb);
}

Variant Redis::sunsubscribe(const Variant &channels) {
    return _this.exec("sunsubscribe", channels);
}

Variant Redis::swapdb(const Variant &src, const Variant &dst) {
    return _this.exec("swapdb", src, dst);
}

Variant Redis::time() {
    return _this.exec("time");
}

Variant Redis::ttl(const Variant &key) {
    return _this.exec("ttl", key);
}

Variant Redis::type(const Variant &key) {
    return _this.exec("type", key);
}

Variant Redis::unlink(const Variant &key, const Variant &other_keys) {
    return _this.exec("unlink", key, other_keys);
}

Variant Redis::unsubscribe(const Variant &channels) {
    return _this.exec("unsubscribe", channels);
}

Variant Redis::unwatch() {
    return _this.exec("unwatch");
}

Variant Redis::watch(const Variant &key, const Variant &other_keys) {
    return _this.exec("watch", key, other_keys);
}

Variant Redis::wait(const Variant &numreplicas, const Variant &timeout) {
    return _this.exec("wait", numreplicas, timeout);
}

Variant Redis::xack(const Variant &key, const Variant &group, const Variant &ids) {
    return _this.exec("xack", key, group, ids);
}

Variant Redis::xadd(const Variant &key, const Variant &id, const Variant &values, const Variant &maxlen, const Variant &approx, const Variant &nomkstream) {
    return _this.exec("xadd", key, id, values, maxlen, approx, nomkstream);
}

Variant Redis::xautoclaim(const Variant &key, const Variant &group, const Variant &consumer, const Variant &min_idle, const Variant &start, const Variant &count, const Variant &justid) {
    return _this.exec("xautoclaim", key, group, consumer, min_idle, start, count, justid);
}

Variant Redis::xclaim(const Variant &key, const Variant &group, const Variant &consumer, const Variant &min_idle, const Variant &ids, const Variant &options) {
    return _this.exec("xclaim", key, group, consumer, min_idle, ids, options);
}

Variant Redis::xdel(const Variant &key, const Variant &ids) {
    return _this.exec("xdel", key, ids);
}

Variant Redis::xgroup(const Variant &operation, const Variant &key, const Variant &group, const Variant &id_or_consumer, const Variant &mkstream, const Variant &entries_read) {
    return _this.exec("xgroup", operation, key, group, id_or_consumer, mkstream, entries_read);
}

Variant Redis::xinfo(const Variant &operation, const Variant &arg1, const Variant &arg2, const Variant &count) {
    return _this.exec("xinfo", operation, arg1, arg2, count);
}

Variant Redis::xlen(const Variant &key) {
    return _this.exec("xlen", key);
}

Variant Redis::xpending(const Variant &key, const Variant &group, const Variant &start, const Variant &end, const Variant &count, const Variant &consumer) {
    return _this.exec("xpending", key, group, start, end, count, consumer);
}

Variant Redis::xrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count) {
    return _this.exec("xrange", key, start, end, count);
}

Variant Redis::xread(const Variant &streams, const Variant &count, const Variant &block) {
    return _this.exec("xread", streams, count, block);
}

Variant Redis::xreadgroup(const Variant &group, const Variant &consumer, const Variant &streams, const Variant &count, const Variant &block) {
    return _this.exec("xreadgroup", group, consumer, streams, count, block);
}

Variant Redis::xrevrange(const Variant &key, const Variant &end, const Variant &start, const Variant &count) {
    return _this.exec("xrevrange", key, end, start, count);
}

Variant Redis::xtrim(const Variant &key, const Variant &threshold, const Variant &approx, const Variant &minid, const Variant &limit) {
    return _this.exec("xtrim", key, threshold, approx, minid, limit);
}

Variant Redis::zAdd(const Variant &key, const Variant &score_or_options, const Variant &more_scores_and_mems) {
    return _this.exec("zAdd", key, score_or_options, more_scores_and_mems);
}

Variant Redis::zCard(const Variant &key) {
    return _this.exec("zCard", key);
}

Variant Redis::zCount(const Variant &key, const Variant &start, const Variant &end) {
    return _this.exec("zCount", key, start, end);
}

Variant Redis::zIncrBy(const Variant &key, const Variant &value, const Variant &member) {
    return _this.exec("zIncrBy", key, value, member);
}

Variant Redis::zLexCount(const Variant &key, const Variant &min, const Variant &max) {
    return _this.exec("zLexCount", key, min, max);
}

Variant Redis::zMscore(const Variant &key, const Variant &member, const Variant &other_members) {
    return _this.exec("zMscore", key, member, other_members);
}

Variant Redis::zPopMax(const Variant &key, const Variant &count) {
    return _this.exec("zPopMax", key, count);
}

Variant Redis::zPopMin(const Variant &key, const Variant &count) {
    return _this.exec("zPopMin", key, count);
}

Variant Redis::zRange(const Variant &key, const Variant &start, const Variant &end, const Variant &options) {
    return _this.exec("zRange", key, start, end, options);
}

Variant Redis::zRangeByLex(const Variant &key, const Variant &min, const Variant &max, const Variant &offset, const Variant &count) {
    return _this.exec("zRangeByLex", key, min, max, offset, count);
}

Variant Redis::zRangeByScore(const Variant &key, const Variant &start, const Variant &end, const Array &options) {
    return _this.exec("zRangeByScore", key, start, end, options);
}

Variant Redis::zrangestore(const Variant &dstkey, const Variant &srckey, const Variant &start, const Variant &end, const Variant &options) {
    return _this.exec("zrangestore", dstkey, srckey, start, end, options);
}

Variant Redis::zRandMember(const Variant &key, const Variant &options) {
    return _this.exec("zRandMember", key, options);
}

Variant Redis::zRank(const Variant &key, const Variant &member) {
    return _this.exec("zRank", key, member);
}

Variant Redis::zRem(const Variant &key, const Variant &member, const Variant &other_members) {
    return _this.exec("zRem", key, member, other_members);
}

Variant Redis::zRemRangeByLex(const Variant &key, const Variant &min, const Variant &max) {
    return _this.exec("zRemRangeByLex", key, min, max);
}

Variant Redis::zRemRangeByRank(const Variant &key, const Variant &start, const Variant &end) {
    return _this.exec("zRemRangeByRank", key, start, end);
}

Variant Redis::zRemRangeByScore(const Variant &key, const Variant &start, const Variant &end) {
    return _this.exec("zRemRangeByScore", key, start, end);
}

Variant Redis::zRevRange(const Variant &key, const Variant &start, const Variant &end, const Variant &scores) {
    return _this.exec("zRevRange", key, start, end, scores);
}

Variant Redis::zRevRangeByLex(const Variant &key, const Variant &max, const Variant &min, const Variant &offset, const Variant &count) {
    return _this.exec("zRevRangeByLex", key, max, min, offset, count);
}

Variant Redis::zRevRangeByScore(const Variant &key, const Variant &max, const Variant &min, const Array &options) {
    return _this.exec("zRevRangeByScore", key, max, min, options);
}

Variant Redis::zRevRank(const Variant &key, const Variant &member) {
    return _this.exec("zRevRank", key, member);
}

Variant Redis::zScore(const Variant &key, const Variant &member) {
    return _this.exec("zScore", key, member);
}

Variant Redis::zdiff(const Variant &keys, const Variant &options) {
    return _this.exec("zdiff", keys, options);
}

Variant Redis::zdiffstore(const Variant &dst, const Variant &keys) {
    return _this.exec("zdiffstore", dst, keys);
}

Variant Redis::zinter(const Variant &keys, const Variant &weights, const Variant &options) {
    return _this.exec("zinter", keys, weights, options);
}

Variant Redis::zintercard(const Variant &keys, const Variant &limit) {
    return _this.exec("zintercard", keys, limit);
}

Variant Redis::zinterstore(const Variant &dst, const Variant &keys, const Variant &weights, const Variant &aggregate) {
    return _this.exec("zinterstore", dst, keys, weights, aggregate);
}

Variant Redis::zscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return _this.exec("zscan", key, iterator, pattern, count);
}

Variant Redis::zunion(const Variant &keys, const Variant &weights, const Variant &options) {
    return _this.exec("zunion", keys, weights, options);
}

Variant Redis::zunionstore(const Variant &dst, const Variant &keys, const Variant &weights, const Variant &aggregate) {
    return _this.exec("zunionstore", dst, keys, weights, aggregate);
}


Variant RedisArray::__call(const Variant &function_name, const Variant &arguments) {
    return _this.exec("__call", function_name, arguments);
}

RedisArray::RedisArray(const Variant &name_or_hosts, const Variant &options) {
    _this = newObject("RedisArray", name_or_hosts, options);
}

Variant RedisArray::_continuum() {
    return _this.exec("_continuum");
}

Variant RedisArray::_distributor() {
    return _this.exec("_distributor");
}

Variant RedisArray::_function() {
    return _this.exec("_function");
}

Variant RedisArray::_hosts() {
    return _this.exec("_hosts");
}

Variant RedisArray::_instance(const Variant &host) {
    return _this.exec("_instance", host);
}

Variant RedisArray::_rehash(const Variant &fn) {
    return _this.exec("_rehash", fn);
}

Variant RedisArray::_target(const Variant &key) {
    return _this.exec("_target", key);
}

Variant RedisArray::bgsave() {
    return _this.exec("bgsave");
}

Variant RedisArray::del(const Variant &key, const Variant &otherkeys) {
    return _this.exec("del", key, otherkeys);
}

Variant RedisArray::discard() {
    return _this.exec("discard");
}

Variant RedisArray::exec() {
    return _this.exec("exec");
}

Variant RedisArray::flushall() {
    return _this.exec("flushall");
}

Variant RedisArray::flushdb() {
    return _this.exec("flushdb");
}

Variant RedisArray::getOption(const Variant &opt) {
    return _this.exec("getOption", opt);
}

Variant RedisArray::hscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return _this.exec("hscan", key, iterator, pattern, count);
}

Variant RedisArray::info() {
    return _this.exec("info");
}

Variant RedisArray::keys(const Variant &pattern) {
    return _this.exec("keys", pattern);
}

Variant RedisArray::mget(const Variant &keys) {
    return _this.exec("mget", keys);
}

Variant RedisArray::mset(const Variant &pairs) {
    return _this.exec("mset", pairs);
}

Variant RedisArray::multi(const Variant &host, const Variant &mode) {
    return _this.exec("multi", host, mode);
}

Variant RedisArray::ping() {
    return _this.exec("ping");
}

Variant RedisArray::save() {
    return _this.exec("save");
}

Variant RedisArray::scan(const Variant &iterator, const Variant &node, const Variant &pattern, const Variant &count) {
    return _this.exec("scan", iterator, node, pattern, count);
}

Variant RedisArray::select(const Variant &index) {
    return _this.exec("select", index);
}

Variant RedisArray::setOption(const Variant &opt, const Variant &value) {
    return _this.exec("setOption", opt, value);
}

Variant RedisArray::sscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return _this.exec("sscan", key, iterator, pattern, count);
}

Variant RedisArray::unlink(const Variant &key, const Variant &otherkeys) {
    return _this.exec("unlink", key, otherkeys);
}

Variant RedisArray::unwatch() {
    return _this.exec("unwatch");
}

Variant RedisArray::zscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return _this.exec("zscan", key, iterator, pattern, count);
}


RedisCluster::RedisCluster(const Variant &name, const Variant &seeds, const Variant &timeout, const Variant &read_timeout, const Variant &persistent, const Variant &auth, const Variant &context) {
    _this = newObject("RedisCluster", name, seeds, timeout, read_timeout, persistent, auth, context);
}

Variant RedisCluster::_compress(const Variant &value) {
    return _this.exec("_compress", value);
}

Variant RedisCluster::_uncompress(const Variant &value) {
    return _this.exec("_uncompress", value);
}

Variant RedisCluster::_serialize(const Variant &value) {
    return _this.exec("_serialize", value);
}

Variant RedisCluster::_unserialize(const Variant &value) {
    return _this.exec("_unserialize", value);
}

Variant RedisCluster::_pack(const Variant &value) {
    return _this.exec("_pack", value);
}

Variant RedisCluster::_unpack(const Variant &value) {
    return _this.exec("_unpack", value);
}

Variant RedisCluster::_prefix(const Variant &key) {
    return _this.exec("_prefix", key);
}

Variant RedisCluster::_masters() {
    return _this.exec("_masters");
}

Variant RedisCluster::_redir() {
    return _this.exec("_redir");
}

Variant RedisCluster::acl(const Variant &key_or_address, const Variant &subcmd, const Variant &args) {
    return _this.exec("acl", key_or_address, subcmd, args);
}

Variant RedisCluster::append(const Variant &key, const Variant &value) {
    return _this.exec("append", key, value);
}

Variant RedisCluster::bgrewriteaof(const Variant &key_or_address) {
    return _this.exec("bgrewriteaof", key_or_address);
}

Variant RedisCluster::bgsave(const Variant &key_or_address) {
    return _this.exec("bgsave", key_or_address);
}

Variant RedisCluster::bitcount(const Variant &key, const Variant &start, const Variant &end, const Variant &bybit) {
    return _this.exec("bitcount", key, start, end, bybit);
}

Variant RedisCluster::bitop(const Variant &operation, const Variant &deskey, const Variant &srckey, const Variant &otherkeys) {
    return _this.exec("bitop", operation, deskey, srckey, otherkeys);
}

Variant RedisCluster::bitpos(const Variant &key, const Variant &bit, const Variant &start, const Variant &end, const Variant &bybit) {
    return _this.exec("bitpos", key, bit, start, end, bybit);
}

Variant RedisCluster::blpop(const Variant &key, const Variant &timeout_or_key, const Variant &extra_args) {
    return _this.exec("blpop", key, timeout_or_key, extra_args);
}

Variant RedisCluster::brpop(const Variant &key, const Variant &timeout_or_key, const Variant &extra_args) {
    return _this.exec("brpop", key, timeout_or_key, extra_args);
}

Variant RedisCluster::brpoplpush(const Variant &srckey, const Variant &deskey, const Variant &timeout) {
    return _this.exec("brpoplpush", srckey, deskey, timeout);
}

Variant RedisCluster::lmove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto) {
    return _this.exec("lmove", src, dst, wherefrom, whereto);
}

Variant RedisCluster::blmove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto, const Variant &timeout) {
    return _this.exec("blmove", src, dst, wherefrom, whereto, timeout);
}

Variant RedisCluster::bzpopmax(const Variant &key, const Variant &timeout_or_key, const Variant &extra_args) {
    return _this.exec("bzpopmax", key, timeout_or_key, extra_args);
}

Variant RedisCluster::bzpopmin(const Variant &key, const Variant &timeout_or_key, const Variant &extra_args) {
    return _this.exec("bzpopmin", key, timeout_or_key, extra_args);
}

Variant RedisCluster::bzmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    return _this.exec("bzmpop", timeout, keys, from, count);
}

Variant RedisCluster::zmpop(const Variant &keys, const Variant &from, const Variant &count) {
    return _this.exec("zmpop", keys, from, count);
}

Variant RedisCluster::blmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    return _this.exec("blmpop", timeout, keys, from, count);
}

Variant RedisCluster::lmpop(const Variant &keys, const Variant &from, const Variant &count) {
    return _this.exec("lmpop", keys, from, count);
}

Variant RedisCluster::clearlasterror() {
    return _this.exec("clearlasterror");
}

Variant RedisCluster::client(const Variant &key_or_address, const Variant &subcommand, const Variant &arg) {
    return _this.exec("client", key_or_address, subcommand, arg);
}

Variant RedisCluster::close() {
    return _this.exec("close");
}

Variant RedisCluster::cluster(const Variant &key_or_address, const Variant &command, const Variant &extra_args) {
    return _this.exec("cluster", key_or_address, command, extra_args);
}

Variant RedisCluster::command(const Variant &extra_args) {
    return _this.exec("command", extra_args);
}

Variant RedisCluster::config(const Variant &key_or_address, const Variant &subcommand, const Variant &extra_args) {
    return _this.exec("config", key_or_address, subcommand, extra_args);
}

Variant RedisCluster::dbsize(const Variant &key_or_address) {
    return _this.exec("dbsize", key_or_address);
}

Variant RedisCluster::copy(const Variant &src, const Variant &dst, const Variant &options) {
    return _this.exec("copy", src, dst, options);
}

Variant RedisCluster::decr(const Variant &key, const Variant &by) {
    return _this.exec("decr", key, by);
}

Variant RedisCluster::decrby(const Variant &key, const Variant &value) {
    return _this.exec("decrby", key, value);
}

Variant RedisCluster::decrbyfloat(const Variant &key, const Variant &value) {
    return _this.exec("decrbyfloat", key, value);
}

Variant RedisCluster::del(const Variant &key, const Variant &other_keys) {
    return _this.exec("del", key, other_keys);
}

Variant RedisCluster::discard() {
    return _this.exec("discard");
}

Variant RedisCluster::dump(const Variant &key) {
    return _this.exec("dump", key);
}

Variant RedisCluster::echo(const Variant &key_or_address, const Variant &msg) {
    return _this.exec("echo", key_or_address, msg);
}

Variant RedisCluster::eval(const Variant &script, const Array &args, const Variant &num_keys) {
    return _this.exec("eval", script, args, num_keys);
}

Variant RedisCluster::eval_ro(const Variant &script, const Array &args, const Variant &num_keys) {
    return _this.exec("eval_ro", script, args, num_keys);
}

Variant RedisCluster::evalsha(const Variant &script_sha, const Array &args, const Variant &num_keys) {
    return _this.exec("evalsha", script_sha, args, num_keys);
}

Variant RedisCluster::evalsha_ro(const Variant &script_sha, const Array &args, const Variant &num_keys) {
    return _this.exec("evalsha_ro", script_sha, args, num_keys);
}

Variant RedisCluster::exec() {
    return _this.exec("exec");
}

Variant RedisCluster::exists(const Variant &key, const Variant &other_keys) {
    return _this.exec("exists", key, other_keys);
}

Variant RedisCluster::touch(const Variant &key, const Variant &other_keys) {
    return _this.exec("touch", key, other_keys);
}

Variant RedisCluster::expire(const Variant &key, const Variant &timeout, const Variant &mode) {
    return _this.exec("expire", key, timeout, mode);
}

Variant RedisCluster::expireat(const Variant &key, const Variant &timestamp, const Variant &mode) {
    return _this.exec("expireat", key, timestamp, mode);
}

Variant RedisCluster::expiretime(const Variant &key) {
    return _this.exec("expiretime", key);
}

Variant RedisCluster::pexpiretime(const Variant &key) {
    return _this.exec("pexpiretime", key);
}

Variant RedisCluster::flushall(const Variant &key_or_address, const Variant &async) {
    return _this.exec("flushall", key_or_address, async);
}

Variant RedisCluster::flushdb(const Variant &key_or_address, const Variant &async) {
    return _this.exec("flushdb", key_or_address, async);
}

Variant RedisCluster::geoadd(const Variant &key, const Variant &lng, const Variant &lat, const Variant &member, const Variant &other_triples_and_options) {
    return _this.exec("geoadd", key, lng, lat, member, other_triples_and_options);
}

Variant RedisCluster::geodist(const Variant &key, const Variant &src, const Variant &dest, const Variant &unit) {
    return _this.exec("geodist", key, src, dest, unit);
}

Variant RedisCluster::geohash(const Variant &key, const Variant &member, const Variant &other_members) {
    return _this.exec("geohash", key, member, other_members);
}

Variant RedisCluster::geopos(const Variant &key, const Variant &member, const Variant &other_members) {
    return _this.exec("geopos", key, member, other_members);
}

Variant RedisCluster::georadius(const Variant &key, const Variant &lng, const Variant &lat, const Variant &radius, const Variant &unit, const Array &options) {
    return _this.exec("georadius", key, lng, lat, radius, unit, options);
}

Variant RedisCluster::georadius_ro(const Variant &key, const Variant &lng, const Variant &lat, const Variant &radius, const Variant &unit, const Array &options) {
    return _this.exec("georadius_ro", key, lng, lat, radius, unit, options);
}

Variant RedisCluster::georadiusbymember(const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Array &options) {
    return _this.exec("georadiusbymember", key, member, radius, unit, options);
}

Variant RedisCluster::georadiusbymember_ro(const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Array &options) {
    return _this.exec("georadiusbymember_ro", key, member, radius, unit, options);
}

Variant RedisCluster::geosearch(const Variant &key, const Variant &position, const Variant &shape, const Variant &unit, const Array &options) {
    return _this.exec("geosearch", key, position, shape, unit, options);
}

Variant RedisCluster::geosearchstore(const Variant &dst, const Variant &src, const Variant &position, const Variant &shape, const Variant &unit, const Array &options) {
    return _this.exec("geosearchstore", dst, src, position, shape, unit, options);
}

Variant RedisCluster::get(const Variant &key) {
    return _this.exec("get", key);
}

Variant RedisCluster::getbit(const Variant &key, const Variant &value) {
    return _this.exec("getbit", key, value);
}

Variant RedisCluster::getlasterror() {
    return _this.exec("getlasterror");
}

Variant RedisCluster::getmode() {
    return _this.exec("getmode");
}

Variant RedisCluster::getoption(const Variant &option) {
    return _this.exec("getoption", option);
}

Variant RedisCluster::getrange(const Variant &key, const Variant &start, const Variant &end) {
    return _this.exec("getrange", key, start, end);
}

Variant RedisCluster::lcs(const Variant &key1, const Variant &key2, const Variant &options) {
    return _this.exec("lcs", key1, key2, options);
}

Variant RedisCluster::getset(const Variant &key, const Variant &value) {
    return _this.exec("getset", key, value);
}

Variant RedisCluster::gettransferredbytes() {
    return _this.exec("gettransferredbytes");
}

Variant RedisCluster::cleartransferredbytes() {
    return _this.exec("cleartransferredbytes");
}

Variant RedisCluster::hdel(const Variant &key, const Variant &member, const Variant &other_members) {
    return _this.exec("hdel", key, member, other_members);
}

Variant RedisCluster::hexists(const Variant &key, const Variant &member) {
    return _this.exec("hexists", key, member);
}

Variant RedisCluster::hget(const Variant &key, const Variant &member) {
    return _this.exec("hget", key, member);
}

Variant RedisCluster::hgetall(const Variant &key) {
    return _this.exec("hgetall", key);
}

Variant RedisCluster::hincrby(const Variant &key, const Variant &member, const Variant &value) {
    return _this.exec("hincrby", key, member, value);
}

Variant RedisCluster::hincrbyfloat(const Variant &key, const Variant &member, const Variant &value) {
    return _this.exec("hincrbyfloat", key, member, value);
}

Variant RedisCluster::hkeys(const Variant &key) {
    return _this.exec("hkeys", key);
}

Variant RedisCluster::hlen(const Variant &key) {
    return _this.exec("hlen", key);
}

Variant RedisCluster::hmget(const Variant &key, const Variant &keys) {
    return _this.exec("hmget", key, keys);
}

Variant RedisCluster::hmset(const Variant &key, const Variant &key_values) {
    return _this.exec("hmset", key, key_values);
}

Variant RedisCluster::hscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return _this.exec("hscan", key, iterator, pattern, count);
}

Variant RedisCluster::hrandfield(const Variant &key, const Variant &options) {
    return _this.exec("hrandfield", key, options);
}

Variant RedisCluster::hset(const Variant &key, const Variant &member, const Variant &value) {
    return _this.exec("hset", key, member, value);
}

Variant RedisCluster::hsetnx(const Variant &key, const Variant &member, const Variant &value) {
    return _this.exec("hsetnx", key, member, value);
}

Variant RedisCluster::hstrlen(const Variant &key, const Variant &field) {
    return _this.exec("hstrlen", key, field);
}

Variant RedisCluster::hvals(const Variant &key) {
    return _this.exec("hvals", key);
}

Variant RedisCluster::incr(const Variant &key, const Variant &by) {
    return _this.exec("incr", key, by);
}

Variant RedisCluster::incrby(const Variant &key, const Variant &value) {
    return _this.exec("incrby", key, value);
}

Variant RedisCluster::incrbyfloat(const Variant &key, const Variant &value) {
    return _this.exec("incrbyfloat", key, value);
}

Variant RedisCluster::info(const Variant &key_or_address, const Variant &sections) {
    return _this.exec("info", key_or_address, sections);
}

Variant RedisCluster::keys(const Variant &pattern) {
    return _this.exec("keys", pattern);
}

Variant RedisCluster::lastsave(const Variant &key_or_address) {
    return _this.exec("lastsave", key_or_address);
}

Variant RedisCluster::lget(const Variant &key, const Variant &index) {
    return _this.exec("lget", key, index);
}

Variant RedisCluster::lindex(const Variant &key, const Variant &index) {
    return _this.exec("lindex", key, index);
}

Variant RedisCluster::linsert(const Variant &key, const Variant &pos, const Variant &pivot, const Variant &value) {
    return _this.exec("linsert", key, pos, pivot, value);
}

Variant RedisCluster::llen(const Variant &key) {
    return _this.exec("llen", key);
}

Variant RedisCluster::lpop(const Variant &key, const Variant &count) {
    return _this.exec("lpop", key, count);
}

Variant RedisCluster::lpos(const Variant &key, const Variant &value, const Variant &options) {
    return _this.exec("lpos", key, value, options);
}

Variant RedisCluster::lpush(const Variant &key, const Variant &value, const Variant &other_values) {
    return _this.exec("lpush", key, value, other_values);
}

Variant RedisCluster::lpushx(const Variant &key, const Variant &value) {
    return _this.exec("lpushx", key, value);
}

Variant RedisCluster::lrange(const Variant &key, const Variant &start, const Variant &end) {
    return _this.exec("lrange", key, start, end);
}

Variant RedisCluster::lrem(const Variant &key, const Variant &value, const Variant &count) {
    return _this.exec("lrem", key, value, count);
}

Variant RedisCluster::lset(const Variant &key, const Variant &index, const Variant &value) {
    return _this.exec("lset", key, index, value);
}

Variant RedisCluster::ltrim(const Variant &key, const Variant &start, const Variant &end) {
    return _this.exec("ltrim", key, start, end);
}

Variant RedisCluster::mget(const Variant &keys) {
    return _this.exec("mget", keys);
}

Variant RedisCluster::mset(const Variant &key_values) {
    return _this.exec("mset", key_values);
}

Variant RedisCluster::msetnx(const Variant &key_values) {
    return _this.exec("msetnx", key_values);
}

Variant RedisCluster::multi(const Variant &value) {
    return _this.exec("multi", value);
}

Variant RedisCluster::object(const Variant &subcommand, const Variant &key) {
    return _this.exec("object", subcommand, key);
}

Variant RedisCluster::persist(const Variant &key) {
    return _this.exec("persist", key);
}

Variant RedisCluster::pexpire(const Variant &key, const Variant &timeout, const Variant &mode) {
    return _this.exec("pexpire", key, timeout, mode);
}

Variant RedisCluster::pexpireat(const Variant &key, const Variant &timestamp, const Variant &mode) {
    return _this.exec("pexpireat", key, timestamp, mode);
}

Variant RedisCluster::pfadd(const Variant &key, const Variant &elements) {
    return _this.exec("pfadd", key, elements);
}

Variant RedisCluster::pfcount(const Variant &key) {
    return _this.exec("pfcount", key);
}

Variant RedisCluster::pfmerge(const Variant &key, const Variant &keys) {
    return _this.exec("pfmerge", key, keys);
}

Variant RedisCluster::ping(const Variant &key_or_address, const Variant &message) {
    return _this.exec("ping", key_or_address, message);
}

Variant RedisCluster::psetex(const Variant &key, const Variant &timeout, const Variant &value) {
    return _this.exec("psetex", key, timeout, value);
}

Variant RedisCluster::psubscribe(const Variant &patterns, const Variant &callback) {
    return _this.exec("psubscribe", patterns, callback);
}

Variant RedisCluster::pttl(const Variant &key) {
    return _this.exec("pttl", key);
}

Variant RedisCluster::publish(const Variant &channel, const Variant &message) {
    return _this.exec("publish", channel, message);
}

Variant RedisCluster::pubsub(const Variant &key_or_address, const Variant &values) {
    return _this.exec("pubsub", key_or_address, values);
}

Variant RedisCluster::punsubscribe(const Variant &pattern, const Variant &other_patterns) {
    return _this.exec("punsubscribe", pattern, other_patterns);
}

Variant RedisCluster::randomkey(const Variant &key_or_address) {
    return _this.exec("randomkey", key_or_address);
}

Variant RedisCluster::rawcommand(const Variant &key_or_address, const Variant &command, const Variant &args) {
    return _this.exec("rawcommand", key_or_address, command, args);
}

Variant RedisCluster::rename(const Variant &key_src, const Variant &key_dst) {
    return _this.exec("rename", key_src, key_dst);
}

Variant RedisCluster::renamenx(const Variant &key, const Variant &newkey) {
    return _this.exec("renamenx", key, newkey);
}

Variant RedisCluster::restore(const Variant &key, const Variant &timeout, const Variant &value, const Variant &options) {
    return _this.exec("restore", key, timeout, value, options);
}

Variant RedisCluster::role(const Variant &key_or_address) {
    return _this.exec("role", key_or_address);
}

Variant RedisCluster::rpop(const Variant &key, const Variant &count) {
    return _this.exec("rpop", key, count);
}

Variant RedisCluster::rpoplpush(const Variant &src, const Variant &dst) {
    return _this.exec("rpoplpush", src, dst);
}

Variant RedisCluster::rpush(const Variant &key, const Variant &elements) {
    return _this.exec("rpush", key, elements);
}

Variant RedisCluster::rpushx(const Variant &key, const Variant &value) {
    return _this.exec("rpushx", key, value);
}

Variant RedisCluster::sadd(const Variant &key, const Variant &value, const Variant &other_values) {
    return _this.exec("sadd", key, value, other_values);
}

Variant RedisCluster::saddarray(const Variant &key, const Variant &values) {
    return _this.exec("saddarray", key, values);
}

Variant RedisCluster::save(const Variant &key_or_address) {
    return _this.exec("save", key_or_address);
}

Variant RedisCluster::scan(const Variant &iterator, const Variant &key_or_address, const Variant &pattern, const Variant &count) {
    return _this.exec("scan", iterator, key_or_address, pattern, count);
}

Variant RedisCluster::scard(const Variant &key) {
    return _this.exec("scard", key);
}

Variant RedisCluster::script(const Variant &key_or_address, const Variant &args) {
    return _this.exec("script", key_or_address, args);
}

Variant RedisCluster::sdiff(const Variant &key, const Variant &other_keys) {
    return _this.exec("sdiff", key, other_keys);
}

Variant RedisCluster::sdiffstore(const Variant &dst, const Variant &key, const Variant &other_keys) {
    return _this.exec("sdiffstore", dst, key, other_keys);
}

Variant RedisCluster::set(const Variant &key, const Variant &value, const Variant &options) {
    return _this.exec("set", key, value, options);
}

Variant RedisCluster::_setbit(const Variant &key, const Variant &offset, const Variant &onoff) {
    return _this.exec("setbit", key, offset, onoff);
}

Variant RedisCluster::setex(const Variant &key, const Variant &expire, const Variant &value) {
    return _this.exec("setex", key, expire, value);
}

Variant RedisCluster::setnx(const Variant &key, const Variant &value) {
    return _this.exec("setnx", key, value);
}

Variant RedisCluster::setoption(const Variant &option, const Variant &value) {
    return _this.exec("setoption", option, value);
}

Variant RedisCluster::setrange(const Variant &key, const Variant &offset, const Variant &value) {
    return _this.exec("setrange", key, offset, value);
}

Variant RedisCluster::sinter(const Variant &key, const Variant &other_keys) {
    return _this.exec("sinter", key, other_keys);
}

Variant RedisCluster::sintercard(const Variant &keys, const Variant &limit) {
    return _this.exec("sintercard", keys, limit);
}

Variant RedisCluster::sinterstore(const Variant &key, const Variant &other_keys) {
    return _this.exec("sinterstore", key, other_keys);
}

Variant RedisCluster::sismember(const Variant &key, const Variant &value) {
    return _this.exec("sismember", key, value);
}

Variant RedisCluster::smismember(const Variant &key, const Variant &member, const Variant &other_members) {
    return _this.exec("smismember", key, member, other_members);
}

Variant RedisCluster::slowlog(const Variant &key_or_address, const Variant &args) {
    return _this.exec("slowlog", key_or_address, args);
}

Variant RedisCluster::smembers(const Variant &key) {
    return _this.exec("smembers", key);
}

Variant RedisCluster::smove(const Variant &src, const Variant &dst, const Variant &member) {
    return _this.exec("smove", src, dst, member);
}

Variant RedisCluster::sort(const Variant &key, const Variant &options) {
    return _this.exec("sort", key, options);
}

Variant RedisCluster::sort_ro(const Variant &key, const Variant &options) {
    return _this.exec("sort_ro", key, options);
}

Variant RedisCluster::spop(const Variant &key, const Variant &count) {
    return _this.exec("spop", key, count);
}

Variant RedisCluster::srandmember(const Variant &key, const Variant &count) {
    return _this.exec("srandmember", key, count);
}

Variant RedisCluster::srem(const Variant &key, const Variant &value, const Variant &other_values) {
    return _this.exec("srem", key, value, other_values);
}

Variant RedisCluster::sscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return _this.exec("sscan", key, iterator, pattern, count);
}

Variant RedisCluster::strlen(const Variant &key) {
    return _this.exec("strlen", key);
}

Variant RedisCluster::subscribe(const Variant &channels, const Variant &cb) {
    return _this.exec("subscribe", channels, cb);
}

Variant RedisCluster::sunion(const Variant &key, const Variant &other_keys) {
    return _this.exec("sunion", key, other_keys);
}

Variant RedisCluster::sunionstore(const Variant &dst, const Variant &key, const Variant &other_keys) {
    return _this.exec("sunionstore", dst, key, other_keys);
}

Variant RedisCluster::time(const Variant &key_or_address) {
    return _this.exec("time", key_or_address);
}

Variant RedisCluster::ttl(const Variant &key) {
    return _this.exec("ttl", key);
}

Variant RedisCluster::type(const Variant &key) {
    return _this.exec("type", key);
}

Variant RedisCluster::unsubscribe(const Variant &channels) {
    return _this.exec("unsubscribe", channels);
}

Variant RedisCluster::unlink(const Variant &key, const Variant &other_keys) {
    return _this.exec("unlink", key, other_keys);
}

Variant RedisCluster::unwatch() {
    return _this.exec("unwatch");
}

Variant RedisCluster::watch(const Variant &key, const Variant &other_keys) {
    return _this.exec("watch", key, other_keys);
}

Variant RedisCluster::xack(const Variant &key, const Variant &group, const Variant &ids) {
    return _this.exec("xack", key, group, ids);
}

Variant RedisCluster::xadd(const Variant &key, const Variant &id, const Variant &values, const Variant &maxlen, const Variant &approx) {
    return _this.exec("xadd", key, id, values, maxlen, approx);
}

Variant RedisCluster::xclaim(const Variant &key, const Variant &group, const Variant &consumer, const Variant &min_iddle, const Variant &ids, const Variant &options) {
    return _this.exec("xclaim", key, group, consumer, min_iddle, ids, options);
}

Variant RedisCluster::xdel(const Variant &key, const Variant &ids) {
    return _this.exec("xdel", key, ids);
}

Variant RedisCluster::xgroup(const Variant &operation, const Variant &key, const Variant &group, const Variant &id_or_consumer, const Variant &mkstream, const Variant &entries_read) {
    return _this.exec("xgroup", operation, key, group, id_or_consumer, mkstream, entries_read);
}

Variant RedisCluster::xautoclaim(const Variant &key, const Variant &group, const Variant &consumer, const Variant &min_idle, const Variant &start, const Variant &count, const Variant &justid) {
    return _this.exec("xautoclaim", key, group, consumer, min_idle, start, count, justid);
}

Variant RedisCluster::xinfo(const Variant &operation, const Variant &arg1, const Variant &arg2, const Variant &count) {
    return _this.exec("xinfo", operation, arg1, arg2, count);
}

Variant RedisCluster::xlen(const Variant &key) {
    return _this.exec("xlen", key);
}

Variant RedisCluster::xpending(const Variant &key, const Variant &group, const Variant &start, const Variant &end, const Variant &count, const Variant &consumer) {
    return _this.exec("xpending", key, group, start, end, count, consumer);
}

Variant RedisCluster::xrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count) {
    return _this.exec("xrange", key, start, end, count);
}

Variant RedisCluster::xread(const Variant &streams, const Variant &count, const Variant &block) {
    return _this.exec("xread", streams, count, block);
}

Variant RedisCluster::xreadgroup(const Variant &group, const Variant &consumer, const Variant &streams, const Variant &count, const Variant &block) {
    return _this.exec("xreadgroup", group, consumer, streams, count, block);
}

Variant RedisCluster::xrevrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count) {
    return _this.exec("xrevrange", key, start, end, count);
}

Variant RedisCluster::xtrim(const Variant &key, const Variant &maxlen, const Variant &approx, const Variant &minid, const Variant &limit) {
    return _this.exec("xtrim", key, maxlen, approx, minid, limit);
}

Variant RedisCluster::zadd(const Variant &key, const Variant &score_or_options, const Variant &more_scores_and_mems) {
    return _this.exec("zadd", key, score_or_options, more_scores_and_mems);
}

Variant RedisCluster::zcard(const Variant &key) {
    return _this.exec("zcard", key);
}

Variant RedisCluster::zcount(const Variant &key, const Variant &start, const Variant &end) {
    return _this.exec("zcount", key, start, end);
}

Variant RedisCluster::zincrby(const Variant &key, const Variant &value, const Variant &member) {
    return _this.exec("zincrby", key, value, member);
}

Variant RedisCluster::zinterstore(const Variant &dst, const Variant &keys, const Variant &weights, const Variant &aggregate) {
    return _this.exec("zinterstore", dst, keys, weights, aggregate);
}

Variant RedisCluster::zintercard(const Variant &keys, const Variant &limit) {
    return _this.exec("zintercard", keys, limit);
}

Variant RedisCluster::zlexcount(const Variant &key, const Variant &min, const Variant &max) {
    return _this.exec("zlexcount", key, min, max);
}

Variant RedisCluster::zpopmax(const Variant &key, const Variant &value) {
    return _this.exec("zpopmax", key, value);
}

Variant RedisCluster::zpopmin(const Variant &key, const Variant &value) {
    return _this.exec("zpopmin", key, value);
}

Variant RedisCluster::zrange(const Variant &key, const Variant &start, const Variant &end, const Variant &options) {
    return _this.exec("zrange", key, start, end, options);
}

Variant RedisCluster::zrangestore(const Variant &dstkey, const Variant &srckey, const Variant &start, const Variant &end, const Variant &options) {
    return _this.exec("zrangestore", dstkey, srckey, start, end, options);
}

Variant RedisCluster::zrandmember(const Variant &key, const Variant &options) {
    return _this.exec("zrandmember", key, options);
}

Variant RedisCluster::zrangebylex(const Variant &key, const Variant &min, const Variant &max, const Variant &offset, const Variant &count) {
    return _this.exec("zrangebylex", key, min, max, offset, count);
}

Variant RedisCluster::zrangebyscore(const Variant &key, const Variant &start, const Variant &end, const Array &options) {
    return _this.exec("zrangebyscore", key, start, end, options);
}

Variant RedisCluster::zrank(const Variant &key, const Variant &member) {
    return _this.exec("zrank", key, member);
}

Variant RedisCluster::zrem(const Variant &key, const Variant &value, const Variant &other_values) {
    return _this.exec("zrem", key, value, other_values);
}

Variant RedisCluster::zremrangebylex(const Variant &key, const Variant &min, const Variant &max) {
    return _this.exec("zremrangebylex", key, min, max);
}

Variant RedisCluster::zremrangebyrank(const Variant &key, const Variant &min, const Variant &max) {
    return _this.exec("zremrangebyrank", key, min, max);
}

Variant RedisCluster::zremrangebyscore(const Variant &key, const Variant &min, const Variant &max) {
    return _this.exec("zremrangebyscore", key, min, max);
}

Variant RedisCluster::zrevrange(const Variant &key, const Variant &min, const Variant &max, const Variant &options) {
    return _this.exec("zrevrange", key, min, max, options);
}

Variant RedisCluster::zrevrangebylex(const Variant &key, const Variant &min, const Variant &max, const Variant &options) {
    return _this.exec("zrevrangebylex", key, min, max, options);
}

Variant RedisCluster::zrevrangebyscore(const Variant &key, const Variant &min, const Variant &max, const Variant &options) {
    return _this.exec("zrevrangebyscore", key, min, max, options);
}

Variant RedisCluster::zrevrank(const Variant &key, const Variant &member) {
    return _this.exec("zrevrank", key, member);
}

Variant RedisCluster::zscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return _this.exec("zscan", key, iterator, pattern, count);
}

Variant RedisCluster::zscore(const Variant &key, const Variant &member) {
    return _this.exec("zscore", key, member);
}

Variant RedisCluster::zmscore(const Variant &key, const Variant &member, const Variant &other_members) {
    return _this.exec("zmscore", key, member, other_members);
}

Variant RedisCluster::zunionstore(const Variant &dst, const Variant &keys, const Variant &weights, const Variant &aggregate) {
    return _this.exec("zunionstore", dst, keys, weights, aggregate);
}

Variant RedisCluster::zinter(const Variant &keys, const Variant &weights, const Variant &options) {
    return _this.exec("zinter", keys, weights, options);
}

Variant RedisCluster::zdiffstore(const Variant &dst, const Variant &keys) {
    return _this.exec("zdiffstore", dst, keys);
}

Variant RedisCluster::zunion(const Variant &keys, const Variant &weights, const Variant &options) {
    return _this.exec("zunion", keys, weights, options);
}

Variant RedisCluster::zdiff(const Variant &keys, const Variant &options) {
    return _this.exec("zdiff", keys, options);
}


RedisClusterException::RedisClusterException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("RedisClusterException", message, code, previous);
}

Variant RedisClusterException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant RedisClusterException::getMessage() {
    return _this.exec("getMessage");
}

Variant RedisClusterException::getCode() {
    return _this.exec("getCode");
}

Variant RedisClusterException::getFile() {
    return _this.exec("getFile");
}

Variant RedisClusterException::getLine() {
    return _this.exec("getLine");
}

Variant RedisClusterException::getTrace() {
    return _this.exec("getTrace");
}

Variant RedisClusterException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant RedisClusterException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant RedisClusterException::__toString() {
    return _this.exec("__toString");
}


RedisSentinel::RedisSentinel(const Variant &options) {
    _this = newObject("RedisSentinel", options);
}

Variant RedisSentinel::ckquorum(const Variant &master) {
    return _this.exec("ckquorum", master);
}

Variant RedisSentinel::failover(const Variant &master) {
    return _this.exec("failover", master);
}

Variant RedisSentinel::flushconfig() {
    return _this.exec("flushconfig");
}

Variant RedisSentinel::getMasterAddrByName(const Variant &master) {
    return _this.exec("getMasterAddrByName", master);
}

Variant RedisSentinel::master(const Variant &master) {
    return _this.exec("master", master);
}

Variant RedisSentinel::masters() {
    return _this.exec("masters");
}

Variant RedisSentinel::myid() {
    return _this.exec("myid");
}

Variant RedisSentinel::ping() {
    return _this.exec("ping");
}

Variant RedisSentinel::reset(const Variant &pattern) {
    return _this.exec("reset", pattern);
}

Variant RedisSentinel::sentinels(const Variant &master) {
    return _this.exec("sentinels", master);
}

Variant RedisSentinel::slaves(const Variant &master) {
    return _this.exec("slaves", master);
}


RedisException::RedisException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("RedisException", message, code, previous);
}

Variant RedisException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant RedisException::getMessage() {
    return _this.exec("getMessage");
}

Variant RedisException::getCode() {
    return _this.exec("getCode");
}

Variant RedisException::getFile() {
    return _this.exec("getFile");
}

Variant RedisException::getLine() {
    return _this.exec("getLine");
}

Variant RedisException::getTrace() {
    return _this.exec("getTrace");
}

Variant RedisException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant RedisException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant RedisException::__toString() {
    return _this.exec("__toString");
}


}
