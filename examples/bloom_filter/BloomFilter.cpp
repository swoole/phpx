#include "phpx.h"

extern "C"
{
#include <php_swoole.h>
#include <swoole.h>
extern void MurmurHash3_x64_128(const void * key, const int len, const uint32_t seed, void *out);
extern void SpookyHash128(const void *key, size_t len, uint64_t seed1, uint64_t seed2, uint64_t *hash1, uint64_t *hash2);
}

#include <iostream>

using namespace php;
using namespace std;

struct BloomFilterObject
{
    size_t capacity;
    char *array;
    uint32_t k_num;
    uint64_t bit_num;
    uint64_t *hashes;
    swLock lock;
};

#define RESOURCE_NAME  "BloomFilterResource"
#define PROPERTY_NAME  "ptr"

static void compute_hashes(uint32_t k_num, char *key, size_t len, uint64_t *hashes)
{
    uint64_t out[2];
    MurmurHash3_x64_128(key, len, 0, out);

    hashes[0] = out[0];
    hashes[1] = out[1];

    uint64_t *hash1 = out;
    uint64_t *hash2 = hash1 + 1;
    SpookyHash128(key, len, 0, 0, hash1, hash2);

    hashes[2] = out[0];
    hashes[3] = out[1];

    for (uint32_t i = 4; i < k_num; i++)
    {
        hashes[i] = hashes[1] + ((i * hashes[3]) % 18446744073709551557U);
    }
}

static void BloomFilterResDtor(zend_resource *res)
{
    BloomFilterObject *bf = static_cast<BloomFilterObject *>(res->ptr);
    efree(bf->hashes);
    bf->lock.free(&bf->lock);
    sw_shm_free(bf);
}

static PHPX_METHOD(BloomFilter, __construct)
{
    long capacity = args[0].toInt();
    if (capacity <= 0)
    {
        capacity = 65536;
    }

    uint32_t k_num = 2;
    if (args.exists(1))
    {
        k_num = (uint32_t) args[1].toInt();
    }

    BloomFilterObject *bf = (BloomFilterObject *) sw_shm_malloc(sizeof(BloomFilterObject) + capacity);
    if (bf == NULL)
    {
        throwException("RuntimeException", "sw_shm_malloc() failed.");
    }
    bf->capacity = capacity;
    bf->array = (char *) (bf + 1);
    bzero(bf->array, bf->capacity);

    bf->hashes = (uint64_t*) ecalloc(k_num, sizeof(uint64_t));
    if (bf->hashes == NULL)
    {
        throwException("RuntimeException", "ecalloc() failed.");
    }
    bf->bit_num = bf->capacity * 8;
    bf->k_num = k_num;

    if (swRWLock_create(&bf->lock, 1) < 0)
    {
        throwException("RuntimeException", "swRWLock_create() failed.");
    }

    _this.oSet(PROPERTY_NAME, RESOURCE_NAME, bf);
}

PHPX_METHOD(BloomFilter, has)
{
    BloomFilterObject *bf = _this.oGet<BloomFilterObject>(PROPERTY_NAME, RESOURCE_NAME);
    auto key = args[0];
    compute_hashes(bf->k_num, key.toCString(), key.length(), bf->hashes);

    uint32_t i;
    uint32_t n;
    bool miss;

    bf->lock.lock_rd(&bf->lock);
    for (i = 0; i < bf->k_num; i++)
    {
        n = bf->hashes[i] % bf->bit_num;
        miss = !(bf->array[n / 8] & (1 << (n % 8)));
        if (miss)
        {
            bf->lock.unlock(&bf->lock);
            retval = false;
            return;
        }
    }
    bf->lock.unlock(&bf->lock);
    retval = true;
}

static PHPX_METHOD(BloomFilter, add)
{
    BloomFilterObject *bf = _this.oGet<BloomFilterObject>(PROPERTY_NAME, RESOURCE_NAME);
    auto key = args[0];
    compute_hashes(bf->k_num, key.toCString(), key.length(), bf->hashes);

    uint32_t i;
    uint32_t n;

    bf->lock.lock(&bf->lock);
    for (i = 0; i < bf->k_num; i++)
    {
        n = bf->hashes[i] % bf->bit_num;
        bf->array[n / 8] |= (1 << (n % 8));
    }
    bf->lock.unlock(&bf->lock);
}

static PHPX_METHOD(BloomFilter, clear)
{
    BloomFilterObject *bf = _this.oGet<BloomFilterObject>(PROPERTY_NAME, RESOURCE_NAME);
    bf->lock.lock(&bf->lock);
    bzero(bf->array, bf->capacity);
    bf->lock.unlock(&bf->lock);
}

static PHPX_METHOD(BloomFilter, dump)
{
    BloomFilterObject *bf = _this.oGet<BloomFilterObject>(PROPERTY_NAME, RESOURCE_NAME);
    auto file = args[0].toCString();

    bf->lock.lock(&bf->lock);
    int fd = open(file, O_CREAT | O_WRONLY, 0644);
    if (fd < 0)
    {
        fail: bf->lock.unlock(&bf->lock);
        retval = false;
        if (fd >= 0)
        {
            close(fd);
            unlink(file);
        }
        return;
    }
    if (swoole_sync_writefile(fd, &bf->capacity, sizeof(bf->capacity)) < 0)
    {
        goto fail;
    }
    if (swoole_sync_writefile(fd, bf->array, bf->capacity) < 0)
    {
        goto fail;
    }
    bf->lock.unlock(&bf->lock);
    close(fd);
    retval = true;
}

static PHPX_METHOD(BloomFilter, load)
{
    auto file = args[0].toCString();
    int fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        fail: retval = false;
        if (fd >= 0)
        {
            close(fd);
        }
        return;
    }

    size_t capacity;
    if (swoole_sync_readfile(fd, &capacity, sizeof(capacity)) < 0)
    {
        goto fail;
    }

    long filesize = swoole_file_size(file);
    if (filesize < 0 || filesize < capacity + sizeof(capacity))
    {
        goto fail;
    }

    auto o = newObject("BloomFilter", (long) capacity);
    BloomFilterObject *bf = o.oGet<BloomFilterObject>(PROPERTY_NAME, RESOURCE_NAME);
    if (swoole_sync_readfile(fd, bf->array, capacity) < 0)
    {
        goto fail;
    }
    close(fd);
    retval = o;
}

PHPX_EXTENSION()
{
    Extension *extension = new Extension("BloomFilter", "1.0.1");

    extension->onStart = [extension]() noexcept
    {
        extension->registerConstant("BLOOMFILTER_VERSION", 10001);

        Class *c = new Class("BloomFilter");
        c->addMethod(PHPX_ME(BloomFilter, __construct), CONSTRUCT);
        c->addMethod(PHPX_ME(BloomFilter, add));
        c->addMethod(PHPX_ME(BloomFilter, has));
        c->addMethod(PHPX_ME(BloomFilter, clear));
        c->addMethod(PHPX_ME(BloomFilter, load), STATIC);
        c->addMethod(PHPX_ME(BloomFilter, dump));

        extension->registerClass(c);
        extension->registerResource(RESOURCE_NAME, BloomFilterResDtor);
    };

    extension->require("swoole");

    extension->info({"BloomFilter support", "enabled"},
                    {
                        {"author", "Tianfeng Han"},
                        {"version", extension->version},
                        {"date", "2018-01-10"},
                    });

    return extension;
}
