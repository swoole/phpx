#include "phpx.h"
#include "ext/swoole/include/swoole.h"
#include "ext/swoole/include/swoole_lock.h"
#include "ext/swoole/include/swoole_file.h"
#include "ext/swoole/php_swoole.h"

extern "C" {
extern void MurmurHash3_x64_128(const void *key, const int len, const uint32_t seed, void *out);
extern void SpookyHash128(
    const void *key, size_t len, uint64_t seed1, uint64_t seed2, uint64_t *hash1, uint64_t *hash2);
}

BEGIN_EXTERN_C()
#include "BloomFilter_arginfo.h"
END_EXTERN_C()

#include <iostream>

using namespace php;
using namespace std;
using swoole::File;
using swoole::RWLock;

static std::shared_ptr<Extension> s_bloomfilter_extension;

struct BloomFilterObject {
    size_t capacity;
    char *array;
    uint32_t k_num;
    uint64_t bit_num;
    uint64_t *hashes;
    RWLock *lock;
};

#define RESOURCE_NAME "BloomFilterResource"
#define PROPERTY_NAME "ptr"

static void compute_hashes(uint32_t k_num, const char *key, size_t len, uint64_t *hashes) {
    uint64_t out[2];
    MurmurHash3_x64_128(key, len, 0, out);

    hashes[0] = out[0];
    hashes[1] = out[1];

    uint64_t *hash1 = out;
    uint64_t *hash2 = hash1 + 1;
    SpookyHash128(key, len, 0, 0, hash1, hash2);

    hashes[2] = out[0];
    hashes[3] = out[1];

    for (uint32_t i = 4; i < k_num; i++) {
        hashes[i] = hashes[1] + ((i * hashes[3]) % 18446744073709551557U);
    }
}

static void BloomFilterResDtor(zend_resource *res) {
    BloomFilterObject *bf = static_cast<BloomFilterObject *>(res->ptr);
    efree(bf->hashes);
    delete bf->lock;
    sw_shm_free(bf);
}

PHPX_METHOD(BloomFilter, __construct) {
    long capacity = args[0].toInt();
    if (capacity <= 0) {
        capacity = 65536;
    }

    uint32_t k_num = 2;
    if (args.exists(1)) {
        k_num = (uint32_t) args[1].toInt();
    }

    BloomFilterObject *bf = (BloomFilterObject *) sw_shm_malloc(sizeof(BloomFilterObject) + capacity);
    if (bf == NULL) {
        throwException("RuntimeException", "sw_shm_malloc() failed.");
    }
    bf->capacity = capacity;
    bf->array = (char *) (bf + 1);
    bzero(bf->array, bf->capacity);

    bf->hashes = (uint64_t *) ecalloc(k_num, sizeof(uint64_t));
    if (bf->hashes == NULL) {
        throwException("RuntimeException", "ecalloc() failed.");
    }
    bf->bit_num = bf->capacity * 8;
    bf->k_num = k_num;
    bf->lock = new RWLock(1);

    _this.oSet(PROPERTY_NAME, RESOURCE_NAME, bf);

    return nullptr;
}

PHPX_METHOD(BloomFilter, has) {
    BloomFilterObject *bf = _this.oGet<BloomFilterObject>(PROPERTY_NAME, RESOURCE_NAME);
    auto key = args[0];
    compute_hashes(bf->k_num, key.toCString(), key.length(), bf->hashes);

    uint32_t i;
    uint32_t n;
    bool miss;

    bf->lock->lock_rd();
    for (i = 0; i < bf->k_num; i++) {
        n = bf->hashes[i] % bf->bit_num;
        miss = !(bf->array[n / 8] & (1 << (n % 8)));
        if (miss) {
            bf->lock->unlock();
            return false;
        }
    }
    bf->lock->unlock();
    return true;
}

PHPX_METHOD(BloomFilter, add) {
    BloomFilterObject *bf = _this.oGet<BloomFilterObject>(PROPERTY_NAME, RESOURCE_NAME);
    auto key = args[0];
    compute_hashes(bf->k_num, key.toCString(), key.length(), bf->hashes);

    uint32_t i;
    uint32_t n;

    bf->lock->lock();
    for (i = 0; i < bf->k_num; i++) {
        n = bf->hashes[i] % bf->bit_num;
        bf->array[n / 8] |= (1 << (n % 8));
    }
    bf->lock->unlock();

    return nullptr;
}

PHPX_METHOD(BloomFilter, clear) {
    BloomFilterObject *bf = _this.oGet<BloomFilterObject>(PROPERTY_NAME, RESOURCE_NAME);
    bf->lock->lock();
    bzero(bf->array, bf->capacity);
    bf->lock->unlock();

    return nullptr;
}

PHPX_METHOD(BloomFilter, dump) {
    BloomFilterObject *bf = _this.oGet<BloomFilterObject>(PROPERTY_NAME, RESOURCE_NAME);
    auto file = args[0].toCString();

    bf->lock->lock();
    File fp(file, File::CREATE | File::WRITE, 0644);
    if (!fp.ready()) {
    fail:
        bf->lock->unlock();
        return false;
    }
    if (fp.write(&bf->capacity, sizeof(bf->capacity)) == 0) {
        goto fail;
    }
    if (fp.write(bf->array, bf->capacity) == 0) {
        goto fail;
    }
    bf->lock->unlock();
    return true;
}

PHPX_METHOD(BloomFilter, load) {
    auto file = args[0].toCString();

    File fp(file, File::READ);
    if (!fp.ready()) {
    fail:
        return false;
    }

    size_t capacity = 0;
    if (fp.read(&capacity, sizeof(capacity)) == 0) {
        goto fail;
    }
    long filesize = fp.get_size();
    if (filesize < 0 || filesize < capacity + sizeof(capacity)) {
        goto fail;
    }

    auto o = newObject("BloomFilter", (long) capacity);
    BloomFilterObject *bf = o.oGet<BloomFilterObject>(PROPERTY_NAME, RESOURCE_NAME);
    if (fp.read(bf->array, capacity) == 0) {
        goto fail;
    }
    return o;
}

PHPX_EXTENSION() {
    s_bloomfilter_extension = std::make_shared<Extension>("BloomFilter", "1.0.2");
    auto extension = s_bloomfilter_extension.get();

    extension->onStart = [extension]() noexcept {
        extension->registerConstant("BLOOMFILTER_VERSION", 10002);
        Class *c = new Class("BloomFilter");
        c->addProperty("ptr", nullptr, ZEND_ACC_PUBLIC);
        c->registerFunctions(class_BloomFilter_methods);
        extension->registerClass(c);
        extension->registerResource(RESOURCE_NAME, BloomFilterResDtor);
    };

    extension->require("swoole");

    extension->info({"BloomFilter support", "enabled"},
                    {
                        {"author", "Tianfeng Han"},
                        {"version", extension->version},
                        {"date", "2021-02-07"},
                    });

    return extension;
}
