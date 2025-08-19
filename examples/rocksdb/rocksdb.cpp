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
 | Author: shiguangqi  <shiguangqi2008@gmail.com>                        |
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

PHPX_METHOD(rocksDB, construct) {
	auto _path = args[0];
	auto _option = args[1];
	auto _readoption = args[2];
	auto _writeoption = args[3];
	auto _mode = args[4]; //0 default 1 readonly 2 openAsSecondary
	auto _ttl = args[5]; //0 default x ttl time second
	auto _secondary_path = args[6];//SecondaryPath

	int mode = 0;//default
	if (_mode.isInt()) {
		mode = _mode.toInt();
	}
	int32_t ttl = 0;
	if (_ttl.isInt() && _ttl.toInt() > 0) {
		ttl = (int32_t) _ttl.toInt();
	}
	string path = _path.toStdString();
	string secondary_path = _secondary_path.toStdString();
	if (!_option.isArray()) {
		throwException("\\Exception",
				"RocksDB construct function parameter 2 open option should be array.");
		return;
	}
	//open option 处理
	Options options;
	options.IncreaseParallelism();
	options.OptimizeLevelStyleCompaction();

	Array option(_option);
	if (option.exists("create_if_missing")) {
		options.create_if_missing = true;
	}
	if (option.exists("error_if_exists")
			&& option["error_if_exists"].toBool()) {
		options.error_if_exists = true;
	}
	if (option.exists("paranoid_checks")
			&& option["paranoid_checks"].toBool()) {
		options.paranoid_checks = true;
	}
	if (option.exists("max_open_files") && option["max_open_files"].isInt()) {
		options.max_open_files = option["max_open_files"].toInt();
	}
	char *delim_char;
	if (option.exists("merge_operator") && option["merge_operator"].isString()) {
		delim_char = option["merge_operator"].toCString();
		options.merge_operator.reset(new StringAppendOperator(delim_char[0]));
	}

	Status s;
	if (ttl > 0 && mode == 0) {
		DBWithTTL* db;
		s = DBWithTTL::Open(options, path, &db, ttl);
		//抛出异常
		if (!s.ok()) {
			string name = "RocksDB open failed msg"+s.ToString();
			throwException("\\Exception",name.c_str());
			return;
		}
		_this.oSet("rocksdb", "dbResource", db);
	} else if (ttl > 0 && mode == 1) {
		DBWithTTL* db;
		s = DBWithTTL::Open(options, path, &db, ttl, true);
		//抛出异常
		if (!s.ok()) {
			string name = "RocksDB open failed msg"+s.ToString();
			throwException("\\Exception",name.c_str());
			return;
		}
		_this.oSet("rocksdb", "dbResource", db);
	} else if (mode == 0) {
		DB* db;
		s = DB::Open(options, path, &db);
		//抛出异常
		if (!s.ok()) {
			string name = "RocksDB open failed msg"+s.ToString();
			throwException("\\Exception",name.c_str());
			return;
		}
		_this.oSet("rocksdb", "dbResource", db);
	} else if (mode == 2) {
		DB* db;
		s = DB::OpenAsSecondary(options, path, secondary_path, &db);
		//抛出异常
		if (!s.ok()) {
			string name = "RocksDB open failed msg"+s.ToString();
			throwException("\\Exception",name.c_str());
			return;
		}
		_this.oSet("rocksdb", "dbResource", db);
	} else {
		DB* db;
		s = DB::OpenForReadOnly(options, path, &db);
		//抛出异常
		if (!s.ok()) {
			string name = "RocksDB open failed msg"+s.ToString();
			throwException("\\Exception",name.c_str());
			return;
		}
		_this.oSet("rocksdb", "dbResource", db);
	}

	assert(s.ok());

	//WriteOptions
	WriteOptions* write_options = new WriteOptions();
	Array writeoption(_writeoption);
	if (writeoption.exists("sync") && writeoption["sync"].toBool()) {
		write_options->sync = true;
	}
	if (writeoption.exists("disableWAL")
			&& writeoption["disableWAL"].toBool()) {
		write_options->disableWAL = true;
	}
	_this.oSet("write_options", "writeOptionsResource", write_options);

	//ReadOptions
	ReadOptions* read_options = new ReadOptions();
	Array readoption(_readoption);
	if (readoption.exists("verify_checksums")
			&& readoption["verify_checksums"].toBool()) {
		read_options->verify_checksums = true;
	}
	if (readoption.exists("fill_cache") && readoption["fill_cache"].toBool()) {
		read_options->fill_cache = true;
	}
	_this.oSet("read_options", "readOptionsResource", read_options);
}

PHPX_METHOD(rocksDB, put) {
	//get write option
	WriteOptions* wop = _this.oGet<WriteOptions>("write_options","writeOptionsResource");
	DB* db = _this.oGet<DB>("rocksdb","dbResource");

	auto _key = args[0];
	auto _value = args[1];
	string key = _key.toStdString();
	string value = _value.toStdString();
	Status s = db->Put(*wop, key, value);
	if (!s.ok()) {
		retval = false;
		throwException("\\Exception", "RocksDB put with read only mode");
	} else {
		retval = true;
	}
}

PHPX_METHOD(rocksDB, merge) {
	//get write option
	WriteOptions* wop = _this.oGet<WriteOptions>("write_options","writeOptionsResource");
	DB* db = _this.get("rocksdb").toResource<DB>("dbResource");

	auto _key = args[0];
	auto _val = args[1];
	string key = _key.toStdString();
	string val = _val.toStdString();
	Status s = db->Merge(*wop, key, val);
	if (!s.ok()) {
		retval = false;
	} else {
		retval = true;
	}
}

PHPX_METHOD(rocksDB, get) {
	//get read option
	ReadOptions* rop = _this.oGet<ReadOptions>("read_options","readOptionsResource");
	DB* db = _this.oGet<DB>("rocksdb","dbResource");

	auto _key = args[0];
	string key = _key.toStdString();
	string value;
	Status s = db->Get(*rop, key, &value);
	if (!s.ok()) {
		retval = false;
	} else {
		retval = value;
	}
}

PHPX_METHOD(rocksDB, delete) {
	//get write option
	WriteOptions* wop = _this.oGet<WriteOptions>("write_options","writeOptionsResource");
	DB* db = _this.get("rocksdb").toResource<DB>("dbResource");

	auto _key = args[0];
	string key = _key.toStdString();
	Status s = db->Delete(*wop, key);
	if (!s.ok()) {
		retval = false;
	} else {
		retval = true;
	}
}

PHPX_METHOD(rocksDB, tryCatchUpWithPrimary) {
	DB* db = _this.get("rocksdb").toResource<DB>("dbResource");
	Status s = db->TryCatchUpWithPrimary();
	if (!s.ok()) {
		retval = false;
	} else {
		retval = true;
	}
}

static void dbResource_destory(zend_resource *res) {
	DB* db = static_cast<DB *>(res->ptr);
	delete db;
}

static void readOptionsResource_destory(zend_resource *res) {
	ReadOptions* r = static_cast<ReadOptions *>(res->ptr);
	delete r;
}

static void writeOptionsResource_destory(zend_resource *res) {
	WriteOptions* w = static_cast<WriteOptions *>(res->ptr);
	delete w;
}

PHPX_EXTENSION()
{
	Extension *extension = new Extension("phpx-rocksdb", "0.0.2");

	extension->onStart =
			[extension]() noexcept
			{
//				cout << extension->name << "startup" << endl;
				extension->registerConstant("ROCKSDB_EXT_VERSION", 1002);
				Class *c = new Class("RocksDB");
				c->addMethod("__construct", rocksDB_construct);
				c->addMethod("put" , rocksDB_put);
				c->addMethod("get" , rocksDB_get);
				c->addMethod("delete" , rocksDB_delete);
				c->addMethod("merge" , rocksDB_merge);
				c->addMethod("tryCatchUpWithPrimary" , rocksDB_tryCatchUpWithPrimary);

				c->addProperty("version" , "1.0.2", STATIC);

				extension->registerClass(c);

				extension->registerResource("dbResource", dbResource_destory);
				extension->registerResource("writeOptionsResource", writeOptionsResource_destory);
				extension->registerResource("readOptionsResource", readOptionsResource_destory);

			};
	return extension;
}
