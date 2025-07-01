#include "phpx.h"
#include "class/redis.h"

namespace php {
Redis::Redis(const Variant &options) {
    this_ = newObject("Redis", options);
}

Variant Redis::_compress(const Variant &value) {
    return this_.exec("_compress", value);
}

Variant Redis::_uncompress(const Variant &value) {
    return this_.exec("_uncompress", value);
}

Variant Redis::_prefix(const Variant &key) {
    return this_.exec("_prefix", key);
}

Variant Redis::_serialize(const Variant &value) {
    return this_.exec("_serialize", value);
}

Variant Redis::_unserialize(const Variant &value) {
    return this_.exec("_unserialize", value);
}

Variant Redis::_pack(const Variant &value) {
    return this_.exec("_pack", value);
}

Variant Redis::_unpack(const Variant &value) {
    return this_.exec("_unpack", value);
}

Variant Redis::acl(const Variant &subcmd, const Variant &args) {
    return this_.exec("acl", subcmd, args);
}

Variant Redis::append(const Variant &key, const Variant &value) {
    return this_.exec("append", key, value);
}

Variant Redis::auth(const Variant &credentials) {
    return this_.exec("auth", credentials);
}

Variant Redis::bgSave() {
    return this_.exec("bgSave");
}

Variant Redis::bgrewriteaof() {
    return this_.exec("bgrewriteaof");
}

Variant Redis::bitcount(const Variant &key, const Variant &start, const Variant &end, const Variant &bybit) {
    return this_.exec("bitcount", key, start, end, bybit);
}

Variant Redis::bitop(const Variant &operation, const Variant &deskey, const Variant &srckey, const Variant &other_keys) {
    return this_.exec("bitop", operation, deskey, srckey, other_keys);
}

Variant Redis::bitpos(const Variant &key, const Variant &bit, const Variant &start, const Variant &end, const Variant &bybit) {
    return this_.exec("bitpos", key, bit, start, end, bybit);
}

Variant Redis::blPop(const Variant &key_or_keys, const Variant &timeout_or_key, const Variant &extra_args) {
    return this_.exec("blPop", key_or_keys, timeout_or_key, extra_args);
}

Variant Redis::brPop(const Variant &key_or_keys, const Variant &timeout_or_key, const Variant &extra_args) {
    return this_.exec("brPop", key_or_keys, timeout_or_key, extra_args);
}

Variant Redis::brpoplpush(const Variant &src, const Variant &dst, const Variant &timeout) {
    return this_.exec("brpoplpush", src, dst, timeout);
}

Variant Redis::bzPopMax(const Variant &key, const Variant &timeout_or_key, const Variant &extra_args) {
    return this_.exec("bzPopMax", key, timeout_or_key, extra_args);
}

Variant Redis::bzPopMin(const Variant &key, const Variant &timeout_or_key, const Variant &extra_args) {
    return this_.exec("bzPopMin", key, timeout_or_key, extra_args);
}

Variant Redis::bzmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec("bzmpop", timeout, keys, from, count);
}

Variant Redis::zmpop(const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec("zmpop", keys, from, count);
}

Variant Redis::blmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec("blmpop", timeout, keys, from, count);
}

Variant Redis::lmpop(const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec("lmpop", keys, from, count);
}

Variant Redis::clearLastError() {
    return this_.exec("clearLastError");
}

Variant Redis::client(const Variant &opt, const Variant &args) {
    return this_.exec("client", opt, args);
}

Variant Redis::close() {
    return this_.exec("close");
}

Variant Redis::command(const Variant &opt, const Variant &args) {
    return this_.exec("command", opt, args);
}

Variant Redis::config(const Variant &operation, const Variant &key_or_settings, const Variant &value) {
    return this_.exec("config", operation, key_or_settings, value);
}

Variant Redis::connect(const Variant &host, const Variant &port, const Variant &timeout, const Variant &persistent_id, const Variant &retry_interval, const Variant &read_timeout, const Variant &context) {
    return this_.exec("connect", host, port, timeout, persistent_id, retry_interval, read_timeout, context);
}

Variant Redis::copy(const Variant &src, const Variant &dst, const Variant &options) {
    return this_.exec("copy", src, dst, options);
}

Variant Redis::dbSize() {
    return this_.exec("dbSize");
}

Variant Redis::debug(const Variant &key) {
    return this_.exec("debug", key);
}

Variant Redis::decr(const Variant &key, const Variant &by) {
    return this_.exec("decr", key, by);
}

Variant Redis::decrBy(const Variant &key, const Variant &value) {
    return this_.exec("decrBy", key, value);
}

Variant Redis::del(const Variant &key, const Variant &other_keys) {
    return this_.exec("del", key, other_keys);
}

Variant Redis::_delete(const Variant &key, const Variant &other_keys) {
    return this_.exec("delete", key, other_keys);
}

Variant Redis::discard() {
    return this_.exec("discard");
}

Variant Redis::dump(const Variant &key) {
    return this_.exec("dump", key);
}

Variant Redis::echo(const Variant &str) {
    return this_.exec("echo", str);
}

Variant Redis::eval(const Variant &script, const Array &args, const Variant &num_keys) {
    return this_.exec("eval", script, args, num_keys);
}

Variant Redis::eval_ro(const Variant &script_sha, const Array &args, const Variant &num_keys) {
    return this_.exec("eval_ro", script_sha, args, num_keys);
}

Variant Redis::evalsha(const Variant &sha1, const Array &args, const Variant &num_keys) {
    return this_.exec("evalsha", sha1, args, num_keys);
}

Variant Redis::evalsha_ro(const Variant &sha1, const Array &args, const Variant &num_keys) {
    return this_.exec("evalsha_ro", sha1, args, num_keys);
}

Variant Redis::exec() {
    return this_.exec("exec");
}

Variant Redis::exists(const Variant &key, const Variant &other_keys) {
    return this_.exec("exists", key, other_keys);
}

Variant Redis::expire(const Variant &key, const Variant &timeout, const Variant &mode) {
    return this_.exec("expire", key, timeout, mode);
}

Variant Redis::expireAt(const Variant &key, const Variant &timestamp, const Variant &mode) {
    return this_.exec("expireAt", key, timestamp, mode);
}

Variant Redis::failover(const Variant &to, const Variant &abort, const Variant &timeout) {
    return this_.exec("failover", to, abort, timeout);
}

Variant Redis::expiretime(const Variant &key) {
    return this_.exec("expiretime", key);
}

Variant Redis::pexpiretime(const Variant &key) {
    return this_.exec("pexpiretime", key);
}

Variant Redis::fcall(const Variant &fn, const Array &keys, const Array &args) {
    return this_.exec("fcall", fn, keys, args);
}

Variant Redis::fcall_ro(const Variant &fn, const Array &keys, const Array &args) {
    return this_.exec("fcall_ro", fn, keys, args);
}

Variant Redis::flushAll(const Variant &sync) {
    return this_.exec("flushAll", sync);
}

Variant Redis::flushDB(const Variant &sync) {
    return this_.exec("flushDB", sync);
}

Variant Redis::function(const Variant &operation, const Variant &args) {
    return this_.exec("function", operation, args);
}

Variant Redis::geoadd(const Variant &key, const Variant &lng, const Variant &lat, const Variant &member, const Variant &other_triples_and_options) {
    return this_.exec("geoadd", key, lng, lat, member, other_triples_and_options);
}

Variant Redis::geodist(const Variant &key, const Variant &src, const Variant &dst, const Variant &unit) {
    return this_.exec("geodist", key, src, dst, unit);
}

Variant Redis::geohash(const Variant &key, const Variant &member, const Variant &other_members) {
    return this_.exec("geohash", key, member, other_members);
}

Variant Redis::geopos(const Variant &key, const Variant &member, const Variant &other_members) {
    return this_.exec("geopos", key, member, other_members);
}

Variant Redis::georadius(const Variant &key, const Variant &lng, const Variant &lat, const Variant &radius, const Variant &unit, const Array &options) {
    return this_.exec("georadius", key, lng, lat, radius, unit, options);
}

Variant Redis::georadius_ro(const Variant &key, const Variant &lng, const Variant &lat, const Variant &radius, const Variant &unit, const Array &options) {
    return this_.exec("georadius_ro", key, lng, lat, radius, unit, options);
}

Variant Redis::georadiusbymember(const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Array &options) {
    return this_.exec("georadiusbymember", key, member, radius, unit, options);
}

Variant Redis::georadiusbymember_ro(const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Array &options) {
    return this_.exec("georadiusbymember_ro", key, member, radius, unit, options);
}

Variant Redis::geosearch(const Variant &key, const Variant &position, const Variant &shape, const Variant &unit, const Array &options) {
    return this_.exec("geosearch", key, position, shape, unit, options);
}

Variant Redis::geosearchstore(const Variant &dst, const Variant &src, const Variant &position, const Variant &shape, const Variant &unit, const Array &options) {
    return this_.exec("geosearchstore", dst, src, position, shape, unit, options);
}

Variant Redis::get(const Variant &key) {
    return this_.exec("get", key);
}

Variant Redis::getAuth() {
    return this_.exec("getAuth");
}

Variant Redis::getBit(const Variant &key, const Variant &idx) {
    return this_.exec("getBit", key, idx);
}

Variant Redis::getEx(const Variant &key, const Array &options) {
    return this_.exec("getEx", key, options);
}

Variant Redis::getDBNum() {
    return this_.exec("getDBNum");
}

Variant Redis::getDel(const Variant &key) {
    return this_.exec("getDel", key);
}

Variant Redis::getHost() {
    return this_.exec("getHost");
}

Variant Redis::getLastError() {
    return this_.exec("getLastError");
}

Variant Redis::getMode() {
    return this_.exec("getMode");
}

Variant Redis::getOption(const Variant &option) {
    return this_.exec("getOption", option);
}

Variant Redis::getPersistentID() {
    return this_.exec("getPersistentID");
}

Variant Redis::getPort() {
    return this_.exec("getPort");
}

Variant Redis::getRange(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec("getRange", key, start, end);
}

Variant Redis::lcs(const Variant &key1, const Variant &key2, const Variant &options) {
    return this_.exec("lcs", key1, key2, options);
}

Variant Redis::getReadTimeout() {
    return this_.exec("getReadTimeout");
}

Variant Redis::getset(const Variant &key, const Variant &value) {
    return this_.exec("getset", key, value);
}

Variant Redis::getTimeout() {
    return this_.exec("getTimeout");
}

Variant Redis::getTransferredBytes() {
    return this_.exec("getTransferredBytes");
}

Variant Redis::clearTransferredBytes() {
    return this_.exec("clearTransferredBytes");
}

Variant Redis::hDel(const Variant &key, const Variant &field, const Variant &other_fields) {
    return this_.exec("hDel", key, field, other_fields);
}

Variant Redis::hExists(const Variant &key, const Variant &field) {
    return this_.exec("hExists", key, field);
}

Variant Redis::hGet(const Variant &key, const Variant &member) {
    return this_.exec("hGet", key, member);
}

Variant Redis::hGetAll(const Variant &key) {
    return this_.exec("hGetAll", key);
}

Variant Redis::hIncrBy(const Variant &key, const Variant &field, const Variant &value) {
    return this_.exec("hIncrBy", key, field, value);
}

Variant Redis::hIncrByFloat(const Variant &key, const Variant &field, const Variant &value) {
    return this_.exec("hIncrByFloat", key, field, value);
}

Variant Redis::hKeys(const Variant &key) {
    return this_.exec("hKeys", key);
}

Variant Redis::hLen(const Variant &key) {
    return this_.exec("hLen", key);
}

Variant Redis::hMget(const Variant &key, const Variant &fields) {
    return this_.exec("hMget", key, fields);
}

Variant Redis::hMset(const Variant &key, const Variant &fieldvals) {
    return this_.exec("hMset", key, fieldvals);
}

Variant Redis::hRandField(const Variant &key, const Variant &options) {
    return this_.exec("hRandField", key, options);
}

Variant Redis::hSet(const Variant &key, const Variant &member, const Variant &value) {
    return this_.exec("hSet", key, member, value);
}

Variant Redis::hSetNx(const Variant &key, const Variant &field, const Variant &value) {
    return this_.exec("hSetNx", key, field, value);
}

Variant Redis::hStrLen(const Variant &key, const Variant &field) {
    return this_.exec("hStrLen", key, field);
}

Variant Redis::hVals(const Variant &key) {
    return this_.exec("hVals", key);
}

Variant Redis::hscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec("hscan", key, iterator, pattern, count);
}

Variant Redis::incr(const Variant &key, const Variant &by) {
    return this_.exec("incr", key, by);
}

Variant Redis::incrBy(const Variant &key, const Variant &value) {
    return this_.exec("incrBy", key, value);
}

Variant Redis::incrByFloat(const Variant &key, const Variant &value) {
    return this_.exec("incrByFloat", key, value);
}

Variant Redis::info(const Variant &sections) {
    return this_.exec("info", sections);
}

Variant Redis::isConnected() {
    return this_.exec("isConnected");
}

Variant Redis::keys(const Variant &pattern) {
    return this_.exec("keys", pattern);
}

Variant Redis::lInsert(const Variant &key, const Variant &pos, const Variant &pivot, const Variant &value) {
    return this_.exec("lInsert", key, pos, pivot, value);
}

Variant Redis::lLen(const Variant &key) {
    return this_.exec("lLen", key);
}

Variant Redis::lMove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto) {
    return this_.exec("lMove", src, dst, wherefrom, whereto);
}

Variant Redis::blmove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto, const Variant &timeout) {
    return this_.exec("blmove", src, dst, wherefrom, whereto, timeout);
}

Variant Redis::lPop(const Variant &key, const Variant &count) {
    return this_.exec("lPop", key, count);
}

Variant Redis::lPos(const Variant &key, const Variant &value, const Variant &options) {
    return this_.exec("lPos", key, value, options);
}

Variant Redis::lPush(const Variant &key, const Variant &elements) {
    return this_.exec("lPush", key, elements);
}

Variant Redis::rPush(const Variant &key, const Variant &elements) {
    return this_.exec("rPush", key, elements);
}

Variant Redis::lPushx(const Variant &key, const Variant &value) {
    return this_.exec("lPushx", key, value);
}

Variant Redis::rPushx(const Variant &key, const Variant &value) {
    return this_.exec("rPushx", key, value);
}

Variant Redis::lSet(const Variant &key, const Variant &index, const Variant &value) {
    return this_.exec("lSet", key, index, value);
}

Variant Redis::lastSave() {
    return this_.exec("lastSave");
}

Variant Redis::lindex(const Variant &key, const Variant &index) {
    return this_.exec("lindex", key, index);
}

Variant Redis::lrange(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec("lrange", key, start, end);
}

Variant Redis::lrem(const Variant &key, const Variant &value, const Variant &count) {
    return this_.exec("lrem", key, value, count);
}

Variant Redis::ltrim(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec("ltrim", key, start, end);
}

Variant Redis::mget(const Variant &keys) {
    return this_.exec("mget", keys);
}

Variant Redis::migrate(const Variant &host, const Variant &port, const Variant &key, const Variant &dstdb, const Variant &timeout, const Variant &copy, const Variant &replace, const Variant &credentials) {
    return this_.exec("migrate", host, port, key, dstdb, timeout, copy, replace, credentials);
}

Variant Redis::move(const Variant &key, const Variant &index) {
    return this_.exec("move", key, index);
}

Variant Redis::mset(const Variant &key_values) {
    return this_.exec("mset", key_values);
}

Variant Redis::msetnx(const Variant &key_values) {
    return this_.exec("msetnx", key_values);
}

Variant Redis::multi(const Variant &value) {
    return this_.exec("multi", value);
}

Variant Redis::object(const Variant &subcommand, const Variant &key) {
    return this_.exec("object", subcommand, key);
}

Variant Redis::open(const Variant &host, const Variant &port, const Variant &timeout, const Variant &persistent_id, const Variant &retry_interval, const Variant &read_timeout, const Variant &context) {
    return this_.exec("open", host, port, timeout, persistent_id, retry_interval, read_timeout, context);
}

Variant Redis::pconnect(const Variant &host, const Variant &port, const Variant &timeout, const Variant &persistent_id, const Variant &retry_interval, const Variant &read_timeout, const Variant &context) {
    return this_.exec("pconnect", host, port, timeout, persistent_id, retry_interval, read_timeout, context);
}

Variant Redis::persist(const Variant &key) {
    return this_.exec("persist", key);
}

Variant Redis::pexpire(const Variant &key, const Variant &timeout, const Variant &mode) {
    return this_.exec("pexpire", key, timeout, mode);
}

Variant Redis::pexpireAt(const Variant &key, const Variant &timestamp, const Variant &mode) {
    return this_.exec("pexpireAt", key, timestamp, mode);
}

Variant Redis::pfadd(const Variant &key, const Variant &elements) {
    return this_.exec("pfadd", key, elements);
}

Variant Redis::pfcount(const Variant &key_or_keys) {
    return this_.exec("pfcount", key_or_keys);
}

Variant Redis::pfmerge(const Variant &dst, const Variant &srckeys) {
    return this_.exec("pfmerge", dst, srckeys);
}

Variant Redis::ping(const Variant &message) {
    return this_.exec("ping", message);
}

Variant Redis::pipeline() {
    return this_.exec("pipeline");
}

Variant Redis::popen(const Variant &host, const Variant &port, const Variant &timeout, const Variant &persistent_id, const Variant &retry_interval, const Variant &read_timeout, const Variant &context) {
    return this_.exec("popen", host, port, timeout, persistent_id, retry_interval, read_timeout, context);
}

Variant Redis::psetex(const Variant &key, const Variant &expire, const Variant &value) {
    return this_.exec("psetex", key, expire, value);
}

Variant Redis::psubscribe(const Variant &patterns, const Variant &cb) {
    return this_.exec("psubscribe", patterns, cb);
}

Variant Redis::pttl(const Variant &key) {
    return this_.exec("pttl", key);
}

Variant Redis::publish(const Variant &channel, const Variant &message) {
    return this_.exec("publish", channel, message);
}

Variant Redis::pubsub(const Variant &command, const Variant &arg) {
    return this_.exec("pubsub", command, arg);
}

Variant Redis::punsubscribe(const Variant &patterns) {
    return this_.exec("punsubscribe", patterns);
}

Variant Redis::rPop(const Variant &key, const Variant &count) {
    return this_.exec("rPop", key, count);
}

Variant Redis::randomKey() {
    return this_.exec("randomKey");
}

Variant Redis::rawcommand(const Variant &command, const Variant &args) {
    return this_.exec("rawcommand", command, args);
}

Variant Redis::rename(const Variant &old_name, const Variant &new_name) {
    return this_.exec("rename", old_name, new_name);
}

Variant Redis::renameNx(const Variant &key_src, const Variant &key_dst) {
    return this_.exec("renameNx", key_src, key_dst);
}

Variant Redis::reset() {
    return this_.exec("reset");
}

Variant Redis::restore(const Variant &key, const Variant &ttl, const Variant &value, const Variant &options) {
    return this_.exec("restore", key, ttl, value, options);
}

Variant Redis::role() {
    return this_.exec("role");
}

Variant Redis::rpoplpush(const Variant &srckey, const Variant &dstkey) {
    return this_.exec("rpoplpush", srckey, dstkey);
}

Variant Redis::sAdd(const Variant &key, const Variant &value, const Variant &other_values) {
    return this_.exec("sAdd", key, value, other_values);
}

Variant Redis::sAddArray(const Variant &key, const Variant &values) {
    return this_.exec("sAddArray", key, values);
}

Variant Redis::sDiff(const Variant &key, const Variant &other_keys) {
    return this_.exec("sDiff", key, other_keys);
}

Variant Redis::sDiffStore(const Variant &dst, const Variant &key, const Variant &other_keys) {
    return this_.exec("sDiffStore", dst, key, other_keys);
}

Variant Redis::sInter(const Variant &key, const Variant &other_keys) {
    return this_.exec("sInter", key, other_keys);
}

Variant Redis::sintercard(const Variant &keys, const Variant &limit) {
    return this_.exec("sintercard", keys, limit);
}

Variant Redis::sInterStore(const Variant &key, const Variant &other_keys) {
    return this_.exec("sInterStore", key, other_keys);
}

Variant Redis::sMembers(const Variant &key) {
    return this_.exec("sMembers", key);
}

Variant Redis::sMisMember(const Variant &key, const Variant &member, const Variant &other_members) {
    return this_.exec("sMisMember", key, member, other_members);
}

Variant Redis::sMove(const Variant &src, const Variant &dst, const Variant &value) {
    return this_.exec("sMove", src, dst, value);
}

Variant Redis::sPop(const Variant &key, const Variant &count) {
    return this_.exec("sPop", key, count);
}

Variant Redis::sRandMember(const Variant &key, const Variant &count) {
    return this_.exec("sRandMember", key, count);
}

Variant Redis::sUnion(const Variant &key, const Variant &other_keys) {
    return this_.exec("sUnion", key, other_keys);
}

Variant Redis::sUnionStore(const Variant &dst, const Variant &key, const Variant &other_keys) {
    return this_.exec("sUnionStore", dst, key, other_keys);
}

Variant Redis::save() {
    return this_.exec("save");
}

Variant Redis::scan(const Variant &iterator, const Variant &pattern, const Variant &count, const Variant &type) {
    return this_.exec("scan", iterator, pattern, count, type);
}

Variant Redis::scard(const Variant &key) {
    return this_.exec("scard", key);
}

Variant Redis::script(const Variant &command, const Variant &args) {
    return this_.exec("script", command, args);
}

Variant Redis::select(const Variant &db) {
    return this_.exec("select", db);
}

Variant Redis::set(const Variant &key, const Variant &value, const Variant &options) {
    return this_.exec("set", key, value, options);
}

Variant Redis::setBit(const Variant &key, const Variant &idx, const Variant &value) {
    return this_.exec("setBit", key, idx, value);
}

Variant Redis::setRange(const Variant &key, const Variant &index, const Variant &value) {
    return this_.exec("setRange", key, index, value);
}

Variant Redis::setOption(const Variant &option, const Variant &value) {
    return this_.exec("setOption", option, value);
}

Variant Redis::setex(const Variant &key, const Variant &expire, const Variant &value) {
    return this_.exec("setex", key, expire, value);
}

Variant Redis::setnx(const Variant &key, const Variant &value) {
    return this_.exec("setnx", key, value);
}

Variant Redis::sismember(const Variant &key, const Variant &value) {
    return this_.exec("sismember", key, value);
}

Variant Redis::slaveof(const Variant &host, const Variant &port) {
    return this_.exec("slaveof", host, port);
}

Variant Redis::replicaof(const Variant &host, const Variant &port) {
    return this_.exec("replicaof", host, port);
}

Variant Redis::touch(const Variant &key_or_array, const Variant &more_keys) {
    return this_.exec("touch", key_or_array, more_keys);
}

Variant Redis::slowlog(const Variant &operation, const Variant &length) {
    return this_.exec("slowlog", operation, length);
}

Variant Redis::sort(const Variant &key, const Variant &options) {
    return this_.exec("sort", key, options);
}

Variant Redis::sort_ro(const Variant &key, const Variant &options) {
    return this_.exec("sort_ro", key, options);
}

Variant Redis::sortAsc(const Variant &key, const Variant &pattern, const Variant &get, const Variant &offset, const Variant &count, const Variant &store) {
    return this_.exec("sortAsc", key, pattern, get, offset, count, store);
}

Variant Redis::sortAscAlpha(const Variant &key, const Variant &pattern, const Variant &get, const Variant &offset, const Variant &count, const Variant &store) {
    return this_.exec("sortAscAlpha", key, pattern, get, offset, count, store);
}

Variant Redis::sortDesc(const Variant &key, const Variant &pattern, const Variant &get, const Variant &offset, const Variant &count, const Variant &store) {
    return this_.exec("sortDesc", key, pattern, get, offset, count, store);
}

Variant Redis::sortDescAlpha(const Variant &key, const Variant &pattern, const Variant &get, const Variant &offset, const Variant &count, const Variant &store) {
    return this_.exec("sortDescAlpha", key, pattern, get, offset, count, store);
}

Variant Redis::srem(const Variant &key, const Variant &value, const Variant &other_values) {
    return this_.exec("srem", key, value, other_values);
}

Variant Redis::sscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec("sscan", key, iterator, pattern, count);
}

Variant Redis::ssubscribe(const Variant &channels, const Variant &cb) {
    return this_.exec("ssubscribe", channels, cb);
}

Variant Redis::strlen(const Variant &key) {
    return this_.exec("strlen", key);
}

Variant Redis::subscribe(const Variant &channels, const Variant &cb) {
    return this_.exec("subscribe", channels, cb);
}

Variant Redis::sunsubscribe(const Variant &channels) {
    return this_.exec("sunsubscribe", channels);
}

Variant Redis::swapdb(const Variant &src, const Variant &dst) {
    return this_.exec("swapdb", src, dst);
}

Variant Redis::time() {
    return this_.exec("time");
}

Variant Redis::ttl(const Variant &key) {
    return this_.exec("ttl", key);
}

Variant Redis::type(const Variant &key) {
    return this_.exec("type", key);
}

Variant Redis::unlink(const Variant &key, const Variant &other_keys) {
    return this_.exec("unlink", key, other_keys);
}

Variant Redis::unsubscribe(const Variant &channels) {
    return this_.exec("unsubscribe", channels);
}

Variant Redis::unwatch() {
    return this_.exec("unwatch");
}

Variant Redis::watch(const Variant &key, const Variant &other_keys) {
    return this_.exec("watch", key, other_keys);
}

Variant Redis::wait(const Variant &numreplicas, const Variant &timeout) {
    return this_.exec("wait", numreplicas, timeout);
}

Variant Redis::xack(const Variant &key, const Variant &group, const Variant &ids) {
    return this_.exec("xack", key, group, ids);
}

Variant Redis::xadd(const Variant &key, const Variant &id, const Variant &values, const Variant &maxlen, const Variant &approx, const Variant &nomkstream) {
    return this_.exec("xadd", key, id, values, maxlen, approx, nomkstream);
}

Variant Redis::xautoclaim(const Variant &key, const Variant &group, const Variant &consumer, const Variant &min_idle, const Variant &start, const Variant &count, const Variant &justid) {
    return this_.exec("xautoclaim", key, group, consumer, min_idle, start, count, justid);
}

Variant Redis::xclaim(const Variant &key, const Variant &group, const Variant &consumer, const Variant &min_idle, const Variant &ids, const Variant &options) {
    return this_.exec("xclaim", key, group, consumer, min_idle, ids, options);
}

Variant Redis::xdel(const Variant &key, const Variant &ids) {
    return this_.exec("xdel", key, ids);
}

Variant Redis::xgroup(const Variant &operation, const Variant &key, const Variant &group, const Variant &id_or_consumer, const Variant &mkstream, const Variant &entries_read) {
    return this_.exec("xgroup", operation, key, group, id_or_consumer, mkstream, entries_read);
}

Variant Redis::xinfo(const Variant &operation, const Variant &arg1, const Variant &arg2, const Variant &count) {
    return this_.exec("xinfo", operation, arg1, arg2, count);
}

Variant Redis::xlen(const Variant &key) {
    return this_.exec("xlen", key);
}

Variant Redis::xpending(const Variant &key, const Variant &group, const Variant &start, const Variant &end, const Variant &count, const Variant &consumer) {
    return this_.exec("xpending", key, group, start, end, count, consumer);
}

Variant Redis::xrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count) {
    return this_.exec("xrange", key, start, end, count);
}

Variant Redis::xread(const Variant &streams, const Variant &count, const Variant &block) {
    return this_.exec("xread", streams, count, block);
}

Variant Redis::xreadgroup(const Variant &group, const Variant &consumer, const Variant &streams, const Variant &count, const Variant &block) {
    return this_.exec("xreadgroup", group, consumer, streams, count, block);
}

Variant Redis::xrevrange(const Variant &key, const Variant &end, const Variant &start, const Variant &count) {
    return this_.exec("xrevrange", key, end, start, count);
}

Variant Redis::xtrim(const Variant &key, const Variant &threshold, const Variant &approx, const Variant &minid, const Variant &limit) {
    return this_.exec("xtrim", key, threshold, approx, minid, limit);
}

Variant Redis::zAdd(const Variant &key, const Variant &score_or_options, const Variant &more_scores_and_mems) {
    return this_.exec("zAdd", key, score_or_options, more_scores_and_mems);
}

Variant Redis::zCard(const Variant &key) {
    return this_.exec("zCard", key);
}

Variant Redis::zCount(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec("zCount", key, start, end);
}

Variant Redis::zIncrBy(const Variant &key, const Variant &value, const Variant &member) {
    return this_.exec("zIncrBy", key, value, member);
}

Variant Redis::zLexCount(const Variant &key, const Variant &min, const Variant &max) {
    return this_.exec("zLexCount", key, min, max);
}

Variant Redis::zMscore(const Variant &key, const Variant &member, const Variant &other_members) {
    return this_.exec("zMscore", key, member, other_members);
}

Variant Redis::zPopMax(const Variant &key, const Variant &count) {
    return this_.exec("zPopMax", key, count);
}

Variant Redis::zPopMin(const Variant &key, const Variant &count) {
    return this_.exec("zPopMin", key, count);
}

Variant Redis::zRange(const Variant &key, const Variant &start, const Variant &end, const Variant &options) {
    return this_.exec("zRange", key, start, end, options);
}

Variant Redis::zRangeByLex(const Variant &key, const Variant &min, const Variant &max, const Variant &offset, const Variant &count) {
    return this_.exec("zRangeByLex", key, min, max, offset, count);
}

Variant Redis::zRangeByScore(const Variant &key, const Variant &start, const Variant &end, const Array &options) {
    return this_.exec("zRangeByScore", key, start, end, options);
}

Variant Redis::zrangestore(const Variant &dstkey, const Variant &srckey, const Variant &start, const Variant &end, const Variant &options) {
    return this_.exec("zrangestore", dstkey, srckey, start, end, options);
}

Variant Redis::zRandMember(const Variant &key, const Variant &options) {
    return this_.exec("zRandMember", key, options);
}

Variant Redis::zRank(const Variant &key, const Variant &member) {
    return this_.exec("zRank", key, member);
}

Variant Redis::zRem(const Variant &key, const Variant &member, const Variant &other_members) {
    return this_.exec("zRem", key, member, other_members);
}

Variant Redis::zRemRangeByLex(const Variant &key, const Variant &min, const Variant &max) {
    return this_.exec("zRemRangeByLex", key, min, max);
}

Variant Redis::zRemRangeByRank(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec("zRemRangeByRank", key, start, end);
}

Variant Redis::zRemRangeByScore(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec("zRemRangeByScore", key, start, end);
}

Variant Redis::zRevRange(const Variant &key, const Variant &start, const Variant &end, const Variant &scores) {
    return this_.exec("zRevRange", key, start, end, scores);
}

Variant Redis::zRevRangeByLex(const Variant &key, const Variant &max, const Variant &min, const Variant &offset, const Variant &count) {
    return this_.exec("zRevRangeByLex", key, max, min, offset, count);
}

Variant Redis::zRevRangeByScore(const Variant &key, const Variant &max, const Variant &min, const Array &options) {
    return this_.exec("zRevRangeByScore", key, max, min, options);
}

Variant Redis::zRevRank(const Variant &key, const Variant &member) {
    return this_.exec("zRevRank", key, member);
}

Variant Redis::zScore(const Variant &key, const Variant &member) {
    return this_.exec("zScore", key, member);
}

Variant Redis::zdiff(const Variant &keys, const Variant &options) {
    return this_.exec("zdiff", keys, options);
}

Variant Redis::zdiffstore(const Variant &dst, const Variant &keys) {
    return this_.exec("zdiffstore", dst, keys);
}

Variant Redis::zinter(const Variant &keys, const Variant &weights, const Variant &options) {
    return this_.exec("zinter", keys, weights, options);
}

Variant Redis::zintercard(const Variant &keys, const Variant &limit) {
    return this_.exec("zintercard", keys, limit);
}

Variant Redis::zinterstore(const Variant &dst, const Variant &keys, const Variant &weights, const Variant &aggregate) {
    return this_.exec("zinterstore", dst, keys, weights, aggregate);
}

Variant Redis::zscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec("zscan", key, iterator, pattern, count);
}

Variant Redis::zunion(const Variant &keys, const Variant &weights, const Variant &options) {
    return this_.exec("zunion", keys, weights, options);
}

Variant Redis::zunionstore(const Variant &dst, const Variant &keys, const Variant &weights, const Variant &aggregate) {
    return this_.exec("zunionstore", dst, keys, weights, aggregate);
}


Variant RedisArray::__call(const Variant &function_name, const Variant &arguments) {
    return this_.exec("__call", function_name, arguments);
}

RedisArray::RedisArray(const Variant &name_or_hosts, const Variant &options) {
    this_ = newObject("RedisArray", name_or_hosts, options);
}

Variant RedisArray::_continuum() {
    return this_.exec("_continuum");
}

Variant RedisArray::_distributor() {
    return this_.exec("_distributor");
}

Variant RedisArray::_function() {
    return this_.exec("_function");
}

Variant RedisArray::_hosts() {
    return this_.exec("_hosts");
}

Variant RedisArray::_instance(const Variant &host) {
    return this_.exec("_instance", host);
}

Variant RedisArray::_rehash(const Variant &fn) {
    return this_.exec("_rehash", fn);
}

Variant RedisArray::_target(const Variant &key) {
    return this_.exec("_target", key);
}

Variant RedisArray::bgsave() {
    return this_.exec("bgsave");
}

Variant RedisArray::del(const Variant &key, const Variant &otherkeys) {
    return this_.exec("del", key, otherkeys);
}

Variant RedisArray::discard() {
    return this_.exec("discard");
}

Variant RedisArray::exec() {
    return this_.exec("exec");
}

Variant RedisArray::flushall() {
    return this_.exec("flushall");
}

Variant RedisArray::flushdb() {
    return this_.exec("flushdb");
}

Variant RedisArray::getOption(const Variant &opt) {
    return this_.exec("getOption", opt);
}

Variant RedisArray::hscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec("hscan", key, iterator, pattern, count);
}

Variant RedisArray::info() {
    return this_.exec("info");
}

Variant RedisArray::keys(const Variant &pattern) {
    return this_.exec("keys", pattern);
}

Variant RedisArray::mget(const Variant &keys) {
    return this_.exec("mget", keys);
}

Variant RedisArray::mset(const Variant &pairs) {
    return this_.exec("mset", pairs);
}

Variant RedisArray::multi(const Variant &host, const Variant &mode) {
    return this_.exec("multi", host, mode);
}

Variant RedisArray::ping() {
    return this_.exec("ping");
}

Variant RedisArray::save() {
    return this_.exec("save");
}

Variant RedisArray::scan(const Variant &iterator, const Variant &node, const Variant &pattern, const Variant &count) {
    return this_.exec("scan", iterator, node, pattern, count);
}

Variant RedisArray::select(const Variant &index) {
    return this_.exec("select", index);
}

Variant RedisArray::setOption(const Variant &opt, const Variant &value) {
    return this_.exec("setOption", opt, value);
}

Variant RedisArray::sscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec("sscan", key, iterator, pattern, count);
}

Variant RedisArray::unlink(const Variant &key, const Variant &otherkeys) {
    return this_.exec("unlink", key, otherkeys);
}

Variant RedisArray::unwatch() {
    return this_.exec("unwatch");
}

Variant RedisArray::zscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec("zscan", key, iterator, pattern, count);
}


RedisCluster::RedisCluster(const Variant &name, const Variant &seeds, const Variant &timeout, const Variant &read_timeout, const Variant &persistent, const Variant &auth, const Variant &context) {
    this_ = newObject("RedisCluster", name, seeds, timeout, read_timeout, persistent, auth, context);
}

Variant RedisCluster::_compress(const Variant &value) {
    return this_.exec("_compress", value);
}

Variant RedisCluster::_uncompress(const Variant &value) {
    return this_.exec("_uncompress", value);
}

Variant RedisCluster::_serialize(const Variant &value) {
    return this_.exec("_serialize", value);
}

Variant RedisCluster::_unserialize(const Variant &value) {
    return this_.exec("_unserialize", value);
}

Variant RedisCluster::_pack(const Variant &value) {
    return this_.exec("_pack", value);
}

Variant RedisCluster::_unpack(const Variant &value) {
    return this_.exec("_unpack", value);
}

Variant RedisCluster::_prefix(const Variant &key) {
    return this_.exec("_prefix", key);
}

Variant RedisCluster::_masters() {
    return this_.exec("_masters");
}

Variant RedisCluster::_redir() {
    return this_.exec("_redir");
}

Variant RedisCluster::acl(const Variant &key_or_address, const Variant &subcmd, const Variant &args) {
    return this_.exec("acl", key_or_address, subcmd, args);
}

Variant RedisCluster::append(const Variant &key, const Variant &value) {
    return this_.exec("append", key, value);
}

Variant RedisCluster::bgrewriteaof(const Variant &key_or_address) {
    return this_.exec("bgrewriteaof", key_or_address);
}

Variant RedisCluster::bgsave(const Variant &key_or_address) {
    return this_.exec("bgsave", key_or_address);
}

Variant RedisCluster::bitcount(const Variant &key, const Variant &start, const Variant &end, const Variant &bybit) {
    return this_.exec("bitcount", key, start, end, bybit);
}

Variant RedisCluster::bitop(const Variant &operation, const Variant &deskey, const Variant &srckey, const Variant &otherkeys) {
    return this_.exec("bitop", operation, deskey, srckey, otherkeys);
}

Variant RedisCluster::bitpos(const Variant &key, const Variant &bit, const Variant &start, const Variant &end, const Variant &bybit) {
    return this_.exec("bitpos", key, bit, start, end, bybit);
}

Variant RedisCluster::blpop(const Variant &key, const Variant &timeout_or_key, const Variant &extra_args) {
    return this_.exec("blpop", key, timeout_or_key, extra_args);
}

Variant RedisCluster::brpop(const Variant &key, const Variant &timeout_or_key, const Variant &extra_args) {
    return this_.exec("brpop", key, timeout_or_key, extra_args);
}

Variant RedisCluster::brpoplpush(const Variant &srckey, const Variant &deskey, const Variant &timeout) {
    return this_.exec("brpoplpush", srckey, deskey, timeout);
}

Variant RedisCluster::lmove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto) {
    return this_.exec("lmove", src, dst, wherefrom, whereto);
}

Variant RedisCluster::blmove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto, const Variant &timeout) {
    return this_.exec("blmove", src, dst, wherefrom, whereto, timeout);
}

Variant RedisCluster::bzpopmax(const Variant &key, const Variant &timeout_or_key, const Variant &extra_args) {
    return this_.exec("bzpopmax", key, timeout_or_key, extra_args);
}

Variant RedisCluster::bzpopmin(const Variant &key, const Variant &timeout_or_key, const Variant &extra_args) {
    return this_.exec("bzpopmin", key, timeout_or_key, extra_args);
}

Variant RedisCluster::bzmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec("bzmpop", timeout, keys, from, count);
}

Variant RedisCluster::zmpop(const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec("zmpop", keys, from, count);
}

Variant RedisCluster::blmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec("blmpop", timeout, keys, from, count);
}

Variant RedisCluster::lmpop(const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec("lmpop", keys, from, count);
}

Variant RedisCluster::clearlasterror() {
    return this_.exec("clearlasterror");
}

Variant RedisCluster::client(const Variant &key_or_address, const Variant &subcommand, const Variant &arg) {
    return this_.exec("client", key_or_address, subcommand, arg);
}

Variant RedisCluster::close() {
    return this_.exec("close");
}

Variant RedisCluster::cluster(const Variant &key_or_address, const Variant &command, const Variant &extra_args) {
    return this_.exec("cluster", key_or_address, command, extra_args);
}

Variant RedisCluster::command(const Variant &extra_args) {
    return this_.exec("command", extra_args);
}

Variant RedisCluster::config(const Variant &key_or_address, const Variant &subcommand, const Variant &extra_args) {
    return this_.exec("config", key_or_address, subcommand, extra_args);
}

Variant RedisCluster::dbsize(const Variant &key_or_address) {
    return this_.exec("dbsize", key_or_address);
}

Variant RedisCluster::copy(const Variant &src, const Variant &dst, const Variant &options) {
    return this_.exec("copy", src, dst, options);
}

Variant RedisCluster::decr(const Variant &key, const Variant &by) {
    return this_.exec("decr", key, by);
}

Variant RedisCluster::decrby(const Variant &key, const Variant &value) {
    return this_.exec("decrby", key, value);
}

Variant RedisCluster::decrbyfloat(const Variant &key, const Variant &value) {
    return this_.exec("decrbyfloat", key, value);
}

Variant RedisCluster::del(const Variant &key, const Variant &other_keys) {
    return this_.exec("del", key, other_keys);
}

Variant RedisCluster::discard() {
    return this_.exec("discard");
}

Variant RedisCluster::dump(const Variant &key) {
    return this_.exec("dump", key);
}

Variant RedisCluster::echo(const Variant &key_or_address, const Variant &msg) {
    return this_.exec("echo", key_or_address, msg);
}

Variant RedisCluster::eval(const Variant &script, const Array &args, const Variant &num_keys) {
    return this_.exec("eval", script, args, num_keys);
}

Variant RedisCluster::eval_ro(const Variant &script, const Array &args, const Variant &num_keys) {
    return this_.exec("eval_ro", script, args, num_keys);
}

Variant RedisCluster::evalsha(const Variant &script_sha, const Array &args, const Variant &num_keys) {
    return this_.exec("evalsha", script_sha, args, num_keys);
}

Variant RedisCluster::evalsha_ro(const Variant &script_sha, const Array &args, const Variant &num_keys) {
    return this_.exec("evalsha_ro", script_sha, args, num_keys);
}

Variant RedisCluster::exec() {
    return this_.exec("exec");
}

Variant RedisCluster::exists(const Variant &key, const Variant &other_keys) {
    return this_.exec("exists", key, other_keys);
}

Variant RedisCluster::touch(const Variant &key, const Variant &other_keys) {
    return this_.exec("touch", key, other_keys);
}

Variant RedisCluster::expire(const Variant &key, const Variant &timeout, const Variant &mode) {
    return this_.exec("expire", key, timeout, mode);
}

Variant RedisCluster::expireat(const Variant &key, const Variant &timestamp, const Variant &mode) {
    return this_.exec("expireat", key, timestamp, mode);
}

Variant RedisCluster::expiretime(const Variant &key) {
    return this_.exec("expiretime", key);
}

Variant RedisCluster::pexpiretime(const Variant &key) {
    return this_.exec("pexpiretime", key);
}

Variant RedisCluster::flushall(const Variant &key_or_address, const Variant &async) {
    return this_.exec("flushall", key_or_address, async);
}

Variant RedisCluster::flushdb(const Variant &key_or_address, const Variant &async) {
    return this_.exec("flushdb", key_or_address, async);
}

Variant RedisCluster::geoadd(const Variant &key, const Variant &lng, const Variant &lat, const Variant &member, const Variant &other_triples_and_options) {
    return this_.exec("geoadd", key, lng, lat, member, other_triples_and_options);
}

Variant RedisCluster::geodist(const Variant &key, const Variant &src, const Variant &dest, const Variant &unit) {
    return this_.exec("geodist", key, src, dest, unit);
}

Variant RedisCluster::geohash(const Variant &key, const Variant &member, const Variant &other_members) {
    return this_.exec("geohash", key, member, other_members);
}

Variant RedisCluster::geopos(const Variant &key, const Variant &member, const Variant &other_members) {
    return this_.exec("geopos", key, member, other_members);
}

Variant RedisCluster::georadius(const Variant &key, const Variant &lng, const Variant &lat, const Variant &radius, const Variant &unit, const Array &options) {
    return this_.exec("georadius", key, lng, lat, radius, unit, options);
}

Variant RedisCluster::georadius_ro(const Variant &key, const Variant &lng, const Variant &lat, const Variant &radius, const Variant &unit, const Array &options) {
    return this_.exec("georadius_ro", key, lng, lat, radius, unit, options);
}

Variant RedisCluster::georadiusbymember(const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Array &options) {
    return this_.exec("georadiusbymember", key, member, radius, unit, options);
}

Variant RedisCluster::georadiusbymember_ro(const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Array &options) {
    return this_.exec("georadiusbymember_ro", key, member, radius, unit, options);
}

Variant RedisCluster::geosearch(const Variant &key, const Variant &position, const Variant &shape, const Variant &unit, const Array &options) {
    return this_.exec("geosearch", key, position, shape, unit, options);
}

Variant RedisCluster::geosearchstore(const Variant &dst, const Variant &src, const Variant &position, const Variant &shape, const Variant &unit, const Array &options) {
    return this_.exec("geosearchstore", dst, src, position, shape, unit, options);
}

Variant RedisCluster::get(const Variant &key) {
    return this_.exec("get", key);
}

Variant RedisCluster::getbit(const Variant &key, const Variant &value) {
    return this_.exec("getbit", key, value);
}

Variant RedisCluster::getlasterror() {
    return this_.exec("getlasterror");
}

Variant RedisCluster::getmode() {
    return this_.exec("getmode");
}

Variant RedisCluster::getoption(const Variant &option) {
    return this_.exec("getoption", option);
}

Variant RedisCluster::getrange(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec("getrange", key, start, end);
}

Variant RedisCluster::lcs(const Variant &key1, const Variant &key2, const Variant &options) {
    return this_.exec("lcs", key1, key2, options);
}

Variant RedisCluster::getset(const Variant &key, const Variant &value) {
    return this_.exec("getset", key, value);
}

Variant RedisCluster::gettransferredbytes() {
    return this_.exec("gettransferredbytes");
}

Variant RedisCluster::cleartransferredbytes() {
    return this_.exec("cleartransferredbytes");
}

Variant RedisCluster::hdel(const Variant &key, const Variant &member, const Variant &other_members) {
    return this_.exec("hdel", key, member, other_members);
}

Variant RedisCluster::hexists(const Variant &key, const Variant &member) {
    return this_.exec("hexists", key, member);
}

Variant RedisCluster::hget(const Variant &key, const Variant &member) {
    return this_.exec("hget", key, member);
}

Variant RedisCluster::hgetall(const Variant &key) {
    return this_.exec("hgetall", key);
}

Variant RedisCluster::hincrby(const Variant &key, const Variant &member, const Variant &value) {
    return this_.exec("hincrby", key, member, value);
}

Variant RedisCluster::hincrbyfloat(const Variant &key, const Variant &member, const Variant &value) {
    return this_.exec("hincrbyfloat", key, member, value);
}

Variant RedisCluster::hkeys(const Variant &key) {
    return this_.exec("hkeys", key);
}

Variant RedisCluster::hlen(const Variant &key) {
    return this_.exec("hlen", key);
}

Variant RedisCluster::hmget(const Variant &key, const Variant &keys) {
    return this_.exec("hmget", key, keys);
}

Variant RedisCluster::hmset(const Variant &key, const Variant &key_values) {
    return this_.exec("hmset", key, key_values);
}

Variant RedisCluster::hscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec("hscan", key, iterator, pattern, count);
}

Variant RedisCluster::hrandfield(const Variant &key, const Variant &options) {
    return this_.exec("hrandfield", key, options);
}

Variant RedisCluster::hset(const Variant &key, const Variant &member, const Variant &value) {
    return this_.exec("hset", key, member, value);
}

Variant RedisCluster::hsetnx(const Variant &key, const Variant &member, const Variant &value) {
    return this_.exec("hsetnx", key, member, value);
}

Variant RedisCluster::hstrlen(const Variant &key, const Variant &field) {
    return this_.exec("hstrlen", key, field);
}

Variant RedisCluster::hvals(const Variant &key) {
    return this_.exec("hvals", key);
}

Variant RedisCluster::incr(const Variant &key, const Variant &by) {
    return this_.exec("incr", key, by);
}

Variant RedisCluster::incrby(const Variant &key, const Variant &value) {
    return this_.exec("incrby", key, value);
}

Variant RedisCluster::incrbyfloat(const Variant &key, const Variant &value) {
    return this_.exec("incrbyfloat", key, value);
}

Variant RedisCluster::info(const Variant &key_or_address, const Variant &sections) {
    return this_.exec("info", key_or_address, sections);
}

Variant RedisCluster::keys(const Variant &pattern) {
    return this_.exec("keys", pattern);
}

Variant RedisCluster::lastsave(const Variant &key_or_address) {
    return this_.exec("lastsave", key_or_address);
}

Variant RedisCluster::lget(const Variant &key, const Variant &index) {
    return this_.exec("lget", key, index);
}

Variant RedisCluster::lindex(const Variant &key, const Variant &index) {
    return this_.exec("lindex", key, index);
}

Variant RedisCluster::linsert(const Variant &key, const Variant &pos, const Variant &pivot, const Variant &value) {
    return this_.exec("linsert", key, pos, pivot, value);
}

Variant RedisCluster::llen(const Variant &key) {
    return this_.exec("llen", key);
}

Variant RedisCluster::lpop(const Variant &key, const Variant &count) {
    return this_.exec("lpop", key, count);
}

Variant RedisCluster::lpos(const Variant &key, const Variant &value, const Variant &options) {
    return this_.exec("lpos", key, value, options);
}

Variant RedisCluster::lpush(const Variant &key, const Variant &value, const Variant &other_values) {
    return this_.exec("lpush", key, value, other_values);
}

Variant RedisCluster::lpushx(const Variant &key, const Variant &value) {
    return this_.exec("lpushx", key, value);
}

Variant RedisCluster::lrange(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec("lrange", key, start, end);
}

Variant RedisCluster::lrem(const Variant &key, const Variant &value, const Variant &count) {
    return this_.exec("lrem", key, value, count);
}

Variant RedisCluster::lset(const Variant &key, const Variant &index, const Variant &value) {
    return this_.exec("lset", key, index, value);
}

Variant RedisCluster::ltrim(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec("ltrim", key, start, end);
}

Variant RedisCluster::mget(const Variant &keys) {
    return this_.exec("mget", keys);
}

Variant RedisCluster::mset(const Variant &key_values) {
    return this_.exec("mset", key_values);
}

Variant RedisCluster::msetnx(const Variant &key_values) {
    return this_.exec("msetnx", key_values);
}

Variant RedisCluster::multi(const Variant &value) {
    return this_.exec("multi", value);
}

Variant RedisCluster::object(const Variant &subcommand, const Variant &key) {
    return this_.exec("object", subcommand, key);
}

Variant RedisCluster::persist(const Variant &key) {
    return this_.exec("persist", key);
}

Variant RedisCluster::pexpire(const Variant &key, const Variant &timeout, const Variant &mode) {
    return this_.exec("pexpire", key, timeout, mode);
}

Variant RedisCluster::pexpireat(const Variant &key, const Variant &timestamp, const Variant &mode) {
    return this_.exec("pexpireat", key, timestamp, mode);
}

Variant RedisCluster::pfadd(const Variant &key, const Variant &elements) {
    return this_.exec("pfadd", key, elements);
}

Variant RedisCluster::pfcount(const Variant &key) {
    return this_.exec("pfcount", key);
}

Variant RedisCluster::pfmerge(const Variant &key, const Variant &keys) {
    return this_.exec("pfmerge", key, keys);
}

Variant RedisCluster::ping(const Variant &key_or_address, const Variant &message) {
    return this_.exec("ping", key_or_address, message);
}

Variant RedisCluster::psetex(const Variant &key, const Variant &timeout, const Variant &value) {
    return this_.exec("psetex", key, timeout, value);
}

Variant RedisCluster::psubscribe(const Variant &patterns, const Variant &callback) {
    return this_.exec("psubscribe", patterns, callback);
}

Variant RedisCluster::pttl(const Variant &key) {
    return this_.exec("pttl", key);
}

Variant RedisCluster::publish(const Variant &channel, const Variant &message) {
    return this_.exec("publish", channel, message);
}

Variant RedisCluster::pubsub(const Variant &key_or_address, const Variant &values) {
    return this_.exec("pubsub", key_or_address, values);
}

Variant RedisCluster::punsubscribe(const Variant &pattern, const Variant &other_patterns) {
    return this_.exec("punsubscribe", pattern, other_patterns);
}

Variant RedisCluster::randomkey(const Variant &key_or_address) {
    return this_.exec("randomkey", key_or_address);
}

Variant RedisCluster::rawcommand(const Variant &key_or_address, const Variant &command, const Variant &args) {
    return this_.exec("rawcommand", key_or_address, command, args);
}

Variant RedisCluster::rename(const Variant &key_src, const Variant &key_dst) {
    return this_.exec("rename", key_src, key_dst);
}

Variant RedisCluster::renamenx(const Variant &key, const Variant &newkey) {
    return this_.exec("renamenx", key, newkey);
}

Variant RedisCluster::restore(const Variant &key, const Variant &timeout, const Variant &value, const Variant &options) {
    return this_.exec("restore", key, timeout, value, options);
}

Variant RedisCluster::role(const Variant &key_or_address) {
    return this_.exec("role", key_or_address);
}

Variant RedisCluster::rpop(const Variant &key, const Variant &count) {
    return this_.exec("rpop", key, count);
}

Variant RedisCluster::rpoplpush(const Variant &src, const Variant &dst) {
    return this_.exec("rpoplpush", src, dst);
}

Variant RedisCluster::rpush(const Variant &key, const Variant &elements) {
    return this_.exec("rpush", key, elements);
}

Variant RedisCluster::rpushx(const Variant &key, const Variant &value) {
    return this_.exec("rpushx", key, value);
}

Variant RedisCluster::sadd(const Variant &key, const Variant &value, const Variant &other_values) {
    return this_.exec("sadd", key, value, other_values);
}

Variant RedisCluster::saddarray(const Variant &key, const Variant &values) {
    return this_.exec("saddarray", key, values);
}

Variant RedisCluster::save(const Variant &key_or_address) {
    return this_.exec("save", key_or_address);
}

Variant RedisCluster::scan(const Variant &iterator, const Variant &key_or_address, const Variant &pattern, const Variant &count) {
    return this_.exec("scan", iterator, key_or_address, pattern, count);
}

Variant RedisCluster::scard(const Variant &key) {
    return this_.exec("scard", key);
}

Variant RedisCluster::script(const Variant &key_or_address, const Variant &args) {
    return this_.exec("script", key_or_address, args);
}

Variant RedisCluster::sdiff(const Variant &key, const Variant &other_keys) {
    return this_.exec("sdiff", key, other_keys);
}

Variant RedisCluster::sdiffstore(const Variant &dst, const Variant &key, const Variant &other_keys) {
    return this_.exec("sdiffstore", dst, key, other_keys);
}

Variant RedisCluster::set(const Variant &key, const Variant &value, const Variant &options) {
    return this_.exec("set", key, value, options);
}

Variant RedisCluster::_setbit(const Variant &key, const Variant &offset, const Variant &onoff) {
    return this_.exec("setbit", key, offset, onoff);
}

Variant RedisCluster::setex(const Variant &key, const Variant &expire, const Variant &value) {
    return this_.exec("setex", key, expire, value);
}

Variant RedisCluster::setnx(const Variant &key, const Variant &value) {
    return this_.exec("setnx", key, value);
}

Variant RedisCluster::setoption(const Variant &option, const Variant &value) {
    return this_.exec("setoption", option, value);
}

Variant RedisCluster::setrange(const Variant &key, const Variant &offset, const Variant &value) {
    return this_.exec("setrange", key, offset, value);
}

Variant RedisCluster::sinter(const Variant &key, const Variant &other_keys) {
    return this_.exec("sinter", key, other_keys);
}

Variant RedisCluster::sintercard(const Variant &keys, const Variant &limit) {
    return this_.exec("sintercard", keys, limit);
}

Variant RedisCluster::sinterstore(const Variant &key, const Variant &other_keys) {
    return this_.exec("sinterstore", key, other_keys);
}

Variant RedisCluster::sismember(const Variant &key, const Variant &value) {
    return this_.exec("sismember", key, value);
}

Variant RedisCluster::smismember(const Variant &key, const Variant &member, const Variant &other_members) {
    return this_.exec("smismember", key, member, other_members);
}

Variant RedisCluster::slowlog(const Variant &key_or_address, const Variant &args) {
    return this_.exec("slowlog", key_or_address, args);
}

Variant RedisCluster::smembers(const Variant &key) {
    return this_.exec("smembers", key);
}

Variant RedisCluster::smove(const Variant &src, const Variant &dst, const Variant &member) {
    return this_.exec("smove", src, dst, member);
}

Variant RedisCluster::sort(const Variant &key, const Variant &options) {
    return this_.exec("sort", key, options);
}

Variant RedisCluster::sort_ro(const Variant &key, const Variant &options) {
    return this_.exec("sort_ro", key, options);
}

Variant RedisCluster::spop(const Variant &key, const Variant &count) {
    return this_.exec("spop", key, count);
}

Variant RedisCluster::srandmember(const Variant &key, const Variant &count) {
    return this_.exec("srandmember", key, count);
}

Variant RedisCluster::srem(const Variant &key, const Variant &value, const Variant &other_values) {
    return this_.exec("srem", key, value, other_values);
}

Variant RedisCluster::sscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec("sscan", key, iterator, pattern, count);
}

Variant RedisCluster::strlen(const Variant &key) {
    return this_.exec("strlen", key);
}

Variant RedisCluster::subscribe(const Variant &channels, const Variant &cb) {
    return this_.exec("subscribe", channels, cb);
}

Variant RedisCluster::sunion(const Variant &key, const Variant &other_keys) {
    return this_.exec("sunion", key, other_keys);
}

Variant RedisCluster::sunionstore(const Variant &dst, const Variant &key, const Variant &other_keys) {
    return this_.exec("sunionstore", dst, key, other_keys);
}

Variant RedisCluster::time(const Variant &key_or_address) {
    return this_.exec("time", key_or_address);
}

Variant RedisCluster::ttl(const Variant &key) {
    return this_.exec("ttl", key);
}

Variant RedisCluster::type(const Variant &key) {
    return this_.exec("type", key);
}

Variant RedisCluster::unsubscribe(const Variant &channels) {
    return this_.exec("unsubscribe", channels);
}

Variant RedisCluster::unlink(const Variant &key, const Variant &other_keys) {
    return this_.exec("unlink", key, other_keys);
}

Variant RedisCluster::unwatch() {
    return this_.exec("unwatch");
}

Variant RedisCluster::watch(const Variant &key, const Variant &other_keys) {
    return this_.exec("watch", key, other_keys);
}

Variant RedisCluster::xack(const Variant &key, const Variant &group, const Variant &ids) {
    return this_.exec("xack", key, group, ids);
}

Variant RedisCluster::xadd(const Variant &key, const Variant &id, const Variant &values, const Variant &maxlen, const Variant &approx) {
    return this_.exec("xadd", key, id, values, maxlen, approx);
}

Variant RedisCluster::xclaim(const Variant &key, const Variant &group, const Variant &consumer, const Variant &min_iddle, const Variant &ids, const Variant &options) {
    return this_.exec("xclaim", key, group, consumer, min_iddle, ids, options);
}

Variant RedisCluster::xdel(const Variant &key, const Variant &ids) {
    return this_.exec("xdel", key, ids);
}

Variant RedisCluster::xgroup(const Variant &operation, const Variant &key, const Variant &group, const Variant &id_or_consumer, const Variant &mkstream, const Variant &entries_read) {
    return this_.exec("xgroup", operation, key, group, id_or_consumer, mkstream, entries_read);
}

Variant RedisCluster::xautoclaim(const Variant &key, const Variant &group, const Variant &consumer, const Variant &min_idle, const Variant &start, const Variant &count, const Variant &justid) {
    return this_.exec("xautoclaim", key, group, consumer, min_idle, start, count, justid);
}

Variant RedisCluster::xinfo(const Variant &operation, const Variant &arg1, const Variant &arg2, const Variant &count) {
    return this_.exec("xinfo", operation, arg1, arg2, count);
}

Variant RedisCluster::xlen(const Variant &key) {
    return this_.exec("xlen", key);
}

Variant RedisCluster::xpending(const Variant &key, const Variant &group, const Variant &start, const Variant &end, const Variant &count, const Variant &consumer) {
    return this_.exec("xpending", key, group, start, end, count, consumer);
}

Variant RedisCluster::xrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count) {
    return this_.exec("xrange", key, start, end, count);
}

Variant RedisCluster::xread(const Variant &streams, const Variant &count, const Variant &block) {
    return this_.exec("xread", streams, count, block);
}

Variant RedisCluster::xreadgroup(const Variant &group, const Variant &consumer, const Variant &streams, const Variant &count, const Variant &block) {
    return this_.exec("xreadgroup", group, consumer, streams, count, block);
}

Variant RedisCluster::xrevrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count) {
    return this_.exec("xrevrange", key, start, end, count);
}

Variant RedisCluster::xtrim(const Variant &key, const Variant &maxlen, const Variant &approx, const Variant &minid, const Variant &limit) {
    return this_.exec("xtrim", key, maxlen, approx, minid, limit);
}

Variant RedisCluster::zadd(const Variant &key, const Variant &score_or_options, const Variant &more_scores_and_mems) {
    return this_.exec("zadd", key, score_or_options, more_scores_and_mems);
}

Variant RedisCluster::zcard(const Variant &key) {
    return this_.exec("zcard", key);
}

Variant RedisCluster::zcount(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec("zcount", key, start, end);
}

Variant RedisCluster::zincrby(const Variant &key, const Variant &value, const Variant &member) {
    return this_.exec("zincrby", key, value, member);
}

Variant RedisCluster::zinterstore(const Variant &dst, const Variant &keys, const Variant &weights, const Variant &aggregate) {
    return this_.exec("zinterstore", dst, keys, weights, aggregate);
}

Variant RedisCluster::zintercard(const Variant &keys, const Variant &limit) {
    return this_.exec("zintercard", keys, limit);
}

Variant RedisCluster::zlexcount(const Variant &key, const Variant &min, const Variant &max) {
    return this_.exec("zlexcount", key, min, max);
}

Variant RedisCluster::zpopmax(const Variant &key, const Variant &value) {
    return this_.exec("zpopmax", key, value);
}

Variant RedisCluster::zpopmin(const Variant &key, const Variant &value) {
    return this_.exec("zpopmin", key, value);
}

Variant RedisCluster::zrange(const Variant &key, const Variant &start, const Variant &end, const Variant &options) {
    return this_.exec("zrange", key, start, end, options);
}

Variant RedisCluster::zrangestore(const Variant &dstkey, const Variant &srckey, const Variant &start, const Variant &end, const Variant &options) {
    return this_.exec("zrangestore", dstkey, srckey, start, end, options);
}

Variant RedisCluster::zrandmember(const Variant &key, const Variant &options) {
    return this_.exec("zrandmember", key, options);
}

Variant RedisCluster::zrangebylex(const Variant &key, const Variant &min, const Variant &max, const Variant &offset, const Variant &count) {
    return this_.exec("zrangebylex", key, min, max, offset, count);
}

Variant RedisCluster::zrangebyscore(const Variant &key, const Variant &start, const Variant &end, const Array &options) {
    return this_.exec("zrangebyscore", key, start, end, options);
}

Variant RedisCluster::zrank(const Variant &key, const Variant &member) {
    return this_.exec("zrank", key, member);
}

Variant RedisCluster::zrem(const Variant &key, const Variant &value, const Variant &other_values) {
    return this_.exec("zrem", key, value, other_values);
}

Variant RedisCluster::zremrangebylex(const Variant &key, const Variant &min, const Variant &max) {
    return this_.exec("zremrangebylex", key, min, max);
}

Variant RedisCluster::zremrangebyrank(const Variant &key, const Variant &min, const Variant &max) {
    return this_.exec("zremrangebyrank", key, min, max);
}

Variant RedisCluster::zremrangebyscore(const Variant &key, const Variant &min, const Variant &max) {
    return this_.exec("zremrangebyscore", key, min, max);
}

Variant RedisCluster::zrevrange(const Variant &key, const Variant &min, const Variant &max, const Variant &options) {
    return this_.exec("zrevrange", key, min, max, options);
}

Variant RedisCluster::zrevrangebylex(const Variant &key, const Variant &min, const Variant &max, const Variant &options) {
    return this_.exec("zrevrangebylex", key, min, max, options);
}

Variant RedisCluster::zrevrangebyscore(const Variant &key, const Variant &min, const Variant &max, const Variant &options) {
    return this_.exec("zrevrangebyscore", key, min, max, options);
}

Variant RedisCluster::zrevrank(const Variant &key, const Variant &member) {
    return this_.exec("zrevrank", key, member);
}

Variant RedisCluster::zscan(const Variant &key, const Variant &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec("zscan", key, iterator, pattern, count);
}

Variant RedisCluster::zscore(const Variant &key, const Variant &member) {
    return this_.exec("zscore", key, member);
}

Variant RedisCluster::zmscore(const Variant &key, const Variant &member, const Variant &other_members) {
    return this_.exec("zmscore", key, member, other_members);
}

Variant RedisCluster::zunionstore(const Variant &dst, const Variant &keys, const Variant &weights, const Variant &aggregate) {
    return this_.exec("zunionstore", dst, keys, weights, aggregate);
}

Variant RedisCluster::zinter(const Variant &keys, const Variant &weights, const Variant &options) {
    return this_.exec("zinter", keys, weights, options);
}

Variant RedisCluster::zdiffstore(const Variant &dst, const Variant &keys) {
    return this_.exec("zdiffstore", dst, keys);
}

Variant RedisCluster::zunion(const Variant &keys, const Variant &weights, const Variant &options) {
    return this_.exec("zunion", keys, weights, options);
}

Variant RedisCluster::zdiff(const Variant &keys, const Variant &options) {
    return this_.exec("zdiff", keys, options);
}


RedisClusterException::RedisClusterException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("RedisClusterException", message, code, previous);
}

Variant RedisClusterException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant RedisClusterException::getMessage() {
    return this_.exec("getMessage");
}

Variant RedisClusterException::getCode() {
    return this_.exec("getCode");
}

Variant RedisClusterException::getFile() {
    return this_.exec("getFile");
}

Variant RedisClusterException::getLine() {
    return this_.exec("getLine");
}

Variant RedisClusterException::getTrace() {
    return this_.exec("getTrace");
}

Variant RedisClusterException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant RedisClusterException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant RedisClusterException::__toString() {
    return this_.exec("__toString");
}


RedisSentinel::RedisSentinel(const Variant &options) {
    this_ = newObject("RedisSentinel", options);
}

Variant RedisSentinel::ckquorum(const Variant &master) {
    return this_.exec("ckquorum", master);
}

Variant RedisSentinel::failover(const Variant &master) {
    return this_.exec("failover", master);
}

Variant RedisSentinel::flushconfig() {
    return this_.exec("flushconfig");
}

Variant RedisSentinel::getMasterAddrByName(const Variant &master) {
    return this_.exec("getMasterAddrByName", master);
}

Variant RedisSentinel::master(const Variant &master) {
    return this_.exec("master", master);
}

Variant RedisSentinel::masters() {
    return this_.exec("masters");
}

Variant RedisSentinel::myid() {
    return this_.exec("myid");
}

Variant RedisSentinel::ping() {
    return this_.exec("ping");
}

Variant RedisSentinel::reset(const Variant &pattern) {
    return this_.exec("reset", pattern);
}

Variant RedisSentinel::sentinels(const Variant &master) {
    return this_.exec("sentinels", master);
}

Variant RedisSentinel::slaves(const Variant &master) {
    return this_.exec("slaves", master);
}


RedisException::RedisException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("RedisException", message, code, previous);
}

Variant RedisException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant RedisException::getMessage() {
    return this_.exec("getMessage");
}

Variant RedisException::getCode() {
    return this_.exec("getCode");
}

Variant RedisException::getFile() {
    return this_.exec("getFile");
}

Variant RedisException::getLine() {
    return this_.exec("getLine");
}

Variant RedisException::getTrace() {
    return this_.exec("getTrace");
}

Variant RedisException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant RedisException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant RedisException::__toString() {
    return this_.exec("__toString");
}


}
