/*
 +----------------------------------------------------------------------+
 | Swoole                                                               |
 +----------------------------------------------------------------------+
 | This source file is subject to version 2.0 of the Apache license,    |
 | that is bundled with this package in the file LICENSE, and is        |
 | available through the world-wide-web at the following url:           |
 | http://www.apache.org/licenses/LICENSE-2.0.html                      |
 | If you did not receive a copy of the Apache2.0 license and are unable|
 | to obtain it through the world-wide-web, please send a note to       |
 | license@swoole.com so we can mail you a copy immediately.            |
 +----------------------------------------------------------------------+
 | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
 +----------------------------------------------------------------------+
 */

#include "phpx.h"
#include "rocksdb/db.h"
#include "rocksdb/utilities/db_ttl.h"
#include "rocksdb/merge_operator.h"
#include "merge_operators/stringappend.h"

#include <iostream>

using namespace php;
using namespace std;
using namespace rocksdb;

PHPX_METHOD(rocksDB, construct)
{
    auto _path = args[0];
    auto _option = args[1];
    auto _readoption = args[2];
    auto _writeoption = args[3];
    auto _read_only = args[4]; //0 default 1 readonly

    int read_only = 0;
    if (_read_only.isInt())
    {
        read_only = _read_only.toInt();
    }

    string path = _path.toString();
    if (!_option.isArray())
    {
        throwException("RocksDB_Exception", "RocksDB construct function parameter 2 open option should be array.");
        return;
    }

    Options options;
    options.IncreaseParallelism();
    options.OptimizeLevelStyleCompaction();

    Array option(_option);
    if (option.exists("create_if_missing"))
    {
        options.create_if_missing = true;
    }
    if (option.exists("error_if_exists") && option["error_if_exists"].toBool())
    {
        options.error_if_exists = true;
    }
    if (option.exists("paranoid_checks") && option["paranoid_checks"].toBool())
    {
        options.paranoid_checks = true;
    }
    if (option.exists("max_open_files") && option["max_open_files"].isInt())
    {
        options.max_open_files = option["max_open_files"].toInt();
    }
    char *delim_char;
    if (option.exists("merge_operator") && option["merge_operator"].isString())
    {
        delim_char = option["merge_operator"].toCString();
        options.merge_operator.reset(new StringAppendOperator(delim_char[0]));
    }

    DB* db = nullptr;
    Status s;
    if (read_only == 0)
    {
        s = DB::Open(options, path, &db);
    }
    else
    {
        s = DB::OpenForReadOnly(options, path, &db);
    }

    if (!s.ok())
    {
        string name = "RocksDB open failed msg" + s.ToString();
        throwException("RocksDB_Exception", name.c_str());
        return;
    }

    _this.oSet("rocksdb", "dbResource", db);

    WriteOptions* write_options = new WriteOptions();
    Array writeoption(_writeoption);
    if (writeoption.exists("sync") && writeoption["sync"].toBool())
    {
        write_options->sync = true;
    }
    if (writeoption.exists("disableWAL") && writeoption["disableWAL"].toBool())
    {
        write_options->disableWAL = true;
    }
    _this.oSet("write_options", "writeOptionsResource", write_options);

    ReadOptions* read_options = new ReadOptions();
    Array readoption(_readoption);
    if (readoption.exists("verify_checksums") && readoption["verify_checksums"].toBool())
    {
        read_options->verify_checksums = true;
    }
    if (readoption.exists("fill_cache") && readoption["fill_cache"].toBool())
    {
        read_options->fill_cache = true;
    }
    _this.oSet("read_options", "readOptionsResource", read_options);
}

PHPX_METHOD(rocksDB, put)
{
    WriteOptions* wop = _this.oGet<WriteOptions>("write_options", "writeOptionsResource");
    DB* db = _this.oGet<DB>("rocksdb", "dbResource");

    auto _key = args[0];
    auto _value = args[1];
    string key = _key.toString();
    string value = _value.toString();
    Status s = db->Put(*wop, key, value);
    if (!s.ok())
    {
        retval = false;
        throwException("RocksDB_Exception", "RocksDB put with read only mode");
    }
    else
    {
        retval = true;
    }
}

PHPX_METHOD(rocksDB, merge)
{
    //get write option
    WriteOptions* wop = _this.oGet<WriteOptions>("write_options", "writeOptionsResource");
    DB* db = _this.get("rocksdb").toResource<DB>("dbResource");

    auto _key = args[0];
    auto _val = args[1];
    string key = _key.toString();
    string val = _val.toString();
    Status s = db->Merge(*wop, key, val);
    if (!s.ok())
    {
        retval = false;
    }
    else
    {
        retval = true;
    }
}

PHPX_METHOD(rocksDB, get)
{
    ReadOptions* rop = _this.oGet<ReadOptions>("read_options", "readOptionsResource");
    DB* db = _this.oGet<DB>("rocksdb", "dbResource");

    auto _key = args[0];
    string key = _key.toString();
    string value;
    Status s = db->Get(*rop, key, &value);
    if (!s.ok())
    {
        retval = false;
    }
    else
    {
        retval = value;
    }
}

PHPX_METHOD(rocksDB, delete)
{
    WriteOptions* wop = _this.oGet<WriteOptions>("write_options", "writeOptionsResource");
    DB* db = _this.get("rocksdb").toResource<DB>("dbResource");

    auto _key = args[0];
    string key = _key.toString();
    Status s = db->Delete(*wop, key);
    if (!s.ok())
    {
        retval = false;
    }
    else
    {
        retval = true;
    }
}

static void dbResource_destory(zend_resource *res)
{
    DBWithTTL* db = static_cast<DBWithTTL *>(res->ptr);
    delete db;
}

static void readOptionsResource_destory(zend_resource *res)
{
    ReadOptions* r = static_cast<ReadOptions *>(res->ptr);
    delete r;
}

static void writeOptionsResource_destory(zend_resource *res)
{
    WriteOptions* w = static_cast<WriteOptions *>(res->ptr);
    delete w;
}

PHPX_EXTENSION()
{
    Extension *extension = new Extension("phpx-rocksdb", "0.0.3");

    extension->onStart = [extension]() noexcept
    {
        char version[32];
        snprintf(version, sizeof(version), "%d.%d.%d", ROCKSDB_MAJOR, ROCKSDB_MINOR, ROCKSDB_PATCH);
        extension->registerConstant("ROCKSDB_VERSION", version);

        Class *c = new Class("RocksDB");
        c->addMethod("__construct", rocksDB_construct);
        c->addMethod("put" , rocksDB_put);
        c->addMethod("get" , rocksDB_get);
        c->addMethod("delete" , rocksDB_delete);
        c->addMethod("merge" , rocksDB_merge);

        extension->registerClass(c);

        Class *ex = new Class("RocksDB_Exception");
        ex->extends(zend_exception_get_default());
        extension->registerClass(ex);

        extension->registerResource("dbResource", dbResource_destory);
        extension->registerResource("writeOptionsResource", writeOptionsResource_destory);
        extension->registerResource("readOptionsResource", readOptionsResource_destory);
    };
    return extension;
}
