#include "phpx_literal_string.h"

namespace php {
class Redis {
    Object this_;

  public:
    Redis(const Variant &options = {});
    Variant _compress(const Variant &value);
    Variant _uncompress(const Variant &value);
    Variant _prefix(const Variant &key);
    Variant _serialize(const Variant &value);
    Variant _unserialize(const Variant &value);
    Variant _pack(const Variant &value);
    Variant _unpack(const Variant &value);
    template <typename... Args>
    Variant acl(const Variant &subcmd, const Args &...args) {
        return this_.exec(LITERAL_STRING[1049], {subcmd, args...});
    }
    Variant append(const Variant &key, const Variant &value);
    Variant auth(const Variant &credentials);
    Variant bgSave();
    Variant bgrewriteaof();
    Variant waitaof(const Variant &numlocal, const Variant &numreplicas, const Variant &timeout);
    Variant bitcount(const Variant &key,
                     const Variant &start = 0,
                     const Variant &end = -1,
                     const Variant &bybit = false);
    template <typename... Args>
    Variant bitop(const Variant &operation, const Variant &deskey, const Variant &srckey, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1055], {operation, deskey, srckey, other_keys...});
    }
    Variant bitpos(const Variant &key,
                   const Variant &bit,
                   const Variant &start = 0,
                   const Variant &end = -1,
                   const Variant &bybit = false);
    template <typename... Args>
    Variant blPop(const Variant &key_or_keys, const Variant &timeout_or_key, const Args &...extra_args) {
        return this_.exec(LITERAL_STRING[1057], {key_or_keys, timeout_or_key, extra_args...});
    }
    template <typename... Args>
    Variant brPop(const Variant &key_or_keys, const Variant &timeout_or_key, const Args &...extra_args) {
        return this_.exec(LITERAL_STRING[1058], {key_or_keys, timeout_or_key, extra_args...});
    }
    Variant brpoplpush(const Variant &src, const Variant &dst, const Variant &timeout);
    template <typename... Args>
    Variant bzPopMax(const Variant &key, const Variant &timeout_or_key, const Args &...extra_args) {
        return this_.exec(LITERAL_STRING[1060], {key, timeout_or_key, extra_args...});
    }
    template <typename... Args>
    Variant bzPopMin(const Variant &key, const Variant &timeout_or_key, const Args &...extra_args) {
        return this_.exec(LITERAL_STRING[1061], {key, timeout_or_key, extra_args...});
    }
    Variant bzmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count = 1);
    Variant zmpop(const Variant &keys, const Variant &from, const Variant &count = 1);
    Variant blmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count = 1);
    Variant lmpop(const Variant &keys, const Variant &from, const Variant &count = 1);
    Variant clearLastError();
    template <typename... Args>
    Variant client(const Variant &opt, const Args &...args) {
        return this_.exec(LITERAL_STRING[1067], {opt, args...});
    }
    Variant close();
    template <typename... Args>
    Variant command(const Variant &opt, const Args &...args) {
        return this_.exec(LITERAL_STRING[1069], {opt, args...});
    }
    Variant config(const Variant &operation, const Variant &key_or_settings = {}, const Variant &value = {});
    Variant connect(const Variant &host,
                    const Variant &port = 6379,
                    const Variant &timeout = 0,
                    const Variant &persistent_id = {},
                    const Variant &retry_interval = 0,
                    const Variant &read_timeout = 0,
                    const Variant &context = {});
    Variant copy(const Variant &src, const Variant &dst, const Variant &options = {});
    Variant dbSize();
    Variant debug(const Variant &key);
    Variant decr(const Variant &key, const Variant &by = 1);
    Variant decrBy(const Variant &key, const Variant &value);
    template <typename... Args>
    Variant del(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1076], {key, other_keys...});
    }
    template <typename... Args>
    Variant _delete(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[876], {key, other_keys...});
    }
    Variant discard();
    Variant dump(const Variant &key);
    Variant echo(const Variant &str);
    Variant eval(const Variant &script, const Variant &args = Array{}, const Variant &num_keys = 0);
    Variant eval_ro(const Variant &script_sha, const Variant &args = Array{}, const Variant &num_keys = 0);
    Variant evalsha(const Variant &sha1, const Variant &args = Array{}, const Variant &num_keys = 0);
    Variant evalsha_ro(const Variant &sha1, const Variant &args = Array{}, const Variant &num_keys = 0);
    Variant exec();
    template <typename... Args>
    Variant exists(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1084], {key, other_keys...});
    }
    Variant expire(const Variant &key, const Variant &timeout, const Variant &mode = {});
    Variant expireAt(const Variant &key, const Variant &timestamp, const Variant &mode = {});
    Variant failover(const Variant &to = {}, const Variant &abort = false, const Variant &timeout = 0);
    Variant expiretime(const Variant &key);
    Variant pexpiretime(const Variant &key);
    Variant fcall(const Variant &fn, const Variant &keys = Array{}, const Variant &args = Array{});
    Variant fcall_ro(const Variant &fn, const Variant &keys = Array{}, const Variant &args = Array{});
    Variant flushAll(const Variant &sync = {});
    Variant flushDB(const Variant &sync = {});
    template <typename... Args>
    Variant function(const Variant &operation, const Args &...args) {
        return this_.exec(LITERAL_STRING[1094], {operation, args...});
    }
    template <typename... Args>
    Variant geoadd(const Variant &key,
                   const Variant &lng,
                   const Variant &lat,
                   const Variant &member,
                   const Args &...other_triples_and_options) {
        return this_.exec(LITERAL_STRING[1095], {key, lng, lat, member, other_triples_and_options...});
    }
    Variant geodist(const Variant &key, const Variant &src, const Variant &dst, const Variant &unit = {});
    template <typename... Args>
    Variant geohash(const Variant &key, const Variant &member, const Args &...other_members) {
        return this_.exec(LITERAL_STRING[1097], {key, member, other_members...});
    }
    template <typename... Args>
    Variant geopos(const Variant &key, const Variant &member, const Args &...other_members) {
        return this_.exec(LITERAL_STRING[1098], {key, member, other_members...});
    }
    Variant georadius(const Variant &key,
                      const Variant &lng,
                      const Variant &lat,
                      const Variant &radius,
                      const Variant &unit,
                      const Variant &options = Array{});
    Variant georadius_ro(const Variant &key,
                         const Variant &lng,
                         const Variant &lat,
                         const Variant &radius,
                         const Variant &unit,
                         const Variant &options = Array{});
    Variant georadiusbymember(const Variant &key,
                              const Variant &member,
                              const Variant &radius,
                              const Variant &unit,
                              const Variant &options = Array{});
    Variant georadiusbymember_ro(const Variant &key,
                                 const Variant &member,
                                 const Variant &radius,
                                 const Variant &unit,
                                 const Variant &options = Array{});
    Variant geosearch(const Variant &key,
                      const Variant &position,
                      const Variant &shape,
                      const Variant &unit,
                      const Variant &options = Array{});
    Variant geosearchstore(const Variant &dst,
                           const Variant &src,
                           const Variant &position,
                           const Variant &shape,
                           const Variant &unit,
                           const Variant &options = Array{});
    Variant get(const Variant &key);
    Variant getWithMeta(const Variant &key);
    Variant getAuth();
    Variant getBit(const Variant &key, const Variant &idx);
    Variant getEx(const Variant &key, const Variant &options = Array{});
    Variant getDBNum();
    Variant getDel(const Variant &key);
    Variant getHost();
    Variant getLastError();
    Variant getMode();
    Variant getOption(const Variant &option);
    Variant getPersistentID();
    Variant getPort();
    Variant serverName();
    Variant serverVersion();
    Variant getRange(const Variant &key, const Variant &start, const Variant &end);
    Variant lcs(const Variant &key1, const Variant &key2, const Variant &options = {});
    Variant getReadTimeout();
    Variant getset(const Variant &key, const Variant &value);
    Variant getTimeout();
    Variant getTransferredBytes();
    Variant clearTransferredBytes();
    template <typename... Args>
    Variant hDel(const Variant &key, const Variant &field, const Args &...other_fields) {
        return this_.exec(LITERAL_STRING[1126], {key, field, other_fields...});
    }
    Variant hExists(const Variant &key, const Variant &field);
    Variant hGet(const Variant &key, const Variant &member);
    Variant hGetAll(const Variant &key);
    Variant hIncrBy(const Variant &key, const Variant &field, const Variant &value);
    Variant hIncrByFloat(const Variant &key, const Variant &field, const Variant &value);
    Variant hKeys(const Variant &key);
    Variant hLen(const Variant &key);
    Variant hMget(const Variant &key, const Variant &fields);
    Variant hMset(const Variant &key, const Variant &fieldvals);
    Variant hRandField(const Variant &key, const Variant &options = {});
    template <typename... Args>
    Variant hSet(const Variant &key, const Args &...fields_and_vals) {
        return this_.exec(LITERAL_STRING[1137], {key, fields_and_vals...});
    }
    Variant hSetNx(const Variant &key, const Variant &field, const Variant &value);
    Variant hStrLen(const Variant &key, const Variant &field);
    Variant hVals(const Variant &key);
    Variant hscan(const Variant &key, const Reference &iterator, const Variant &pattern = {}, const Variant &count = 0);
    Variant expiremember(const Variant &key, const Variant &field, const Variant &ttl, const Variant &unit = {});
    Variant expirememberat(const Variant &key, const Variant &field, const Variant &timestamp);
    Variant incr(const Variant &key, const Variant &by = 1);
    Variant incrBy(const Variant &key, const Variant &value);
    Variant incrByFloat(const Variant &key, const Variant &value);
    template <typename... Args>
    Variant info(const Args &...sections) {
        return this_.exec(LITERAL_STRING[1147], {sections...});
    }
    Variant isConnected();
    Variant keys(const Variant &pattern);
    Variant lInsert(const Variant &key, const Variant &pos, const Variant &pivot, const Variant &value);
    Variant lLen(const Variant &key);
    Variant lMove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto);
    Variant blmove(const Variant &src,
                   const Variant &dst,
                   const Variant &wherefrom,
                   const Variant &whereto,
                   const Variant &timeout);
    Variant lPop(const Variant &key, const Variant &count = 0);
    Variant lPos(const Variant &key, const Variant &value, const Variant &options = {});
    template <typename... Args>
    Variant lPush(const Variant &key, const Args &...elements) {
        return this_.exec(LITERAL_STRING[1156], {key, elements...});
    }
    template <typename... Args>
    Variant rPush(const Variant &key, const Args &...elements) {
        return this_.exec(LITERAL_STRING[1157], {key, elements...});
    }
    Variant lPushx(const Variant &key, const Variant &value);
    Variant rPushx(const Variant &key, const Variant &value);
    Variant lSet(const Variant &key, const Variant &index, const Variant &value);
    Variant lastSave();
    Variant lindex(const Variant &key, const Variant &index);
    Variant lrange(const Variant &key, const Variant &start, const Variant &end);
    Variant lrem(const Variant &key, const Variant &value, const Variant &count = 0);
    Variant ltrim(const Variant &key, const Variant &start, const Variant &end);
    Variant mget(const Variant &keys);
    Variant migrate(const Variant &host,
                    const Variant &port,
                    const Variant &key,
                    const Variant &dstdb,
                    const Variant &timeout,
                    const Variant &copy = false,
                    const Variant &replace = false,
                    const Variant &credentials = {});
    Variant move(const Variant &key, const Variant &index);
    Variant mset(const Variant &key_values);
    Variant msetnx(const Variant &key_values);
    Variant multi(const Variant &value = 1);
    Variant object(const Variant &subcommand, const Variant &key);
    Variant open(const Variant &host,
                 const Variant &port = 6379,
                 const Variant &timeout = 0,
                 const Variant &persistent_id = {},
                 const Variant &retry_interval = 0,
                 const Variant &read_timeout = 0,
                 const Variant &context = {});
    Variant pconnect(const Variant &host,
                     const Variant &port = 6379,
                     const Variant &timeout = 0,
                     const Variant &persistent_id = {},
                     const Variant &retry_interval = 0,
                     const Variant &read_timeout = 0,
                     const Variant &context = {});
    Variant persist(const Variant &key);
    Variant pexpire(const Variant &key, const Variant &timeout, const Variant &mode = {});
    Variant pexpireAt(const Variant &key, const Variant &timestamp, const Variant &mode = {});
    Variant pfadd(const Variant &key, const Variant &elements);
    Variant pfcount(const Variant &key_or_keys);
    Variant pfmerge(const Variant &dst, const Variant &srckeys);
    Variant ping(const Variant &message = {});
    Variant pipeline();
    Variant popen(const Variant &host,
                  const Variant &port = 6379,
                  const Variant &timeout = 0,
                  const Variant &persistent_id = {},
                  const Variant &retry_interval = 0,
                  const Variant &read_timeout = 0,
                  const Variant &context = {});
    Variant psetex(const Variant &key, const Variant &expire, const Variant &value);
    Variant psubscribe(const Variant &patterns, const Variant &cb);
    Variant pttl(const Variant &key);
    Variant publish(const Variant &channel, const Variant &message);
    Variant pubsub(const Variant &command, const Variant &arg = {});
    Variant punsubscribe(const Variant &patterns);
    Variant rPop(const Variant &key, const Variant &count = 0);
    Variant randomKey();
    template <typename... Args>
    Variant rawcommand(const Variant &command, const Args &...args) {
        return this_.exec(LITERAL_STRING[1192], {command, args...});
    }
    Variant rename(const Variant &old_name, const Variant &new_name);
    Variant renameNx(const Variant &key_src, const Variant &key_dst);
    Variant reset();
    Variant restore(const Variant &key, const Variant &ttl, const Variant &value, const Variant &options = {});
    Variant role();
    Variant rpoplpush(const Variant &srckey, const Variant &dstkey);
    template <typename... Args>
    Variant sAdd(const Variant &key, const Variant &value, const Args &...other_values) {
        return this_.exec(LITERAL_STRING[1198], {key, value, other_values...});
    }
    Variant sAddArray(const Variant &key, const Variant &values);
    template <typename... Args>
    Variant sDiff(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1200], {key, other_keys...});
    }
    template <typename... Args>
    Variant sDiffStore(const Variant &dst, const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1201], {dst, key, other_keys...});
    }
    template <typename... Args>
    Variant sInter(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1202], {key, other_keys...});
    }
    Variant sintercard(const Variant &keys, const Variant &limit = -1);
    template <typename... Args>
    Variant sInterStore(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1204], {key, other_keys...});
    }
    Variant sMembers(const Variant &key);
    template <typename... Args>
    Variant sMisMember(const Variant &key, const Variant &member, const Args &...other_members) {
        return this_.exec(LITERAL_STRING[1206], {key, member, other_members...});
    }
    Variant sMove(const Variant &src, const Variant &dst, const Variant &value);
    Variant sPop(const Variant &key, const Variant &count = 0);
    Variant sRandMember(const Variant &key, const Variant &count = 0);
    template <typename... Args>
    Variant sUnion(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1210], {key, other_keys...});
    }
    template <typename... Args>
    Variant sUnionStore(const Variant &dst, const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1211], {dst, key, other_keys...});
    }
    Variant save();
    Variant scan(const Reference &iterator,
                 const Variant &pattern = {},
                 const Variant &count = 0,
                 const Variant &type = {});
    Variant scard(const Variant &key);
    template <typename... Args>
    Variant script(const Variant &command, const Args &...args) {
        return this_.exec(LITERAL_STRING[1214], {command, args...});
    }
    Variant select(const Variant &db);
    Variant set(const Variant &key, const Variant &value, const Variant &options = {});
    Variant setBit(const Variant &key, const Variant &idx, const Variant &value);
    Variant setRange(const Variant &key, const Variant &index, const Variant &value);
    Variant setOption(const Variant &option, const Variant &value);
    Variant setex(const Variant &key, const Variant &expire, const Variant &value);
    Variant setnx(const Variant &key, const Variant &value);
    Variant sismember(const Variant &key, const Variant &value);
    Variant slaveof(const Variant &host = {}, const Variant &port = 6379);
    Variant replicaof(const Variant &host = {}, const Variant &port = 6379);
    template <typename... Args>
    Variant touch(const Variant &key_or_array, const Args &...more_keys) {
        return this_.exec(LITERAL_STRING[1225], {key_or_array, more_keys...});
    }
    Variant slowlog(const Variant &operation, const Variant &length = 0);
    Variant sort(const Variant &key, const Variant &options = {});
    Variant sort_ro(const Variant &key, const Variant &options = {});
    Variant sortAsc(const Variant &key,
                    const Variant &pattern = {},
                    const Variant &get = {},
                    const Variant &offset = -1,
                    const Variant &count = -1,
                    const Variant &store = {});
    Variant sortAscAlpha(const Variant &key,
                         const Variant &pattern = {},
                         const Variant &get = {},
                         const Variant &offset = -1,
                         const Variant &count = -1,
                         const Variant &store = {});
    Variant sortDesc(const Variant &key,
                     const Variant &pattern = {},
                     const Variant &get = {},
                     const Variant &offset = -1,
                     const Variant &count = -1,
                     const Variant &store = {});
    Variant sortDescAlpha(const Variant &key,
                          const Variant &pattern = {},
                          const Variant &get = {},
                          const Variant &offset = -1,
                          const Variant &count = -1,
                          const Variant &store = {});
    template <typename... Args>
    Variant srem(const Variant &key, const Variant &value, const Args &...other_values) {
        return this_.exec(LITERAL_STRING[1233], {key, value, other_values...});
    }
    Variant sscan(const Variant &key, const Reference &iterator, const Variant &pattern = {}, const Variant &count = 0);
    Variant ssubscribe(const Variant &channels, const Variant &cb);
    Variant strlen(const Variant &key);
    Variant subscribe(const Variant &channels, const Variant &cb);
    Variant sunsubscribe(const Variant &channels);
    Variant swapdb(const Variant &src, const Variant &dst);
    Variant time();
    Variant ttl(const Variant &key);
    Variant type(const Variant &key);
    template <typename... Args>
    Variant unlink(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1242], {key, other_keys...});
    }
    Variant unsubscribe(const Variant &channels);
    Variant unwatch();
    template <typename... Args>
    Variant watch(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1245], {key, other_keys...});
    }
    Variant wait(const Variant &numreplicas, const Variant &timeout);
    Variant xack(const Variant &key, const Variant &group, const Variant &ids);
    Variant xadd(const Variant &key,
                 const Variant &id,
                 const Variant &values,
                 const Variant &maxlen = 0,
                 const Variant &approx = false,
                 const Variant &nomkstream = false);
    Variant xautoclaim(const Variant &key,
                       const Variant &group,
                       const Variant &consumer,
                       const Variant &min_idle,
                       const Variant &start,
                       const Variant &count = -1,
                       const Variant &justid = false);
    Variant xclaim(const Variant &key,
                   const Variant &group,
                   const Variant &consumer,
                   const Variant &min_idle,
                   const Variant &ids,
                   const Variant &options);
    Variant xdel(const Variant &key, const Variant &ids);
    Variant xgroup(const Variant &operation,
                   const Variant &key = {},
                   const Variant &group = {},
                   const Variant &id_or_consumer = {},
                   const Variant &mkstream = false,
                   const Variant &entries_read = -2);
    Variant xinfo(const Variant &operation,
                  const Variant &arg1 = {},
                  const Variant &arg2 = {},
                  const Variant &count = -1);
    Variant xlen(const Variant &key);
    Variant xpending(const Variant &key,
                     const Variant &group,
                     const Variant &start = {},
                     const Variant &end = {},
                     const Variant &count = -1,
                     const Variant &consumer = {});
    Variant xrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count = -1);
    Variant xread(const Variant &streams, const Variant &count = -1, const Variant &block = -1);
    Variant xreadgroup(const Variant &group,
                       const Variant &consumer,
                       const Variant &streams,
                       const Variant &count = 1,
                       const Variant &block = 1);
    Variant xrevrange(const Variant &key, const Variant &end, const Variant &start, const Variant &count = -1);
    Variant xtrim(const Variant &key,
                  const Variant &threshold,
                  const Variant &approx = false,
                  const Variant &minid = false,
                  const Variant &limit = -1);
    template <typename... Args>
    Variant zAdd(const Variant &key, const Variant &score_or_options, const Args &...more_scores_and_mems) {
        return this_.exec(LITERAL_STRING[1261], {key, score_or_options, more_scores_and_mems...});
    }
    Variant zCard(const Variant &key);
    Variant zCount(const Variant &key, const Variant &start, const Variant &end);
    Variant zIncrBy(const Variant &key, const Variant &value, const Variant &member);
    Variant zLexCount(const Variant &key, const Variant &min, const Variant &max);
    template <typename... Args>
    Variant zMscore(const Variant &key, const Variant &member, const Args &...other_members) {
        return this_.exec(LITERAL_STRING[1266], {key, member, other_members...});
    }
    Variant zPopMax(const Variant &key, const Variant &count = {});
    Variant zPopMin(const Variant &key, const Variant &count = {});
    Variant zRange(const Variant &key, const Variant &start, const Variant &end, const Variant &options = {});
    Variant zRangeByLex(const Variant &key,
                        const Variant &min,
                        const Variant &max,
                        const Variant &offset = -1,
                        const Variant &count = -1);
    Variant zRangeByScore(const Variant &key,
                          const Variant &start,
                          const Variant &end,
                          const Variant &options = Array{});
    Variant zrangestore(const Variant &dstkey,
                        const Variant &srckey,
                        const Variant &start,
                        const Variant &end,
                        const Variant &options = {});
    Variant zRandMember(const Variant &key, const Variant &options = {});
    Variant zRank(const Variant &key, const Variant &member);
    template <typename... Args>
    Variant zRem(const Variant &key, const Variant &member, const Args &...other_members) {
        return this_.exec(LITERAL_STRING[1275], {key, member, other_members...});
    }
    Variant zRemRangeByLex(const Variant &key, const Variant &min, const Variant &max);
    Variant zRemRangeByRank(const Variant &key, const Variant &start, const Variant &end);
    Variant zRemRangeByScore(const Variant &key, const Variant &start, const Variant &end);
    Variant zRevRange(const Variant &key, const Variant &start, const Variant &end, const Variant &scores = {});
    Variant zRevRangeByLex(const Variant &key,
                           const Variant &max,
                           const Variant &min,
                           const Variant &offset = -1,
                           const Variant &count = -1);
    Variant zRevRangeByScore(const Variant &key,
                             const Variant &max,
                             const Variant &min,
                             const Variant &options = Array{});
    Variant zRevRank(const Variant &key, const Variant &member);
    Variant zScore(const Variant &key, const Variant &member);
    Variant zdiff(const Variant &keys, const Variant &options = {});
    Variant zdiffstore(const Variant &dst, const Variant &keys);
    Variant zinter(const Variant &keys, const Variant &weights = {}, const Variant &options = {});
    Variant zintercard(const Variant &keys, const Variant &limit = -1);
    Variant zinterstore(const Variant &dst,
                        const Variant &keys,
                        const Variant &weights = {},
                        const Variant &aggregate = {});
    Variant zscan(const Variant &key, const Reference &iterator, const Variant &pattern = {}, const Variant &count = 0);
    Variant zunion(const Variant &keys, const Variant &weights = {}, const Variant &options = {});
    Variant zunionstore(const Variant &dst,
                        const Variant &keys,
                        const Variant &weights = {},
                        const Variant &aggregate = {});
};

class RedisArray {
    Object this_;

  public:
    Variant __call(const Variant &function_name, const Variant &arguments);
    RedisArray(const Variant &name_or_hosts, const Variant &options = {});
    Variant _continuum();
    Variant _distributor();
    Variant _function();
    Variant _hosts();
    Variant _instance(const Variant &host);
    Variant _rehash(const Variant &fn = {});
    Variant _target(const Variant &key);
    Variant bgsave();
    template <typename... Args>
    Variant del(const Variant &key, const Args &...otherkeys) {
        return this_.exec(LITERAL_STRING[1076], {key, otherkeys...});
    }
    Variant discard();
    Variant exec();
    Variant flushall();
    Variant flushdb();
    Variant getOption(const Variant &opt);
    Variant hscan(const Variant &key, const Reference &iterator, const Variant &pattern = {}, const Variant &count = 0);
    Variant info();
    Variant keys(const Variant &pattern);
    Variant mget(const Variant &keys);
    Variant mset(const Variant &pairs);
    Variant multi(const Variant &host, const Variant &mode = {});
    Variant ping();
    Variant save();
    Variant scan(const Reference &iterator, const Variant &node, const Variant &pattern = {}, const Variant &count = 0);
    Variant select(const Variant &index);
    Variant setOption(const Variant &opt, const Variant &value);
    Variant sscan(const Variant &key, const Reference &iterator, const Variant &pattern = {}, const Variant &count = 0);
    template <typename... Args>
    Variant unlink(const Variant &key, const Args &...otherkeys) {
        return this_.exec(LITERAL_STRING[1242], {key, otherkeys...});
    }
    Variant unwatch();
    Variant zscan(const Variant &key, const Reference &iterator, const Variant &pattern = {}, const Variant &count = 0);
};

class RedisCluster {
    Object this_;

  public:
    RedisCluster(const Variant &name,
                 const Variant &seeds = {},
                 const Variant &timeout = 0,
                 const Variant &read_timeout = 0,
                 const Variant &persistent = false,
                 const Variant &auth = {},
                 const Variant &context = {});
    Variant _compress(const Variant &value);
    Variant _uncompress(const Variant &value);
    Variant _serialize(const Variant &value);
    Variant _unserialize(const Variant &value);
    Variant _pack(const Variant &value);
    Variant _unpack(const Variant &value);
    Variant _prefix(const Variant &key);
    Variant _masters();
    Variant _redir();
    template <typename... Args>
    Variant acl(const Variant &key_or_address, const Variant &subcmd, const Args &...args) {
        return this_.exec(LITERAL_STRING[1049], {key_or_address, subcmd, args...});
    }
    Variant append(const Variant &key, const Variant &value);
    Variant bgrewriteaof(const Variant &key_or_address);
    Variant waitaof(const Variant &key_or_address,
                    const Variant &numlocal,
                    const Variant &numreplicas,
                    const Variant &timeout);
    Variant bgsave(const Variant &key_or_address);
    Variant bitcount(const Variant &key,
                     const Variant &start = 0,
                     const Variant &end = -1,
                     const Variant &bybit = false);
    template <typename... Args>
    Variant bitop(const Variant &operation, const Variant &deskey, const Variant &srckey, const Args &...otherkeys) {
        return this_.exec(LITERAL_STRING[1055], {operation, deskey, srckey, otherkeys...});
    }
    Variant bitpos(const Variant &key,
                   const Variant &bit,
                   const Variant &start = 0,
                   const Variant &end = -1,
                   const Variant &bybit = false);
    template <typename... Args>
    Variant blpop(const Variant &key, const Variant &timeout_or_key, const Args &...extra_args) {
        return this_.exec(LITERAL_STRING[1307], {key, timeout_or_key, extra_args...});
    }
    template <typename... Args>
    Variant brpop(const Variant &key, const Variant &timeout_or_key, const Args &...extra_args) {
        return this_.exec(LITERAL_STRING[1308], {key, timeout_or_key, extra_args...});
    }
    Variant brpoplpush(const Variant &srckey, const Variant &deskey, const Variant &timeout);
    Variant lmove(const Variant &src, const Variant &dst, const Variant &wherefrom, const Variant &whereto);
    Variant blmove(const Variant &src,
                   const Variant &dst,
                   const Variant &wherefrom,
                   const Variant &whereto,
                   const Variant &timeout);
    template <typename... Args>
    Variant bzpopmax(const Variant &key, const Variant &timeout_or_key, const Args &...extra_args) {
        return this_.exec(LITERAL_STRING[1310], {key, timeout_or_key, extra_args...});
    }
    template <typename... Args>
    Variant bzpopmin(const Variant &key, const Variant &timeout_or_key, const Args &...extra_args) {
        return this_.exec(LITERAL_STRING[1311], {key, timeout_or_key, extra_args...});
    }
    Variant bzmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count = 1);
    Variant zmpop(const Variant &keys, const Variant &from, const Variant &count = 1);
    Variant blmpop(const Variant &timeout, const Variant &keys, const Variant &from, const Variant &count = 1);
    Variant lmpop(const Variant &keys, const Variant &from, const Variant &count = 1);
    Variant clearlasterror();
    Variant client(const Variant &key_or_address, const Variant &subcommand, const Variant &arg = {});
    Variant close();
    template <typename... Args>
    Variant cluster(const Variant &key_or_address, const Variant &command, const Args &...extra_args) {
        return this_.exec(LITERAL_STRING[1313], {key_or_address, command, extra_args...});
    }
    template <typename... Args>
    Variant command(const Args &...extra_args) {
        return this_.exec(LITERAL_STRING[1069], {extra_args...});
    }
    template <typename... Args>
    Variant config(const Variant &key_or_address, const Variant &subcommand, const Args &...extra_args) {
        return this_.exec(LITERAL_STRING[1070], {key_or_address, subcommand, extra_args...});
    }
    Variant dbsize(const Variant &key_or_address);
    Variant copy(const Variant &src, const Variant &dst, const Variant &options = {});
    Variant decr(const Variant &key, const Variant &by = 1);
    Variant decrby(const Variant &key, const Variant &value);
    Variant decrbyfloat(const Variant &key, const Variant &value);
    template <typename... Args>
    Variant del(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1076], {key, other_keys...});
    }
    Variant discard();
    Variant dump(const Variant &key);
    Variant echo(const Variant &key_or_address, const Variant &msg);
    Variant eval(const Variant &script, const Variant &args = Array{}, const Variant &num_keys = 0);
    Variant eval_ro(const Variant &script, const Variant &args = Array{}, const Variant &num_keys = 0);
    Variant evalsha(const Variant &script_sha, const Variant &args = Array{}, const Variant &num_keys = 0);
    Variant evalsha_ro(const Variant &script_sha, const Variant &args = Array{}, const Variant &num_keys = 0);
    Variant exec();
    template <typename... Args>
    Variant exists(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1084], {key, other_keys...});
    }
    template <typename... Args>
    Variant touch(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1225], {key, other_keys...});
    }
    Variant expire(const Variant &key, const Variant &timeout, const Variant &mode = {});
    Variant expireat(const Variant &key, const Variant &timestamp, const Variant &mode = {});
    Variant expiretime(const Variant &key);
    Variant pexpiretime(const Variant &key);
    Variant flushall(const Variant &key_or_address, const Variant &async = false);
    Variant flushdb(const Variant &key_or_address, const Variant &async = false);
    template <typename... Args>
    Variant geoadd(const Variant &key,
                   const Variant &lng,
                   const Variant &lat,
                   const Variant &member,
                   const Args &...other_triples_and_options) {
        return this_.exec(LITERAL_STRING[1095], {key, lng, lat, member, other_triples_and_options...});
    }
    Variant geodist(const Variant &key, const Variant &src, const Variant &dest, const Variant &unit = {});
    template <typename... Args>
    Variant geohash(const Variant &key, const Variant &member, const Args &...other_members) {
        return this_.exec(LITERAL_STRING[1097], {key, member, other_members...});
    }
    template <typename... Args>
    Variant geopos(const Variant &key, const Variant &member, const Args &...other_members) {
        return this_.exec(LITERAL_STRING[1098], {key, member, other_members...});
    }
    Variant georadius(const Variant &key,
                      const Variant &lng,
                      const Variant &lat,
                      const Variant &radius,
                      const Variant &unit,
                      const Variant &options = Array{});
    Variant georadius_ro(const Variant &key,
                         const Variant &lng,
                         const Variant &lat,
                         const Variant &radius,
                         const Variant &unit,
                         const Variant &options = Array{});
    Variant georadiusbymember(const Variant &key,
                              const Variant &member,
                              const Variant &radius,
                              const Variant &unit,
                              const Variant &options = Array{});
    Variant georadiusbymember_ro(const Variant &key,
                                 const Variant &member,
                                 const Variant &radius,
                                 const Variant &unit,
                                 const Variant &options = Array{});
    Variant geosearch(const Variant &key,
                      const Variant &position,
                      const Variant &shape,
                      const Variant &unit,
                      const Variant &options = Array{});
    Variant geosearchstore(const Variant &dst,
                           const Variant &src,
                           const Variant &position,
                           const Variant &shape,
                           const Variant &unit,
                           const Variant &options = Array{});
    Variant get(const Variant &key);
    Variant getdel(const Variant &key);
    Variant getWithMeta(const Variant &key);
    Variant getex(const Variant &key, const Variant &options = Array{});
    Variant getbit(const Variant &key, const Variant &value);
    Variant getlasterror();
    Variant getmode();
    Variant getoption(const Variant &option);
    Variant getrange(const Variant &key, const Variant &start, const Variant &end);
    Variant lcs(const Variant &key1, const Variant &key2, const Variant &options = {});
    Variant getset(const Variant &key, const Variant &value);
    Variant gettransferredbytes();
    Variant cleartransferredbytes();
    template <typename... Args>
    Variant hdel(const Variant &key, const Variant &member, const Args &...other_members) {
        return this_.exec(LITERAL_STRING[1327], {key, member, other_members...});
    }
    Variant hexists(const Variant &key, const Variant &member);
    Variant hget(const Variant &key, const Variant &member);
    Variant hgetall(const Variant &key);
    Variant hincrby(const Variant &key, const Variant &member, const Variant &value);
    Variant hincrbyfloat(const Variant &key, const Variant &member, const Variant &value);
    Variant hkeys(const Variant &key);
    Variant hlen(const Variant &key);
    Variant hmget(const Variant &key, const Variant &keys);
    Variant hmset(const Variant &key, const Variant &key_values);
    Variant hscan(const Variant &key, const Reference &iterator, const Variant &pattern = {}, const Variant &count = 0);
    Variant expiremember(const Variant &key, const Variant &field, const Variant &ttl, const Variant &unit = {});
    Variant expirememberat(const Variant &key, const Variant &field, const Variant &timestamp);
    Variant hrandfield(const Variant &key, const Variant &options = {});
    Variant hset(const Variant &key, const Variant &member, const Variant &value);
    Variant hsetnx(const Variant &key, const Variant &member, const Variant &value);
    Variant hstrlen(const Variant &key, const Variant &field);
    Variant hvals(const Variant &key);
    Variant incr(const Variant &key, const Variant &by = 1);
    Variant incrby(const Variant &key, const Variant &value);
    Variant incrbyfloat(const Variant &key, const Variant &value);
    template <typename... Args>
    Variant info(const Variant &key_or_address, const Args &...sections) {
        return this_.exec(LITERAL_STRING[1147], {key_or_address, sections...});
    }
    Variant keys(const Variant &pattern);
    Variant lastsave(const Variant &key_or_address);
    Variant lget(const Variant &key, const Variant &index);
    Variant lindex(const Variant &key, const Variant &index);
    Variant linsert(const Variant &key, const Variant &pos, const Variant &pivot, const Variant &value);
    Variant llen(const Variant &key);
    Variant lpop(const Variant &key, const Variant &count = 0);
    Variant lpos(const Variant &key, const Variant &value, const Variant &options = {});
    template <typename... Args>
    Variant lpush(const Variant &key, const Variant &value, const Args &...other_values) {
        return this_.exec(LITERAL_STRING[1350], {key, value, other_values...});
    }
    Variant lpushx(const Variant &key, const Variant &value);
    Variant lrange(const Variant &key, const Variant &start, const Variant &end);
    Variant lrem(const Variant &key, const Variant &value, const Variant &count = 0);
    Variant lset(const Variant &key, const Variant &index, const Variant &value);
    Variant ltrim(const Variant &key, const Variant &start, const Variant &end);
    Variant mget(const Variant &keys);
    Variant mset(const Variant &key_values);
    Variant msetnx(const Variant &key_values);
    Variant multi(const Variant &value = 1);
    Variant object(const Variant &subcommand, const Variant &key);
    Variant persist(const Variant &key);
    Variant pexpire(const Variant &key, const Variant &timeout, const Variant &mode = {});
    Variant pexpireat(const Variant &key, const Variant &timestamp, const Variant &mode = {});
    Variant pfadd(const Variant &key, const Variant &elements);
    Variant pfcount(const Variant &key);
    Variant pfmerge(const Variant &key, const Variant &keys);
    Variant ping(const Variant &key_or_address, const Variant &message = {});
    Variant psetex(const Variant &key, const Variant &timeout, const Variant &value);
    Variant psubscribe(const Variant &patterns, const Variant &callback);
    Variant pttl(const Variant &key);
    Variant publish(const Variant &channel, const Variant &message);
    template <typename... Args>
    Variant pubsub(const Variant &key_or_address, const Args &...values) {
        return this_.exec(LITERAL_STRING[1188], {key_or_address, values...});
    }
    template <typename... Args>
    Variant punsubscribe(const Variant &pattern, const Args &...other_patterns) {
        return this_.exec(LITERAL_STRING[1189], {pattern, other_patterns...});
    }
    Variant randomkey(const Variant &key_or_address);
    template <typename... Args>
    Variant rawcommand(const Variant &key_or_address, const Variant &command, const Args &...args) {
        return this_.exec(LITERAL_STRING[1192], {key_or_address, command, args...});
    }
    Variant rename(const Variant &key_src, const Variant &key_dst);
    Variant renamenx(const Variant &key, const Variant &newkey);
    Variant restore(const Variant &key, const Variant &timeout, const Variant &value, const Variant &options = {});
    Variant role(const Variant &key_or_address);
    Variant rpop(const Variant &key, const Variant &count = 0);
    Variant rpoplpush(const Variant &src, const Variant &dst);
    template <typename... Args>
    Variant rpush(const Variant &key, const Args &...elements) {
        return this_.exec(LITERAL_STRING[1357], {key, elements...});
    }
    Variant rpushx(const Variant &key, const Variant &value);
    template <typename... Args>
    Variant sadd(const Variant &key, const Variant &value, const Args &...other_values) {
        return this_.exec(LITERAL_STRING[1359], {key, value, other_values...});
    }
    Variant saddarray(const Variant &key, const Variant &values);
    Variant save(const Variant &key_or_address);
    Variant scan(const Reference &iterator,
                 const Variant &key_or_address,
                 const Variant &pattern = {},
                 const Variant &count = 0);
    Variant scard(const Variant &key);
    template <typename... Args>
    Variant script(const Variant &key_or_address, const Args &...args) {
        return this_.exec(LITERAL_STRING[1214], {key_or_address, args...});
    }
    template <typename... Args>
    Variant sdiff(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1361], {key, other_keys...});
    }
    template <typename... Args>
    Variant sdiffstore(const Variant &dst, const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1362], {dst, key, other_keys...});
    }
    Variant set(const Variant &key, const Variant &value, const Variant &options = {});
    Variant _setbit(const Variant &key, const Variant &offset, const Variant &onoff);
    Variant setex(const Variant &key, const Variant &expire, const Variant &value);
    Variant setnx(const Variant &key, const Variant &value);
    Variant setoption(const Variant &option, const Variant &value);
    Variant setrange(const Variant &key, const Variant &offset, const Variant &value);
    template <typename... Args>
    Variant sinter(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1366], {key, other_keys...});
    }
    Variant sintercard(const Variant &keys, const Variant &limit = -1);
    template <typename... Args>
    Variant sinterstore(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1367], {key, other_keys...});
    }
    Variant sismember(const Variant &key, const Variant &value);
    template <typename... Args>
    Variant smismember(const Variant &key, const Variant &member, const Args &...other_members) {
        return this_.exec(LITERAL_STRING[1368], {key, member, other_members...});
    }
    template <typename... Args>
    Variant slowlog(const Variant &key_or_address, const Args &...args) {
        return this_.exec(LITERAL_STRING[1226], {key_or_address, args...});
    }
    Variant smembers(const Variant &key);
    Variant smove(const Variant &src, const Variant &dst, const Variant &member);
    Variant sort(const Variant &key, const Variant &options = {});
    Variant sort_ro(const Variant &key, const Variant &options = {});
    Variant spop(const Variant &key, const Variant &count = 0);
    Variant srandmember(const Variant &key, const Variant &count = 0);
    template <typename... Args>
    Variant srem(const Variant &key, const Variant &value, const Args &...other_values) {
        return this_.exec(LITERAL_STRING[1233], {key, value, other_values...});
    }
    Variant sscan(const Variant &key, const Reference &iterator, const Variant &pattern = {}, const Variant &count = 0);
    Variant strlen(const Variant &key);
    Variant subscribe(const Variant &channels, const Variant &cb);
    template <typename... Args>
    Variant sunion(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1373], {key, other_keys...});
    }
    template <typename... Args>
    Variant sunionstore(const Variant &dst, const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1374], {dst, key, other_keys...});
    }
    Variant time(const Variant &key_or_address);
    Variant ttl(const Variant &key);
    Variant type(const Variant &key);
    Variant unsubscribe(const Variant &channels);
    template <typename... Args>
    Variant unlink(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1242], {key, other_keys...});
    }
    Variant unwatch();
    template <typename... Args>
    Variant watch(const Variant &key, const Args &...other_keys) {
        return this_.exec(LITERAL_STRING[1245], {key, other_keys...});
    }
    Variant xack(const Variant &key, const Variant &group, const Variant &ids);
    Variant xadd(const Variant &key,
                 const Variant &id,
                 const Variant &values,
                 const Variant &maxlen = 0,
                 const Variant &approx = false);
    Variant xclaim(const Variant &key,
                   const Variant &group,
                   const Variant &consumer,
                   const Variant &min_iddle,
                   const Variant &ids,
                   const Variant &options);
    Variant xdel(const Variant &key, const Variant &ids);
    Variant xgroup(const Variant &operation,
                   const Variant &key = {},
                   const Variant &group = {},
                   const Variant &id_or_consumer = {},
                   const Variant &mkstream = false,
                   const Variant &entries_read = -2);
    Variant xautoclaim(const Variant &key,
                       const Variant &group,
                       const Variant &consumer,
                       const Variant &min_idle,
                       const Variant &start,
                       const Variant &count = -1,
                       const Variant &justid = false);
    Variant xinfo(const Variant &operation,
                  const Variant &arg1 = {},
                  const Variant &arg2 = {},
                  const Variant &count = -1);
    Variant xlen(const Variant &key);
    Variant xpending(const Variant &key,
                     const Variant &group,
                     const Variant &start = {},
                     const Variant &end = {},
                     const Variant &count = -1,
                     const Variant &consumer = {});
    Variant xrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count = -1);
    Variant xread(const Variant &streams, const Variant &count = -1, const Variant &block = -1);
    Variant xreadgroup(const Variant &group,
                       const Variant &consumer,
                       const Variant &streams,
                       const Variant &count = 1,
                       const Variant &block = 1);
    Variant xrevrange(const Variant &key, const Variant &start, const Variant &end, const Variant &count = -1);
    Variant xtrim(const Variant &key,
                  const Variant &maxlen,
                  const Variant &approx = false,
                  const Variant &minid = false,
                  const Variant &limit = -1);
    template <typename... Args>
    Variant zadd(const Variant &key, const Variant &score_or_options, const Args &...more_scores_and_mems) {
        return this_.exec(LITERAL_STRING[1375], {key, score_or_options, more_scores_and_mems...});
    }
    Variant zcard(const Variant &key);
    Variant zcount(const Variant &key, const Variant &start, const Variant &end);
    Variant zincrby(const Variant &key, const Variant &value, const Variant &member);
    Variant zinterstore(const Variant &dst,
                        const Variant &keys,
                        const Variant &weights = {},
                        const Variant &aggregate = {});
    Variant zintercard(const Variant &keys, const Variant &limit = -1);
    Variant zlexcount(const Variant &key, const Variant &min, const Variant &max);
    Variant zpopmax(const Variant &key, const Variant &value = {});
    Variant zpopmin(const Variant &key, const Variant &value = {});
    Variant zrange(const Variant &key, const Variant &start, const Variant &end, const Variant &options = {});
    Variant zrangestore(const Variant &dstkey,
                        const Variant &srckey,
                        const Variant &start,
                        const Variant &end,
                        const Variant &options = {});
    Variant zrandmember(const Variant &key, const Variant &options = {});
    Variant zrangebylex(const Variant &key,
                        const Variant &min,
                        const Variant &max,
                        const Variant &offset = -1,
                        const Variant &count = -1);
    Variant zrangebyscore(const Variant &key,
                          const Variant &start,
                          const Variant &end,
                          const Variant &options = Array{});
    Variant zrank(const Variant &key, const Variant &member);
    template <typename... Args>
    Variant zrem(const Variant &key, const Variant &value, const Args &...other_values) {
        return this_.exec(LITERAL_STRING[1387], {key, value, other_values...});
    }
    Variant zremrangebylex(const Variant &key, const Variant &min, const Variant &max);
    Variant zremrangebyrank(const Variant &key, const Variant &min, const Variant &max);
    Variant zremrangebyscore(const Variant &key, const Variant &min, const Variant &max);
    Variant zrevrange(const Variant &key, const Variant &min, const Variant &max, const Variant &options = {});
    Variant zrevrangebylex(const Variant &key, const Variant &min, const Variant &max, const Variant &options = {});
    Variant zrevrangebyscore(const Variant &key, const Variant &min, const Variant &max, const Variant &options = {});
    Variant zrevrank(const Variant &key, const Variant &member);
    Variant zscan(const Variant &key, const Reference &iterator, const Variant &pattern = {}, const Variant &count = 0);
    Variant zscore(const Variant &key, const Variant &member);
    template <typename... Args>
    Variant zmscore(const Variant &key, const Variant &member, const Args &...other_members) {
        return this_.exec(LITERAL_STRING[1396], {key, member, other_members...});
    }
    Variant zunionstore(const Variant &dst,
                        const Variant &keys,
                        const Variant &weights = {},
                        const Variant &aggregate = {});
    Variant zinter(const Variant &keys, const Variant &weights = {}, const Variant &options = {});
    Variant zdiffstore(const Variant &dst, const Variant &keys);
    Variant zunion(const Variant &keys, const Variant &weights = {}, const Variant &options = {});
    Variant zdiff(const Variant &keys, const Variant &options = {});
};

class RedisClusterException {
    Object this_;

  public:
    RedisClusterException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class RedisSentinel {
    Object this_;

  public:
    RedisSentinel(const Variant &options = {});
    Variant ckquorum(const Variant &master);
    Variant failover(const Variant &master);
    Variant flushconfig();
    Variant getMasterAddrByName(const Variant &master);
    Variant master(const Variant &master);
    Variant masters();
    Variant myid();
    Variant ping();
    Variant reset(const Variant &pattern);
    Variant sentinels(const Variant &master);
    Variant slaves(const Variant &master);
};

class RedisException {
    Object this_;

  public:
    RedisException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

}  // namespace php
