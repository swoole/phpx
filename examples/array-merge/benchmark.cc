#include "phpx_std.h"
#include "sapi/embed/php_embed.h"
#include <chrono>
#include <cstdio>
#include <utility>

template <std::size_t... I>
php::Array merge_many(const php::Array &input, std::index_sequence<I...>) {
    return php::fn::array_merge(((void) I, input)...);
}

template <std::size_t N>
void measure(std::size_t length, bool mixed) {
    php::Array input;
    for (std::size_t i = 0; i < length; ++i) {
        input.append(static_cast<php::Int>(i));
    }
    if (mixed) input.set("label", "shared");
    const int iterations = 1000;
    std::size_t checksum = 0;
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < iterations; ++i) {
        auto result = merge_many(input, std::make_index_sequence<N>{});
        checksum += result.length();
    }
    auto elapsed = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start).count();
    std::printf("%s arrays=%zu elements=%zu iterations=%d ms=%.3f checksum=%zu\n",
                mixed ? "mixed" : "packed", N, length, iterations, elapsed, checksum);
}
int main(int argc, char **argv) {
    if (php_embed_init(argc, argv) == FAILURE) return 1;
    php::request_init();
    measure<2>(1024, false);
    measure<8>(1024, false);
    measure<32>(1024, false);
    measure<2>(1024, true);
    measure<8>(1024, true);
    measure<32>(1024, true);
    php::request_shutdown();
    php_embed_shutdown();
}
