#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/core.h"
#include "class/sockets.h"
#include "class/spl.h"

namespace php {
namespace Swoole {
class Exception;
class Error;
class Event;
class Atomic;
class Lock;
class Table;
class Timer;
class Coroutine;
class ExitException;
class Runtime;
class Process;
class Client;
class Server;
class Thread;
}  // namespace Swoole
namespace Swoole::Atomic {
class Long;
}
namespace Swoole::Timer {
class Iterator;
}
namespace Swoole::Coroutine {
class Iterator;
class Context;
class CanceledException;
class TimeoutException;
class System;
class Scheduler;
class Lock;
class Channel;
class Socket;
class Client;
}  // namespace Swoole::Coroutine
namespace Swoole::Coroutine::Curl {
class Exception;
}
namespace Swoole::Process {
class Pool;
}
namespace Swoole::Coroutine::Socket {
class Exception;
}
namespace Swoole::Client {
class Exception;
}
namespace Swoole::Async {
class Client;
}
namespace Swoole::Coroutine::Http::Client {
class Exception;
}
namespace Swoole::Coroutine::Http2::Client {
class Exception;
}
namespace Swoole::Http2 {
class Request;
class Response;
}  // namespace Swoole::Http2
namespace Swoole::Coroutine::Http2 {
class Client;
}
namespace FTP {
class Connection;
}
namespace Swoole::Server {
class Task;
class Event;
class Packet;
class PipeMessage;
class StatusInfo;
class TaskResult;
class Port;
}  // namespace Swoole::Server
namespace Swoole::Connection {
class Iterator;
}
namespace Swoole::Http {
class Request;
class Cookie;
class Server;
class Response;
}  // namespace Swoole::Http
namespace Swoole::WebSocket {
class Frame;
class Server;
class CloseFrame;
}  // namespace Swoole::WebSocket
namespace Swoole::Coroutine::Http {
class Client;
class Server;
}  // namespace Swoole::Coroutine::Http
namespace Swoole::Redis {
class Server;
}
namespace Swoole::NameResolver {
class Context;
}
namespace Swoole::Thread {
class Error;
class Atomic;
class Lock;
class Barrier;
class Queue;
class Map;
class ArrayList;
}  // namespace Swoole::Thread
namespace Swoole::Thread::Atomic {
class Long;
}

namespace Swoole {

class Exception : public Exception {
  public:
    Exception(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class Error : public Error {
  public:
    Error(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class Event {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Event(const Object &obj) : this_(obj) {}
    Event();
    static Variant add(const Variant &fd,
                       const Variant &read_callback = {},
                       const Variant &write_callback = {},
                       const Variant &events = 512);
    static Variant del(const Variant &fd);
    static Variant set(const Variant &fd,
                       const Variant &read_callback = {},
                       const Variant &write_callback = {},
                       const Variant &events = 0);
    static Variant isset(const Variant &fd, const Variant &events = 1536);
    static Variant dispatch();
    static Variant defer(const Variant &callback);
    static Variant cycle(const Variant &callback, const Variant &before = false);
    static Variant write(const Variant &fd, const Variant &data);
    static Variant wait();
    static Variant rshutdown();
    static Variant exit();
};

class Atomic {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Atomic(const Variant &value = 0);
    Variant add(const Variant &add_value = 1);
    Variant sub(const Variant &sub_value = 1);
    Variant get();
    Variant set(const Variant &value);
    Variant wait(const Variant &timeout = 1);
    Variant wakeup(const Variant &count = 1);
    Variant cmpset(const Variant &cmp_value, const Variant &new_value);
};

class Lock {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int MUTEX = 3;
    static constexpr int RWLOCK = 1;
    static constexpr int SPINLOCK = 5;

    Lock(const Variant &type = 3);
    Variant lock(const Variant &operation = 2, const Variant &timeout = -1);
    Variant unlock();
};

class Table {
  protected:
    Object this_;
    Table() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int TYPE_INT = 1;
    static constexpr int TYPE_STRING = 3;
    static constexpr int TYPE_FLOAT = 2;

    Table(const Variant &table_size, const Variant &conflict_proportion = 0.20000000000000001);
    Variant column(const Variant &name, const Variant &type, const Variant &size = 0);
    Variant create();
    Variant destroy();
    Variant set(const Variant &key, const Variant &value);
    Variant get(const Variant &key, const Variant &field = {});
    Variant count();
    Variant del(const Variant &key);
    Variant delete_(const Variant &key);
    Variant exists(const Variant &key);
    Variant exist(const Variant &key);
    Variant incr(const Variant &key, const Variant &column, const Variant &incrby = 1);
    Variant decr(const Variant &key, const Variant &column, const Variant &incrby = 1);
    Variant getSize();
    Variant getMemorySize();
    Variant stats();
    Variant rewind();
    Variant valid();
    Variant next();
    Variant current();
    Variant key();
};

class Timer {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Timer(const Object &obj) : this_(obj) {}
    Timer();
    template <typename... Args>
    Variant tick(const Variant &ms, const Variant &callback, const Args &...params) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(LITERAL_STRING[2970], LITERAL_STRING[2972]);
        }
        return php::call(_method_fn, {ms, callback, params...});
    }
    template <typename... Args>
    Variant after(const Variant &ms, const Variant &callback, const Args &...params) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(LITERAL_STRING[2970], LITERAL_STRING[477]);
        }
        return php::call(_method_fn, {ms, callback, params...});
    }
    static Variant exists(const Variant &timer_id);
    static Variant info(const Variant &timer_id);
    static Variant stats();
    static Variant list();
    static Variant clear(const Variant &timer_id);
    static Variant clearAll();
};

class Coroutine {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Coroutine(const Object &obj) : this_(obj) {}
    Coroutine();
    template <typename... Args>
    Variant create(const Variant &func, const Args &...param) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[161]);
        }
        return php::call(_method_fn, {func, param...});
    }
    static Variant defer(const Variant &callback);
    static Variant set(const Variant &options);
    static Variant getOptions();
    static Variant exists(const Variant &cid);
    static Variant yield();
    static Variant cancel(const Variant &cid, const Variant &throw_exception = false);
    static Variant join(const Variant &cid_array, const Variant &timeout = -1);
    static Variant isCanceled();
    static Variant setTimeLimit(const Variant &timeout);
    static Variant suspend();
    static Variant resume(const Variant &cid);
    static Variant stats();
    static Variant getCid();
    static Variant getuid();
    static Variant getPcid(const Variant &cid = 0);
    static Variant getContext(const Variant &cid = 0);
    static Variant getBackTrace(const Variant &cid = 0, const Variant &options = 1, const Variant &limit = 0);
    static Variant printBackTrace(const Variant &cid = 0, const Variant &options = 0, const Variant &limit = 0);
    static Variant getElapsed(const Variant &cid = 0);
    static Variant getStackUsage(const Variant &cid = 0);
    static Variant list();
    static Variant listCoroutines();
    static Variant enableScheduler();
    static Variant disableScheduler();
    static Variant gethostbyname(const Variant &domain_name, const Variant &type = 2, const Variant &timeout = -1);
    static Variant dnsLookup(const Variant &domain_name, const Variant &timeout = 60, const Variant &type = 2);
    static Variant exec(const Variant &command, const Variant &get_error_stream = false);
    static Variant sleep(const Variant &seconds);
    static Variant getaddrinfo(const Variant &domain,
                               const Variant &family = 2,
                               const Variant &socktype = 1,
                               const Variant &protocol = 6,
                               const Variant &service = {},
                               const Variant &timeout = -1);
    static Variant statvfs(const Variant &path);
    static Variant readFile(const Variant &filename, const Variant &flag = 0);
    static Variant writeFile(const Variant &filename, const Variant &file_content, const Variant &flags = 0);
    static Variant wait(const Variant &timeout = -1);
    static Variant waitPid(const Variant &pid, const Variant &timeout = -1);
    static Variant waitSignal(const Variant &signals, const Variant &timeout = -1);
    static Variant waitEvent(const Variant &socket, const Variant &events = 512, const Variant &timeout = -1);
};

class ExitException : public Exception {
  public:
    Variant getFlags();
    Variant getStatus();
    ExitException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class Runtime {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Runtime(const Object &obj) : this_(obj) {}
    Runtime();
    static Variant enableCoroutine(const Variant &flags = 2143287295);
    static Variant getHookFlags();
    static Variant setHookFlags(const Variant &flags);
};

class Process {
  protected:
    Object this_;
    Process() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int IPC_NOWAIT = 256;
    static constexpr int PIPE_MASTER = 1;
    static constexpr int PIPE_WORKER = 2;
    static constexpr int PIPE_READ = 3;
    static constexpr int PIPE_WRITE = 4;
    static constexpr int PIPE_TYPE_NONE = 0;
    static constexpr int PIPE_TYPE_STREAM = 1;
    static constexpr int PIPE_TYPE_DGRAM = 2;

    Process(const Variant &callback,
            const Variant &redirect_stdin_and_stdout = false,
            const Variant &pipe_type = 2,
            const Variant &enable_coroutine = false);
    static Variant wait(const Variant &blocking = true);
    static Variant signal(const Variant &signal_no, const Variant &callback = {});
    static Variant alarm(const Variant &usec, const Variant &type = 0);
    static Variant kill(const Variant &pid, const Variant &signal_no = 15);
    static Variant daemon(const Variant &nochdir = true, const Variant &noclose = true, const Variant &pipes = Array{});
    static Variant setAffinity(const Variant &cpu_settings);
    static Variant getAffinity();
    Variant setPriority(const Variant &which, const Variant &priority, const Variant &who = {});
    Variant getPriority(const Variant &which, const Variant &who = {});
    Variant set(const Variant &settings);
    Variant setTimeout(const Variant &seconds);
    Variant setBlocking(const Variant &blocking);
    Variant useQueue(const Variant &key = 0, const Variant &mode = 2, const Variant &capacity = -1);
    Variant statQueue();
    Variant freeQueue();
    Variant start();
    Variant write(const Variant &data);
    Variant close(const Variant &which = 0);
    Variant read(const Variant &size = 8192);
    Variant push(const Variant &data);
    Variant pop(const Variant &size = 65536);
    Variant exit(const Variant &exit_code = 0);
    Variant exec(const Variant &exec_file, const Variant &args);
    Variant exportSocket();
    Variant name(const Variant &process_name);
};

class Client {
  protected:
    Object this_;
    Client() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int MSG_OOB = 1;
    static constexpr int MSG_PEEK = 2;
    static constexpr int MSG_DONTWAIT = 64;
    static constexpr int MSG_WAITALL = 256;
    static constexpr int SHUT_RDWR = 2;
    static constexpr int SHUT_RD = 0;
    static constexpr int SHUT_WR = 1;

    Client(const Variant &type, const Variant &async = false, const Variant &id = "");
    Variant set(const Variant &settings);
    Variant connect(const Variant &host,
                    const Variant &port = 0,
                    const Variant &timeout = 0.5,
                    const Variant &sock_flag = 0);
    Variant recv(const Variant &size = 65536, const Variant &flag = 0);
    Variant send(const Variant &data, const Variant &flag = 0);
    Variant sendfile(const Variant &filename, const Variant &offset = 0, const Variant &length = 0);
    Variant sendto(const Variant &ip, const Variant &port, const Variant &data);
    Variant shutdown(const Variant &how);
    Variant enableSSL(const Variant &on_ssl_ready = {});
    Variant getPeerCert();
    Variant verifyPeerCert();
    Variant isConnected();
    Variant getsockname();
    Variant getpeername();
    Variant close(const Variant &force = false);
    Socket getSocket();
};

class Server {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Server(const Variant &host = "0.0.0.0",
           const Variant &port = 0,
           const Variant &mode = 1,
           const Variant &sock_type = 1);
    Variant listen(const Variant &host, const Variant &port, const Variant &sock_type);
    Variant addlistener(const Variant &host, const Variant &port, const Variant &sock_type);
    Variant on(const Variant &event_name, const Variant &callback);
    Variant getCallback(const Variant &event_name);
    Variant set(const Variant &settings);
    Variant start();
    Variant send(const Variant &fd, const Variant &send_data, const Variant &server_socket = -1);
    Variant sendto(const Variant &ip, const Variant &port, const Variant &send_data, const Variant &server_socket = -1);
    Variant sendwait(const Variant &conn_fd, const Variant &send_data);
    Variant exists(const Variant &fd);
    Variant exist(const Variant &fd);
    Variant protect(const Variant &fd, const Variant &is_protected = true);
    Variant sendfile(const Variant &conn_fd,
                     const Variant &filename,
                     const Variant &offset = 0,
                     const Variant &length = 0);
    Variant close(const Variant &fd, const Variant &reset = false);
    Variant confirm(const Variant &fd);
    Variant pause(const Variant &fd);
    Variant resume(const Variant &fd);
    Variant task(const Variant &data, const Variant &task_worker_index = -1, const Variant &finish_callback = {});
    Variant taskwait(const Variant &data, const Variant &timeout = 0.5, const Variant &task_worker_index = -1);
    Variant taskWaitMulti(const Variant &tasks, const Variant &timeout = 0.5);
    Variant taskCo(const Variant &tasks, const Variant &timeout = 0.5);
    Variant finish(const Variant &data);
    Variant reload(const Variant &only_reload_taskworker = false);
    Variant shutdown();
    Variant stop(const Variant &worker_id = -1);
    Variant getLastError();
    Variant heartbeat(const Variant &if_close_connection = true);
    Variant getClientInfo(const Variant &fd, const Variant &reactor_id = -1, const Variant &ignore_error = false);
    Variant getClientList(const Variant &start_fd = 0, const Variant &find_count = 10);
    Variant getWorkerId();
    Variant getWorkerPid(const Variant &worker_id = -1);
    Variant getWorkerStatus(const Variant &worker_id = -1);
    Variant getManagerPid();
    Variant getMasterPid();
    Variant connection_info(const Variant &fd, const Variant &reactor_id = -1, const Variant &ignore_error = false);
    Variant connection_list(const Variant &start_fd = 0, const Variant &find_count = 10);
    Variant sendMessage(const Variant &message, const Variant &dst_worker_id);
    Variant command(const Variant &name,
                    const Variant &process_id,
                    const Variant &process_type,
                    const Variant &data,
                    const Variant &json_decode = true);
    Variant addCommand(const Variant &name, const Variant &accepted_process_types, const Variant &callback);
    Variant addProcess(const Process &process);
    Variant addProcess(const Variant &process);
    Variant stats();
    Socket getSocket(const Variant &port = 0);
    Variant bind(const Variant &fd, const Variant &uid);
};

class Thread {
  protected:
    Object this_;
    Thread() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int HARDWARE_CONCURRENCY = 12;
    static inline const Variant API_NAME{ZEND_STRL("POSIX Threads"), true};
    static constexpr int SCHED_OTHER = 0;
    static constexpr int SCHED_FIFO = 1;
    static constexpr int SCHED_RR = 2;
    static constexpr int SCHED_BATCH = 3;
    static constexpr int SCHED_ISO = 4;
    static constexpr int SCHED_IDLE = 5;
    static constexpr int SCHED_DEADLINE = 6;

    template <typename... Args>
    Thread(const Variant &script_file, const Args &...args) {
        this_ = newObject(LITERAL_STRING[3268], {script_file, args...});
    }
    Variant isAlive();
    Variant join();
    Variant joinable();
    Variant getExitStatus();
    Variant detach();
    static Variant getArguments();
    static Variant getId();
    static Variant getInfo();
    static Variant activeCount();
    static Variant yield();
    static Variant setName(const Variant &name);
    static Variant setAffinity(const Variant &cpu_settings);
    static Variant getAffinity();
    static Variant setPriority(const Variant &priority, const Variant &policy = 0);
    static Variant getPriority();
    static Variant getNativeId();
};

}  // namespace Swoole
namespace Swoole::Atomic {

class Long {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Long(const Variant &value = 0);
    Variant add(const Variant &add_value = 1);
    Variant sub(const Variant &sub_value = 1);
    Variant get();
    Variant set(const Variant &value);
    Variant cmpset(const Variant &cmp_value, const Variant &new_value);
};

}  // namespace Swoole::Atomic
namespace Swoole::Timer {

class Iterator : public ArrayIterator_ {
  public:
    Iterator(const Variant &array = Array{}, const Variant &flags = 0);
};

}  // namespace Swoole::Timer
namespace Swoole::Coroutine {

class Iterator : public ArrayIterator_ {
  public:
    Iterator(const Variant &array = Array{}, const Variant &flags = 0);
};

class Context : public ArrayObject {
  public:
    Context(const Variant &array = Array{}, const Variant &flags = 0, const Variant &iterator_class = "ArrayIterator");
};

class CanceledException : public Exception {
  public:
    CanceledException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class TimeoutException : public Exception {
  public:
    TimeoutException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class System {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit System(const Object &obj) : this_(obj) {}
    System();
    static Variant gethostbyname(const Variant &domain_name, const Variant &type = 2, const Variant &timeout = -1);
    static Variant dnsLookup(const Variant &domain_name, const Variant &timeout = 60, const Variant &type = 2);
    static Variant exec(const Variant &command, const Variant &get_error_stream = false);
    static Variant sleep(const Variant &seconds);
    static Variant getaddrinfo(const Variant &domain,
                               const Variant &family = 2,
                               const Variant &socktype = 1,
                               const Variant &protocol = 6,
                               const Variant &service = {},
                               const Variant &timeout = -1);
    static Variant statvfs(const Variant &path);
    static Variant readFile(const Variant &filename, const Variant &flag = 0);
    static Variant writeFile(const Variant &filename, const Variant &file_content, const Variant &flags = 0);
    static Variant wait(const Variant &timeout = -1);
    static Variant waitPid(const Variant &pid, const Variant &timeout = -1);
    static Variant waitSignal(const Variant &signals, const Variant &timeout = -1);
    static Variant waitEvent(const Variant &socket, const Variant &events = 512, const Variant &timeout = -1);
};

class Scheduler {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Scheduler(const Object &obj) : this_(obj) {}
    Scheduler();
    template <typename... Args>
    Variant add(const Variant &func, const Args &...param) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
        }
        return this_.call(_method_fn, {func, param...});
    }
    template <typename... Args>
    Variant parallel(const Variant &n, const Variant &func, const Args &...param) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3114]);
        }
        return this_.call(_method_fn, {n, func, param...});
    }
    Variant set(const Variant &settings);
    Variant getOptions();
    Variant start();
};

class Lock {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Lock(const Variant &shared = false);
    Variant lock(const Variant &operation = 2);
    Variant unlock();
};

class Channel {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Channel(const Variant &size = 1);
    Variant push(const Variant &data, const Variant &timeout = -1);
    Variant pop(const Variant &timeout = -1);
    Variant isEmpty();
    Variant isFull();
    Variant close();
    Variant stats();
    Variant length();
};

class Socket {
  protected:
    Object this_;
    Socket() = default;

  public:
    Object getObject() const {
        return this_;
    }
    Socket(const Variant &domain, const Variant &type, const Variant &protocol = 0);
    Variant bind(const Variant &address, const Variant &port = 0);
    Variant listen(const Variant &backlog = 512);
    Variant accept(const Variant &timeout = 0);
    Variant connect(const Variant &host, const Variant &port = 0, const Variant &timeout = 0);
    Variant checkLiveness();
    Variant getBoundCid(const Variant &event);
    Variant peek(const Variant &length = 65536);
    Variant recv(const Variant &length = 65536, const Variant &timeout = 0);
    Variant recvAll(const Variant &length = 65536, const Variant &timeout = 0);
    Variant recvLine(const Variant &length = 65536, const Variant &timeout = 0);
    Variant recvWithBuffer(const Variant &length = 65536, const Variant &timeout = 0);
    Variant recvPacket(const Variant &timeout = 0);
    Variant send(const Variant &data, const Variant &timeout = 0);
    Variant readVector(const Variant &io_vector, const Variant &timeout = 0);
    Variant readVectorAll(const Variant &io_vector, const Variant &timeout = 0);
    Variant writeVector(const Variant &io_vector, const Variant &timeout = 0);
    Variant writeVectorAll(const Variant &io_vector, const Variant &timeout = 0);
    Variant sendFile(const Variant &file, const Variant &offset = 0, const Variant &length = 0);
    Variant sendAll(const Variant &data, const Variant &timeout = 0);
    Variant recvfrom(const Reference &peername, const Variant &timeout = 0);
    Variant sendto(const Variant &addr, const Variant &port, const Variant &data);
    Variant getOption(const Variant &level, const Variant &opt_name);
    Variant setProtocol(const Variant &settings);
    Variant setOption(const Variant &level, const Variant &opt_name, const Variant &opt_value);
    Variant sslHandshake();
    Variant shutdown(const Variant &how = 2);
    Variant cancel(const Variant &event = 512);
    Variant close();
    Variant getpeername();
    Variant getsockname();
    Variant isClosed();
    static Variant import(const Variant &stream);
};

class Client {
  protected:
    Object this_;
    Client() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int MSG_OOB = 1;
    static constexpr int MSG_PEEK = 2;
    static constexpr int MSG_DONTWAIT = 64;
    static constexpr int MSG_WAITALL = 256;

    Client(const Variant &type);
    Variant set(const Variant &settings);
    Variant connect(const Variant &host,
                    const Variant &port = 0,
                    const Variant &timeout = 0,
                    const Variant &sock_flag = 0);
    Variant recv(const Variant &timeout = 0);
    Variant peek(const Variant &length = 65535);
    Variant send(const Variant &data, const Variant &timeout = 0);
    Variant sendfile(const Variant &filename, const Variant &offset = 0, const Variant &length = 0);
    Variant sendto(const Variant &address, const Variant &port, const Variant &data);
    Variant recvfrom(const Variant &length, const Reference &address, const Reference &port = 0);
    Variant enableSSL();
    Variant getPeerCert();
    Variant verifyPeerCert(const Variant &allow_self_signed = false);
    Variant isConnected();
    Variant getsockname();
    Variant getpeername();
    Variant close();
    Variant exportSocket();
};

}  // namespace Swoole::Coroutine
namespace Swoole::Coroutine::Curl {

class Exception : public Swoole_Exception {
  public:
    Exception(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

}  // namespace Swoole::Coroutine::Curl
namespace Swoole::Process {

class Pool {
  protected:
    Object this_;
    Pool() = default;

  public:
    Object getObject() const {
        return this_;
    }
    Pool(const Variant &worker_num,
         const Variant &ipc_type = 0,
         const Variant &msgqueue_key = 0,
         const Variant &enable_coroutine = false);
    Variant set(const Variant &settings);
    Variant on(const Variant &name, const Variant &callback);
    Variant getProcess(const Variant &work_id = -1);
    Variant listen(const Variant &host, const Variant &port = 0, const Variant &backlog = 2048);
    Variant write(const Variant &data);
    Variant sendMessage(const Variant &data, const Variant &dst_worker_id);
    Variant detach();
    Variant start();
    Variant stop();
    Variant shutdown();
};

}  // namespace Swoole::Process
namespace Swoole::Coroutine::Socket {

class Exception : public Swoole_Exception {
  public:
    Exception(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

}  // namespace Swoole::Coroutine::Socket
namespace Swoole::Client {

class Exception : public Swoole_Exception {
  public:
    Exception(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

}  // namespace Swoole::Client
namespace Swoole::Async {

class Client : public Swoole_Client {
  protected:
    Client() = default;

  public:
    Client(const Variant &type);
    Variant connect(const Variant &host,
                    const Variant &port = 0,
                    const Variant &timeout = 0.5,
                    const Variant &sock_flag = 0);
    Variant sleep();
    Variant wakeup();
    Variant pause();
    Variant resume();
    Variant enableSSL(const Variant &on_ssl_ready = {});
    Variant isConnected();
    Variant close(const Variant &force = false);
    Variant on(const Variant &host, const Variant &callback);
};

}  // namespace Swoole::Async
namespace Swoole::Coroutine::Http::Client {

class Exception : public Swoole_Exception {
  public:
    Exception(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

}  // namespace Swoole::Coroutine::Http::Client
namespace Swoole::Coroutine::Http2::Client {

class Exception : public Swoole_Exception {
  public:
    Exception(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

}  // namespace Swoole::Coroutine::Http2::Client
namespace Swoole::Http2 {

class Request {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Request(const Object &obj) : this_(obj) {}
    Request();
};

class Response {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Response(const Object &obj) : this_(obj) {}
    Response();
};

}  // namespace Swoole::Http2
namespace Swoole::Coroutine::Http2 {

class Client {
  protected:
    Object this_;
    Client() = default;

  public:
    Object getObject() const {
        return this_;
    }
    Client(const Variant &host, const Variant &port = 80, const Variant &open_ssl = false);
    Variant set(const Variant &settings);
    Variant connect();
    Variant stats(const Variant &key = "");
    Variant isStreamExist(const Variant &stream_id);
    Variant send(const Swoole_Http2_Request &request);
    Variant send(const Variant &request);
    Variant write(const Variant &stream_id, const Variant &data, const Variant &end_stream = false);
    Swoole_Http2_Response recv(const Variant &timeout = 0);
    Swoole_Http2_Response read(const Variant &timeout = 0);
    Variant goaway(const Variant &error_code = 0, const Variant &debug_data = "");
    Variant ping();
    Variant close();
};

}  // namespace Swoole::Coroutine::Http2
namespace FTP {

class Connection {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Connection(const Object &obj) : this_(obj) {}
    Connection();
};

}  // namespace FTP
namespace Swoole::Server {

class Task {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Task(const Object &obj) : this_(obj) {}
    Task();
    Variant finish(const Variant &data);
    static Variant pack(const Variant &data);
    static Variant unpack(const Variant &data);
};

class Event {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Event(const Object &obj) : this_(obj) {}
    Event();
};

class Packet {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Packet(const Object &obj) : this_(obj) {}
    Packet();
};

class PipeMessage {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit PipeMessage(const Object &obj) : this_(obj) {}
    PipeMessage();
};

class StatusInfo {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit StatusInfo(const Object &obj) : this_(obj) {}
    StatusInfo();
};

class TaskResult {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit TaskResult(const Object &obj) : this_(obj) {}
    TaskResult();
};

class Port {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Variant set(const Variant &settings);
    Variant on(const Variant &event_name, const Variant &callback);
    Variant getCallback(const Variant &event_name);
    Socket getSocket();
};

}  // namespace Swoole::Server
namespace Swoole::Connection {

class Iterator {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Iterator();
    Variant rewind();
    Variant next();
    Variant current();
    Variant key();
    Variant valid();
    Variant count();
    Variant offsetExists(const Variant &fd);
    Variant offsetGet(const Variant &fd);
    Variant offsetSet(const Variant &fd, const Variant &value);
    Variant offsetUnset(const Variant &fd);
};

}  // namespace Swoole::Connection
namespace Swoole::Http {

class Request {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Request(const Object &obj) : this_(obj) {}
    Request();
    Variant getContent();
    Variant rawContent();
    Variant getData();
    static Request create(const Variant &options = Array{});
    Variant parse(const Variant &data);
    Variant isCompleted();
    Variant getMethod();
};

class Cookie {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Cookie(const Variant &encode = true);
    Variant withName(const Variant &name);
    Variant withValue(const Variant &value = "");
    Variant withExpires(const Variant &expires = 0);
    Variant withPath(const Variant &path = "/");
    Variant withDomain(const Variant &domain = "");
    Variant withSecure(const Variant &secure = false);
    Variant withHttpOnly(const Variant &http_only = false);
    Variant withSameSite(const Variant &same_site = "");
    Variant withPriority(const Variant &priority = "");
    Variant withPartitioned(const Variant &partitioned = false);
    Variant toString();
    Variant toArray();
    Variant reset();
};

class Server : public Swoole_Server {
  public:
    Server(const Variant &host = "0.0.0.0",
           const Variant &port = 0,
           const Variant &mode = 1,
           const Variant &sock_type = 1);
};

class Response {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Response(const Object &obj) : this_(obj) {}
    Response();
    Variant initHeader();
    Variant isWritable();
    Variant cookie(const Variant &name_or_object,
                   const Variant &value = "",
                   const Variant &expires = 0,
                   const Variant &path = "/",
                   const Variant &domain = "",
                   const Variant &secure = false,
                   const Variant &httponly = false,
                   const Variant &samesite = "",
                   const Variant &priority = "",
                   const Variant &partitioned = false);
    Variant setCookie(const Variant &name_or_object,
                      const Variant &value = "",
                      const Variant &expires = 0,
                      const Variant &path = "/",
                      const Variant &domain = "",
                      const Variant &secure = false,
                      const Variant &httponly = false,
                      const Variant &samesite = "",
                      const Variant &priority = "",
                      const Variant &partitioned = false);
    Variant rawcookie(const Variant &name_or_object,
                      const Variant &value = "",
                      const Variant &expires = 0,
                      const Variant &path = "/",
                      const Variant &domain = "",
                      const Variant &secure = false,
                      const Variant &httponly = false,
                      const Variant &samesite = "",
                      const Variant &priority = "",
                      const Variant &partitioned = false);
    Variant setRawCookie(const Variant &name_or_object,
                         const Variant &value = "",
                         const Variant &expires = 0,
                         const Variant &path = "/",
                         const Variant &domain = "",
                         const Variant &secure = false,
                         const Variant &httponly = false,
                         const Variant &samesite = "",
                         const Variant &priority = "",
                         const Variant &partitioned = false);
    Variant status(const Variant &http_code, const Variant &reason = "");
    Variant setStatusCode(const Variant &http_code, const Variant &reason = "");
    Variant header(const Variant &key, const Variant &value, const Variant &format = true);
    Variant setHeader(const Variant &key, const Variant &value, const Variant &format = true);
    Variant trailer(const Variant &key, const Variant &value);
    Variant ping(const Variant &data = "");
    Variant goaway(const Variant &error_code = 0, const Variant &debug_data = "");
    Variant write(const Variant &content);
    Variant end(const Variant &content = {});
    Variant sendfile(const Variant &filename, const Variant &offset = 0, const Variant &length = 0);
    Variant redirect(const Variant &location, const Variant &http_code = 302);
    Variant detach();
    static Response create(const Variant &server = -1, const Variant &fd = -1);
    Variant upgrade();
    Variant push(const Variant &data, const Variant &opcode = 1, const Variant &flags = 1);
    Variant recv(const Variant &timeout = 0);
    Variant close();
    Variant disconnect(const Variant &code = 1000, const Variant &reason = "");
};

}  // namespace Swoole::Http
namespace Swoole::WebSocket {

class Frame {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Frame(const Object &obj) : this_(obj) {}
    Frame();
    Variant __toString();
    static Variant pack(const Variant &data, const Variant &opcode = 1, const Variant &flags = 1);
    static Frame unpack(const Variant &data);
};

class Server : public Swoole_Http_Server {
  public:
    Variant push(const Variant &fd, const Variant &data, const Variant &opcode = 1, const Variant &flags = 1);
    Variant disconnect(const Variant &fd, const Variant &code = 1000, const Variant &reason = "");
    Variant ping(const Variant &fd, const Variant &data = "");
    Variant isEstablished(const Variant &fd);
    static Variant pack(const Variant &data, const Variant &opcode = 1, const Variant &flags = 1);
    static Frame unpack(const Variant &data);
    Server(const Variant &host = "0.0.0.0",
           const Variant &port = 0,
           const Variant &mode = 1,
           const Variant &sock_type = 1);
};

class CloseFrame : public Frame {
  public:
    explicit CloseFrame(const Object &obj) : Frame(obj) {}
    CloseFrame();
};

}  // namespace Swoole::WebSocket
namespace Swoole::Coroutine::Http {

class Client {
  protected:
    Object this_;
    Client() = default;

  public:
    Object getObject() const {
        return this_;
    }
    Client(const Variant &host, const Variant &port = 0, const Variant &ssl = false);
    Variant set(const Variant &settings);
    Variant getDefer();
    Variant setDefer(const Variant &defer = true);
    Variant setMethod(const Variant &method);
    Variant setHeaders(const Variant &headers);
    Variant setBasicAuth(const Variant &username, const Variant &password);
    Variant setCookies(const Variant &cookies);
    Variant setData(const Variant &data);
    Variant addFile(const Variant &path,
                    const Variant &name,
                    const Variant &type = {},
                    const Variant &filename = {},
                    const Variant &offset = 0,
                    const Variant &length = 0);
    Variant addData(const Variant &path, const Variant &name, const Variant &type = {}, const Variant &filename = {});
    Variant execute(const Variant &path);
    Variant getpeername();
    Variant getsockname();
    Variant get(const Variant &path);
    Variant post(const Variant &path, const Variant &data);
    Variant download(const Variant &path, const Variant &file, const Variant &offset = 0);
    Variant getBody();
    Variant getHeaders();
    Variant getCookies();
    Variant getStatusCode();
    Variant getHeaderOut();
    Variant getPeerCert();
    Variant upgrade(const Variant &path);
    Variant push(const Variant &data, const Variant &opcode = 1, const Variant &flags = 1);
    Variant recv(const Variant &timeout = 0);
    Variant close();
    Variant ping(const Variant &data = "");
    Variant disconnect(const Variant &code = 1000, const Variant &reason = "");
};

class Server {
  protected:
    Object this_;
    Server() = default;

  public:
    Object getObject() const {
        return this_;
    }
    Server(const Variant &host, const Variant &port = 0, const Variant &ssl = false, const Variant &reuse_port = false);
    Variant set(const Variant &settings);
    Variant handle(const Variant &pattern, const Variant &callback);
    Variant start();
    Variant shutdown();
};

}  // namespace Swoole::Coroutine::Http
namespace Swoole::Redis {

class Server : public Swoole_Server {
  public:
    static constexpr int NIL = 1;
    static constexpr int ERROR = 0;
    static constexpr int STATUS = 2;
    static constexpr int INT = 3;
    static constexpr int STRING = 4;
    static constexpr int SET = 5;
    static constexpr int MAP = 6;

    Variant setHandler(const Variant &command, const Variant &callback);
    Variant getHandler(const Variant &command);
    static Variant format(const Variant &type, const Variant &value = {});
    Server(const Variant &host = "0.0.0.0",
           const Variant &port = 0,
           const Variant &mode = 1,
           const Variant &sock_type = 1);
};

}  // namespace Swoole::Redis
namespace Swoole::NameResolver {

class Context {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Context(const Variant &family = 2, const Variant &with_port = false);
};

}  // namespace Swoole::NameResolver
namespace Swoole::Thread {

class Error {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Error(const Object &obj) : this_(obj) {}
    Error();
};

class Atomic {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Atomic(const Variant &value = 0);
    Variant add(const Variant &add_value = 1);
    Variant sub(const Variant &sub_value = 1);
    Variant get();
    Variant set(const Variant &value);
    Variant wait(const Variant &timeout = 1);
    Variant wakeup(const Variant &count = 1);
    Variant cmpset(const Variant &cmp_value, const Variant &new_value);
};

class Lock {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int MUTEX = 3;
    static constexpr int RWLOCK = 1;
    static constexpr int SPINLOCK = 5;

    Lock(const Variant &type = 3);
    Variant lock(const Variant &operation = 2, const Variant &timeout = -1);
    Variant unlock();
};

class Barrier {
  protected:
    Object this_;
    Barrier() = default;

  public:
    Object getObject() const {
        return this_;
    }
    Barrier(const Variant &count);
    Variant wait();
};

class Queue {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int NOTIFY_ONE = 1;
    static constexpr int NOTIFY_ALL = 2;

    Queue();
    Variant push(const Variant &value, const Variant &notify_which = 0);
    Variant pop(const Variant &wait = 0);
    Variant clean();
    Variant count();
};

class Map {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Map(const Variant &array = {});
    Variant offsetGet(const Variant &key);
    Variant offsetExists(const Variant &key);
    Variant offsetSet(const Variant &key, const Variant &value);
    Variant offsetUnset(const Variant &key);
    Variant find(const Variant &value);
    Variant count();
    Variant incr(const Variant &key, const Variant &value = 1);
    Variant decr(const Variant &key, const Variant &value = 1);
    Variant add(const Variant &key, const Variant &value);
    Variant update(const Variant &key, const Variant &value);
    Variant clean();
    Variant keys();
    Variant values();
    Variant toArray();
    Variant sort();
};

class ArrayList {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    ArrayList(const Variant &array = {});
    Variant offsetGet(const Variant &key);
    Variant offsetExists(const Variant &key);
    Variant offsetSet(const Variant &key, const Variant &value);
    Variant offsetUnset(const Variant &key);
    Variant find(const Variant &value);
    Variant incr(const Variant &key, const Variant &value = 1);
    Variant decr(const Variant &key, const Variant &value = 1);
    Variant clean();
    Variant count();
    Variant toArray();
    Variant sort();
};

}  // namespace Swoole::Thread
namespace Swoole::Thread::Atomic {

class Long {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Long(const Variant &value = 0);
    Variant add(const Variant &add_value = 1);
    Variant sub(const Variant &sub_value = 1);
    Variant get();
    Variant set(const Variant &value);
    Variant cmpset(const Variant &cmp_value, const Variant &new_value);
};

}  // namespace Swoole::Thread::Atomic
}  // namespace php
