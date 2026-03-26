#include "phpx_literal_string.h"

namespace php {
class BcMath_Number {
    Object this_;

  public:
    BcMath_Number(const Variant &num);
    Variant add(const Variant &num, const Variant &scale = {});
    Variant sub(const Variant &num, const Variant &scale = {});
    Variant mul(const Variant &num, const Variant &scale = {});
    Variant div(const Variant &num, const Variant &scale = {});
    Variant mod(const Variant &num, const Variant &scale = {});
    Variant divmod(const Variant &num, const Variant &scale = {});
    Variant powmod(const Variant &exponent, const Variant &modulus, const Variant &scale = {});
    Variant pow(const Variant &exponent, const Variant &scale = {});
    Variant sqrt(const Variant &scale = {});
    Variant floor();
    Variant ceil();
    Variant round(const Variant &precision = 0, const Variant &mode = {});
    Variant compare(const Variant &num, const Variant &scale = {});
    Variant __toString();
    Variant __serialize();
    Variant __unserialize(const Variant &data);
};

}  // namespace php
