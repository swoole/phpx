/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Type checking, misc, and variable function wrappers      |
  +----------------------------------------------------------------------+
  | Implementations for microtime, hrtime, crc32, pack/unpack,            |
  | and HTML entity functions.                                            |
  +----------------------------------------------------------------------+
*/

#include "php_std_misc.h"

#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <cerrno>
#include <sys/time.h>
#include <ctime>

namespace php::std {

// ========================
// microtime
// ========================

Variant microtime(bool as_float) {
    struct timeval tp = {0};

    if (gettimeofday(&tp, nullptr) != 0) {
        // gettimeofday shouldn't fail, but return false if it does
        return Variant(false);
    }

    if (as_float) {
        return Variant((double)(tp.tv_sec + tp.tv_usec / 1000000.0));
    }

    // Return as formatted string: "0.12345678 1234567890"
    char buf[64];
    int len = snprintf(buf, sizeof(buf), "%.8F %ld",
                       tp.tv_usec / 1000000.0,
                       (long)tp.tv_sec);
    return Variant(buf, static_cast<size_t>(len));
}

// ========================
// hrtime
// ========================

Variant hrtime(bool as_number) {
#if ZEND_HRTIME_AVAILABLE
    zend_hrtime_t t = zend_hrtime();

    if (as_number) {
#ifdef ZEND_ENABLE_ZVAL_LONG64
        return Variant(static_cast<Int>(t));
#else
        // On 32-bit platforms, return as double
        char buf[ZEND_LTOA_BUF_LEN];
        int len = snprintf(buf, sizeof(buf), "%llu", (unsigned long long)t);
        buf[len] = '\0';
        double d = zend_strtod(buf, nullptr);
        return Variant(d);
#endif
    } else {
        Array result;
        result.set(String("0"), Variant(static_cast<Int>(t / 1000000000ULL)));
        result.set(String("1"), Variant(static_cast<Int>(t % 1000000000ULL)));
        return Variant(result);
    }
#else
    return Variant(false);
#endif
}

// ========================
// pack — simplified implementation for common numeric formats
// ========================

// Helper: reverse bytes in a 16-bit integer
static inline uint16_t rev16(uint16_t v) {
    return (uint16_t)(((v & 0xFF) << 8) | ((v >> 8) & 0xFF));
}

// Helper: reverse bytes in a 32-bit integer
static inline uint32_t rev32(uint32_t v) {
    return ((v & 0xFF) << 24) | ((v & 0x00FF0000) >> 8) |
           ((v & 0x0000FF00) << 8) | ((v >> 24) & 0xFF);
}

// Determine machine endianness
#ifdef WORDS_BIGENDIAN
static constexpr bool MACHINE_LITTLE_ENDIAN = false;
#else
static constexpr bool MACHINE_LITTLE_ENDIAN = true;
#endif

// Helper: pack an integer value into output buffer with given size and endianness
static void do_pack(zend_long val, size_t size, bool little_endian, char *output) {
    if (little_endian != MACHINE_LITTLE_ENDIAN) {
        // Need to swap
        if (size == 2) {
            uint16_t v = (uint16_t)val;
            v = rev16(v);
            if (MACHINE_LITTLE_ENDIAN) {
                v >>= (sizeof(v) - size) * 8;
            }
            memcpy(output, &v, size);
        } else if (size == 4) {
            uint32_t v = (uint32_t)val;
            v = rev32(v);
            if (MACHINE_LITTLE_ENDIAN) {
                v >>= (sizeof(v) - size) * 8;
            }
            memcpy(output, &v, size);
        } else if (size == 8) {
            uint64_t v = (uint64_t)val;
            // reverse 64-bit
            uint32_t lo = (uint32_t)(v & 0xFFFFFFFFULL);
            uint32_t hi = (uint32_t)(v >> 32);
            lo = rev32(lo);
            hi = rev32(hi);
            v = ((uint64_t)lo << 32) | hi;
            if (MACHINE_LITTLE_ENDIAN) {
                v >>= (sizeof(v) - size) * 8;
            }
            memcpy(output, &v, size);
        } else {
            memcpy(output, &val, size);
        }
    } else {
        // Same endianness, just shift for big-endian platform
#ifdef WORDS_BIGENDIAN
        uint64_t v = (uint64_t)val;
        v <<= (sizeof(v) - size) * 8;
        memcpy(output, &v, size);
#else
        memcpy(output, &val, size);
#endif
    }
}

Variant pack(const String &format, const Variant &values) {
    const char *fmt = format.data();
    size_t fmt_len = format.length();

    // First pass: calculate output size
    size_t output_size = 0;
    size_t arg_idx = 0;

    for (size_t i = 0; i < fmt_len; i++) {
        char code = fmt[i];
        int count = 1;

        if (i + 1 < fmt_len) {
            char next = fmt[i + 1];
            if (next == '*') {
                // '*' means use all remaining args — we can't pre-compute, skip
                i++;
                count = 0; // will be handled in second pass
            } else if (next >= '0' && next <= '9') {
                count = atoi(&fmt[i + 1]);
                while (i + 1 < fmt_len && fmt[i + 1] >= '0' && fmt[i + 1] <= '9') {
                    i++;
                }
            }
        }

        if (count <= 0) continue; // '*' handled in second pass

        switch (code) {
            case 'c': case 'C': case 'x':
                output_size += count;
                break;
            case 's': case 'S': case 'n': case 'v':
                output_size += count * 2;
                break;
            case 'i': case 'I':
                output_size += count * sizeof(int);
                break;
            case 'l': case 'L': case 'N': case 'V':
                output_size += count * 4;
                break;
            case 'f': case 'g': case 'G':
                output_size += count * sizeof(float);
                break;
            case 'd': case 'e': case 'E':
                output_size += count * sizeof(double);
                break;
            default:
                // Unsupported format code — skip
                break;
        }
    }

    // Second pass: actually pack values
    // Get the values array
    Array args;
    if (values.isArray()) {
        args = values.toArray();
    } else {
        // Values passed as single arg or variadic — wrap in array
        args = Array(1);
        args.set(static_cast<zend_ulong>(0), values);
    }

    zend_string *output = zend_string_alloc(output_size, 0);
    memset(ZSTR_VAL(output), 0, output_size);

    size_t output_pos = 0;
    arg_idx = 0;

    for (size_t i = 0; i < fmt_len; i++) {
        char code = fmt[i];
        int count = 1;

        if (i + 1 < fmt_len) {
            char next = fmt[i + 1];
            if (next == '*') {
                i++;
                count = 0;
                // Skip this code with '*'
                continue;
            } else if (next >= '0' && next <= '9') {
                count = atoi(&fmt[i + 1]);
                while (i + 1 < fmt_len && fmt[i + 1] >= '0' && fmt[i + 1] <= '9') {
                    i++;
                }
            }
        }

        for (int j = 0; j < count; j++) {
            if (arg_idx >= args.count()) {
                break;
            }

            Variant arg = args.get(static_cast<zend_ulong>(arg_idx));
            arg_idx++;

            switch (code) {
                case 'c':   // signed char
                case 'C':   // unsigned char
                {
                    int8_t c = (int8_t)arg.toInt();
                    ZSTR_VAL(output)[output_pos++] = (char)c;
                    break;
                }

                case 's':   // signed short (machine endian)
                case 'S':   // unsigned short (machine endian)
                {
                    do_pack(arg.toInt(), 2, MACHINE_LITTLE_ENDIAN, &ZSTR_VAL(output)[output_pos]);
                    output_pos += 2;
                    break;
                }

                case 'n':   // unsigned short (big endian)
                {
                    do_pack(arg.toInt(), 2, false, &ZSTR_VAL(output)[output_pos]);
                    output_pos += 2;
                    break;
                }

                case 'v':   // unsigned short (little endian)
                {
                    do_pack(arg.toInt(), 2, true, &ZSTR_VAL(output)[output_pos]);
                    output_pos += 2;
                    break;
                }

                case 'i':   // signed int (machine size, machine endian)
                case 'I':   // unsigned int (machine size, machine endian)
                {
                    do_pack(arg.toInt(), sizeof(int), MACHINE_LITTLE_ENDIAN, &ZSTR_VAL(output)[output_pos]);
                    output_pos += sizeof(int);
                    break;
                }

                case 'l':   // signed long (32-bit, machine endian)
                case 'L':   // unsigned long (32-bit, machine endian)
                {
                    do_pack(arg.toInt(), 4, MACHINE_LITTLE_ENDIAN, &ZSTR_VAL(output)[output_pos]);
                    output_pos += 4;
                    break;
                }

                case 'N':   // unsigned long (32-bit, big endian)
                {
                    do_pack(arg.toInt(), 4, false, &ZSTR_VAL(output)[output_pos]);
                    output_pos += 4;
                    break;
                }

                case 'V':   // unsigned long (32-bit, little endian)
                {
                    do_pack(arg.toInt(), 4, true, &ZSTR_VAL(output)[output_pos]);
                    output_pos += 4;
                    break;
                }

                case 'f':   // float (machine endian)
                {
                    float val = (float)arg.toFloat();
                    memcpy(&ZSTR_VAL(output)[output_pos], &val, sizeof(float));
                    output_pos += sizeof(float);
                    break;
                }

                case 'd':   // double (machine endian)
                {
                    double val = arg.toFloat();
                    memcpy(&ZSTR_VAL(output)[output_pos], &val, sizeof(double));
                    output_pos += sizeof(double);
                    break;
                }

                default:
                    break;
            }
        }
    }

    ZSTR_VAL(output)[output_pos] = '\0';
    ZSTR_LEN(output) = output_pos;

    return Variant(output, php::Ctor::Move);
}

// ========================
// unpack — simplified implementation for common numeric formats
// ========================

Variant unpack(const String &format, const String &data, Int offset) {
    const char *fmt = format.data();
    size_t fmt_len = format.length();
    const char *input = data.data();
    Int input_len = static_cast<Int>(data.length());

    if (offset < 0 || offset > input_len) {
        // Invalid offset
        return Variant(false);
    }

    input += offset;
    input_len -= offset;

    Array result;

    for (size_t i = 0; i < fmt_len; ) {
        char type = fmt[i++];
        int count = 1;

        // Parse count
        if (i < fmt_len) {
            char c = fmt[i];
            if (c == '*') {
                count = -1;
                i++;
            } else if (c >= '0' && c <= '9') {
                errno = 0;
                long tmp = strtol(&fmt[i], nullptr, 10);
                if (errno || tmp < INT_MIN || tmp > INT_MAX) {
                    return Variant(false);
                }
                count = (int)tmp;
                while (i < fmt_len && fmt[i] >= '0' && fmt[i] <= '9') {
                    i++;
                }
            }
        }

        // Parse name
        const char *name_start = &fmt[i];
        while (i < fmt_len && fmt[i] != '/') {
            i++;
        }
        size_t name_len = (size_t)(&fmt[i] - name_start);
        if (name_len > 200) name_len = 200;

        // Determine element size
        int size = 0;
        switch (type) {
            case 'c': case 'C': size = 1; break;
            case 's': case 'S': case 'n': case 'v': size = 2; break;
            case 'i': case 'I': size = sizeof(int); break;
            case 'l': case 'L': case 'N': case 'V': size = 4; break;
            case 'f': case 'g': case 'G': size = sizeof(float); break;
            case 'd': case 'e': case 'E': size = sizeof(double); break;
            default:
                return Variant(false);
        }

        int remaining = (int)(input_len);
        int reps = count;

        if (count < 0) {
            // '*' means as many as fit
            reps = (size > 0) ? (remaining / size) : 0;
        }

        for (int j = 0; j < reps; j++) {
            int pos = j * size;

            if (pos + size > remaining) {
                break;
            }

            // Build key name
            bool use_numeric_key = (name_len == 0);
            String key;
            if (!use_numeric_key) {
                if (reps == 1) {
                    key = String(name_start, name_len);
                } else {
                    char buf[32];
                    int blen = snprintf(buf, sizeof(buf), "%d", j + 1);
                    zend_string *tmp = zend_string_concat2(
                        name_start, name_len, buf, static_cast<size_t>(blen));
                    key = String(tmp, php::Ctor::Move);
                }
            }

            Variant val;

            switch (type) {
                case 'c':   // signed char
                {
                    int8_t x = (int8_t)input[pos];
                    val = Variant(static_cast<Int>(x));
                    break;
                }
                case 'C':   // unsigned char
                {
                    uint8_t x = (uint8_t)input[pos];
                    val = Variant(static_cast<Int>(x));
                    break;
                }
                case 's':   // signed short (machine endian)
                {
                    int16_t x;
                    memcpy(&x, &input[pos], 2);
                    val = Variant(static_cast<Int>(x));
                    break;
                }
                case 'S':   // unsigned short (machine endian)
                case 'v':   // unsigned short (little endian)
                case 'n':   // unsigned short (big endian)
                {
                    uint16_t x;
                    memcpy(&x, &input[pos], 2);
#ifdef WORDS_BIGENDIAN
                    if (type == 'v') x = rev16(x);
                    if (type == 'n' && !WORDS_BIGENDIAN) x = rev16(x);
#else
                    if (type == 'n') x = rev16(x);
#endif
                    val = Variant(static_cast<Int>(x));
                    break;
                }
                case 'i':   // signed int (machine endian)
                {
                    int x;
                    memcpy(&x, &input[pos], sizeof(int));
                    val = Variant(static_cast<Int>(x));
                    break;
                }
                case 'I':   // unsigned int (machine endian)
                {
                    unsigned int x;
                    memcpy(&x, &input[pos], sizeof(int));
                    val = Variant(static_cast<Int>(x));
                    break;
                }
                case 'l':   // signed 32-bit (machine endian)
                {
                    int32_t x;
                    memcpy(&x, &input[pos], 4);
                    val = Variant(static_cast<Int>(x));
                    break;
                }
                case 'L':   // unsigned 32-bit (machine endian)
                case 'V':   // unsigned 32-bit (little endian)
                case 'N':   // unsigned 32-bit (big endian)
                {
                    uint32_t x;
                    memcpy(&x, &input[pos], 4);
#ifdef WORDS_BIGENDIAN
                    if (type == 'V') x = rev32(x);
                    if (type == 'N' && !WORDS_BIGENDIAN) x = rev32(x);
#else
                    if (type == 'N') x = rev32(x);
#endif
                    val = Variant(static_cast<Int>(x));
                    break;
                }
                case 'f':   // float (machine endian)
                {
                    float v;
                    memcpy(&v, &input[pos], sizeof(float));
                    val = Variant(static_cast<double>(v));
                    break;
                }
                case 'd':   // double (machine endian)
                {
                    double v;
                    memcpy(&v, &input[pos], sizeof(double));
                    val = Variant(v);
                    break;
                }
                default:
                    val = Variant(static_cast<Int>(0));
                    break;
            }

            if (use_numeric_key) {
                result.set(static_cast<zend_ulong>(j + 1), val);
            } else {
                result.set(key, val);
            }
        }

        // Skip '/' separator
        if (i < fmt_len && fmt[i] == '/') {
            i++;
        }
    }

    return Variant(result);
}

// ========================
// HTML entity functions — delegate to PHPAPI functions
// ========================

static inline const char *resolve_encoding(const Variant &encoding, const char *default_enc) {
    if (encoding.isNull()) {
        return default_enc;
    }
    if (encoding.isString()) {
        return encoding.toCString();
    }
    return default_enc;
}

String htmlspecialchars(const String &s, Int flags,
                        const Variant &encoding, bool double_encode) {
    if (s.length() == 0) {
        return String();
    }

    const char *hint = resolve_encoding(encoding, nullptr);

    zend_string *result = php_escape_html_entities_ex(
        (const unsigned char *)s.data(), s.length(),
        0,  /* all = false */
        (int)flags,
        hint,
        double_encode,
        0   /* quiet = false */
    );

    return String(result, php::Ctor::Move);
}

String htmlentities(const String &s, Int flags,
                    const Variant &encoding, bool double_encode) {
    if (s.length() == 0) {
        return String();
    }

    const char *hint = resolve_encoding(encoding, nullptr);

    zend_string *result = php_escape_html_entities_ex(
        (const unsigned char *)s.data(), s.length(),
        1,  /* all = true */
        (int)flags,
        hint,
        double_encode,
        0   /* quiet = false */
    );

    return String(result, php::Ctor::Move);
}

String htmlspecialchars_decode(const String &s, Int flags) {
    zend_string *result = php_unescape_html_entities(
        const_cast<zend_string *>(s.str()),
        0,  /* all = false */
        (int)flags,
        nullptr
    );

    return String(result, php::Ctor::Move);
}

String html_entity_decode(const String &s, Int flags,
                          const Variant &encoding) {
    const char *hint = resolve_encoding(encoding, nullptr);

    zend_string *result = php_unescape_html_entities(
        const_cast<zend_string *>(s.str()),
        1,  /* all = true */
        (int)flags,
        hint
    );

    return String(result, php::Ctor::Move);
}

// strip_tags: use php_strip_tags PHPAPI or fall back to naive implementation
String strip_tags(const String &s, const Variant &allowed_tags) {
    size_t srclen = s.length();

    if (srclen == 0) {
        return String();
    }

    // Build allowed tags string
    zend_string *allowed_str = nullptr;
    const char *allowed = nullptr;
    size_t allowed_len = 0;

    if (!allowed_tags.isNull()) {
        if (allowed_tags.isString()) {
            allowed = allowed_tags.toCString();
            allowed_len = strlen(allowed);
        } else if (allowed_tags.isArray()) {
            Array arr = allowed_tags.toArray();
            allowed_str = zend_string_init("", 0, 0);
            bool first = true;
            for (const auto &item : arr) {
                ::std::string tag = item.value.toStdString();
                if (!first) {
                    allowed_str = zend_string_extend(allowed_str, allowed_str->len + 1 + tag.length(), 0);
                    ZSTR_VAL(allowed_str)[ZSTR_LEN(allowed_str)] = ',';
                    ZSTR_LEN(allowed_str)++;
                } else {
                    first = false;
                    zend_string_release(allowed_str);
                    allowed_str = zend_string_init(tag.c_str(), tag.length(), 0);
                    continue;
                }
                memcpy(ZSTR_VAL(allowed_str) + ZSTR_LEN(allowed_str), tag.c_str(), tag.length());
                ZSTR_LEN(allowed_str) += tag.length();
            }
            ZSTR_VAL(allowed_str)[ZSTR_LEN(allowed_str)] = '\0';
            allowed = ZSTR_VAL(allowed_str);
            allowed_len = ZSTR_LEN(allowed_str);
        }
    }

    // Allocate output buffer (input length is an upper bound)
    zend_string *result = zend_string_alloc(srclen, 0);
    memcpy(ZSTR_VAL(result), s.data(), srclen);
    ZSTR_VAL(result)[srclen] = '\0';

    // Call PHPAPI php_strip_tags which modifies the buffer in-place
    size_t outlen = php_strip_tags(ZSTR_VAL(result), srclen, allowed, allowed_len);

    if (allowed_str) {
        zend_string_release(allowed_str);
    }

    ZSTR_LEN(result) = outlen;
    return String(result, php::Ctor::Move);
}

// ========================
// md5
// ========================

Variant md5(const String &s, bool raw_output) {
    PHP_MD5_CTX context;
    unsigned char digest[16];

    PHP_MD5Init(&context);
    PHP_MD5Update(&context, (const unsigned char *)s.data(), s.length());
    PHP_MD5Final(digest, &context);

    if (raw_output) {
        return Variant(String((char *)digest, 16));
    }

    char hex[33];
    make_digest_ex(hex, digest, 16);
    return Variant(String(hex, 32));
}

// ========================
// version_compare
// ========================

Int version_compare(const String &v1, const String &v2) {
    return static_cast<Int>(php_version_compare(v1.data(), v2.data()));
}

// ========================
// print_r
// ========================

Variant print_r(const Variant &value, bool do_return) {
    if (do_return) {
        zend_string *s = zend_print_zval_r_to_str(NO_CONST_V(value), 0);
        if (!s) {
            return Variant(String());
        }
        return Variant(String(s, Ctor::Move));
    }
    zend_print_zval_r(NO_CONST_V(value), 0);
    return Variant(true);
}

// ========================
// uniqid
// ========================

static zend_string *_uniqid_hash(const String &prefix, bool more_entropy) {
    char uniqid_buf[128];
    struct timeval tv;
    gettimeofday(&tv, NULL);
    zend_ulong sec = static_cast<zend_ulong>(tv.tv_sec);
    int usec = static_cast<int>(tv.tv_usec % 0x100000);

    if (more_entropy) {
        int len = snprintf(uniqid_buf, sizeof(uniqid_buf),
                           "%s%08lx%05x%.8F",
                           prefix.length() > 0 ? prefix.data() : "",
                           sec, usec, php_combined_lcg() * 10);
        return zend_string_init(uniqid_buf, len, 0);
    }

    int len = snprintf(uniqid_buf, sizeof(uniqid_buf),
                       "%s%08lx%05x",
                       prefix.length() > 0 ? prefix.data() : "",
                       sec, usec);
    return zend_string_init(uniqid_buf, len, 0);
}

String uniqid(const String &prefix, bool more_entropy) {
    zend_string *s = _uniqid_hash(prefix, more_entropy);
    return String(s, Ctor::Move);
}

// ========================
// parse_str
// ========================

Array parse_str(const String &str) {
    Array retval;
    auto res = estrndup(str.data(), str.length());
    sapi_module.treat_data(PARSE_STRING, res, retval.ptr());
    return retval;
}

// ========================
// shell_exec
// ========================

Variant shell_exec(const String &command) {
    if (command.length() == 0) {
    	zend_argument_value_error(1, "cannot be empty");
        return Variant(nullptr);
    }

#ifdef PHP_WIN32
    FILE *in = VCWD_POPEN(command.data(), "rt");
#else
    FILE *in = VCWD_POPEN(command.data(), "r");
#endif
    if (!in) {
        php_error_docref(nullptr, E_WARNING, "Unable to execute '%s'", command.data());
        return Variant(false);
    }

    php_stream *stream = php_stream_fopen_from_pipe(in, "rb");
    zend_string *ret = php_stream_copy_to_mem(stream, PHP_STREAM_COPY_ALL, 0);
    php_stream_close(stream);

    if (ret && ZSTR_LEN(ret) > 0) {
        return Variant(String(ret, php::Ctor::Move));
    }
    if (ret) {
        zend_string_release(ret);
    }
    return Variant(nullptr);
}

}  // namespace php::std
