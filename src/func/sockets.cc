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
        fn = getFunction(LITERAL_STRING[1695]);
    }
    return call(fn, {&read, &write, &except, seconds, microseconds});
}
Socket socket_create_listen(const Variant &port, const Variant &backlog) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1696]);
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
        fn = getFunction(LITERAL_STRING[1697]);
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
        fn = getFunction(LITERAL_STRING[1697]);
    }
    return call(fn, {socket});
}
Variant socket_set_nonblock(const Socket &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1698]);
    }
    return call(fn, {socket.getObject()});
}
Variant socket_set_nonblock(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1698]);
    }
    return call(fn, {socket});
}
Variant socket_set_block(const Socket &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1699]);
    }
    return call(fn, {socket.getObject()});
}
Variant socket_set_block(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1699]);
    }
    return call(fn, {socket});
}
Variant socket_listen(const Socket &socket, const Variant &backlog) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1700]);
    }
    return call(fn, {socket.getObject(), backlog});
}
Variant socket_listen(const Variant &socket, const Variant &backlog) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1700]);
    }
    return call(fn, {socket, backlog});
}
Variant socket_close(const Socket &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1701]);
    }
    return call(fn, {socket.getObject()});
}
Variant socket_close(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1701]);
    }
    return call(fn, {socket});
}
Variant socket_write(const Socket &socket, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1702]);
    }
    return call(fn, {socket.getObject(), data, length});
}
Variant socket_write(const Variant &socket, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1702]);
    }
    return call(fn, {socket, data, length});
}
Variant socket_read(const Socket &socket, const Variant &length, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1703]);
    }
    return call(fn, {socket.getObject(), length, mode});
}
Variant socket_read(const Variant &socket, const Variant &length, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1703]);
    }
    return call(fn, {socket, length, mode});
}
Variant socket_getsockname(const Socket &socket, const Reference &address, const Reference &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1704]);
    }
    return call(fn, {socket.getObject(), &address, &port});
}
Variant socket_getsockname(const Variant &socket, const Reference &address, const Reference &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1704]);
    }
    return call(fn, {socket, &address, &port});
}
Variant socket_getpeername(const Socket &socket, const Reference &address, const Reference &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1705]);
    }
    return call(fn, {socket.getObject(), &address, &port});
}
Variant socket_getpeername(const Variant &socket, const Reference &address, const Reference &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1705]);
    }
    return call(fn, {socket, &address, &port});
}
Socket socket_create(const Variant &domain, const Variant &type, const Variant &protocol) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1706]);
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
        fn = getFunction(LITERAL_STRING[1707]);
    }
    return call(fn, {socket.getObject(), address, port});
}
Variant socket_connect(const Variant &socket, const Variant &address, const Variant &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1707]);
    }
    return call(fn, {socket, address, port});
}
Variant socket_strerror(const Variant &error_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1708]);
    }
    return call(fn, {error_code});
}
Variant socket_bind(const Socket &socket, const Variant &address, const Variant &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1709]);
    }
    return call(fn, {socket.getObject(), address, port});
}
Variant socket_bind(const Variant &socket, const Variant &address, const Variant &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1709]);
    }
    return call(fn, {socket, address, port});
}
Variant socket_recv(const Socket &socket, const Reference &data, const Variant &length, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1710]);
    }
    return call(fn, {socket.getObject(), &data, length, flags});
}
Variant socket_recv(const Variant &socket, const Reference &data, const Variant &length, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1710]);
    }
    return call(fn, {socket, &data, length, flags});
}
Variant socket_send(const Socket &socket, const Variant &data, const Variant &length, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1711]);
    }
    return call(fn, {socket.getObject(), data, length, flags});
}
Variant socket_send(const Variant &socket, const Variant &data, const Variant &length, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1711]);
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
        fn = getFunction(LITERAL_STRING[1712]);
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
        fn = getFunction(LITERAL_STRING[1712]);
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
        fn = getFunction(LITERAL_STRING[1713]);
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
        fn = getFunction(LITERAL_STRING[1713]);
    }
    return call(fn, {socket, data, length, flags, address, port});
}
Variant socket_get_option(const Socket &socket, const Variant &level, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1714]);
    }
    return call(fn, {socket.getObject(), level, option});
}
Variant socket_get_option(const Variant &socket, const Variant &level, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1714]);
    }
    return call(fn, {socket, level, option});
}
Variant socket_getopt(const Socket &socket, const Variant &level, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1715]);
    }
    return call(fn, {socket.getObject(), level, option});
}
Variant socket_getopt(const Variant &socket, const Variant &level, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1715]);
    }
    return call(fn, {socket, level, option});
}
Variant socket_set_option(const Socket &socket, const Variant &level, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1716]);
    }
    return call(fn, {socket.getObject(), level, option, value});
}
Variant socket_set_option(const Variant &socket, const Variant &level, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1716]);
    }
    return call(fn, {socket, level, option, value});
}
Variant socket_setopt(const Socket &socket, const Variant &level, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1717]);
    }
    return call(fn, {socket.getObject(), level, option, value});
}
Variant socket_setopt(const Variant &socket, const Variant &level, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1717]);
    }
    return call(fn, {socket, level, option, value});
}
Variant socket_create_pair(const Variant &domain, const Variant &type, const Variant &protocol, const Reference &pair) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1718]);
    }
    return call(fn, {domain, type, protocol, &pair});
}
Variant socket_shutdown(const Socket &socket, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1719]);
    }
    return call(fn, {socket.getObject(), mode});
}
Variant socket_shutdown(const Variant &socket, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1719]);
    }
    return call(fn, {socket, mode});
}
Variant socket_atmark(const Socket &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1720]);
    }
    return call(fn, {socket.getObject()});
}
Variant socket_atmark(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1720]);
    }
    return call(fn, {socket});
}
Variant socket_last_error(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1721]);
    }
    return call(fn, {socket});
}
Variant socket_clear_error(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1722]);
    }
    return call(fn, {socket});
}
Socket socket_import_stream(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1723]);
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
        fn = getFunction(LITERAL_STRING[1724]);
    }
    return call(fn, {socket.getObject()});
}
Variant socket_export_stream(const Variant &socket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1724]);
    }
    return call(fn, {socket});
}
Variant socket_sendmsg(const Socket &socket, const Variant &message, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1725]);
    }
    return call(fn, {socket.getObject(), message, flags});
}
Variant socket_sendmsg(const Variant &socket, const Variant &message, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1725]);
    }
    return call(fn, {socket, message, flags});
}
Variant socket_recvmsg(const Socket &socket, const Reference &message, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1726]);
    }
    return call(fn, {socket.getObject(), &message, flags});
}
Variant socket_recvmsg(const Variant &socket, const Reference &message, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1726]);
    }
    return call(fn, {socket, &message, flags});
}
Variant socket_cmsg_space(const Variant &level, const Variant &type, const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1727]);
    }
    return call(fn, {level, type, num});
}
Variant socket_addrinfo_lookup(const Variant &host, const Variant &service, const Variant &hints) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1728]);
    }
    return call(fn, {host, service, hints});
}
Socket socket_addrinfo_connect(const AddressInfo &address) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1729]);
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
        fn = getFunction(LITERAL_STRING[1729]);
    }
    return call(fn, {address});
}
Socket socket_addrinfo_bind(const AddressInfo &address) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1730]);
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
        fn = getFunction(LITERAL_STRING[1730]);
    }
    return call(fn, {address});
}
Variant socket_addrinfo_explain(const AddressInfo &address) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1731]);
    }
    return call(fn, {address.getObject()});
}
Variant socket_addrinfo_explain(const Variant &address) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1731]);
    }
    return call(fn, {address});
}
}  // namespace php
