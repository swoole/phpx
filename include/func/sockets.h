#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Variant socket_select(const Reference &read,
                      const Reference &write,
                      const Reference &except,
                      const Variant &seconds,
                      const Variant &microseconds = 0);
Socket socket_create_listen(const Variant &port, const Variant &backlog = 4096);
Socket socket_accept(const Socket &socket);
Variant socket_accept(const Variant &socket);
Variant socket_set_nonblock(const Socket &socket);
Variant socket_set_nonblock(const Variant &socket);
Variant socket_set_block(const Socket &socket);
Variant socket_set_block(const Variant &socket);
Variant socket_listen(const Socket &socket, const Variant &backlog = 0);
Variant socket_listen(const Variant &socket, const Variant &backlog = 0);
Variant socket_close(const Socket &socket);
Variant socket_close(const Variant &socket);
Variant socket_write(const Socket &socket, const Variant &data, const Variant &length = nullptr);
Variant socket_write(const Variant &socket, const Variant &data, const Variant &length = nullptr);
Variant socket_read(const Socket &socket, const Variant &length, const Variant &mode = 2);
Variant socket_read(const Variant &socket, const Variant &length, const Variant &mode = 2);
Variant socket_getsockname(const Socket &socket, const Reference &address, const Reference &port = nullptr);
Variant socket_getsockname(const Variant &socket, const Reference &address, const Reference &port = nullptr);
Variant socket_getpeername(const Socket &socket, const Reference &address, const Reference &port = nullptr);
Variant socket_getpeername(const Variant &socket, const Reference &address, const Reference &port = nullptr);
Socket socket_create(const Variant &domain, const Variant &type, const Variant &protocol);
Variant socket_connect(const Socket &socket, const Variant &address, const Variant &port = nullptr);
Variant socket_connect(const Variant &socket, const Variant &address, const Variant &port = nullptr);
Variant socket_strerror(const Variant &error_code);
Variant socket_bind(const Socket &socket, const Variant &address, const Variant &port = 0);
Variant socket_bind(const Variant &socket, const Variant &address, const Variant &port = 0);
Variant socket_recv(const Socket &socket, const Reference &data, const Variant &length, const Variant &flags);
Variant socket_recv(const Variant &socket, const Reference &data, const Variant &length, const Variant &flags);
Variant socket_send(const Socket &socket, const Variant &data, const Variant &length, const Variant &flags);
Variant socket_send(const Variant &socket, const Variant &data, const Variant &length, const Variant &flags);
Variant socket_recvfrom(const Socket &socket,
                        const Reference &data,
                        const Variant &length,
                        const Variant &flags,
                        const Reference &address,
                        const Reference &port = nullptr);
Variant socket_recvfrom(const Variant &socket,
                        const Reference &data,
                        const Variant &length,
                        const Variant &flags,
                        const Reference &address,
                        const Reference &port = nullptr);
Variant socket_sendto(const Socket &socket,
                      const Variant &data,
                      const Variant &length,
                      const Variant &flags,
                      const Variant &address,
                      const Variant &port = nullptr);
Variant socket_sendto(const Variant &socket,
                      const Variant &data,
                      const Variant &length,
                      const Variant &flags,
                      const Variant &address,
                      const Variant &port = nullptr);
Variant socket_get_option(const Socket &socket, const Variant &level, const Variant &option);
Variant socket_get_option(const Variant &socket, const Variant &level, const Variant &option);
Variant socket_getopt(const Socket &socket, const Variant &level, const Variant &option);
Variant socket_getopt(const Variant &socket, const Variant &level, const Variant &option);
Variant socket_set_option(const Socket &socket, const Variant &level, const Variant &option, const Variant &value);
Variant socket_set_option(const Variant &socket, const Variant &level, const Variant &option, const Variant &value);
Variant socket_setopt(const Socket &socket, const Variant &level, const Variant &option, const Variant &value);
Variant socket_setopt(const Variant &socket, const Variant &level, const Variant &option, const Variant &value);
Variant socket_create_pair(const Variant &domain, const Variant &type, const Variant &protocol, const Reference &pair);
Variant socket_shutdown(const Socket &socket, const Variant &mode = 2);
Variant socket_shutdown(const Variant &socket, const Variant &mode = 2);
Variant socket_atmark(const Socket &socket);
Variant socket_atmark(const Variant &socket);
Variant socket_last_error(const Variant &socket = nullptr);
Variant socket_clear_error(const Variant &socket = nullptr);
Socket socket_import_stream(const Variant &stream);
Variant socket_export_stream(const Socket &socket);
Variant socket_export_stream(const Variant &socket);
Variant socket_sendmsg(const Socket &socket, const Variant &message, const Variant &flags = 0);
Variant socket_sendmsg(const Variant &socket, const Variant &message, const Variant &flags = 0);
Variant socket_recvmsg(const Socket &socket, const Reference &message, const Variant &flags = 0);
Variant socket_recvmsg(const Variant &socket, const Reference &message, const Variant &flags = 0);
Variant socket_cmsg_space(const Variant &level, const Variant &type, const Variant &num = 0);
Variant socket_addrinfo_lookup(const Variant &host, const Variant &service = nullptr, const Variant &hints = Array{});
Socket socket_addrinfo_connect(const AddressInfo &address);
Variant socket_addrinfo_connect(const Variant &address);
Socket socket_addrinfo_bind(const AddressInfo &address);
Variant socket_addrinfo_bind(const Variant &address);
Variant socket_addrinfo_explain(const AddressInfo &address);
Variant socket_addrinfo_explain(const Variant &address);

}  // namespace php
