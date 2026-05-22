#include "phpx.h"
#include "phpx_class.h"
#include "class/swoole.h"

namespace php::Swoole {
Exception::Exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2910], {message, code, previous});
}
Error::Error(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2911], {message, code, previous});
}
Event::Event() {
    this_ = newObject(LITERAL_STRING[2912]);
}
Variant Event::add(const Variant &fd,
                   const Variant &read_callback,
                   const Variant &write_callback,
                   const Variant &events) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2912], LITERAL_STRING[16]);
    }
    return php::call(_method_fn, {fd, read_callback, write_callback, events});
}
Variant Event::del(const Variant &fd) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2912], LITERAL_STRING[1299]);
    }
    return php::call(_method_fn, {fd});
}
Variant Event::set(const Variant &fd,
                   const Variant &read_callback,
                   const Variant &write_callback,
                   const Variant &events) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2912], LITERAL_STRING[1437]);
    }
    return php::call(_method_fn, {fd, read_callback, write_callback, events});
}
Variant Event::isset(const Variant &fd, const Variant &events) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2912], LITERAL_STRING[2917]);
    }
    return php::call(_method_fn, {fd, events});
}
Variant Event::dispatch() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2912], LITERAL_STRING[2919]);
    }
    return php::call(_method_fn, {});
}
Variant Event::defer(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2912], LITERAL_STRING[2865]);
    }
    return php::call(_method_fn, {callback});
}
Variant Event::cycle(const Variant &callback, const Variant &before) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2912], LITERAL_STRING[2922]);
    }
    return php::call(_method_fn, {callback, before});
}
Variant Event::write(const Variant &fd, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2912], LITERAL_STRING[1843]);
    }
    return php::call(_method_fn, {fd, data});
}
Variant Event::wait() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2912], LITERAL_STRING[1467]);
    }
    return php::call(_method_fn, {});
}
Variant Event::rshutdown() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2912], LITERAL_STRING[2926]);
    }
    return php::call(_method_fn, {});
}
Variant Event::exit() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2912], LITERAL_STRING[2928]);
    }
    return php::call(_method_fn, {});
}
Atomic::Atomic(const Variant &value) {
    this_ = newObject(LITERAL_STRING[2929], {value});
}
Variant Atomic::add(const Variant &add_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {add_value});
}
Variant Atomic::sub(const Variant &sub_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[17]);
    }
    return this_.call(_method_fn, {sub_value});
}
Variant Atomic::get() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[162]);
    }
    return this_.call(_method_fn, {});
}
Variant Atomic::set(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {value});
}
Variant Atomic::wait(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1467]);
    }
    return this_.call(_method_fn, {timeout});
}
Variant Atomic::wakeup(const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2930]);
    }
    return this_.call(_method_fn, {count});
}
Variant Atomic::cmpset(const Variant &cmp_value, const Variant &new_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2931]);
    }
    return this_.call(_method_fn, {cmp_value, new_value});
}
Lock::Lock(const Variant &type) {
    this_ = newObject(LITERAL_STRING[2933], {type});
}
Variant Lock::lock(const Variant &operation, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2934]);
    }
    return this_.call(_method_fn, {operation, timeout});
}
Variant Lock::unlock() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2935]);
    }
    return this_.call(_method_fn, {});
}
Table::Table(const Variant &table_size, const Variant &conflict_proportion) {
    this_ = newObject(LITERAL_STRING[2965], {table_size, conflict_proportion});
}
Variant Table::column(const Variant &name, const Variant &type, const Variant &size) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2966]);
    }
    return this_.call(_method_fn, {name, type, size});
}
Variant Table::create() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[161]);
    }
    return this_.call(_method_fn, {});
}
Variant Table::destroy() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1844]);
    }
    return this_.call(_method_fn, {});
}
Variant Table::set(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Table::get(const Variant &key, const Variant &field) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[162]);
    }
    return this_.call(_method_fn, {key, field});
}
Variant Table::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant Table::del(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1299]);
    }
    return this_.call(_method_fn, {key});
}
Variant Table::delete_(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1120]);
    }
    return this_.call(_method_fn, {key});
}
Variant Table::exists(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1307]);
    }
    return this_.call(_method_fn, {key});
}
Variant Table::exist(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2967]);
    }
    return this_.call(_method_fn, {key});
}
Variant Table::incr(const Variant &key, const Variant &column, const Variant &incrby) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1367]);
    }
    return this_.call(_method_fn, {key, column, incrby});
}
Variant Table::decr(const Variant &key, const Variant &column, const Variant &incrby) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1297]);
    }
    return this_.call(_method_fn, {key, column, incrby});
}
Variant Table::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2106]);
    }
    return this_.call(_method_fn, {});
}
Variant Table::getMemorySize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2968]);
    }
    return this_.call(_method_fn, {});
}
Variant Table::stats() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2969]);
    }
    return this_.call(_method_fn, {});
}
Variant Table::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant Table::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant Table::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant Table::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant Table::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Timer::Timer() {
    this_ = newObject(LITERAL_STRING[2970]);
}
Variant Timer::exists(const Variant &timer_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2970], LITERAL_STRING[1307]);
    }
    return php::call(_method_fn, {timer_id});
}
Variant Timer::info(const Variant &timer_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2970], LITERAL_STRING[1370]);
    }
    return php::call(_method_fn, {timer_id});
}
Variant Timer::stats() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2970], LITERAL_STRING[2969]);
    }
    return php::call(_method_fn, {});
}
Variant Timer::list() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2970], LITERAL_STRING[2978]);
    }
    return php::call(_method_fn, {});
}
Variant Timer::clear(const Variant &timer_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2970], LITERAL_STRING[2215]);
    }
    return php::call(_method_fn, {timer_id});
}
Variant Timer::clearAll() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2970], LITERAL_STRING[2981]);
    }
    return php::call(_method_fn, {});
}
Coroutine::Coroutine() {
    this_ = newObject(LITERAL_STRING[2983]);
}
Variant Coroutine::defer(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[2865]);
    }
    return php::call(_method_fn, {callback});
}
Variant Coroutine::set(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[1437]);
    }
    return php::call(_method_fn, {options});
}
Variant Coroutine::getOptions() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[2988]);
    }
    return php::call(_method_fn, {});
}
Variant Coroutine::exists(const Variant &cid) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[1307]);
    }
    return php::call(_method_fn, {cid});
}
Variant Coroutine::yield() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[2991]);
    }
    return php::call(_method_fn, {});
}
Variant Coroutine::cancel(const Variant &cid, const Variant &throw_exception) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[2993]);
    }
    return php::call(_method_fn, {cid, throw_exception});
}
Variant Coroutine::join(const Variant &cid_array, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[2423]);
    }
    return php::call(_method_fn, {cid_array, timeout});
}
Variant Coroutine::isCanceled() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[2996]);
    }
    return php::call(_method_fn, {});
}
Variant Coroutine::setTimeLimit(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[2998]);
    }
    return php::call(_method_fn, {timeout});
}
Variant Coroutine::suspend() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[188]);
    }
    return php::call(_method_fn, {});
}
Variant Coroutine::resume(const Variant &cid) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[180]);
    }
    return php::call(_method_fn, {cid});
}
Variant Coroutine::stats() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[2969]);
    }
    return php::call(_method_fn, {});
}
Variant Coroutine::getCid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3003]);
    }
    return php::call(_method_fn, {});
}
Variant Coroutine::getuid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3005]);
    }
    return php::call(_method_fn, {});
}
Variant Coroutine::getPcid(const Variant &cid) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3007]);
    }
    return php::call(_method_fn, {cid});
}
Variant Coroutine::getContext(const Variant &cid) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3009]);
    }
    return php::call(_method_fn, {cid});
}
Variant Coroutine::getBackTrace(const Variant &cid, const Variant &options, const Variant &limit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3011]);
    }
    return php::call(_method_fn, {cid, options, limit});
}
Variant Coroutine::printBackTrace(const Variant &cid, const Variant &options, const Variant &limit) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3013]);
    }
    return php::call(_method_fn, {cid, options, limit});
}
Variant Coroutine::getElapsed(const Variant &cid) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3015]);
    }
    return php::call(_method_fn, {cid});
}
Variant Coroutine::getStackUsage(const Variant &cid) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3017]);
    }
    return php::call(_method_fn, {cid});
}
Variant Coroutine::list() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[2978]);
    }
    return php::call(_method_fn, {});
}
Variant Coroutine::listCoroutines() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3020]);
    }
    return php::call(_method_fn, {});
}
Variant Coroutine::enableScheduler() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3022]);
    }
    return php::call(_method_fn, {});
}
Variant Coroutine::disableScheduler() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3024]);
    }
    return php::call(_method_fn, {});
}
Variant Coroutine::gethostbyname(const Variant &domain_name, const Variant &type, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[2373]);
    }
    return php::call(_method_fn, {domain_name, type, timeout});
}
Variant Coroutine::dnsLookup(const Variant &domain_name, const Variant &timeout, const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3027]);
    }
    return php::call(_method_fn, {domain_name, timeout, type});
}
Variant Coroutine::exec(const Variant &command, const Variant &get_error_stream) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[1077]);
    }
    return php::call(_method_fn, {command, get_error_stream});
}
Variant Coroutine::sleep(const Variant &seconds) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[2325]);
    }
    return php::call(_method_fn, {seconds});
}
Variant Coroutine::getaddrinfo(const Variant &domain,
                               const Variant &family,
                               const Variant &socktype,
                               const Variant &protocol,
                               const Variant &service,
                               const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3031]);
    }
    return php::call(_method_fn, {domain, family, socktype, protocol, service, timeout});
}
Variant Coroutine::statvfs(const Variant &path) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3033]);
    }
    return php::call(_method_fn, {path});
}
Variant Coroutine::readFile(const Variant &filename, const Variant &flag) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3035]);
    }
    return php::call(_method_fn, {filename, flag});
}
Variant Coroutine::writeFile(const Variant &filename, const Variant &file_content, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3037]);
    }
    return php::call(_method_fn, {filename, file_content, flags});
}
Variant Coroutine::wait(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[1467]);
    }
    return php::call(_method_fn, {timeout});
}
Variant Coroutine::waitPid(const Variant &pid, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3040]);
    }
    return php::call(_method_fn, {pid, timeout});
}
Variant Coroutine::waitSignal(const Variant &signals, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3042]);
    }
    return php::call(_method_fn, {signals, timeout});
}
Variant Coroutine::waitEvent(const Variant &socket, const Variant &events, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2983], LITERAL_STRING[3044]);
    }
    return php::call(_method_fn, {socket, events, timeout});
}
Variant ExitException::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2064]);
    }
    return this_.call(_method_fn, {});
}
Variant ExitException::getStatus() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3084]);
    }
    return this_.call(_method_fn, {});
}
ExitException::ExitException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[3085], {message, code, previous});
}
Runtime::Runtime() {
    this_ = newObject(LITERAL_STRING[3119]);
}
Variant Runtime::enableCoroutine(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3119], LITERAL_STRING[3121]);
    }
    return php::call(_method_fn, {flags});
}
Variant Runtime::getHookFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3119], LITERAL_STRING[3123]);
    }
    return php::call(_method_fn, {});
}
Variant Runtime::setHookFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3119], LITERAL_STRING[3125]);
    }
    return php::call(_method_fn, {flags});
}
Process::Process(const Variant &callback,
                 const Variant &redirect_stdin_and_stdout,
                 const Variant &pipe_type,
                 const Variant &enable_coroutine) {
    this_ = newObject(LITERAL_STRING[2936], {callback, redirect_stdin_and_stdout, pipe_type, enable_coroutine});
}
Variant Process::wait(const Variant &blocking) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2936], LITERAL_STRING[1467]);
    }
    return php::call(_method_fn, {blocking});
}
Variant Process::signal(const Variant &signal_no, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2936], LITERAL_STRING[2939]);
    }
    return php::call(_method_fn, {signal_no, callback});
}
Variant Process::alarm(const Variant &usec, const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2936], LITERAL_STRING[2941]);
    }
    return php::call(_method_fn, {usec, type});
}
Variant Process::kill(const Variant &pid, const Variant &signal_no) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2936], LITERAL_STRING[907]);
    }
    return php::call(_method_fn, {pid, signal_no});
}
Variant Process::daemon(const Variant &nochdir, const Variant &noclose, const Variant &pipes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2936], LITERAL_STRING[2944]);
    }
    return php::call(_method_fn, {nochdir, noclose, pipes});
}
Variant Process::setAffinity(const Variant &cpu_settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2936], LITERAL_STRING[2946]);
    }
    return php::call(_method_fn, {cpu_settings});
}
Variant Process::getAffinity() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2936], LITERAL_STRING[2948]);
    }
    return php::call(_method_fn, {});
}
Variant Process::setPriority(const Variant &which, const Variant &priority, const Variant &who) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2949]);
    }
    return this_.call(_method_fn, {which, priority, who});
}
Variant Process::getPriority(const Variant &which, const Variant &who) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2950]);
    }
    return this_.call(_method_fn, {which, who});
}
Variant Process::set(const Variant &settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {settings});
}
Variant Process::setTimeout(const Variant &seconds) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2951]);
    }
    return this_.call(_method_fn, {seconds});
}
Variant Process::setBlocking(const Variant &blocking) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2952]);
    }
    return this_.call(_method_fn, {blocking});
}
Variant Process::useQueue(const Variant &key, const Variant &mode, const Variant &capacity) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2953]);
    }
    return this_.call(_method_fn, {key, mode, capacity});
}
Variant Process::statQueue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2954]);
    }
    return this_.call(_method_fn, {});
}
Variant Process::freeQueue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2955]);
    }
    return this_.call(_method_fn, {});
}
Variant Process::start() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[179]);
    }
    return this_.call(_method_fn, {});
}
Variant Process::write(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1843]);
    }
    return this_.call(_method_fn, {data});
}
Variant Process::close(const Variant &which) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {which});
}
Variant Process::read(const Variant &size) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1842]);
    }
    return this_.call(_method_fn, {size});
}
Variant Process::push(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2157]);
    }
    return this_.call(_method_fn, {data});
}
Variant Process::pop(const Variant &size) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2155]);
    }
    return this_.call(_method_fn, {size});
}
Variant Process::exit(const Variant &exit_code) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2928]);
    }
    return this_.call(_method_fn, {exit_code});
}
Variant Process::exec(const Variant &exec_file, const Variant &args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1077]);
    }
    return this_.call(_method_fn, {exec_file, args});
}
Variant Process::exportSocket() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2956]);
    }
    return this_.call(_method_fn, {});
}
Variant Process::name(const Variant &process_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2957]);
    }
    return this_.call(_method_fn, {process_name});
}
Client::Client(const Variant &type, const Variant &async, const Variant &id) {
    this_ = newObject(LITERAL_STRING[3152], {type, async, id});
}
Variant Client::set(const Variant &settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {settings});
}
Variant Client::connect(const Variant &host, const Variant &port, const Variant &timeout, const Variant &sock_flag) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[897]);
    }
    return this_.call(_method_fn, {host, port, timeout, sock_flag});
}
Variant Client::recv(const Variant &size, const Variant &flag) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3131]);
    }
    return this_.call(_method_fn, {size, flag});
}
Variant Client::send(const Variant &data, const Variant &flag) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[154]);
    }
    return this_.call(_method_fn, {data, flag});
}
Variant Client::sendfile(const Variant &filename, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3153]);
    }
    return this_.call(_method_fn, {filename, offset, length});
}
Variant Client::sendto(const Variant &ip, const Variant &port, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3143]);
    }
    return this_.call(_method_fn, {ip, port, data});
}
Variant Client::shutdown(const Variant &how) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2964]);
    }
    return this_.call(_method_fn, {how});
}
Variant Client::enableSSL(const Variant &on_ssl_ready) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3154]);
    }
    return this_.call(_method_fn, {on_ssl_ready});
}
Variant Client::getPeerCert() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3155]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::verifyPeerCert() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3156]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::isConnected() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1371]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::getsockname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3147]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::getpeername() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3146]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::close(const Variant &force) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {force});
}
Socket Client::getSocket() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3157]);
    }
    auto _rv = this_.call(_method_fn, {});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "Swoole\Client::getSocket() returned false");
    }
    return Socket(Object(std::move(_rv)));
}
Server::Server(const Variant &host, const Variant &port, const Variant &mode, const Variant &sock_type) {
    this_ = newObject(LITERAL_STRING[3188], {host, port, mode, sock_type});
}
Variant Server::listen(const Variant &host, const Variant &port, const Variant &sock_type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2961]);
    }
    return this_.call(_method_fn, {host, port, sock_type});
}
Variant Server::addlistener(const Variant &host, const Variant &port, const Variant &sock_type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3189]);
    }
    return this_.call(_method_fn, {host, port, sock_type});
}
Variant Server::on(const Variant &event_name, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2959]);
    }
    return this_.call(_method_fn, {event_name, callback});
}
Variant Server::getCallback(const Variant &event_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3190]);
    }
    return this_.call(_method_fn, {event_name});
}
Variant Server::set(const Variant &settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {settings});
}
Variant Server::start() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[179]);
    }
    return this_.call(_method_fn, {});
}
Variant Server::send(const Variant &fd, const Variant &send_data, const Variant &server_socket) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[154]);
    }
    return this_.call(_method_fn, {fd, send_data, server_socket});
}
Variant Server::sendto(const Variant &ip, const Variant &port, const Variant &send_data, const Variant &server_socket) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3143]);
    }
    return this_.call(_method_fn, {ip, port, send_data, server_socket});
}
Variant Server::sendwait(const Variant &conn_fd, const Variant &send_data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3191]);
    }
    return this_.call(_method_fn, {conn_fd, send_data});
}
Variant Server::exists(const Variant &fd) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1307]);
    }
    return this_.call(_method_fn, {fd});
}
Variant Server::exist(const Variant &fd) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2967]);
    }
    return this_.call(_method_fn, {fd});
}
Variant Server::protect(const Variant &fd, const Variant &is_protected) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3192]);
    }
    return this_.call(_method_fn, {fd, is_protected});
}
Variant Server::sendfile(const Variant &conn_fd,
                         const Variant &filename,
                         const Variant &offset,
                         const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3153]);
    }
    return this_.call(_method_fn, {conn_fd, filename, offset, length});
}
Variant Server::close(const Variant &fd, const Variant &reset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {fd, reset});
}
Variant Server::confirm(const Variant &fd) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3193]);
    }
    return this_.call(_method_fn, {fd});
}
Variant Server::pause(const Variant &fd) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3160]);
    }
    return this_.call(_method_fn, {fd});
}
Variant Server::resume(const Variant &fd) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[180]);
    }
    return this_.call(_method_fn, {fd});
}
Variant Server::task(const Variant &data, const Variant &task_worker_index, const Variant &finish_callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3194]);
    }
    return this_.call(_method_fn, {data, task_worker_index, finish_callback});
}
Variant Server::taskwait(const Variant &data, const Variant &timeout, const Variant &task_worker_index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3195]);
    }
    return this_.call(_method_fn, {data, timeout, task_worker_index});
}
Variant Server::taskWaitMulti(const Variant &tasks, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3196]);
    }
    return this_.call(_method_fn, {tasks, timeout});
}
Variant Server::taskCo(const Variant &tasks, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3197]);
    }
    return this_.call(_method_fn, {tasks, timeout});
}
Variant Server::finish(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3198]);
    }
    return this_.call(_method_fn, {data});
}
Variant Server::reload(const Variant &only_reload_taskworker) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3199]);
    }
    return this_.call(_method_fn, {only_reload_taskworker});
}
Variant Server::shutdown() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2964]);
    }
    return this_.call(_method_fn, {});
}
Variant Server::stop(const Variant &worker_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2963]);
    }
    return this_.call(_method_fn, {worker_id});
}
Variant Server::getLastError() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1335]);
    }
    return this_.call(_method_fn, {});
}
Variant Server::heartbeat(const Variant &if_close_connection) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3200]);
    }
    return this_.call(_method_fn, {if_close_connection});
}
Variant Server::getClientInfo(const Variant &fd, const Variant &reactor_id, const Variant &ignore_error) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3201]);
    }
    return this_.call(_method_fn, {fd, reactor_id, ignore_error});
}
Variant Server::getClientList(const Variant &start_fd, const Variant &find_count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3202]);
    }
    return this_.call(_method_fn, {start_fd, find_count});
}
Variant Server::getWorkerId() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3203]);
    }
    return this_.call(_method_fn, {});
}
Variant Server::getWorkerPid(const Variant &worker_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3204]);
    }
    return this_.call(_method_fn, {worker_id});
}
Variant Server::getWorkerStatus(const Variant &worker_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3205]);
    }
    return this_.call(_method_fn, {worker_id});
}
Variant Server::getManagerPid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3206]);
    }
    return this_.call(_method_fn, {});
}
Variant Server::getMasterPid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3207]);
    }
    return this_.call(_method_fn, {});
}
Variant Server::connection_info(const Variant &fd, const Variant &reactor_id, const Variant &ignore_error) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3208]);
    }
    return this_.call(_method_fn, {fd, reactor_id, ignore_error});
}
Variant Server::connection_list(const Variant &start_fd, const Variant &find_count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3209]);
    }
    return this_.call(_method_fn, {start_fd, find_count});
}
Variant Server::sendMessage(const Variant &message, const Variant &dst_worker_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2962]);
    }
    return this_.call(_method_fn, {message, dst_worker_id});
}
Variant Server::command(const Variant &name,
                        const Variant &process_id,
                        const Variant &process_type,
                        const Variant &data,
                        const Variant &json_decode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1294]);
    }
    return this_.call(_method_fn, {name, process_id, process_type, data, json_decode});
}
Variant Server::addCommand(const Variant &name, const Variant &accepted_process_types, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3210]);
    }
    return this_.call(_method_fn, {name, accepted_process_types, callback});
}
Variant Server::addProcess(const Process &process) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3211]);
    }
    return this_.call(_method_fn, {process.getObject()});
}
Variant Server::addProcess(const Variant &process) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3211]);
    }
    return this_.call(_method_fn, {process});
}
Variant Server::stats() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2969]);
    }
    return this_.call(_method_fn, {});
}
Socket Server::getSocket(const Variant &port) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3157]);
    }
    auto _rv = this_.call(_method_fn, {port});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "Swoole\Server::getSocket() returned false");
    }
    return Socket(Object(std::move(_rv)));
}
Variant Server::bind(const Variant &fd, const Variant &uid) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[147]);
    }
    return this_.call(_method_fn, {fd, uid});
}
Variant Thread::isAlive() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3269]);
    }
    return this_.call(_method_fn, {});
}
Variant Thread::join() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2423]);
    }
    return this_.call(_method_fn, {});
}
Variant Thread::joinable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3270]);
    }
    return this_.call(_method_fn, {});
}
Variant Thread::getExitStatus() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3271]);
    }
    return this_.call(_method_fn, {});
}
Variant Thread::detach() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2186]);
    }
    return this_.call(_method_fn, {});
}
Variant Thread::getArguments() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3268], LITERAL_STRING[1798]);
    }
    return php::call(_method_fn, {});
}
Variant Thread::getId() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3268], LITERAL_STRING[1795]);
    }
    return php::call(_method_fn, {});
}
Variant Thread::getInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3268], LITERAL_STRING[2190]);
    }
    return php::call(_method_fn, {});
}
Variant Thread::activeCount() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3268], LITERAL_STRING[3276]);
    }
    return php::call(_method_fn, {});
}
Variant Thread::yield() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3268], LITERAL_STRING[2991]);
    }
    return php::call(_method_fn, {});
}
Variant Thread::setName(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3268], LITERAL_STRING[3279]);
    }
    return php::call(_method_fn, {name});
}
Variant Thread::setAffinity(const Variant &cpu_settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3268], LITERAL_STRING[2946]);
    }
    return php::call(_method_fn, {cpu_settings});
}
Variant Thread::getAffinity() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3268], LITERAL_STRING[2948]);
    }
    return php::call(_method_fn, {});
}
Variant Thread::setPriority(const Variant &priority, const Variant &policy) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3268], LITERAL_STRING[2949]);
    }
    return php::call(_method_fn, {priority, policy});
}
Variant Thread::getPriority() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3268], LITERAL_STRING[2950]);
    }
    return php::call(_method_fn, {});
}
Variant Thread::getNativeId() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3268], LITERAL_STRING[3285]);
    }
    return php::call(_method_fn, {});
}
}  // namespace php::Swoole
namespace php::Swoole::Atomic {
Long::Long(const Variant &value) {
    this_ = newObject(LITERAL_STRING[2932], {value});
}
Variant Long::add(const Variant &add_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {add_value});
}
Variant Long::sub(const Variant &sub_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[17]);
    }
    return this_.call(_method_fn, {sub_value});
}
Variant Long::get() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[162]);
    }
    return this_.call(_method_fn, {});
}
Variant Long::set(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {value});
}
Variant Long::cmpset(const Variant &cmp_value, const Variant &new_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2931]);
    }
    return this_.call(_method_fn, {cmp_value, new_value});
}
}  // namespace php::Swoole::Atomic
namespace php::Swoole::Timer {
Iterator::Iterator(const Variant &array, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[2982], {array, flags});
}
}  // namespace php::Swoole::Timer
namespace php::Swoole::Coroutine {
Iterator::Iterator(const Variant &array, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[3082], {array, flags});
}
Context::Context(const Variant &array, const Variant &flags, const Variant &iterator_class) {
    this_ = newObject(LITERAL_STRING[3083], {array, flags, iterator_class});
}
CanceledException::CanceledException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[3086], {message, code, previous});
}
TimeoutException::TimeoutException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[3087], {message, code, previous});
}
System::System() {
    this_ = newObject(LITERAL_STRING[3088]);
}
Variant System::gethostbyname(const Variant &domain_name, const Variant &type, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3088], LITERAL_STRING[2373]);
    }
    return php::call(_method_fn, {domain_name, type, timeout});
}
Variant System::dnsLookup(const Variant &domain_name, const Variant &timeout, const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3088], LITERAL_STRING[3027]);
    }
    return php::call(_method_fn, {domain_name, timeout, type});
}
Variant System::exec(const Variant &command, const Variant &get_error_stream) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3088], LITERAL_STRING[1077]);
    }
    return php::call(_method_fn, {command, get_error_stream});
}
Variant System::sleep(const Variant &seconds) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3088], LITERAL_STRING[2325]);
    }
    return php::call(_method_fn, {seconds});
}
Variant System::getaddrinfo(const Variant &domain,
                            const Variant &family,
                            const Variant &socktype,
                            const Variant &protocol,
                            const Variant &service,
                            const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3088], LITERAL_STRING[3031]);
    }
    return php::call(_method_fn, {domain, family, socktype, protocol, service, timeout});
}
Variant System::statvfs(const Variant &path) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3088], LITERAL_STRING[3033]);
    }
    return php::call(_method_fn, {path});
}
Variant System::readFile(const Variant &filename, const Variant &flag) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3088], LITERAL_STRING[3035]);
    }
    return php::call(_method_fn, {filename, flag});
}
Variant System::writeFile(const Variant &filename, const Variant &file_content, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3088], LITERAL_STRING[3037]);
    }
    return php::call(_method_fn, {filename, file_content, flags});
}
Variant System::wait(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3088], LITERAL_STRING[1467]);
    }
    return php::call(_method_fn, {timeout});
}
Variant System::waitPid(const Variant &pid, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3088], LITERAL_STRING[3040]);
    }
    return php::call(_method_fn, {pid, timeout});
}
Variant System::waitSignal(const Variant &signals, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3088], LITERAL_STRING[3042]);
    }
    return php::call(_method_fn, {signals, timeout});
}
Variant System::waitEvent(const Variant &socket, const Variant &events, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3088], LITERAL_STRING[3044]);
    }
    return php::call(_method_fn, {socket, events, timeout});
}
Scheduler::Scheduler() {
    this_ = newObject(LITERAL_STRING[3113]);
}
Variant Scheduler::set(const Variant &settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {settings});
}
Variant Scheduler::getOptions() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2988]);
    }
    return this_.call(_method_fn, {});
}
Variant Scheduler::start() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[179]);
    }
    return this_.call(_method_fn, {});
}
Lock::Lock(const Variant &shared) {
    this_ = newObject(LITERAL_STRING[3115], {shared});
}
Variant Lock::lock(const Variant &operation) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2934]);
    }
    return this_.call(_method_fn, {operation});
}
Variant Lock::unlock() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2935]);
    }
    return this_.call(_method_fn, {});
}
Channel::Channel(const Variant &size) {
    this_ = newObject(LITERAL_STRING[3116], {size});
}
Variant Channel::push(const Variant &data, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2157]);
    }
    return this_.call(_method_fn, {data, timeout});
}
Variant Channel::pop(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2155]);
    }
    return this_.call(_method_fn, {timeout});
}
Variant Channel::isEmpty() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2161]);
    }
    return this_.call(_method_fn, {});
}
Variant Channel::isFull() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3117]);
    }
    return this_.call(_method_fn, {});
}
Variant Channel::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {});
}
Variant Channel::stats() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2969]);
    }
    return this_.call(_method_fn, {});
}
Variant Channel::length() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3118]);
    }
    return this_.call(_method_fn, {});
}
Socket::Socket(const Variant &domain, const Variant &type, const Variant &protocol) {
    this_ = newObject(LITERAL_STRING[3127], {domain, type, protocol});
}
Variant Socket::bind(const Variant &address, const Variant &port) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[147]);
    }
    return this_.call(_method_fn, {address, port});
}
Variant Socket::listen(const Variant &backlog) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2961]);
    }
    return this_.call(_method_fn, {backlog});
}
Variant Socket::accept(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2057]);
    }
    return this_.call(_method_fn, {timeout});
}
Variant Socket::connect(const Variant &host, const Variant &port, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[897]);
    }
    return this_.call(_method_fn, {host, port, timeout});
}
Variant Socket::checkLiveness() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3128]);
    }
    return this_.call(_method_fn, {});
}
Variant Socket::getBoundCid(const Variant &event) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3129]);
    }
    return this_.call(_method_fn, {event});
}
Variant Socket::peek(const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3130]);
    }
    return this_.call(_method_fn, {length});
}
Variant Socket::recv(const Variant &length, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3131]);
    }
    return this_.call(_method_fn, {length, timeout});
}
Variant Socket::recvAll(const Variant &length, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3132]);
    }
    return this_.call(_method_fn, {length, timeout});
}
Variant Socket::recvLine(const Variant &length, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3133]);
    }
    return this_.call(_method_fn, {length, timeout});
}
Variant Socket::recvWithBuffer(const Variant &length, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3134]);
    }
    return this_.call(_method_fn, {length, timeout});
}
Variant Socket::recvPacket(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3135]);
    }
    return this_.call(_method_fn, {timeout});
}
Variant Socket::send(const Variant &data, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[154]);
    }
    return this_.call(_method_fn, {data, timeout});
}
Variant Socket::readVector(const Variant &io_vector, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3136]);
    }
    return this_.call(_method_fn, {io_vector, timeout});
}
Variant Socket::readVectorAll(const Variant &io_vector, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3137]);
    }
    return this_.call(_method_fn, {io_vector, timeout});
}
Variant Socket::writeVector(const Variant &io_vector, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3138]);
    }
    return this_.call(_method_fn, {io_vector, timeout});
}
Variant Socket::writeVectorAll(const Variant &io_vector, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3139]);
    }
    return this_.call(_method_fn, {io_vector, timeout});
}
Variant Socket::sendFile(const Variant &file, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3140]);
    }
    return this_.call(_method_fn, {file, offset, length});
}
Variant Socket::sendAll(const Variant &data, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3141]);
    }
    return this_.call(_method_fn, {data, timeout});
}
Variant Socket::recvfrom(const Reference &peername, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3142]);
    }
    return this_.call(_method_fn, {&peername, timeout});
}
Variant Socket::sendto(const Variant &addr, const Variant &port, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3143]);
    }
    return this_.call(_method_fn, {addr, port, data});
}
Variant Socket::getOption(const Variant &level, const Variant &opt_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1337]);
    }
    return this_.call(_method_fn, {level, opt_name});
}
Variant Socket::setProtocol(const Variant &settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3144]);
    }
    return this_.call(_method_fn, {settings});
}
Variant Socket::setOption(const Variant &level, const Variant &opt_name, const Variant &opt_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1440]);
    }
    return this_.call(_method_fn, {level, opt_name, opt_value});
}
Variant Socket::sslHandshake() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3145]);
    }
    return this_.call(_method_fn, {});
}
Variant Socket::shutdown(const Variant &how) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2964]);
    }
    return this_.call(_method_fn, {how});
}
Variant Socket::cancel(const Variant &event) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2993]);
    }
    return this_.call(_method_fn, {event});
}
Variant Socket::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {});
}
Variant Socket::getpeername() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3146]);
    }
    return this_.call(_method_fn, {});
}
Variant Socket::getsockname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3147]);
    }
    return this_.call(_method_fn, {});
}
Variant Socket::isClosed() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1675]);
    }
    return this_.call(_method_fn, {});
}
Variant Socket::import(const Variant &stream) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3127], LITERAL_STRING[3149]);
    }
    return php::call(_method_fn, {stream});
}
Client::Client(const Variant &type) {
    this_ = newObject(LITERAL_STRING[3161], {type});
}
Variant Client::set(const Variant &settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {settings});
}
Variant Client::connect(const Variant &host, const Variant &port, const Variant &timeout, const Variant &sock_flag) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[897]);
    }
    return this_.call(_method_fn, {host, port, timeout, sock_flag});
}
Variant Client::recv(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3131]);
    }
    return this_.call(_method_fn, {timeout});
}
Variant Client::peek(const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3130]);
    }
    return this_.call(_method_fn, {length});
}
Variant Client::send(const Variant &data, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[154]);
    }
    return this_.call(_method_fn, {data, timeout});
}
Variant Client::sendfile(const Variant &filename, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3153]);
    }
    return this_.call(_method_fn, {filename, offset, length});
}
Variant Client::sendto(const Variant &address, const Variant &port, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3143]);
    }
    return this_.call(_method_fn, {address, port, data});
}
Variant Client::recvfrom(const Variant &length, const Reference &address, const Reference &port) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3142]);
    }
    return this_.call(_method_fn, {length, &address, &port});
}
Variant Client::enableSSL() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3154]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::getPeerCert() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3155]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::verifyPeerCert(const Variant &allow_self_signed) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3156]);
    }
    return this_.call(_method_fn, {allow_self_signed});
}
Variant Client::isConnected() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1371]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::getsockname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3147]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::getpeername() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3146]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::exportSocket() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2956]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php::Swoole::Coroutine
namespace php::Swoole::Coroutine::Curl {
Exception::Exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[3126], {message, code, previous});
}
}  // namespace php::Swoole::Coroutine::Curl
namespace php::Swoole::Process {
Pool::Pool(const Variant &worker_num,
           const Variant &ipc_type,
           const Variant &msgqueue_key,
           const Variant &enable_coroutine) {
    this_ = newObject(LITERAL_STRING[2958], {worker_num, ipc_type, msgqueue_key, enable_coroutine});
}
Variant Pool::set(const Variant &settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {settings});
}
Variant Pool::on(const Variant &name, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2959]);
    }
    return this_.call(_method_fn, {name, callback});
}
Variant Pool::getProcess(const Variant &work_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2960]);
    }
    return this_.call(_method_fn, {work_id});
}
Variant Pool::listen(const Variant &host, const Variant &port, const Variant &backlog) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2961]);
    }
    return this_.call(_method_fn, {host, port, backlog});
}
Variant Pool::write(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1843]);
    }
    return this_.call(_method_fn, {data});
}
Variant Pool::sendMessage(const Variant &data, const Variant &dst_worker_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2962]);
    }
    return this_.call(_method_fn, {data, dst_worker_id});
}
Variant Pool::detach() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2186]);
    }
    return this_.call(_method_fn, {});
}
Variant Pool::start() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[179]);
    }
    return this_.call(_method_fn, {});
}
Variant Pool::stop() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2963]);
    }
    return this_.call(_method_fn, {});
}
Variant Pool::shutdown() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2964]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php::Swoole::Process
namespace php::Swoole::Coroutine::Socket {
Exception::Exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[3151], {message, code, previous});
}
}  // namespace php::Swoole::Coroutine::Socket
namespace php::Swoole::Client {
Exception::Exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[3158], {message, code, previous});
}
}  // namespace php::Swoole::Client
namespace php::Swoole::Async {
Client::Client(const Variant &type) {
    this_ = newObject(LITERAL_STRING[3159], {type});
}
Variant Client::connect(const Variant &host, const Variant &port, const Variant &timeout, const Variant &sock_flag) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[897]);
    }
    return this_.call(_method_fn, {host, port, timeout, sock_flag});
}
Variant Client::sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2325]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2930]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::pause() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3160]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::resume() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[180]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::enableSSL(const Variant &on_ssl_ready) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3154]);
    }
    return this_.call(_method_fn, {on_ssl_ready});
}
Variant Client::isConnected() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1371]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::close(const Variant &force) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {force});
}
Variant Client::on(const Variant &host, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2959]);
    }
    return this_.call(_method_fn, {host, callback});
}
}  // namespace php::Swoole::Async
namespace php::Swoole::Coroutine::Http::Client {
Exception::Exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[3180], {message, code, previous});
}
}  // namespace php::Swoole::Coroutine::Http::Client
namespace php::Swoole::Coroutine::Http2::Client {
Exception::Exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[3184], {message, code, previous});
}
}  // namespace php::Swoole::Coroutine::Http2::Client
namespace php::Swoole::Http2 {
Request::Request() {
    this_ = newObject(LITERAL_STRING[3185]);
}
Response::Response() {
    this_ = newObject(LITERAL_STRING[3186]);
}
}  // namespace php::Swoole::Http2
namespace php::Swoole::Coroutine::Http2 {
Client::Client(const Variant &host, const Variant &port, const Variant &open_ssl) {
    this_ = newObject(LITERAL_STRING[3181], {host, port, open_ssl});
}
Variant Client::set(const Variant &settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {settings});
}
Variant Client::connect() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[897]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::stats(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2969]);
    }
    return this_.call(_method_fn, {key});
}
Variant Client::isStreamExist(const Variant &stream_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3182]);
    }
    return this_.call(_method_fn, {stream_id});
}
Variant Client::send(const Swoole_Http2_Request &request) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[154]);
    }
    return this_.call(_method_fn, {request.getObject()});
}
Variant Client::send(const Variant &request) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[154]);
    }
    return this_.call(_method_fn, {request});
}
Variant Client::write(const Variant &stream_id, const Variant &data, const Variant &end_stream) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1843]);
    }
    return this_.call(_method_fn, {stream_id, data, end_stream});
}
Swoole_Http2_Response Client::recv(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3131]);
    }
    auto _rv = this_.call(_method_fn, {timeout});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "Swoole\Coroutine\Http2\Client::recv() returned false");
    }
    return Swoole_Http2_Response(Object(std::move(_rv)));
}
Swoole_Http2_Response Client::read(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1842]);
    }
    auto _rv = this_.call(_method_fn, {timeout});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "Swoole\Coroutine\Http2\Client::read() returned false");
    }
    return Swoole_Http2_Response(Object(std::move(_rv)));
}
Variant Client::goaway(const Variant &error_code, const Variant &debug_data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3183]);
    }
    return this_.call(_method_fn, {error_code, debug_data});
}
Variant Client::ping() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[911]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php::Swoole::Coroutine::Http2
namespace php::FTP {
Connection::Connection() {
    this_ = newObject(LITERAL_STRING[3187]);
}
}  // namespace php::FTP
namespace php::Swoole::Server {
Task::Task() {
    this_ = newObject(LITERAL_STRING[3212]);
}
Variant Task::finish(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3198]);
    }
    return this_.call(_method_fn, {data});
}
Variant Task::pack(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3212], LITERAL_STRING[2615]);
    }
    return php::call(_method_fn, {data});
}
Variant Task::unpack(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3212], LITERAL_STRING[2616]);
    }
    return php::call(_method_fn, {data});
}
Event::Event() {
    this_ = newObject(LITERAL_STRING[3215]);
}
Packet::Packet() {
    this_ = newObject(LITERAL_STRING[3216]);
}
PipeMessage::PipeMessage() {
    this_ = newObject(LITERAL_STRING[3217]);
}
StatusInfo::StatusInfo() {
    this_ = newObject(LITERAL_STRING[3218]);
}
TaskResult::TaskResult() {
    this_ = newObject(LITERAL_STRING[3219]);
}
Variant Port::set(const Variant &settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {settings});
}
Variant Port::on(const Variant &event_name, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2959]);
    }
    return this_.call(_method_fn, {event_name, callback});
}
Variant Port::getCallback(const Variant &event_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3190]);
    }
    return this_.call(_method_fn, {event_name});
}
Socket Port::getSocket() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3157]);
    }
    auto _rv = this_.call(_method_fn, {});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "Swoole\Server\Port::getSocket() returned false");
    }
    return Socket(Object(std::move(_rv)));
}
}  // namespace php::Swoole::Server
namespace php::Swoole::Connection {
Iterator::Iterator() {
    this_ = newObject(LITERAL_STRING[3220], {});
}
Variant Iterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant Iterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant Iterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant Iterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant Iterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant Iterator::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant Iterator::offsetExists(const Variant &fd) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[166]);
    }
    return this_.call(_method_fn, {fd});
}
Variant Iterator::offsetGet(const Variant &fd) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[164]);
    }
    return this_.call(_method_fn, {fd});
}
Variant Iterator::offsetSet(const Variant &fd, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[165]);
    }
    return this_.call(_method_fn, {fd, value});
}
Variant Iterator::offsetUnset(const Variant &fd) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[167]);
    }
    return this_.call(_method_fn, {fd});
}
}  // namespace php::Swoole::Connection
namespace php::Swoole::Http {
Request::Request() {
    this_ = newObject(LITERAL_STRING[3222]);
}
Variant Request::getContent() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1192]);
    }
    return this_.call(_method_fn, {});
}
Variant Request::rawContent() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3223]);
    }
    return this_.call(_method_fn, {});
}
Variant Request::getData() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3224]);
    }
    return this_.call(_method_fn, {});
}
Request Request::create(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3222], LITERAL_STRING[161]);
    }
    return Request(Object(php::call(_method_fn, {options})));
}
Variant Request::parse(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3226]);
    }
    return this_.call(_method_fn, {data});
}
Variant Request::isCompleted() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3227]);
    }
    return this_.call(_method_fn, {});
}
Variant Request::getMethod() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1718]);
    }
    return this_.call(_method_fn, {});
}
Cookie::Cookie(const Variant &encode) {
    this_ = newObject(LITERAL_STRING[3240], {encode});
}
Variant Cookie::withName(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3241]);
    }
    return this_.call(_method_fn, {name});
}
Variant Cookie::withValue(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3242]);
    }
    return this_.call(_method_fn, {value});
}
Variant Cookie::withExpires(const Variant &expires) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3243]);
    }
    return this_.call(_method_fn, {expires});
}
Variant Cookie::withPath(const Variant &path) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3244]);
    }
    return this_.call(_method_fn, {path});
}
Variant Cookie::withDomain(const Variant &domain) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3245]);
    }
    return this_.call(_method_fn, {domain});
}
Variant Cookie::withSecure(const Variant &secure) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3246]);
    }
    return this_.call(_method_fn, {secure});
}
Variant Cookie::withHttpOnly(const Variant &http_only) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3247]);
    }
    return this_.call(_method_fn, {http_only});
}
Variant Cookie::withSameSite(const Variant &same_site) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3248]);
    }
    return this_.call(_method_fn, {same_site});
}
Variant Cookie::withPriority(const Variant &priority) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3249]);
    }
    return this_.call(_method_fn, {priority});
}
Variant Cookie::withPartitioned(const Variant &partitioned) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3250]);
    }
    return this_.call(_method_fn, {partitioned});
}
Variant Cookie::toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3251]);
    }
    return this_.call(_method_fn, {});
}
Variant Cookie::toArray() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2179]);
    }
    return this_.call(_method_fn, {});
}
Variant Cookie::reset() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[959]);
    }
    return this_.call(_method_fn, {});
}
Server::Server(const Variant &host, const Variant &port, const Variant &mode, const Variant &sock_type) {
    this_ = newObject(LITERAL_STRING[3252], {host, port, mode, sock_type});
}
Response::Response() {
    this_ = newObject(LITERAL_STRING[3228]);
}
Variant Response::initHeader() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3229]);
    }
    return this_.call(_method_fn, {});
}
Variant Response::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1134]);
    }
    return this_.call(_method_fn, {});
}
Variant Response::cookie(const Variant &name_or_object,
                         const Variant &value,
                         const Variant &expires,
                         const Variant &path,
                         const Variant &domain,
                         const Variant &secure,
                         const Variant &httponly,
                         const Variant &samesite,
                         const Variant &priority,
                         const Variant &partitioned) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3230]);
    }
    return this_.call(
        _method_fn, {name_or_object, value, expires, path, domain, secure, httponly, samesite, priority, partitioned});
}
Variant Response::setCookie(const Variant &name_or_object,
                            const Variant &value,
                            const Variant &expires,
                            const Variant &path,
                            const Variant &domain,
                            const Variant &secure,
                            const Variant &httponly,
                            const Variant &samesite,
                            const Variant &priority,
                            const Variant &partitioned) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3231]);
    }
    return this_.call(
        _method_fn, {name_or_object, value, expires, path, domain, secure, httponly, samesite, priority, partitioned});
}
Variant Response::rawcookie(const Variant &name_or_object,
                            const Variant &value,
                            const Variant &expires,
                            const Variant &path,
                            const Variant &domain,
                            const Variant &secure,
                            const Variant &httponly,
                            const Variant &samesite,
                            const Variant &priority,
                            const Variant &partitioned) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3232]);
    }
    return this_.call(
        _method_fn, {name_or_object, value, expires, path, domain, secure, httponly, samesite, priority, partitioned});
}
Variant Response::setRawCookie(const Variant &name_or_object,
                               const Variant &value,
                               const Variant &expires,
                               const Variant &path,
                               const Variant &domain,
                               const Variant &secure,
                               const Variant &httponly,
                               const Variant &samesite,
                               const Variant &priority,
                               const Variant &partitioned) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3233]);
    }
    return this_.call(
        _method_fn, {name_or_object, value, expires, path, domain, secure, httponly, samesite, priority, partitioned});
}
Variant Response::status(const Variant &http_code, const Variant &reason) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3234]);
    }
    return this_.call(_method_fn, {http_code, reason});
}
Variant Response::setStatusCode(const Variant &http_code, const Variant &reason) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3235]);
    }
    return this_.call(_method_fn, {http_code, reason});
}
Variant Response::header(const Variant &key, const Variant &value, const Variant &format) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2398]);
    }
    return this_.call(_method_fn, {key, value, format});
}
Variant Response::setHeader(const Variant &key, const Variant &value, const Variant &format) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3236]);
    }
    return this_.call(_method_fn, {key, value, format});
}
Variant Response::trailer(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3237]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Response::ping(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[911]);
    }
    return this_.call(_method_fn, {data});
}
Variant Response::goaway(const Variant &error_code, const Variant &debug_data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3183]);
    }
    return this_.call(_method_fn, {error_code, debug_data});
}
Variant Response::write(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1843]);
    }
    return this_.call(_method_fn, {content});
}
Variant Response::end(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2252]);
    }
    return this_.call(_method_fn, {content});
}
Variant Response::sendfile(const Variant &filename, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3153]);
    }
    return this_.call(_method_fn, {filename, offset, length});
}
Variant Response::redirect(const Variant &location, const Variant &http_code) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3238]);
    }
    return this_.call(_method_fn, {location, http_code});
}
Variant Response::detach() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2186]);
    }
    return this_.call(_method_fn, {});
}
Response Response::create(const Variant &server, const Variant &fd) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3228], LITERAL_STRING[161]);
    }
    auto _rv = php::call(_method_fn, {server, fd});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "Swoole\Http\Response::create() returned false");
    }
    return Response(Object(std::move(_rv)));
}
Variant Response::upgrade() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3178]);
    }
    return this_.call(_method_fn, {});
}
Variant Response::push(const Variant &data, const Variant &opcode, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2157]);
    }
    return this_.call(_method_fn, {data, opcode, flags});
}
Variant Response::recv(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3131]);
    }
    return this_.call(_method_fn, {timeout});
}
Variant Response::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {});
}
Variant Response::disconnect(const Variant &code, const Variant &reason) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3179]);
    }
    return this_.call(_method_fn, {code, reason});
}
}  // namespace php::Swoole::Http
namespace php::Swoole::WebSocket {
Frame::Frame() {
    this_ = newObject(LITERAL_STRING[3257]);
}
Variant Frame::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant Frame::pack(const Variant &data, const Variant &opcode, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3257], LITERAL_STRING[2615]);
    }
    return php::call(_method_fn, {data, opcode, flags});
}
Frame Frame::unpack(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3257], LITERAL_STRING[2616]);
    }
    return Frame(Object(php::call(_method_fn, {data})));
}
Variant Server::push(const Variant &fd, const Variant &data, const Variant &opcode, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2157]);
    }
    return this_.call(_method_fn, {fd, data, opcode, flags});
}
Variant Server::disconnect(const Variant &fd, const Variant &code, const Variant &reason) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3179]);
    }
    return this_.call(_method_fn, {fd, code, reason});
}
Variant Server::ping(const Variant &fd, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[911]);
    }
    return this_.call(_method_fn, {fd, data});
}
Variant Server::isEstablished(const Variant &fd) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3253]);
    }
    return this_.call(_method_fn, {fd});
}
Variant Server::pack(const Variant &data, const Variant &opcode, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3255], LITERAL_STRING[2615]);
    }
    return php::call(_method_fn, {data, opcode, flags});
}
Frame Server::unpack(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3255], LITERAL_STRING[2616]);
    }
    return Frame(Object(php::call(_method_fn, {data})));
}
Server::Server(const Variant &host, const Variant &port, const Variant &mode, const Variant &sock_type) {
    this_ = newObject(LITERAL_STRING[3255], {host, port, mode, sock_type});
}
CloseFrame::CloseFrame() {
    this_ = newObject(LITERAL_STRING[3260]);
}
}  // namespace php::Swoole::WebSocket
namespace php::Swoole::Coroutine::Http {
Client::Client(const Variant &host, const Variant &port, const Variant &ssl) {
    this_ = newObject(LITERAL_STRING[3162], {host, port, ssl});
}
Variant Client::set(const Variant &settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {settings});
}
Variant Client::getDefer() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3163]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::setDefer(const Variant &defer) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3164]);
    }
    return this_.call(_method_fn, {defer});
}
Variant Client::setMethod(const Variant &method) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3165]);
    }
    return this_.call(_method_fn, {method});
}
Variant Client::setHeaders(const Variant &headers) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3166]);
    }
    return this_.call(_method_fn, {headers});
}
Variant Client::setBasicAuth(const Variant &username, const Variant &password) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3167]);
    }
    return this_.call(_method_fn, {username, password});
}
Variant Client::setCookies(const Variant &cookies) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3168]);
    }
    return this_.call(_method_fn, {cookies});
}
Variant Client::setData(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3169]);
    }
    return this_.call(_method_fn, {data});
}
Variant Client::addFile(const Variant &path,
                        const Variant &name,
                        const Variant &type,
                        const Variant &filename,
                        const Variant &offset,
                        const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1109]);
    }
    return this_.call(_method_fn, {path, name, type, filename, offset, length});
}
Variant Client::addData(const Variant &path, const Variant &name, const Variant &type, const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3170]);
    }
    return this_.call(_method_fn, {path, name, type, filename});
}
Variant Client::execute(const Variant &path) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[954]);
    }
    return this_.call(_method_fn, {path});
}
Variant Client::getpeername() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3146]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::getsockname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3147]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::get(const Variant &path) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[162]);
    }
    return this_.call(_method_fn, {path});
}
Variant Client::post(const Variant &path, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3171]);
    }
    return this_.call(_method_fn, {path, data});
}
Variant Client::download(const Variant &path, const Variant &file, const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3172]);
    }
    return this_.call(_method_fn, {path, file, offset});
}
Variant Client::getBody() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3173]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::getHeaders() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3174]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::getCookies() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3175]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::getStatusCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3176]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::getHeaderOut() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3177]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::getPeerCert() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3155]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::upgrade(const Variant &path) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3178]);
    }
    return this_.call(_method_fn, {path});
}
Variant Client::push(const Variant &data, const Variant &opcode, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2157]);
    }
    return this_.call(_method_fn, {data, opcode, flags});
}
Variant Client::recv(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3131]);
    }
    return this_.call(_method_fn, {timeout});
}
Variant Client::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {});
}
Variant Client::ping(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[911]);
    }
    return this_.call(_method_fn, {data});
}
Variant Client::disconnect(const Variant &code, const Variant &reason) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3179]);
    }
    return this_.call(_method_fn, {code, reason});
}
Server::Server(const Variant &host, const Variant &port, const Variant &ssl, const Variant &reuse_port) {
    this_ = newObject(LITERAL_STRING[3265], {host, port, ssl, reuse_port});
}
Variant Server::set(const Variant &settings) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {settings});
}
Variant Server::handle(const Variant &pattern, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3266]);
    }
    return this_.call(_method_fn, {pattern, callback});
}
Variant Server::start() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[179]);
    }
    return this_.call(_method_fn, {});
}
Variant Server::shutdown() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2964]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php::Swoole::Coroutine::Http
namespace php::Swoole::Redis {
Variant Server::setHandler(const Variant &command, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3261]);
    }
    return this_.call(_method_fn, {command, callback});
}
Variant Server::getHandler(const Variant &command) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3262]);
    }
    return this_.call(_method_fn, {command});
}
Variant Server::format(const Variant &type, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3264], LITERAL_STRING[306]);
    }
    return php::call(_method_fn, {type, value});
}
Server::Server(const Variant &host, const Variant &port, const Variant &mode, const Variant &sock_type) {
    this_ = newObject(LITERAL_STRING[3264], {host, port, mode, sock_type});
}
}  // namespace php::Swoole::Redis
namespace php::Swoole::NameResolver {
Context::Context(const Variant &family, const Variant &with_port) {
    this_ = newObject(LITERAL_STRING[3267], {family, with_port});
}
}  // namespace php::Swoole::NameResolver
namespace php::Swoole::Thread {
Error::Error() {
    this_ = newObject(LITERAL_STRING[3286]);
}
Atomic::Atomic(const Variant &value) {
    this_ = newObject(LITERAL_STRING[3287], {value});
}
Variant Atomic::add(const Variant &add_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {add_value});
}
Variant Atomic::sub(const Variant &sub_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[17]);
    }
    return this_.call(_method_fn, {sub_value});
}
Variant Atomic::get() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[162]);
    }
    return this_.call(_method_fn, {});
}
Variant Atomic::set(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {value});
}
Variant Atomic::wait(const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1467]);
    }
    return this_.call(_method_fn, {timeout});
}
Variant Atomic::wakeup(const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2930]);
    }
    return this_.call(_method_fn, {count});
}
Variant Atomic::cmpset(const Variant &cmp_value, const Variant &new_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2931]);
    }
    return this_.call(_method_fn, {cmp_value, new_value});
}
Lock::Lock(const Variant &type) {
    this_ = newObject(LITERAL_STRING[3289], {type});
}
Variant Lock::lock(const Variant &operation, const Variant &timeout) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2934]);
    }
    return this_.call(_method_fn, {operation, timeout});
}
Variant Lock::unlock() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2935]);
    }
    return this_.call(_method_fn, {});
}
Barrier::Barrier(const Variant &count) {
    this_ = newObject(LITERAL_STRING[3290], {count});
}
Variant Barrier::wait() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1467]);
    }
    return this_.call(_method_fn, {});
}
Queue::Queue() {
    this_ = newObject(LITERAL_STRING[3291], {});
}
Variant Queue::push(const Variant &value, const Variant &notify_which) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2157]);
    }
    return this_.call(_method_fn, {value, notify_which});
}
Variant Queue::pop(const Variant &wait) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2155]);
    }
    return this_.call(_method_fn, {wait});
}
Variant Queue::clean() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3292]);
    }
    return this_.call(_method_fn, {});
}
Variant Queue::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Map::Map(const Variant &array) {
    this_ = newObject(LITERAL_STRING[3293], {array});
}
Variant Map::offsetGet(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[164]);
    }
    return this_.call(_method_fn, {key});
}
Variant Map::offsetExists(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[166]);
    }
    return this_.call(_method_fn, {key});
}
Variant Map::offsetSet(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[165]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Map::offsetUnset(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[167]);
    }
    return this_.call(_method_fn, {key});
}
Variant Map::find(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3294]);
    }
    return this_.call(_method_fn, {value});
}
Variant Map::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant Map::incr(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1367]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Map::decr(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1297]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Map::add(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Map::update(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3295]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant Map::clean() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3292]);
    }
    return this_.call(_method_fn, {});
}
Variant Map::keys() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1372]);
    }
    return this_.call(_method_fn, {});
}
Variant Map::values() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3296]);
    }
    return this_.call(_method_fn, {});
}
Variant Map::toArray() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2179]);
    }
    return this_.call(_method_fn, {});
}
Variant Map::sort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1448]);
    }
    return this_.call(_method_fn, {});
}
ArrayList::ArrayList(const Variant &array) {
    this_ = newObject(LITERAL_STRING[3297], {array});
}
Variant ArrayList::offsetGet(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[164]);
    }
    return this_.call(_method_fn, {key});
}
Variant ArrayList::offsetExists(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[166]);
    }
    return this_.call(_method_fn, {key});
}
Variant ArrayList::offsetSet(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[165]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant ArrayList::offsetUnset(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[167]);
    }
    return this_.call(_method_fn, {key});
}
Variant ArrayList::find(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3294]);
    }
    return this_.call(_method_fn, {value});
}
Variant ArrayList::incr(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1367]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant ArrayList::decr(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1297]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant ArrayList::clean() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3292]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayList::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayList::toArray() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2179]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayList::sort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1448]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php::Swoole::Thread
namespace php::Swoole::Thread::Atomic {
Long::Long(const Variant &value) {
    this_ = newObject(LITERAL_STRING[3288], {value});
}
Variant Long::add(const Variant &add_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {add_value});
}
Variant Long::sub(const Variant &sub_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[17]);
    }
    return this_.call(_method_fn, {sub_value});
}
Variant Long::get() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[162]);
    }
    return this_.call(_method_fn, {});
}
Variant Long::set(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1437]);
    }
    return this_.call(_method_fn, {value});
}
Variant Long::cmpset(const Variant &cmp_value, const Variant &new_value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2931]);
    }
    return this_.call(_method_fn, {cmp_value, new_value});
}
}  // namespace php::Swoole::Thread::Atomic
