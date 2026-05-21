#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant socket_select(const Reference &read,
                      const Reference &write,
                      const Reference &except,
                      const Variant &seconds,
                      const Variant &microseconds) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1831]);
    }
    return call(fn, {&read, &write, &except, seconds, microseconds});
}
Socket socket_create_listen(const Variant &port, const Variant &backlog) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1832]);
    }
    auto _rv = call(fn, {port, backlog});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "socket_create_listen() returned false");
    }
    return Socket(Object(std::move(_rv)));
}
Socket socket_accept(const Socket &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1833]);
    }
    auto _rv = call(fn, {socket.getObject()});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "socket_accept() returned false");
    }
    return Socket(Object(std::move(_rv)));
}
Variant socket_accept(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1833]);
    }
    return call(fn, {socket});
}
Variant socket_set_nonblock(const Socket &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1834]);
    }
    return call(fn, {socket.getObject()});
}
Variant socket_set_nonblock(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1834]);
    }
    return call(fn, {socket});
}
Variant socket_set_block(const Socket &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1835]);
    }
    return call(fn, {socket.getObject()});
}
Variant socket_set_block(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1835]);
    }
    return call(fn, {socket});
}
Variant socket_listen(const Socket &socket, const Variant &backlog) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1836]);
    }
    return call(fn, {socket.getObject(), backlog});
}
Variant socket_listen(const Variant &socket, const Variant &backlog) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1836]);
    }
    return call(fn, {socket, backlog});
}
Variant socket_close(const Socket &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1837]);
    }
    return call(fn, {socket.getObject()});
}
Variant socket_close(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1837]);
    }
    return call(fn, {socket});
}
Variant socket_write(const Socket &socket, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1838]);
    }
    return call(fn, {socket.getObject(), data, length});
}
Variant socket_write(const Variant &socket, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1838]);
    }
    return call(fn, {socket, data, length});
}
Variant socket_read(const Socket &socket, const Variant &length, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1839]);
    }
    return call(fn, {socket.getObject(), length, mode});
}
Variant socket_read(const Variant &socket, const Variant &length, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1839]);
    }
    return call(fn, {socket, length, mode});
}
Variant socket_getsockname(const Socket &socket, const Reference &address, const Reference &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1840]);
    }
    return call(fn, {socket.getObject(), &address, &port});
}
Variant socket_getsockname(const Variant &socket, const Reference &address, const Reference &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1840]);
    }
    return call(fn, {socket, &address, &port});
}
Variant socket_getpeername(const Socket &socket, const Reference &address, const Reference &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1841]);
    }
    return call(fn, {socket.getObject(), &address, &port});
}
Variant socket_getpeername(const Variant &socket, const Reference &address, const Reference &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1841]);
    }
    return call(fn, {socket, &address, &port});
}
Socket socket_create(const Variant &domain, const Variant &type, const Variant &protocol) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1842]);
    }
    auto _rv = call(fn, {domain, type, protocol});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "socket_create() returned false");
    }
    return Socket(Object(std::move(_rv)));
}
Variant socket_connect(const Socket &socket, const Variant &address, const Variant &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1843]);
    }
    return call(fn, {socket.getObject(), address, port});
}
Variant socket_connect(const Variant &socket, const Variant &address, const Variant &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1843]);
    }
    return call(fn, {socket, address, port});
}
Variant socket_strerror(const Variant &error_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1844]);
    }
    return call(fn, {error_code});
}
Variant socket_bind(const Socket &socket, const Variant &address, const Variant &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1845]);
    }
    return call(fn, {socket.getObject(), address, port});
}
Variant socket_bind(const Variant &socket, const Variant &address, const Variant &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1845]);
    }
    return call(fn, {socket, address, port});
}
Variant socket_recv(const Socket &socket, const Reference &data, const Variant &length, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1846]);
    }
    return call(fn, {socket.getObject(), &data, length, flags});
}
Variant socket_recv(const Variant &socket, const Reference &data, const Variant &length, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1846]);
    }
    return call(fn, {socket, &data, length, flags});
}
Variant socket_send(const Socket &socket, const Variant &data, const Variant &length, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1847]);
    }
    return call(fn, {socket.getObject(), data, length, flags});
}
Variant socket_send(const Variant &socket, const Variant &data, const Variant &length, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1847]);
    }
    return call(fn, {socket, data, length, flags});
}
Variant socket_recvfrom(const Socket &socket,
                        const Reference &data,
                        const Variant &length,
                        const Variant &flags,
                        const Reference &address,
                        const Reference &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1848]);
    }
    return call(fn, {socket.getObject(), &data, length, flags, &address, &port});
}
Variant socket_recvfrom(const Variant &socket,
                        const Reference &data,
                        const Variant &length,
                        const Variant &flags,
                        const Reference &address,
                        const Reference &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1848]);
    }
    return call(fn, {socket, &data, length, flags, &address, &port});
}
Variant socket_sendto(const Socket &socket,
                      const Variant &data,
                      const Variant &length,
                      const Variant &flags,
                      const Variant &address,
                      const Variant &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1849]);
    }
    return call(fn, {socket.getObject(), data, length, flags, address, port});
}
Variant socket_sendto(const Variant &socket,
                      const Variant &data,
                      const Variant &length,
                      const Variant &flags,
                      const Variant &address,
                      const Variant &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1849]);
    }
    return call(fn, {socket, data, length, flags, address, port});
}
Variant socket_get_option(const Socket &socket, const Variant &level, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1850]);
    }
    return call(fn, {socket.getObject(), level, option});
}
Variant socket_get_option(const Variant &socket, const Variant &level, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1850]);
    }
    return call(fn, {socket, level, option});
}
Variant socket_getopt(const Socket &socket, const Variant &level, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1851]);
    }
    return call(fn, {socket.getObject(), level, option});
}
Variant socket_getopt(const Variant &socket, const Variant &level, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1851]);
    }
    return call(fn, {socket, level, option});
}
Variant socket_set_option(const Socket &socket, const Variant &level, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1852]);
    }
    return call(fn, {socket.getObject(), level, option, value});
}
Variant socket_set_option(const Variant &socket, const Variant &level, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1852]);
    }
    return call(fn, {socket, level, option, value});
}
Variant socket_setopt(const Socket &socket, const Variant &level, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1853]);
    }
    return call(fn, {socket.getObject(), level, option, value});
}
Variant socket_setopt(const Variant &socket, const Variant &level, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1853]);
    }
    return call(fn, {socket, level, option, value});
}
Variant socket_create_pair(const Variant &domain, const Variant &type, const Variant &protocol, const Reference &pair) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1854]);
    }
    return call(fn, {domain, type, protocol, &pair});
}
Variant socket_shutdown(const Socket &socket, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1855]);
    }
    return call(fn, {socket.getObject(), mode});
}
Variant socket_shutdown(const Variant &socket, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1855]);
    }
    return call(fn, {socket, mode});
}
Variant socket_atmark(const Socket &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1856]);
    }
    return call(fn, {socket.getObject()});
}
Variant socket_atmark(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1856]);
    }
    return call(fn, {socket});
}
Variant socket_last_error(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1857]);
    }
    return call(fn, {socket});
}
Variant socket_clear_error(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1858]);
    }
    return call(fn, {socket});
}
Socket socket_import_stream(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1859]);
    }
    auto _rv = call(fn, {stream});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "socket_import_stream() returned false");
    }
    return Socket(Object(std::move(_rv)));
}
Variant socket_export_stream(const Socket &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1860]);
    }
    return call(fn, {socket.getObject()});
}
Variant socket_export_stream(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1860]);
    }
    return call(fn, {socket});
}
Variant socket_sendmsg(const Socket &socket, const Variant &message, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1861]);
    }
    return call(fn, {socket.getObject(), message, flags});
}
Variant socket_sendmsg(const Variant &socket, const Variant &message, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1861]);
    }
    return call(fn, {socket, message, flags});
}
Variant socket_recvmsg(const Socket &socket, const Reference &message, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1862]);
    }
    return call(fn, {socket.getObject(), &message, flags});
}
Variant socket_recvmsg(const Variant &socket, const Reference &message, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1862]);
    }
    return call(fn, {socket, &message, flags});
}
Variant socket_cmsg_space(const Variant &level, const Variant &type, const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1863]);
    }
    return call(fn, {level, type, num});
}
Variant socket_addrinfo_lookup(const Variant &host, const Variant &service, const Variant &hints) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1864]);
    }
    return call(fn, {host, service, hints});
}
Socket socket_addrinfo_connect(const AddressInfo &address) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1865]);
    }
    auto _rv = call(fn, {address.getObject()});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "socket_addrinfo_connect() returned false");
    }
    return Socket(Object(std::move(_rv)));
}
Variant socket_addrinfo_connect(const Variant &address) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1865]);
    }
    return call(fn, {address});
}
Socket socket_addrinfo_bind(const AddressInfo &address) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1866]);
    }
    auto _rv = call(fn, {address.getObject()});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "socket_addrinfo_bind() returned false");
    }
    return Socket(Object(std::move(_rv)));
}
Variant socket_addrinfo_bind(const Variant &address) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1866]);
    }
    return call(fn, {address});
}
Variant socket_addrinfo_explain(const AddressInfo &address) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1867]);
    }
    return call(fn, {address.getObject()});
}
Variant socket_addrinfo_explain(const Variant &address) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1867]);
    }
    return call(fn, {address});
}
}  // namespace php
