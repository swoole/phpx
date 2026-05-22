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
    static constexpr int ATTR_USE_BUFFERED_QUERY = 1000;
    static constexpr int ATTR_LOCAL_INFILE = 1001;
    static constexpr int ATTR_INIT_COMMAND = 1002;
    static constexpr int ATTR_COMPRESS = 1003;
    static constexpr int ATTR_DIRECT_QUERY = 1004;
    static constexpr int ATTR_FOUND_ROWS = 1005;
    static constexpr int ATTR_IGNORE_SPACE = 1006;
    static constexpr int ATTR_SSL_KEY = 1007;
    static constexpr int ATTR_SSL_CERT = 1008;
    static constexpr int ATTR_SSL_CA = 1009;
    static constexpr int ATTR_SSL_CAPATH = 1010;
    static constexpr int ATTR_SSL_CIPHER = 1011;
    static constexpr int ATTR_SERVER_PUBLIC_KEY = 1012;
    static constexpr int ATTR_MULTI_STATEMENTS = 1013;
    static constexpr int ATTR_SSL_VERIFY_SERVER_CERT = 1014;
    static constexpr int ATTR_LOCAL_INFILE_DIRECTORY = 1015;

    Variant getWarningCount();
    Mysql(const Variant &dsn, const Variant &username = {}, const Variant &password = {}, const Variant &options = {});
};

}  // namespace Pdo
}  // namespace php
