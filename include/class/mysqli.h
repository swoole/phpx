#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/spl.h"

namespace php {
class mysqli_sql_exception;
class mysqli_driver;
class mysqli_warning;
class mysqli_result;
class mysqli;
class mysqli_stmt;

class mysqli_sql_exception : public RuntimeException {
  public:
    Variant getSqlState();
    mysqli_sql_exception(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class mysqli_driver {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit mysqli_driver(const Object &obj) : this_(obj) {}
    mysqli_driver();
};

class mysqli_warning {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Variant next();
};

class mysqli_result {
  protected:
    Object this_;
    mysqli_result() = default;

  public:
    Object getObject() const {
        return this_;
    }
    mysqli_result(const mysqli &mysql, const Variant &result_mode = 0);
    Variant close();
    Variant free();
    Variant data_seek(const Variant &offset);
    Variant fetch_field();
    Variant fetch_fields();
    Variant fetch_field_direct(const Variant &index);
    Variant fetch_all(const Variant &mode = 2);
    Variant fetch_array(const Variant &mode = 3);
    Variant fetch_assoc();
    Variant fetch_object(const Variant &class_ = "stdClass", const Variant &constructor_args = Array{});
    Variant fetch_row();
    Variant fetch_column(const Variant &column = 0);
    Variant field_seek(const Variant &index);
    Variant free_result();
    Variant getIterator();
};

class mysqli {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    mysqli(const Variant &hostname = {},
           const Variant &username = {},
           const Variant &password = {},
           const Variant &database = {},
           const Variant &port = {},
           const Variant &socket = {});
    Variant autocommit(const Variant &enable);
    Variant begin_transaction(const Variant &flags = 0, const Variant &name = {});
    Variant change_user(const Variant &username, const Variant &password, const Variant &database);
    Variant character_set_name();
    Variant close();
    Variant commit(const Variant &flags = 0, const Variant &name = {});
    Variant connect(const Variant &hostname = {},
                    const Variant &username = {},
                    const Variant &password = {},
                    const Variant &database = {},
                    const Variant &port = {},
                    const Variant &socket = {});
    Variant dump_debug_info();
    Variant debug(const Variant &options);
    Variant get_charset();
    Variant execute_query(const Variant &query, const Variant &params = {});
    Variant get_client_info();
    Variant get_connection_stats();
    Variant get_server_info();
    Variant get_warnings();
    Variant init();
    Variant kill(const Variant &process_id);
    Variant multi_query(const Variant &query);
    Variant more_results();
    Variant next_result();
    Variant ping();
    static Variant poll(const Reference &read,
                        const Reference &error,
                        const Reference &reject,
                        const Variant &seconds,
                        const Variant &microseconds = 0);
    Variant prepare(const Variant &query);
    Variant query(const Variant &query, const Variant &result_mode = 0);
    Variant real_connect(const Variant &hostname = {},
                         const Variant &username = {},
                         const Variant &password = {},
                         const Variant &database = {},
                         const Variant &port = {},
                         const Variant &socket = {},
                         const Variant &flags = 0);
    Variant real_escape_string(const Variant &string);
    Variant reap_async_query();
    Variant escape_string(const Variant &string);
    Variant real_query(const Variant &query);
    Variant release_savepoint(const Variant &name);
    Variant rollback(const Variant &flags = 0, const Variant &name = {});
    Variant savepoint(const Variant &name);
    Variant select_db(const Variant &database);
    Variant set_charset(const Variant &charset);
    Variant options(const Variant &option, const Variant &value);
    Variant set_opt(const Variant &option, const Variant &value);
    Variant ssl_set(const Variant &key,
                    const Variant &certificate,
                    const Variant &ca_certificate,
                    const Variant &ca_path,
                    const Variant &cipher_algos);
    Variant stat();
    Variant stmt_init();
    Variant store_result(const Variant &mode = 0);
    Variant thread_safe();
    Variant use_result();
    Variant refresh(const Variant &flags);
};

class mysqli_stmt {
  protected:
    Object this_;
    mysqli_stmt() = default;

  public:
    Object getObject() const {
        return this_;
    }
    mysqli_stmt(const mysqli &mysql, const Variant &query = {});
    Variant attr_get(const Variant &attribute);
    Variant attr_set(const Variant &attribute, const Variant &value);
    template <typename... Args>
    Variant bind_param(const Variant &types, const Args &...vars) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[952]);
        }
        return this_.call(_method_fn, {types, vars...});
    }
    template <typename... Args>
    Variant bind_result(const Args &...vars) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[953]);
        }
        return this_.call(_method_fn, {vars...});
    }
    Variant close();
    Variant data_seek(const Variant &offset);
    Variant execute(const Variant &params = {});
    Variant fetch();
    Variant get_warnings();
    Variant result_metadata();
    Variant more_results();
    Variant next_result();
    Variant num_rows();
    Variant send_long_data(const Variant &param_num, const Variant &data);
    Variant free_result();
    Variant reset();
    Variant prepare(const Variant &query);
    Variant store_result();
    Variant get_result();
};

}  // namespace php
