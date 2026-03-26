#include "phpx.h"
#include "class/redis.h"

namespace php {
Redis::Redis(const Variant &options) {
    this_ = newObject(LITERAL_STRING[1041], {options});
}
Variant Redis::_compress(const Variant &value) {
    return this_.exec(LITERAL_STRING[1042], {value});
}
Variant Redis::_uncompress(const Variant &value) {
    return this_.exec(LITERAL_STRING[1043], {value});
}
Variant Redis::_prefix(const Variant &key) {
    return this_.exec(LITERAL_STRING[1044], {key});
}
Variant Redis::_serialize(const Variant &value) {
    return this_.exec(LITERAL_STRING[1045], {value});
}
Variant Redis::_unserialize(const Variant &value) {
    return this_.exec(LITERAL_STRING[1046], {value});
}
Variant Redis::_pack(const Variant &value) {
    return this_.exec(LITERAL_STRING[1047], {value});
}
Variant Redis::_unpack(const Variant &value) {
    return this_.exec(LITERAL_STRING[1048], {value});
}
Variant Redis::append(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[349], {key, value});
}
Variant Redis::auth(const Variant &credentials) {
    return this_.exec(LITERAL_STRING[1050], {credentials});
}
Variant Redis::bgSave() {
    return this_.exec(LITERAL_STRING[1051], {});
}
Variant Redis::bgrewriteaof() {
    return this_.exec(LITERAL_STRING[1052], {});
}
Variant Redis::waitaof(const Variant &numlocal, const Variant &numreplicas, const Variant &timeout) {
    return this_.exec(LITERAL_STRING[1053], {numlocal, numreplicas, timeout});
}
Variant Redis::bitcount(const Variant &key, const Variant &start, const Variant &end, const Variant &bybit) {
    return this_.exec(LITERAL_STRING[1054], {key, start, end, bybit});
}
Variant Redis::bitpos(
    const Variant &key, const Variant &bit, const Variant &start, const Variant &end, const Variant &bybit) {
    return this_.exec(LITERAL_STRING[1056], {key, bit, start, end, bybit});
}
Variant Redis::brpoplpush(const Variant &src, const Variant &dst, const Variant &timeout) {
    return this_.exec(LITERAL_STRING[1059], {src, dst, timeout});
}
Variant Redis::bzmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec(LITERAL_STRING[1062], {timeout, keys, from, count});
}
Variant Redis::zmpop(const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec(LITERAL_STRING[1063], {keys, from, count});
}
Variant Redis::blmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec(LITERAL_STRING[1064], {timeout, keys, from, count});
}
Variant Redis::lmpop(const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec(LITERAL_STRING[1065], {keys, from, count});
}
Variant Redis::clearLastError() {
    return this_.exec(LITERAL_STRING[1066], {});
}
Variant Redis::close() {
    return this_.exec(LITERAL_STRING[1068], {});
}
Variant Redis::config(const Variant &operation, const Variant &key_or_settings, const Variant &value) {
    return this_.exec(LITERAL_STRING[1070], {operation, key_or_settings, value});
}
Variant Redis::connect(const Variant &host,
                       const Variant &port,
                       const Variant &timeout,
                       const Variant &persistent_id,
                       const Variant &retry_interval,
                       const Variant &read_timeout,
                       const Variant &context) {
    return this_.exec(LITERAL_STRING[1071],
                      {host, port, timeout, persistent_id, retry_interval, read_timeout, context});
}
Variant Redis::copy(const Variant &src, const Variant &dst, const Variant &options) {
    return this_.exec(LITERAL_STRING[875], {src, dst, options});
}
Variant Redis::dbSize() {
    return this_.exec(LITERAL_STRING[1072], {});
}
Variant Redis::debug(const Variant &key) {
    return this_.exec(LITERAL_STRING[1073], {key});
}
Variant Redis::decr(const Variant &key, const Variant &by) {
    return this_.exec(LITERAL_STRING[1074], {key, by});
}
Variant Redis::decrBy(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1075], {key, value});
}
Variant Redis::discard() {
    return this_.exec(LITERAL_STRING[1077], {});
}
Variant Redis::dump(const Variant &key) {
    return this_.exec(LITERAL_STRING[1078], {key});
}
Variant Redis::echo(const Variant &str) {
    return this_.exec(LITERAL_STRING[1079], {str});
}
Variant Redis::eval(const Variant &script, const Variant &args, const Variant &num_keys) {
    return this_.exec(LITERAL_STRING[1080], {script, args, num_keys});
}
Variant Redis::eval_ro(const Variant &script_sha, const Variant &args, const Variant &num_keys) {
    return this_.exec(LITERAL_STRING[1081], {script_sha, args, num_keys});
}
Variant Redis::evalsha(const Variant &sha1, const Variant &args, const Variant &num_keys) {
    return this_.exec(LITERAL_STRING[1082], {sha1, args, num_keys});
}
Variant Redis::evalsha_ro(const Variant &sha1, const Variant &args, const Variant &num_keys) {
    return this_.exec(LITERAL_STRING[1083], {sha1, args, num_keys});
}
Variant Redis::exec() {
    return this_.exec(LITERAL_STRING[827], {});
}
Variant Redis::expire(const Variant &key, const Variant &timeout, const Variant &mode) {
    return this_.exec(LITERAL_STRING[1085], {key, timeout, mode});
}
Variant Redis::expireAt(const Variant &key, const Variant &timestamp, const Variant &mode) {
    return this_.exec(LITERAL_STRING[1086], {key, timestamp, mode});
}
Variant Redis::failover(const Variant &to, const Variant &abort, const Variant &timeout) {
    return this_.exec(LITERAL_STRING[1087], {to, abort, timeout});
}
Variant Redis::expiretime(const Variant &key) {
    return this_.exec(LITERAL_STRING[1088], {key});
}
Variant Redis::pexpiretime(const Variant &key) {
    return this_.exec(LITERAL_STRING[1089], {key});
}
Variant Redis::fcall(const Variant &fn, const Variant &keys, const Variant &args) {
    return this_.exec(LITERAL_STRING[1090], {fn, keys, args});
}
Variant Redis::fcall_ro(const Variant &fn, const Variant &keys, const Variant &args) {
    return this_.exec(LITERAL_STRING[1091], {fn, keys, args});
}
Variant Redis::flushAll(const Variant &sync) {
    return this_.exec(LITERAL_STRING[1092], {sync});
}
Variant Redis::flushDB(const Variant &sync) {
    return this_.exec(LITERAL_STRING[1093], {sync});
}
Variant Redis::geodist(const Variant &key, const Variant &src, const Variant &dst, const Variant &unit) {
    return this_.exec(LITERAL_STRING[1096], {key, src, dst, unit});
}
Variant Redis::georadius(const Variant &key,
                         const Variant &lng,
                         const Variant &lat,
                         const Variant &radius,
                         const Variant &unit,
                         const Variant &options) {
    return this_.exec(LITERAL_STRING[1099], {key, lng, lat, radius, unit, options});
}
Variant Redis::georadius_ro(const Variant &key,
                            const Variant &lng,
                            const Variant &lat,
                            const Variant &radius,
                            const Variant &unit,
                            const Variant &options) {
    return this_.exec(LITERAL_STRING[1100], {key, lng, lat, radius, unit, options});
}
Variant Redis::georadiusbymember(
    const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Variant &options) {
    return this_.exec(LITERAL_STRING[1101], {key, member, radius, unit, options});
}
Variant Redis::georadiusbymember_ro(
    const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Variant &options) {
    return this_.exec(LITERAL_STRING[1102], {key, member, radius, unit, options});
}
Variant Redis::geosearch(
    const Variant &key, const Variant &position, const Variant &shape, const Variant &unit, const Variant &options) {
    return this_.exec(LITERAL_STRING[1103], {key, position, shape, unit, options});
}
Variant Redis::geosearchstore(const Variant &dst,
                              const Variant &src,
                              const Variant &position,
                              const Variant &shape,
                              const Variant &unit,
                              const Variant &options) {
    return this_.exec(LITERAL_STRING[1104], {dst, src, position, shape, unit, options});
}
Variant Redis::get(const Variant &key) {
    return this_.exec(LITERAL_STRING[131], {key});
}
Variant Redis::getWithMeta(const Variant &key) {
    return this_.exec(LITERAL_STRING[1105], {key});
}
Variant Redis::getAuth() {
    return this_.exec(LITERAL_STRING[1106], {});
}
Variant Redis::getBit(const Variant &key, const Variant &idx) {
    return this_.exec(LITERAL_STRING[1107], {key, idx});
}
Variant Redis::getEx(const Variant &key, const Variant &options) {
    return this_.exec(LITERAL_STRING[1108], {key, options});
}
Variant Redis::getDBNum() {
    return this_.exec(LITERAL_STRING[1109], {});
}
Variant Redis::getDel(const Variant &key) {
    return this_.exec(LITERAL_STRING[1110], {key});
}
Variant Redis::getHost() {
    return this_.exec(LITERAL_STRING[1111], {});
}
Variant Redis::getLastError() {
    return this_.exec(LITERAL_STRING[1112], {});
}
Variant Redis::getMode() {
    return this_.exec(LITERAL_STRING[1113], {});
}
Variant Redis::getOption(const Variant &option) {
    return this_.exec(LITERAL_STRING[1114], {option});
}
Variant Redis::getPersistentID() {
    return this_.exec(LITERAL_STRING[1115], {});
}
Variant Redis::getPort() {
    return this_.exec(LITERAL_STRING[1116], {});
}
Variant Redis::serverName() {
    return this_.exec(LITERAL_STRING[1117], {});
}
Variant Redis::serverVersion() {
    return this_.exec(LITERAL_STRING[1118], {});
}
Variant Redis::getRange(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec(LITERAL_STRING[1119], {key, start, end});
}
Variant Redis::lcs(const Variant &key1, const Variant &key2, const Variant &options) {
    return this_.exec(LITERAL_STRING[1120], {key1, key2, options});
}
Variant Redis::getReadTimeout() {
    return this_.exec(LITERAL_STRING[1121], {});
}
Variant Redis::getset(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1122], {key, value});
}
Variant Redis::getTimeout() {
    return this_.exec(LITERAL_STRING[1123], {});
}
Variant Redis::getTransferredBytes() {
    return this_.exec(LITERAL_STRING[1124], {});
}
Variant Redis::clearTransferredBytes() {
    return this_.exec(LITERAL_STRING[1125], {});
}
Variant Redis::hExists(const Variant &key, const Variant &field) {
    return this_.exec(LITERAL_STRING[1127], {key, field});
}
Variant Redis::hGet(const Variant &key, const Variant &member) {
    return this_.exec(LITERAL_STRING[1128], {key, member});
}
Variant Redis::hGetAll(const Variant &key) {
    return this_.exec(LITERAL_STRING[1129], {key});
}
Variant Redis::hIncrBy(const Variant &key, const Variant &field, const Variant &value) {
    return this_.exec(LITERAL_STRING[1130], {key, field, value});
}
Variant Redis::hIncrByFloat(const Variant &key, const Variant &field, const Variant &value) {
    return this_.exec(LITERAL_STRING[1131], {key, field, value});
}
Variant Redis::hKeys(const Variant &key) {
    return this_.exec(LITERAL_STRING[1132], {key});
}
Variant Redis::hLen(const Variant &key) {
    return this_.exec(LITERAL_STRING[1133], {key});
}
Variant Redis::hMget(const Variant &key, const Variant &fields) {
    return this_.exec(LITERAL_STRING[1134], {key, fields});
}
Variant Redis::hMset(const Variant &key, const Variant &fieldvals) {
    return this_.exec(LITERAL_STRING[1135], {key, fieldvals});
}
Variant Redis::hRandField(const Variant &key, const Variant &options) {
    return this_.exec(LITERAL_STRING[1136], {key, options});
}
Variant Redis::hSetNx(const Variant &key, const Variant &field, const Variant &value) {
    return this_.exec(LITERAL_STRING[1138], {key, field, value});
}
Variant Redis::hStrLen(const Variant &key, const Variant &field) {
    return this_.exec(LITERAL_STRING[1139], {key, field});
}
Variant Redis::hVals(const Variant &key) {
    return this_.exec(LITERAL_STRING[1140], {key});
}
Variant Redis::hscan(const Variant &key, const Reference &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec(LITERAL_STRING[1141], {key, &iterator, pattern, count});
}
Variant Redis::expiremember(const Variant &key, const Variant &field, const Variant &ttl, const Variant &unit) {
    return this_.exec(LITERAL_STRING[1142], {key, field, ttl, unit});
}
Variant Redis::expirememberat(const Variant &key, const Variant &field, const Variant &timestamp) {
    return this_.exec(LITERAL_STRING[1143], {key, field, timestamp});
}
Variant Redis::incr(const Variant &key, const Variant &by) {
    return this_.exec(LITERAL_STRING[1144], {key, by});
}
Variant Redis::incrBy(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1145], {key, value});
}
Variant Redis::incrByFloat(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1146], {key, value});
}
Variant Redis::isConnected() {
    return this_.exec(LITERAL_STRING[1148], {});
}
Variant Redis::keys(const Variant &pattern) {
    return this_.exec(LITERAL_STRING[1149], {pattern});
}
Variant Redis::lInsert(const Variant &key, const Variant &pos, const Variant &pivot, const Variant &value) {
    return this_.exec(LITERAL_STRING[1150], {key, pos, pivot, value});
}
Variant Redis::lLen(const Variant &key) {
    return this_.exec(LITERAL_STRING[1151], {key});
}
Variant Redis::lMove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto) {
    return this_.exec(LITERAL_STRING[1152], {src, dst, wherefrom, whereto});
}
Variant Redis::blmove(
    const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto, const Variant &timeout) {
    return this_.exec(LITERAL_STRING[1153], {src, dst, wherefrom, whereto, timeout});
}
Variant Redis::lPop(const Variant &key, const Variant &count) {
    return this_.exec(LITERAL_STRING[1154], {key, count});
}
Variant Redis::lPos(const Variant &key, const Variant &value, const Variant &options) {
    return this_.exec(LITERAL_STRING[1155], {key, value, options});
}
Variant Redis::lPushx(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1158], {key, value});
}
Variant Redis::rPushx(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1159], {key, value});
}
Variant Redis::lSet(const Variant &key, const Variant &index, const Variant &value) {
    return this_.exec(LITERAL_STRING[1160], {key, index, value});
}
Variant Redis::lastSave() {
    return this_.exec(LITERAL_STRING[1161], {});
}
Variant Redis::lindex(const Variant &key, const Variant &index) {
    return this_.exec(LITERAL_STRING[1162], {key, index});
}
Variant Redis::lrange(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec(LITERAL_STRING[1163], {key, start, end});
}
Variant Redis::lrem(const Variant &key, const Variant &value, const Variant &count) {
    return this_.exec(LITERAL_STRING[1164], {key, value, count});
}
Variant Redis::ltrim(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec(LITERAL_STRING[1165], {key, start, end});
}
Variant Redis::mget(const Variant &keys) {
    return this_.exec(LITERAL_STRING[1166], {keys});
}
Variant Redis::migrate(const Variant &host,
                       const Variant &port,
                       const Variant &key,
                       const Variant &dstdb,
                       const Variant &timeout,
                       const Variant &copy,
                       const Variant &replace,
                       const Variant &credentials) {
    return this_.exec(LITERAL_STRING[1167], {host, port, key, dstdb, timeout, copy, replace, credentials});
}
Variant Redis::move(const Variant &key, const Variant &index) {
    return this_.exec(LITERAL_STRING[1168], {key, index});
}
Variant Redis::mset(const Variant &key_values) {
    return this_.exec(LITERAL_STRING[1169], {key_values});
}
Variant Redis::msetnx(const Variant &key_values) {
    return this_.exec(LITERAL_STRING[1170], {key_values});
}
Variant Redis::multi(const Variant &value) {
    return this_.exec(LITERAL_STRING[1171], {value});
}
Variant Redis::object(const Variant &subcommand, const Variant &key) {
    return this_.exec(LITERAL_STRING[1172], {subcommand, key});
}
Variant Redis::open(const Variant &host,
                    const Variant &port,
                    const Variant &timeout,
                    const Variant &persistent_id,
                    const Variant &retry_interval,
                    const Variant &read_timeout,
                    const Variant &context) {
    return this_.exec(LITERAL_STRING[1173],
                      {host, port, timeout, persistent_id, retry_interval, read_timeout, context});
}
Variant Redis::pconnect(const Variant &host,
                        const Variant &port,
                        const Variant &timeout,
                        const Variant &persistent_id,
                        const Variant &retry_interval,
                        const Variant &read_timeout,
                        const Variant &context) {
    return this_.exec(LITERAL_STRING[1174],
                      {host, port, timeout, persistent_id, retry_interval, read_timeout, context});
}
Variant Redis::persist(const Variant &key) {
    return this_.exec(LITERAL_STRING[1175], {key});
}
Variant Redis::pexpire(const Variant &key, const Variant &timeout, const Variant &mode) {
    return this_.exec(LITERAL_STRING[1176], {key, timeout, mode});
}
Variant Redis::pexpireAt(const Variant &key, const Variant &timestamp, const Variant &mode) {
    return this_.exec(LITERAL_STRING[1177], {key, timestamp, mode});
}
Variant Redis::pfadd(const Variant &key, const Variant &elements) {
    return this_.exec(LITERAL_STRING[1178], {key, elements});
}
Variant Redis::pfcount(const Variant &key_or_keys) {
    return this_.exec(LITERAL_STRING[1179], {key_or_keys});
}
Variant Redis::pfmerge(const Variant &dst, const Variant &srckeys) {
    return this_.exec(LITERAL_STRING[1180], {dst, srckeys});
}
Variant Redis::ping(const Variant &message) {
    return this_.exec(LITERAL_STRING[1181], {message});
}
Variant Redis::pipeline() {
    return this_.exec(LITERAL_STRING[1182], {});
}
Variant Redis::popen(const Variant &host,
                     const Variant &port,
                     const Variant &timeout,
                     const Variant &persistent_id,
                     const Variant &retry_interval,
                     const Variant &read_timeout,
                     const Variant &context) {
    return this_.exec(LITERAL_STRING[1183],
                      {host, port, timeout, persistent_id, retry_interval, read_timeout, context});
}
Variant Redis::psetex(const Variant &key, const Variant &expire, const Variant &value) {
    return this_.exec(LITERAL_STRING[1184], {key, expire, value});
}
Variant Redis::psubscribe(const Variant &patterns, const Variant &cb) {
    return this_.exec(LITERAL_STRING[1185], {patterns, cb});
}
Variant Redis::pttl(const Variant &key) {
    return this_.exec(LITERAL_STRING[1186], {key});
}
Variant Redis::publish(const Variant &channel, const Variant &message) {
    return this_.exec(LITERAL_STRING[1187], {channel, message});
}
Variant Redis::pubsub(const Variant &command, const Variant &arg) {
    return this_.exec(LITERAL_STRING[1188], {command, arg});
}
Variant Redis::punsubscribe(const Variant &patterns) {
    return this_.exec(LITERAL_STRING[1189], {patterns});
}
Variant Redis::rPop(const Variant &key, const Variant &count) {
    return this_.exec(LITERAL_STRING[1190], {key, count});
}
Variant Redis::randomKey() {
    return this_.exec(LITERAL_STRING[1191], {});
}
Variant Redis::rename(const Variant &old_name, const Variant &new_name) {
    return this_.exec(LITERAL_STRING[427], {old_name, new_name});
}
Variant Redis::renameNx(const Variant &key_src, const Variant &key_dst) {
    return this_.exec(LITERAL_STRING[1193], {key_src, key_dst});
}
Variant Redis::reset() {
    return this_.exec(LITERAL_STRING[1194], {});
}
Variant Redis::restore(const Variant &key, const Variant &ttl, const Variant &value, const Variant &options) {
    return this_.exec(LITERAL_STRING[1195], {key, ttl, value, options});
}
Variant Redis::role() {
    return this_.exec(LITERAL_STRING[1196], {});
}
Variant Redis::rpoplpush(const Variant &srckey, const Variant &dstkey) {
    return this_.exec(LITERAL_STRING[1197], {srckey, dstkey});
}
Variant Redis::sAddArray(const Variant &key, const Variant &values) {
    return this_.exec(LITERAL_STRING[1199], {key, values});
}
Variant Redis::sintercard(const Variant &keys, const Variant &limit) {
    return this_.exec(LITERAL_STRING[1203], {keys, limit});
}
Variant Redis::sMembers(const Variant &key) {
    return this_.exec(LITERAL_STRING[1205], {key});
}
Variant Redis::sMove(const Variant &src, const Variant &dst, const Variant &value) {
    return this_.exec(LITERAL_STRING[1207], {src, dst, value});
}
Variant Redis::sPop(const Variant &key, const Variant &count) {
    return this_.exec(LITERAL_STRING[1208], {key, count});
}
Variant Redis::sRandMember(const Variant &key, const Variant &count) {
    return this_.exec(LITERAL_STRING[1209], {key, count});
}
Variant Redis::save() {
    return this_.exec(LITERAL_STRING[375], {});
}
Variant Redis::scan(const Reference &iterator, const Variant &pattern, const Variant &count, const Variant &type) {
    return this_.exec(LITERAL_STRING[1212], {&iterator, pattern, count, type});
}
Variant Redis::scard(const Variant &key) {
    return this_.exec(LITERAL_STRING[1213], {key});
}
Variant Redis::select(const Variant &db) {
    return this_.exec(LITERAL_STRING[1215], {db});
}
Variant Redis::set(const Variant &key, const Variant &value, const Variant &options) {
    return this_.exec(LITERAL_STRING[1216], {key, value, options});
}
Variant Redis::setBit(const Variant &key, const Variant &idx, const Variant &value) {
    return this_.exec(LITERAL_STRING[1217], {key, idx, value});
}
Variant Redis::setRange(const Variant &key, const Variant &index, const Variant &value) {
    return this_.exec(LITERAL_STRING[1218], {key, index, value});
}
Variant Redis::setOption(const Variant &option, const Variant &value) {
    return this_.exec(LITERAL_STRING[1219], {option, value});
}
Variant Redis::setex(const Variant &key, const Variant &expire, const Variant &value) {
    return this_.exec(LITERAL_STRING[1220], {key, expire, value});
}
Variant Redis::setnx(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1221], {key, value});
}
Variant Redis::sismember(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1222], {key, value});
}
Variant Redis::slaveof(const Variant &host, const Variant &port) {
    return this_.exec(LITERAL_STRING[1223], {host, port});
}
Variant Redis::replicaof(const Variant &host, const Variant &port) {
    return this_.exec(LITERAL_STRING[1224], {host, port});
}
Variant Redis::slowlog(const Variant &operation, const Variant &length) {
    return this_.exec(LITERAL_STRING[1226], {operation, length});
}
Variant Redis::sort(const Variant &key, const Variant &options) {
    return this_.exec(LITERAL_STRING[1227], {key, options});
}
Variant Redis::sort_ro(const Variant &key, const Variant &options) {
    return this_.exec(LITERAL_STRING[1228], {key, options});
}
Variant Redis::sortAsc(const Variant &key,
                       const Variant &pattern,
                       const Variant &get,
                       const Variant &offset,
                       const Variant &count,
                       const Variant &store) {
    return this_.exec(LITERAL_STRING[1229], {key, pattern, get, offset, count, store});
}
Variant Redis::sortAscAlpha(const Variant &key,
                            const Variant &pattern,
                            const Variant &get,
                            const Variant &offset,
                            const Variant &count,
                            const Variant &store) {
    return this_.exec(LITERAL_STRING[1230], {key, pattern, get, offset, count, store});
}
Variant Redis::sortDesc(const Variant &key,
                        const Variant &pattern,
                        const Variant &get,
                        const Variant &offset,
                        const Variant &count,
                        const Variant &store) {
    return this_.exec(LITERAL_STRING[1231], {key, pattern, get, offset, count, store});
}
Variant Redis::sortDescAlpha(const Variant &key,
                             const Variant &pattern,
                             const Variant &get,
                             const Variant &offset,
                             const Variant &count,
                             const Variant &store) {
    return this_.exec(LITERAL_STRING[1232], {key, pattern, get, offset, count, store});
}
Variant Redis::sscan(const Variant &key, const Reference &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec(LITERAL_STRING[1234], {key, &iterator, pattern, count});
}
Variant Redis::ssubscribe(const Variant &channels, const Variant &cb) {
    return this_.exec(LITERAL_STRING[1235], {channels, cb});
}
Variant Redis::strlen(const Variant &key) {
    return this_.exec(LITERAL_STRING[1236], {key});
}
Variant Redis::subscribe(const Variant &channels, const Variant &cb) {
    return this_.exec(LITERAL_STRING[1237], {channels, cb});
}
Variant Redis::sunsubscribe(const Variant &channels) {
    return this_.exec(LITERAL_STRING[1238], {channels});
}
Variant Redis::swapdb(const Variant &src, const Variant &dst) {
    return this_.exec(LITERAL_STRING[1239], {src, dst});
}
Variant Redis::time() {
    return this_.exec(LITERAL_STRING[217], {});
}
Variant Redis::ttl(const Variant &key) {
    return this_.exec(LITERAL_STRING[1240], {key});
}
Variant Redis::type(const Variant &key) {
    return this_.exec(LITERAL_STRING[1241], {key});
}
Variant Redis::unsubscribe(const Variant &channels) {
    return this_.exec(LITERAL_STRING[1243], {channels});
}
Variant Redis::unwatch() {
    return this_.exec(LITERAL_STRING[1244], {});
}
Variant Redis::wait(const Variant &numreplicas, const Variant &timeout) {
    return this_.exec(LITERAL_STRING[1246], {numreplicas, timeout});
}
Variant Redis::xack(const Variant &key, const Variant &group, const Variant &ids) {
    return this_.exec(LITERAL_STRING[1247], {key, group, ids});
}
Variant Redis::xadd(const Variant &key,
                    const Variant &id,
                    const Variant &values,
                    const Variant &maxlen,
                    const Variant &approx,
                    const Variant &nomkstream) {
    return this_.exec(LITERAL_STRING[1248], {key, id, values, maxlen, approx, nomkstream});
}
Variant Redis::xautoclaim(const Variant &key,
                          const Variant &group,
                          const Variant &consumer,
                          const Variant &min_idle,
                          const Variant &start,
                          const Variant &count,
                          const Variant &justid) {
    return this_.exec(LITERAL_STRING[1249], {key, group, consumer, min_idle, start, count, justid});
}
Variant Redis::xclaim(const Variant &key,
                      const Variant &group,
                      const Variant &consumer,
                      const Variant &min_idle,
                      const Variant &ids,
                      const Variant &options) {
    return this_.exec(LITERAL_STRING[1250], {key, group, consumer, min_idle, ids, options});
}
Variant Redis::xdel(const Variant &key, const Variant &ids) {
    return this_.exec(LITERAL_STRING[1251], {key, ids});
}
Variant Redis::xgroup(const Variant &operation,
                      const Variant &key,
                      const Variant &group,
                      const Variant &id_or_consumer,
                      const Variant &mkstream,
                      const Variant &entries_read) {
    return this_.exec(LITERAL_STRING[1252], {operation, key, group, id_or_consumer, mkstream, entries_read});
}
Variant Redis::xinfo(const Variant &operation, const Variant &arg1, const Variant &arg2, const Variant &count) {
    return this_.exec(LITERAL_STRING[1253], {operation, arg1, arg2, count});
}
Variant Redis::xlen(const Variant &key) {
    return this_.exec(LITERAL_STRING[1254], {key});
}
Variant Redis::xpending(const Variant &key,
                        const Variant &group,
                        const Variant &start,
                        const Variant &end,
                        const Variant &count,
                        const Variant &consumer) {
    return this_.exec(LITERAL_STRING[1255], {key, group, start, end, count, consumer});
}
Variant Redis::xrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count) {
    return this_.exec(LITERAL_STRING[1256], {key, start, end, count});
}
Variant Redis::xread(const Variant &streams, const Variant &count, const Variant &block) {
    return this_.exec(LITERAL_STRING[1257], {streams, count, block});
}
Variant Redis::xreadgroup(
    const Variant &group, const Variant &consumer, const Variant &streams, const Variant &count, const Variant &block) {
    return this_.exec(LITERAL_STRING[1258], {group, consumer, streams, count, block});
}
Variant Redis::xrevrange(const Variant &key, const Variant &end, const Variant &start, const Variant &count) {
    return this_.exec(LITERAL_STRING[1259], {key, end, start, count});
}
Variant Redis::xtrim(
    const Variant &key, const Variant &threshold, const Variant &approx, const Variant &minid, const Variant &limit) {
    return this_.exec(LITERAL_STRING[1260], {key, threshold, approx, minid, limit});
}
Variant Redis::zCard(const Variant &key) {
    return this_.exec(LITERAL_STRING[1262], {key});
}
Variant Redis::zCount(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec(LITERAL_STRING[1263], {key, start, end});
}
Variant Redis::zIncrBy(const Variant &key, const Variant &value, const Variant &member) {
    return this_.exec(LITERAL_STRING[1264], {key, value, member});
}
Variant Redis::zLexCount(const Variant &key, const Variant &min, const Variant &max) {
    return this_.exec(LITERAL_STRING[1265], {key, min, max});
}
Variant Redis::zPopMax(const Variant &key, const Variant &count) {
    return this_.exec(LITERAL_STRING[1267], {key, count});
}
Variant Redis::zPopMin(const Variant &key, const Variant &count) {
    return this_.exec(LITERAL_STRING[1268], {key, count});
}
Variant Redis::zRange(const Variant &key, const Variant &start, const Variant &end, const Variant &options) {
    return this_.exec(LITERAL_STRING[1269], {key, start, end, options});
}
Variant Redis::zRangeByLex(
    const Variant &key, const Variant &min, const Variant &max, const Variant &offset, const Variant &count) {
    return this_.exec(LITERAL_STRING[1270], {key, min, max, offset, count});
}
Variant Redis::zRangeByScore(const Variant &key, const Variant &start, const Variant &end, const Variant &options) {
    return this_.exec(LITERAL_STRING[1271], {key, start, end, options});
}
Variant Redis::zrangestore(
    const Variant &dstkey, const Variant &srckey, const Variant &start, const Variant &end, const Variant &options) {
    return this_.exec(LITERAL_STRING[1272], {dstkey, srckey, start, end, options});
}
Variant Redis::zRandMember(const Variant &key, const Variant &options) {
    return this_.exec(LITERAL_STRING[1273], {key, options});
}
Variant Redis::zRank(const Variant &key, const Variant &member) {
    return this_.exec(LITERAL_STRING[1274], {key, member});
}
Variant Redis::zRemRangeByLex(const Variant &key, const Variant &min, const Variant &max) {
    return this_.exec(LITERAL_STRING[1276], {key, min, max});
}
Variant Redis::zRemRangeByRank(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec(LITERAL_STRING[1277], {key, start, end});
}
Variant Redis::zRemRangeByScore(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec(LITERAL_STRING[1278], {key, start, end});
}
Variant Redis::zRevRange(const Variant &key, const Variant &start, const Variant &end, const Variant &scores) {
    return this_.exec(LITERAL_STRING[1279], {key, start, end, scores});
}
Variant Redis::zRevRangeByLex(
    const Variant &key, const Variant &max, const Variant &min, const Variant &offset, const Variant &count) {
    return this_.exec(LITERAL_STRING[1280], {key, max, min, offset, count});
}
Variant Redis::zRevRangeByScore(const Variant &key, const Variant &max, const Variant &min, const Variant &options) {
    return this_.exec(LITERAL_STRING[1281], {key, max, min, options});
}
Variant Redis::zRevRank(const Variant &key, const Variant &member) {
    return this_.exec(LITERAL_STRING[1282], {key, member});
}
Variant Redis::zScore(const Variant &key, const Variant &member) {
    return this_.exec(LITERAL_STRING[1283], {key, member});
}
Variant Redis::zdiff(const Variant &keys, const Variant &options) {
    return this_.exec(LITERAL_STRING[1284], {keys, options});
}
Variant Redis::zdiffstore(const Variant &dst, const Variant &keys) {
    return this_.exec(LITERAL_STRING[1285], {dst, keys});
}
Variant Redis::zinter(const Variant &keys, const Variant &weights, const Variant &options) {
    return this_.exec(LITERAL_STRING[1286], {keys, weights, options});
}
Variant Redis::zintercard(const Variant &keys, const Variant &limit) {
    return this_.exec(LITERAL_STRING[1287], {keys, limit});
}
Variant Redis::zinterstore(const Variant &dst, const Variant &keys, const Variant &weights, const Variant &aggregate) {
    return this_.exec(LITERAL_STRING[1288], {dst, keys, weights, aggregate});
}
Variant Redis::zscan(const Variant &key, const Reference &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec(LITERAL_STRING[1289], {key, &iterator, pattern, count});
}
Variant Redis::zunion(const Variant &keys, const Variant &weights, const Variant &options) {
    return this_.exec(LITERAL_STRING[1290], {keys, weights, options});
}
Variant Redis::zunionstore(const Variant &dst, const Variant &keys, const Variant &weights, const Variant &aggregate) {
    return this_.exec(LITERAL_STRING[1291], {dst, keys, weights, aggregate});
}
Variant RedisArray::__call(const Variant &function_name, const Variant &arguments) {
    return this_.exec(LITERAL_STRING[1292], {function_name, arguments});
}
RedisArray::RedisArray(const Variant &name_or_hosts, const Variant &options) {
    this_ = newObject(LITERAL_STRING[1293], {name_or_hosts, options});
}
Variant RedisArray::_continuum() {
    return this_.exec(LITERAL_STRING[1294], {});
}
Variant RedisArray::_distributor() {
    return this_.exec(LITERAL_STRING[1295], {});
}
Variant RedisArray::_function() {
    return this_.exec(LITERAL_STRING[1296], {});
}
Variant RedisArray::_hosts() {
    return this_.exec(LITERAL_STRING[1297], {});
}
Variant RedisArray::_instance(const Variant &host) {
    return this_.exec(LITERAL_STRING[1298], {host});
}
Variant RedisArray::_rehash(const Variant &fn) {
    return this_.exec(LITERAL_STRING[1299], {fn});
}
Variant RedisArray::_target(const Variant &key) {
    return this_.exec(LITERAL_STRING[1300], {key});
}
Variant RedisArray::bgsave() {
    return this_.exec(LITERAL_STRING[1301], {});
}
Variant RedisArray::discard() {
    return this_.exec(LITERAL_STRING[1077], {});
}
Variant RedisArray::exec() {
    return this_.exec(LITERAL_STRING[827], {});
}
Variant RedisArray::flushall() {
    return this_.exec(LITERAL_STRING[1302], {});
}
Variant RedisArray::flushdb() {
    return this_.exec(LITERAL_STRING[1303], {});
}
Variant RedisArray::getOption(const Variant &opt) {
    return this_.exec(LITERAL_STRING[1114], {opt});
}
Variant RedisArray::hscan(const Variant &key, const Reference &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec(LITERAL_STRING[1141], {key, &iterator, pattern, count});
}
Variant RedisArray::info() {
    return this_.exec(LITERAL_STRING[1147], {});
}
Variant RedisArray::keys(const Variant &pattern) {
    return this_.exec(LITERAL_STRING[1149], {pattern});
}
Variant RedisArray::mget(const Variant &keys) {
    return this_.exec(LITERAL_STRING[1166], {keys});
}
Variant RedisArray::mset(const Variant &pairs) {
    return this_.exec(LITERAL_STRING[1169], {pairs});
}
Variant RedisArray::multi(const Variant &host, const Variant &mode) {
    return this_.exec(LITERAL_STRING[1171], {host, mode});
}
Variant RedisArray::ping() {
    return this_.exec(LITERAL_STRING[1181], {});
}
Variant RedisArray::save() {
    return this_.exec(LITERAL_STRING[375], {});
}
Variant RedisArray::scan(const Reference &iterator, const Variant &node, const Variant &pattern, const Variant &count) {
    return this_.exec(LITERAL_STRING[1212], {&iterator, node, pattern, count});
}
Variant RedisArray::select(const Variant &index) {
    return this_.exec(LITERAL_STRING[1215], {index});
}
Variant RedisArray::setOption(const Variant &opt, const Variant &value) {
    return this_.exec(LITERAL_STRING[1219], {opt, value});
}
Variant RedisArray::sscan(const Variant &key, const Reference &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec(LITERAL_STRING[1234], {key, &iterator, pattern, count});
}
Variant RedisArray::unwatch() {
    return this_.exec(LITERAL_STRING[1244], {});
}
Variant RedisArray::zscan(const Variant &key, const Reference &iterator, const Variant &pattern, const Variant &count) {
    return this_.exec(LITERAL_STRING[1289], {key, &iterator, pattern, count});
}
RedisCluster::RedisCluster(const Variant &name,
                           const Variant &seeds,
                           const Variant &timeout,
                           const Variant &read_timeout,
                           const Variant &persistent,
                           const Variant &auth,
                           const Variant &context) {
    this_ = newObject(LITERAL_STRING[1304], {name, seeds, timeout, read_timeout, persistent, auth, context});
}
Variant RedisCluster::_compress(const Variant &value) {
    return this_.exec(LITERAL_STRING[1042], {value});
}
Variant RedisCluster::_uncompress(const Variant &value) {
    return this_.exec(LITERAL_STRING[1043], {value});
}
Variant RedisCluster::_serialize(const Variant &value) {
    return this_.exec(LITERAL_STRING[1045], {value});
}
Variant RedisCluster::_unserialize(const Variant &value) {
    return this_.exec(LITERAL_STRING[1046], {value});
}
Variant RedisCluster::_pack(const Variant &value) {
    return this_.exec(LITERAL_STRING[1047], {value});
}
Variant RedisCluster::_unpack(const Variant &value) {
    return this_.exec(LITERAL_STRING[1048], {value});
}
Variant RedisCluster::_prefix(const Variant &key) {
    return this_.exec(LITERAL_STRING[1044], {key});
}
Variant RedisCluster::_masters() {
    return this_.exec(LITERAL_STRING[1305], {});
}
Variant RedisCluster::_redir() {
    return this_.exec(LITERAL_STRING[1306], {});
}
Variant RedisCluster::append(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[349], {key, value});
}
Variant RedisCluster::bgrewriteaof(const Variant &key_or_address) {
    return this_.exec(LITERAL_STRING[1052], {key_or_address});
}
Variant RedisCluster::waitaof(const Variant &key_or_address,
                              const Variant &numlocal,
                              const Variant &numreplicas,
                              const Variant &timeout) {
    return this_.exec(LITERAL_STRING[1053], {key_or_address, numlocal, numreplicas, timeout});
}
Variant RedisCluster::bgsave(const Variant &key_or_address) {
    return this_.exec(LITERAL_STRING[1301], {key_or_address});
}
Variant RedisCluster::bitcount(const Variant &key, const Variant &start, const Variant &end, const Variant &bybit) {
    return this_.exec(LITERAL_STRING[1054], {key, start, end, bybit});
}
Variant RedisCluster::bitpos(
    const Variant &key, const Variant &bit, const Variant &start, const Variant &end, const Variant &bybit) {
    return this_.exec(LITERAL_STRING[1056], {key, bit, start, end, bybit});
}
Variant RedisCluster::brpoplpush(const Variant &srckey, const Variant &deskey, const Variant &timeout) {
    return this_.exec(LITERAL_STRING[1059], {srckey, deskey, timeout});
}
Variant RedisCluster::lmove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto) {
    return this_.exec(LITERAL_STRING[1309], {src, dst, wherefrom, whereto});
}
Variant RedisCluster::blmove(
    const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto, const Variant &timeout) {
    return this_.exec(LITERAL_STRING[1153], {src, dst, wherefrom, whereto, timeout});
}
Variant RedisCluster::bzmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec(LITERAL_STRING[1062], {timeout, keys, from, count});
}
Variant RedisCluster::zmpop(const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec(LITERAL_STRING[1063], {keys, from, count});
}
Variant RedisCluster::blmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec(LITERAL_STRING[1064], {timeout, keys, from, count});
}
Variant RedisCluster::lmpop(const Variant &keys, const Variant &from, const Variant &count) {
    return this_.exec(LITERAL_STRING[1065], {keys, from, count});
}
Variant RedisCluster::clearlasterror() {
    return this_.exec(LITERAL_STRING[1312], {});
}
Variant RedisCluster::client(const Variant &key_or_address, const Variant &subcommand, const Variant &arg) {
    return this_.exec(LITERAL_STRING[1067], {key_or_address, subcommand, arg});
}
Variant RedisCluster::close() {
    return this_.exec(LITERAL_STRING[1068], {});
}
Variant RedisCluster::dbsize(const Variant &key_or_address) {
    return this_.exec(LITERAL_STRING[1314], {key_or_address});
}
Variant RedisCluster::copy(const Variant &src, const Variant &dst, const Variant &options) {
    return this_.exec(LITERAL_STRING[875], {src, dst, options});
}
Variant RedisCluster::decr(const Variant &key, const Variant &by) {
    return this_.exec(LITERAL_STRING[1074], {key, by});
}
Variant RedisCluster::decrby(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1315], {key, value});
}
Variant RedisCluster::decrbyfloat(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1316], {key, value});
}
Variant RedisCluster::discard() {
    return this_.exec(LITERAL_STRING[1077], {});
}
Variant RedisCluster::dump(const Variant &key) {
    return this_.exec(LITERAL_STRING[1078], {key});
}
Variant RedisCluster::echo(const Variant &key_or_address, const Variant &msg) {
    return this_.exec(LITERAL_STRING[1079], {key_or_address, msg});
}
Variant RedisCluster::eval(const Variant &script, const Variant &args, const Variant &num_keys) {
    return this_.exec(LITERAL_STRING[1080], {script, args, num_keys});
}
Variant RedisCluster::eval_ro(const Variant &script, const Variant &args, const Variant &num_keys) {
    return this_.exec(LITERAL_STRING[1081], {script, args, num_keys});
}
Variant RedisCluster::evalsha(const Variant &script_sha, const Variant &args, const Variant &num_keys) {
    return this_.exec(LITERAL_STRING[1082], {script_sha, args, num_keys});
}
Variant RedisCluster::evalsha_ro(const Variant &script_sha, const Variant &args, const Variant &num_keys) {
    return this_.exec(LITERAL_STRING[1083], {script_sha, args, num_keys});
}
Variant RedisCluster::exec() {
    return this_.exec(LITERAL_STRING[827], {});
}
Variant RedisCluster::expire(const Variant &key, const Variant &timeout, const Variant &mode) {
    return this_.exec(LITERAL_STRING[1085], {key, timeout, mode});
}
Variant RedisCluster::expireat(const Variant &key, const Variant &timestamp, const Variant &mode) {
    return this_.exec(LITERAL_STRING[1317], {key, timestamp, mode});
}
Variant RedisCluster::expiretime(const Variant &key) {
    return this_.exec(LITERAL_STRING[1088], {key});
}
Variant RedisCluster::pexpiretime(const Variant &key) {
    return this_.exec(LITERAL_STRING[1089], {key});
}
Variant RedisCluster::flushall(const Variant &key_or_address, const Variant &async) {
    return this_.exec(LITERAL_STRING[1302], {key_or_address, async});
}
Variant RedisCluster::flushdb(const Variant &key_or_address, const Variant &async) {
    return this_.exec(LITERAL_STRING[1303], {key_or_address, async});
}
Variant RedisCluster::geodist(const Variant &key, const Variant &src, const Variant &dest, const Variant &unit) {
    return this_.exec(LITERAL_STRING[1096], {key, src, dest, unit});
}
Variant RedisCluster::georadius(const Variant &key,
                                const Variant &lng,
                                const Variant &lat,
                                const Variant &radius,
                                const Variant &unit,
                                const Variant &options) {
    return this_.exec(LITERAL_STRING[1099], {key, lng, lat, radius, unit, options});
}
Variant RedisCluster::georadius_ro(const Variant &key,
                                   const Variant &lng,
                                   const Variant &lat,
                                   const Variant &radius,
                                   const Variant &unit,
                                   const Variant &options) {
    return this_.exec(LITERAL_STRING[1100], {key, lng, lat, radius, unit, options});
}
Variant RedisCluster::georadiusbymember(
    const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Variant &options) {
    return this_.exec(LITERAL_STRING[1101], {key, member, radius, unit, options});
}
Variant RedisCluster::georadiusbymember_ro(
    const Variant &key, const Variant &member, const Variant &radius, const Variant &unit, const Variant &options) {
    return this_.exec(LITERAL_STRING[1102], {key, member, radius, unit, options});
}
Variant RedisCluster::geosearch(
    const Variant &key, const Variant &position, const Variant &shape, const Variant &unit, const Variant &options) {
    return this_.exec(LITERAL_STRING[1103], {key, position, shape, unit, options});
}
Variant RedisCluster::geosearchstore(const Variant &dst,
                                     const Variant &src,
                                     const Variant &position,
                                     const Variant &shape,
                                     const Variant &unit,
                                     const Variant &options) {
    return this_.exec(LITERAL_STRING[1104], {dst, src, position, shape, unit, options});
}
Variant RedisCluster::get(const Variant &key) {
    return this_.exec(LITERAL_STRING[131], {key});
}
Variant RedisCluster::getdel(const Variant &key) {
    return this_.exec(LITERAL_STRING[1318], {key});
}
Variant RedisCluster::getWithMeta(const Variant &key) {
    return this_.exec(LITERAL_STRING[1105], {key});
}
Variant RedisCluster::getex(const Variant &key, const Variant &options) {
    return this_.exec(LITERAL_STRING[1319], {key, options});
}
Variant RedisCluster::getbit(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1320], {key, value});
}
Variant RedisCluster::getlasterror() {
    return this_.exec(LITERAL_STRING[1321], {});
}
Variant RedisCluster::getmode() {
    return this_.exec(LITERAL_STRING[1322], {});
}
Variant RedisCluster::getoption(const Variant &option) {
    return this_.exec(LITERAL_STRING[1323], {option});
}
Variant RedisCluster::getrange(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec(LITERAL_STRING[1324], {key, start, end});
}
Variant RedisCluster::lcs(const Variant &key1, const Variant &key2, const Variant &options) {
    return this_.exec(LITERAL_STRING[1120], {key1, key2, options});
}
Variant RedisCluster::getset(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1122], {key, value});
}
Variant RedisCluster::gettransferredbytes() {
    return this_.exec(LITERAL_STRING[1325], {});
}
Variant RedisCluster::cleartransferredbytes() {
    return this_.exec(LITERAL_STRING[1326], {});
}
Variant RedisCluster::hexists(const Variant &key, const Variant &member) {
    return this_.exec(LITERAL_STRING[1328], {key, member});
}
Variant RedisCluster::hget(const Variant &key, const Variant &member) {
    return this_.exec(LITERAL_STRING[1329], {key, member});
}
Variant RedisCluster::hgetall(const Variant &key) {
    return this_.exec(LITERAL_STRING[1330], {key});
}
Variant RedisCluster::hincrby(const Variant &key, const Variant &member, const Variant &value) {
    return this_.exec(LITERAL_STRING[1331], {key, member, value});
}
Variant RedisCluster::hincrbyfloat(const Variant &key, const Variant &member, const Variant &value) {
    return this_.exec(LITERAL_STRING[1332], {key, member, value});
}
Variant RedisCluster::hkeys(const Variant &key) {
    return this_.exec(LITERAL_STRING[1333], {key});
}
Variant RedisCluster::hlen(const Variant &key) {
    return this_.exec(LITERAL_STRING[1334], {key});
}
Variant RedisCluster::hmget(const Variant &key, const Variant &keys) {
    return this_.exec(LITERAL_STRING[1335], {key, keys});
}
Variant RedisCluster::hmset(const Variant &key, const Variant &key_values) {
    return this_.exec(LITERAL_STRING[1336], {key, key_values});
}
Variant RedisCluster::hscan(const Variant &key,
                            const Reference &iterator,
                            const Variant &pattern,
                            const Variant &count) {
    return this_.exec(LITERAL_STRING[1141], {key, &iterator, pattern, count});
}
Variant RedisCluster::expiremember(const Variant &key, const Variant &field, const Variant &ttl, const Variant &unit) {
    return this_.exec(LITERAL_STRING[1142], {key, field, ttl, unit});
}
Variant RedisCluster::expirememberat(const Variant &key, const Variant &field, const Variant &timestamp) {
    return this_.exec(LITERAL_STRING[1143], {key, field, timestamp});
}
Variant RedisCluster::hrandfield(const Variant &key, const Variant &options) {
    return this_.exec(LITERAL_STRING[1337], {key, options});
}
Variant RedisCluster::hset(const Variant &key, const Variant &member, const Variant &value) {
    return this_.exec(LITERAL_STRING[1338], {key, member, value});
}
Variant RedisCluster::hsetnx(const Variant &key, const Variant &member, const Variant &value) {
    return this_.exec(LITERAL_STRING[1339], {key, member, value});
}
Variant RedisCluster::hstrlen(const Variant &key, const Variant &field) {
    return this_.exec(LITERAL_STRING[1340], {key, field});
}
Variant RedisCluster::hvals(const Variant &key) {
    return this_.exec(LITERAL_STRING[1341], {key});
}
Variant RedisCluster::incr(const Variant &key, const Variant &by) {
    return this_.exec(LITERAL_STRING[1144], {key, by});
}
Variant RedisCluster::incrby(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1342], {key, value});
}
Variant RedisCluster::incrbyfloat(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1343], {key, value});
}
Variant RedisCluster::keys(const Variant &pattern) {
    return this_.exec(LITERAL_STRING[1149], {pattern});
}
Variant RedisCluster::lastsave(const Variant &key_or_address) {
    return this_.exec(LITERAL_STRING[1344], {key_or_address});
}
Variant RedisCluster::lget(const Variant &key, const Variant &index) {
    return this_.exec(LITERAL_STRING[1345], {key, index});
}
Variant RedisCluster::lindex(const Variant &key, const Variant &index) {
    return this_.exec(LITERAL_STRING[1162], {key, index});
}
Variant RedisCluster::linsert(const Variant &key, const Variant &pos, const Variant &pivot, const Variant &value) {
    return this_.exec(LITERAL_STRING[1346], {key, pos, pivot, value});
}
Variant RedisCluster::llen(const Variant &key) {
    return this_.exec(LITERAL_STRING[1347], {key});
}
Variant RedisCluster::lpop(const Variant &key, const Variant &count) {
    return this_.exec(LITERAL_STRING[1348], {key, count});
}
Variant RedisCluster::lpos(const Variant &key, const Variant &value, const Variant &options) {
    return this_.exec(LITERAL_STRING[1349], {key, value, options});
}
Variant RedisCluster::lpushx(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1351], {key, value});
}
Variant RedisCluster::lrange(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec(LITERAL_STRING[1163], {key, start, end});
}
Variant RedisCluster::lrem(const Variant &key, const Variant &value, const Variant &count) {
    return this_.exec(LITERAL_STRING[1164], {key, value, count});
}
Variant RedisCluster::lset(const Variant &key, const Variant &index, const Variant &value) {
    return this_.exec(LITERAL_STRING[1352], {key, index, value});
}
Variant RedisCluster::ltrim(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec(LITERAL_STRING[1165], {key, start, end});
}
Variant RedisCluster::mget(const Variant &keys) {
    return this_.exec(LITERAL_STRING[1166], {keys});
}
Variant RedisCluster::mset(const Variant &key_values) {
    return this_.exec(LITERAL_STRING[1169], {key_values});
}
Variant RedisCluster::msetnx(const Variant &key_values) {
    return this_.exec(LITERAL_STRING[1170], {key_values});
}
Variant RedisCluster::multi(const Variant &value) {
    return this_.exec(LITERAL_STRING[1171], {value});
}
Variant RedisCluster::object(const Variant &subcommand, const Variant &key) {
    return this_.exec(LITERAL_STRING[1172], {subcommand, key});
}
Variant RedisCluster::persist(const Variant &key) {
    return this_.exec(LITERAL_STRING[1175], {key});
}
Variant RedisCluster::pexpire(const Variant &key, const Variant &timeout, const Variant &mode) {
    return this_.exec(LITERAL_STRING[1176], {key, timeout, mode});
}
Variant RedisCluster::pexpireat(const Variant &key, const Variant &timestamp, const Variant &mode) {
    return this_.exec(LITERAL_STRING[1353], {key, timestamp, mode});
}
Variant RedisCluster::pfadd(const Variant &key, const Variant &elements) {
    return this_.exec(LITERAL_STRING[1178], {key, elements});
}
Variant RedisCluster::pfcount(const Variant &key) {
    return this_.exec(LITERAL_STRING[1179], {key});
}
Variant RedisCluster::pfmerge(const Variant &key, const Variant &keys) {
    return this_.exec(LITERAL_STRING[1180], {key, keys});
}
Variant RedisCluster::ping(const Variant &key_or_address, const Variant &message) {
    return this_.exec(LITERAL_STRING[1181], {key_or_address, message});
}
Variant RedisCluster::psetex(const Variant &key, const Variant &timeout, const Variant &value) {
    return this_.exec(LITERAL_STRING[1184], {key, timeout, value});
}
Variant RedisCluster::psubscribe(const Variant &patterns, const Variant &callback) {
    return this_.exec(LITERAL_STRING[1185], {patterns, callback});
}
Variant RedisCluster::pttl(const Variant &key) {
    return this_.exec(LITERAL_STRING[1186], {key});
}
Variant RedisCluster::publish(const Variant &channel, const Variant &message) {
    return this_.exec(LITERAL_STRING[1187], {channel, message});
}
Variant RedisCluster::randomkey(const Variant &key_or_address) {
    return this_.exec(LITERAL_STRING[1354], {key_or_address});
}
Variant RedisCluster::rename(const Variant &key_src, const Variant &key_dst) {
    return this_.exec(LITERAL_STRING[427], {key_src, key_dst});
}
Variant RedisCluster::renamenx(const Variant &key, const Variant &newkey) {
    return this_.exec(LITERAL_STRING[1355], {key, newkey});
}
Variant RedisCluster::restore(const Variant &key,
                              const Variant &timeout,
                              const Variant &value,
                              const Variant &options) {
    return this_.exec(LITERAL_STRING[1195], {key, timeout, value, options});
}
Variant RedisCluster::role(const Variant &key_or_address) {
    return this_.exec(LITERAL_STRING[1196], {key_or_address});
}
Variant RedisCluster::rpop(const Variant &key, const Variant &count) {
    return this_.exec(LITERAL_STRING[1356], {key, count});
}
Variant RedisCluster::rpoplpush(const Variant &src, const Variant &dst) {
    return this_.exec(LITERAL_STRING[1197], {src, dst});
}
Variant RedisCluster::rpushx(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1358], {key, value});
}
Variant RedisCluster::saddarray(const Variant &key, const Variant &values) {
    return this_.exec(LITERAL_STRING[1360], {key, values});
}
Variant RedisCluster::save(const Variant &key_or_address) {
    return this_.exec(LITERAL_STRING[375], {key_or_address});
}
Variant RedisCluster::scan(const Reference &iterator,
                           const Variant &key_or_address,
                           const Variant &pattern,
                           const Variant &count) {
    return this_.exec(LITERAL_STRING[1212], {&iterator, key_or_address, pattern, count});
}
Variant RedisCluster::scard(const Variant &key) {
    return this_.exec(LITERAL_STRING[1213], {key});
}
Variant RedisCluster::set(const Variant &key, const Variant &value, const Variant &options) {
    return this_.exec(LITERAL_STRING[1216], {key, value, options});
}
Variant RedisCluster::_setbit(const Variant &key, const Variant &offset, const Variant &onoff) {
    return this_.exec(LITERAL_STRING[1363], {key, offset, onoff});
}
Variant RedisCluster::setex(const Variant &key, const Variant &expire, const Variant &value) {
    return this_.exec(LITERAL_STRING[1220], {key, expire, value});
}
Variant RedisCluster::setnx(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1221], {key, value});
}
Variant RedisCluster::setoption(const Variant &option, const Variant &value) {
    return this_.exec(LITERAL_STRING[1364], {option, value});
}
Variant RedisCluster::setrange(const Variant &key, const Variant &offset, const Variant &value) {
    return this_.exec(LITERAL_STRING[1365], {key, offset, value});
}
Variant RedisCluster::sintercard(const Variant &keys, const Variant &limit) {
    return this_.exec(LITERAL_STRING[1203], {keys, limit});
}
Variant RedisCluster::sismember(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1222], {key, value});
}
Variant RedisCluster::smembers(const Variant &key) {
    return this_.exec(LITERAL_STRING[1369], {key});
}
Variant RedisCluster::smove(const Variant &src, const Variant &dst, const Variant &member) {
    return this_.exec(LITERAL_STRING[1370], {src, dst, member});
}
Variant RedisCluster::sort(const Variant &key, const Variant &options) {
    return this_.exec(LITERAL_STRING[1227], {key, options});
}
Variant RedisCluster::sort_ro(const Variant &key, const Variant &options) {
    return this_.exec(LITERAL_STRING[1228], {key, options});
}
Variant RedisCluster::spop(const Variant &key, const Variant &count) {
    return this_.exec(LITERAL_STRING[1371], {key, count});
}
Variant RedisCluster::srandmember(const Variant &key, const Variant &count) {
    return this_.exec(LITERAL_STRING[1372], {key, count});
}
Variant RedisCluster::sscan(const Variant &key,
                            const Reference &iterator,
                            const Variant &pattern,
                            const Variant &count) {
    return this_.exec(LITERAL_STRING[1234], {key, &iterator, pattern, count});
}
Variant RedisCluster::strlen(const Variant &key) {
    return this_.exec(LITERAL_STRING[1236], {key});
}
Variant RedisCluster::subscribe(const Variant &channels, const Variant &cb) {
    return this_.exec(LITERAL_STRING[1237], {channels, cb});
}
Variant RedisCluster::time(const Variant &key_or_address) {
    return this_.exec(LITERAL_STRING[217], {key_or_address});
}
Variant RedisCluster::ttl(const Variant &key) {
    return this_.exec(LITERAL_STRING[1240], {key});
}
Variant RedisCluster::type(const Variant &key) {
    return this_.exec(LITERAL_STRING[1241], {key});
}
Variant RedisCluster::unsubscribe(const Variant &channels) {
    return this_.exec(LITERAL_STRING[1243], {channels});
}
Variant RedisCluster::unwatch() {
    return this_.exec(LITERAL_STRING[1244], {});
}
Variant RedisCluster::xack(const Variant &key, const Variant &group, const Variant &ids) {
    return this_.exec(LITERAL_STRING[1247], {key, group, ids});
}
Variant RedisCluster::xadd(
    const Variant &key, const Variant &id, const Variant &values, const Variant &maxlen, const Variant &approx) {
    return this_.exec(LITERAL_STRING[1248], {key, id, values, maxlen, approx});
}
Variant RedisCluster::xclaim(const Variant &key,
                             const Variant &group,
                             const Variant &consumer,
                             const Variant &min_iddle,
                             const Variant &ids,
                             const Variant &options) {
    return this_.exec(LITERAL_STRING[1250], {key, group, consumer, min_iddle, ids, options});
}
Variant RedisCluster::xdel(const Variant &key, const Variant &ids) {
    return this_.exec(LITERAL_STRING[1251], {key, ids});
}
Variant RedisCluster::xgroup(const Variant &operation,
                             const Variant &key,
                             const Variant &group,
                             const Variant &id_or_consumer,
                             const Variant &mkstream,
                             const Variant &entries_read) {
    return this_.exec(LITERAL_STRING[1252], {operation, key, group, id_or_consumer, mkstream, entries_read});
}
Variant RedisCluster::xautoclaim(const Variant &key,
                                 const Variant &group,
                                 const Variant &consumer,
                                 const Variant &min_idle,
                                 const Variant &start,
                                 const Variant &count,
                                 const Variant &justid) {
    return this_.exec(LITERAL_STRING[1249], {key, group, consumer, min_idle, start, count, justid});
}
Variant RedisCluster::xinfo(const Variant &operation, const Variant &arg1, const Variant &arg2, const Variant &count) {
    return this_.exec(LITERAL_STRING[1253], {operation, arg1, arg2, count});
}
Variant RedisCluster::xlen(const Variant &key) {
    return this_.exec(LITERAL_STRING[1254], {key});
}
Variant RedisCluster::xpending(const Variant &key,
                               const Variant &group,
                               const Variant &start,
                               const Variant &end,
                               const Variant &count,
                               const Variant &consumer) {
    return this_.exec(LITERAL_STRING[1255], {key, group, start, end, count, consumer});
}
Variant RedisCluster::xrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count) {
    return this_.exec(LITERAL_STRING[1256], {key, start, end, count});
}
Variant RedisCluster::xread(const Variant &streams, const Variant &count, const Variant &block) {
    return this_.exec(LITERAL_STRING[1257], {streams, count, block});
}
Variant RedisCluster::xreadgroup(
    const Variant &group, const Variant &consumer, const Variant &streams, const Variant &count, const Variant &block) {
    return this_.exec(LITERAL_STRING[1258], {group, consumer, streams, count, block});
}
Variant RedisCluster::xrevrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count) {
    return this_.exec(LITERAL_STRING[1259], {key, start, end, count});
}
Variant RedisCluster::xtrim(
    const Variant &key, const Variant &maxlen, const Variant &approx, const Variant &minid, const Variant &limit) {
    return this_.exec(LITERAL_STRING[1260], {key, maxlen, approx, minid, limit});
}
Variant RedisCluster::zcard(const Variant &key) {
    return this_.exec(LITERAL_STRING[1376], {key});
}
Variant RedisCluster::zcount(const Variant &key, const Variant &start, const Variant &end) {
    return this_.exec(LITERAL_STRING[1377], {key, start, end});
}
Variant RedisCluster::zincrby(const Variant &key, const Variant &value, const Variant &member) {
    return this_.exec(LITERAL_STRING[1378], {key, value, member});
}
Variant RedisCluster::zinterstore(const Variant &dst,
                                  const Variant &keys,
                                  const Variant &weights,
                                  const Variant &aggregate) {
    return this_.exec(LITERAL_STRING[1288], {dst, keys, weights, aggregate});
}
Variant RedisCluster::zintercard(const Variant &keys, const Variant &limit) {
    return this_.exec(LITERAL_STRING[1287], {keys, limit});
}
Variant RedisCluster::zlexcount(const Variant &key, const Variant &min, const Variant &max) {
    return this_.exec(LITERAL_STRING[1379], {key, min, max});
}
Variant RedisCluster::zpopmax(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1380], {key, value});
}
Variant RedisCluster::zpopmin(const Variant &key, const Variant &value) {
    return this_.exec(LITERAL_STRING[1381], {key, value});
}
Variant RedisCluster::zrange(const Variant &key, const Variant &start, const Variant &end, const Variant &options) {
    return this_.exec(LITERAL_STRING[1382], {key, start, end, options});
}
Variant RedisCluster::zrangestore(
    const Variant &dstkey, const Variant &srckey, const Variant &start, const Variant &end, const Variant &options) {
    return this_.exec(LITERAL_STRING[1272], {dstkey, srckey, start, end, options});
}
Variant RedisCluster::zrandmember(const Variant &key, const Variant &options) {
    return this_.exec(LITERAL_STRING[1383], {key, options});
}
Variant RedisCluster::zrangebylex(
    const Variant &key, const Variant &min, const Variant &max, const Variant &offset, const Variant &count) {
    return this_.exec(LITERAL_STRING[1384], {key, min, max, offset, count});
}
Variant RedisCluster::zrangebyscore(const Variant &key,
                                    const Variant &start,
                                    const Variant &end,
                                    const Variant &options) {
    return this_.exec(LITERAL_STRING[1385], {key, start, end, options});
}
Variant RedisCluster::zrank(const Variant &key, const Variant &member) {
    return this_.exec(LITERAL_STRING[1386], {key, member});
}
Variant RedisCluster::zremrangebylex(const Variant &key, const Variant &min, const Variant &max) {
    return this_.exec(LITERAL_STRING[1388], {key, min, max});
}
Variant RedisCluster::zremrangebyrank(const Variant &key, const Variant &min, const Variant &max) {
    return this_.exec(LITERAL_STRING[1389], {key, min, max});
}
Variant RedisCluster::zremrangebyscore(const Variant &key, const Variant &min, const Variant &max) {
    return this_.exec(LITERAL_STRING[1390], {key, min, max});
}
Variant RedisCluster::zrevrange(const Variant &key, const Variant &min, const Variant &max, const Variant &options) {
    return this_.exec(LITERAL_STRING[1391], {key, min, max, options});
}
Variant RedisCluster::zrevrangebylex(const Variant &key,
                                     const Variant &min,
                                     const Variant &max,
                                     const Variant &options) {
    return this_.exec(LITERAL_STRING[1392], {key, min, max, options});
}
Variant RedisCluster::zrevrangebyscore(const Variant &key,
                                       const Variant &min,
                                       const Variant &max,
                                       const Variant &options) {
    return this_.exec(LITERAL_STRING[1393], {key, min, max, options});
}
Variant RedisCluster::zrevrank(const Variant &key, const Variant &member) {
    return this_.exec(LITERAL_STRING[1394], {key, member});
}
Variant RedisCluster::zscan(const Variant &key,
                            const Reference &iterator,
                            const Variant &pattern,
                            const Variant &count) {
    return this_.exec(LITERAL_STRING[1289], {key, &iterator, pattern, count});
}
Variant RedisCluster::zscore(const Variant &key, const Variant &member) {
    return this_.exec(LITERAL_STRING[1395], {key, member});
}
Variant RedisCluster::zunionstore(const Variant &dst,
                                  const Variant &keys,
                                  const Variant &weights,
                                  const Variant &aggregate) {
    return this_.exec(LITERAL_STRING[1291], {dst, keys, weights, aggregate});
}
Variant RedisCluster::zinter(const Variant &keys, const Variant &weights, const Variant &options) {
    return this_.exec(LITERAL_STRING[1286], {keys, weights, options});
}
Variant RedisCluster::zdiffstore(const Variant &dst, const Variant &keys) {
    return this_.exec(LITERAL_STRING[1285], {dst, keys});
}
Variant RedisCluster::zunion(const Variant &keys, const Variant &weights, const Variant &options) {
    return this_.exec(LITERAL_STRING[1290], {keys, weights, options});
}
Variant RedisCluster::zdiff(const Variant &keys, const Variant &options) {
    return this_.exec(LITERAL_STRING[1284], {keys, options});
}
RedisClusterException::RedisClusterException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1397], {message, code, previous});
}
Variant RedisClusterException::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant RedisClusterException::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant RedisClusterException::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant RedisClusterException::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant RedisClusterException::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant RedisClusterException::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant RedisClusterException::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant RedisClusterException::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant RedisClusterException::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
RedisSentinel::RedisSentinel(const Variant &options) {
    this_ = newObject(LITERAL_STRING[1398], {options});
}
Variant RedisSentinel::ckquorum(const Variant &master) {
    return this_.exec(LITERAL_STRING[1399], {master});
}
Variant RedisSentinel::failover(const Variant &master) {
    return this_.exec(LITERAL_STRING[1087], {master});
}
Variant RedisSentinel::flushconfig() {
    return this_.exec(LITERAL_STRING[1400], {});
}
Variant RedisSentinel::getMasterAddrByName(const Variant &master) {
    return this_.exec(LITERAL_STRING[1401], {master});
}
Variant RedisSentinel::master(const Variant &master) {
    return this_.exec(LITERAL_STRING[1402], {master});
}
Variant RedisSentinel::masters() {
    return this_.exec(LITERAL_STRING[1403], {});
}
Variant RedisSentinel::myid() {
    return this_.exec(LITERAL_STRING[1404], {});
}
Variant RedisSentinel::ping() {
    return this_.exec(LITERAL_STRING[1181], {});
}
Variant RedisSentinel::reset(const Variant &pattern) {
    return this_.exec(LITERAL_STRING[1194], {pattern});
}
Variant RedisSentinel::sentinels(const Variant &master) {
    return this_.exec(LITERAL_STRING[1405], {master});
}
Variant RedisSentinel::slaves(const Variant &master) {
    return this_.exec(LITERAL_STRING[1406], {master});
}
RedisException::RedisException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1407], {message, code, previous});
}
Variant RedisException::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant RedisException::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant RedisException::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant RedisException::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant RedisException::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant RedisException::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant RedisException::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant RedisException::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant RedisException::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
}  // namespace php
