#include "phpx.h"

namespace php {
Variant socket_select(const Reference &read, const Reference &write, const Reference &except, const Variant &seconds, const Variant &microseconds) {
    return call("socket_select", {&read, &write, &except, seconds, microseconds});
}
Variant socket_create_listen(const Variant &port, const Variant &backlog) {
    return call("socket_create_listen", {port, backlog});
}
Variant socket_accept(const Variant &socket) {
    return call("socket_accept", {socket});
}
Variant socket_set_nonblock(const Variant &socket) {
    return call("socket_set_nonblock", {socket});
}
Variant socket_set_block(const Variant &socket) {
    return call("socket_set_block", {socket});
}
Variant socket_listen(const Variant &socket, const Variant &backlog) {
    return call("socket_listen", {socket, backlog});
}
Variant socket_close(const Variant &socket) {
    return call("socket_close", {socket});
}
Variant socket_write(const Variant &socket, const Variant &data, const Variant &length) {
    return call("socket_write", {socket, data, length});
}
Variant socket_read(const Variant &socket, const Variant &length, const Variant &mode) {
    return call("socket_read", {socket, length, mode});
}
Variant socket_getsockname(const Variant &socket, const Reference &address, const Reference &port) {
    return call("socket_getsockname", {socket, &address, &port});
}
Variant socket_getpeername(const Variant &socket, const Reference &address, const Reference &port) {
    return call("socket_getpeername", {socket, &address, &port});
}
Variant socket_create(const Variant &domain, const Variant &type, const Variant &protocol) {
    return call("socket_create", {domain, type, protocol});
}
Variant socket_connect(const Variant &socket, const Variant &address, const Variant &port) {
    return call("socket_connect", {socket, address, port});
}
Variant socket_strerror(const Variant &error_code) {
    return call("socket_strerror", {error_code});
}
Variant socket_bind(const Variant &socket, const Variant &address, const Variant &port) {
    return call("socket_bind", {socket, address, port});
}
Variant socket_recv(const Variant &socket, const Reference &data, const Variant &length, const Variant &flags) {
    return call("socket_recv", {socket, &data, length, flags});
}
Variant socket_send(const Variant &socket, const Variant &data, const Variant &length, const Variant &flags) {
    return call("socket_send", {socket, data, length, flags});
}
Variant socket_recvfrom(const Variant &socket, const Reference &data, const Variant &length, const Variant &flags, const Reference &address, const Reference &port) {
    return call("socket_recvfrom", {socket, &data, length, flags, &address, &port});
}
Variant socket_sendto(const Variant &socket, const Variant &data, const Variant &length, const Variant &flags, const Variant &address, const Variant &port) {
    return call("socket_sendto", {socket, data, length, flags, address, port});
}
Variant socket_get_option(const Variant &socket, const Variant &level, const Variant &option) {
    return call("socket_get_option", {socket, level, option});
}
Variant socket_getopt(const Variant &socket, const Variant &level, const Variant &option) {
    return call("socket_getopt", {socket, level, option});
}
Variant socket_set_option(const Variant &socket, const Variant &level, const Variant &option, const Variant &value) {
    return call("socket_set_option", {socket, level, option, value});
}
Variant socket_setopt(const Variant &socket, const Variant &level, const Variant &option, const Variant &value) {
    return call("socket_setopt", {socket, level, option, value});
}
Variant socket_create_pair(const Variant &domain, const Variant &type, const Variant &protocol, const Reference &pair) {
    return call("socket_create_pair", {domain, type, protocol, &pair});
}
Variant socket_shutdown(const Variant &socket, const Variant &mode) {
    return call("socket_shutdown", {socket, mode});
}
Variant socket_atmark(const Variant &socket) {
    return call("socket_atmark", {socket});
}
Variant socket_last_error(const Variant &socket) {
    return call("socket_last_error", {socket});
}
Variant socket_clear_error(const Variant &socket) {
    return call("socket_clear_error", {socket});
}
Variant socket_import_stream(const Variant &stream) {
    return call("socket_import_stream", {stream});
}
Variant socket_export_stream(const Variant &socket) {
    return call("socket_export_stream", {socket});
}
Variant socket_sendmsg(const Variant &socket, const Variant &message, const Variant &flags) {
    return call("socket_sendmsg", {socket, message, flags});
}
Variant socket_recvmsg(const Variant &socket, const Reference &message, const Variant &flags) {
    return call("socket_recvmsg", {socket, &message, flags});
}
Variant socket_cmsg_space(const Variant &level, const Variant &type, const Variant &num) {
    return call("socket_cmsg_space", {level, type, num});
}
Variant socket_addrinfo_lookup(const Variant &host, const Variant &service, const Variant &hints) {
    return call("socket_addrinfo_lookup", {host, service, hints});
}
Variant socket_addrinfo_connect(const Variant &address) {
    return call("socket_addrinfo_connect", {address});
}
Variant socket_addrinfo_bind(const Variant &address) {
    return call("socket_addrinfo_bind", {address});
}
Variant socket_addrinfo_explain(const Variant &address) {
    return call("socket_addrinfo_explain", {address});
}
}
