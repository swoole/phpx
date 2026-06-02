#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/pdo.h"

namespace php {
namespace Pdo {
class Mysql;
}

namespace Pdo {

class Mysql : public PDO {
  protected:
    Mysql() = default;

  public:
    static constexpr zend_long ATTR_USE_BUFFERED_QUERY = 1000;
    static constexpr zend_long ATTR_LOCAL_INFILE = 1001;
    static constexpr zend_long ATTR_INIT_COMMAND = 1002;
    static constexpr zend_long ATTR_COMPRESS = 1003;
    static constexpr zend_long ATTR_DIRECT_QUERY = 1004;
    static constexpr zend_long ATTR_FOUND_ROWS = 1005;
    static constexpr zend_long ATTR_IGNORE_SPACE = 1006;
    static constexpr zend_long ATTR_SSL_KEY = 1007;
    static constexpr zend_long ATTR_SSL_CERT = 1008;
    static constexpr zend_long ATTR_SSL_CA = 1009;
    static constexpr zend_long ATTR_SSL_CAPATH = 1010;
    static constexpr zend_long ATTR_SSL_CIPHER = 1011;
    static constexpr zend_long ATTR_SERVER_PUBLIC_KEY = 1012;
    static constexpr zend_long ATTR_MULTI_STATEMENTS = 1013;
    static constexpr zend_long ATTR_SSL_VERIFY_SERVER_CERT = 1014;
    static constexpr zend_long ATTR_LOCAL_INFILE_DIRECTORY = 1015;

    Variant getWarningCount();
    Mysql(const Variant &dsn,
          const Variant &username = nullptr,
          const Variant &password = nullptr,
          const Variant &options = nullptr);
};

}  // namespace Pdo
}  // namespace php
