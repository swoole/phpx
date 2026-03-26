#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant socket_select(const Reference &read,
                      const Reference &write,
                      const Reference &except,
                      const Variant &seconds,
                      const Variant &microseconds) {
    return call(LITERAL_STRING[1635], {&read, &write, &except, seconds, microseconds});
}
Variant socket_create_listen(const Variant &port, const Variant &backlog) {
    return call(LITERAL_STRING[1636], {port, backlog});
}
Variant socket_accept(const Variant &socket) {
    return call(LITERAL_STRING[1637], {socket});
}
Variant socket_set_nonblock(const Variant &socket) {
    return call(LITERAL_STRING[1638], {socket});
}
Variant socket_set_block(const Variant &socket) {
    return call(LITERAL_STRING[1639], {socket});
}
Variant socket_listen(const Variant &socket, const Variant &backlog) {
    return call(LITERAL_STRING[1640], {socket, backlog});
}
Variant socket_close(const Variant &socket) {
    return call(LITERAL_STRING[1641], {socket});
}
Variant socket_write(const Variant &socket, const Variant &data, const Variant &length) {
    return call(LITERAL_STRING[1642], {socket, data, length});
}
Variant socket_read(const Variant &socket, const Variant &length, const Variant &mode) {
    return call(LITERAL_STRING[1643], {socket, length, mode});
}
Variant socket_getsockname(const Variant &socket, const Reference &address, const Reference &port) {
    return call(LITERAL_STRING[1644], {socket, &address, &port});
}
Variant socket_getpeername(const Variant &socket, const Reference &address, const Reference &port) {
    return call(LITERAL_STRING[1645], {socket, &address, &port});
}
Variant socket_create(const Variant &domain, const Variant &type, const Variant &protocol) {
    return call(LITERAL_STRING[1646], {domain, type, protocol});
}
Variant socket_connect(const Variant &socket, const Variant &address, const Variant &port) {
    return call(LITERAL_STRING[1647], {socket, address, port});
}
Variant socket_strerror(const Variant &error_code) {
    return call(LITERAL_STRING[1648], {error_code});
}
Variant socket_bind(const Variant &socket, const Variant &address, const Variant &port) {
    return call(LITERAL_STRING[1649], {socket, address, port});
}
Variant socket_recv(const Variant &socket, const Reference &data, const Variant &length, const Variant &flags) {
    return call(LITERAL_STRING[1650], {socket, &data, length, flags});
}
Variant socket_send(const Variant &socket, const Variant &data, const Variant &length, const Variant &flags) {
    return call(LITERAL_STRING[1651], {socket, data, length, flags});
}
Variant socket_recvfrom(const Variant &socket,
                        const Reference &data,
                        const Variant &length,
                        const Variant &flags,
                        const Reference &address,
                        const Reference &port) {
    return call(LITERAL_STRING[1652], {socket, &data, length, flags, &address, &port});
}
Variant socket_sendto(const Variant &socket,
                      const Variant &data,
                      const Variant &length,
                      const Variant &flags,
                      const Variant &address,
                      const Variant &port) {
    return call(LITERAL_STRING[1653], {socket, data, length, flags, address, port});
}
Variant socket_get_option(const Variant &socket, const Variant &level, const Variant &option) {
    return call(LITERAL_STRING[1654], {socket, level, option});
}
Variant socket_getopt(const Variant &socket, const Variant &level, const Variant &option) {
    return call(LITERAL_STRING[1655], {socket, level, option});
}
Variant socket_set_option(const Variant &socket, const Variant &level, const Variant &option, const Variant &value) {
    return call(LITERAL_STRING[1656], {socket, level, option, value});
}
Variant socket_setopt(const Variant &socket, const Variant &level, const Variant &option, const Variant &value) {
    return call(LITERAL_STRING[1657], {socket, level, option, value});
}
Variant socket_create_pair(const Variant &domain, const Variant &type, const Variant &protocol, const Reference &pair) {
    return call(LITERAL_STRING[1658], {domain, type, protocol, &pair});
}
Variant socket_shutdown(const Variant &socket, const Variant &mode) {
    return call(LITERAL_STRING[1659], {socket, mode});
}
Variant socket_atmark(const Variant &socket) {
    return call(LITERAL_STRING[1660], {socket});
}
Variant socket_last_error(const Variant &socket) {
    return call(LITERAL_STRING[1661], {socket});
}
Variant socket_clear_error(const Variant &socket) {
    return call(LITERAL_STRING[1662], {socket});
}
Variant socket_import_stream(const Variant &stream) {
    return call(LITERAL_STRING[1663], {stream});
}
Variant socket_export_stream(const Variant &socket) {
    return call(LITERAL_STRING[1664], {socket});
}
Variant socket_sendmsg(const Variant &socket, const Variant &message, const Variant &flags) {
    return call(LITERAL_STRING[1665], {socket, message, flags});
}
Variant socket_recvmsg(const Variant &socket, const Reference &message, const Variant &flags) {
    return call(LITERAL_STRING[1666], {socket, &message, flags});
}
Variant socket_cmsg_space(const Variant &level, const Variant &type, const Variant &num) {
    return call(LITERAL_STRING[1667], {level, type, num});
}
Variant socket_addrinfo_lookup(const Variant &host, const Variant &service, const Variant &hints) {
    return call(LITERAL_STRING[1668], {host, service, hints});
}
Variant socket_addrinfo_connect(const Variant &address) {
    return call(LITERAL_STRING[1669], {address});
}
Variant socket_addrinfo_bind(const Variant &address) {
    return call(LITERAL_STRING[1670], {address});
}
Variant socket_addrinfo_explain(const Variant &address) {
    return call(LITERAL_STRING[1671], {address});
}
}  // namespace php
