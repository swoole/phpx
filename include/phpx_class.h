/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <rango@swoole.com>                             |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

namespace php {
class InternalIterator;
class Exception;
class ErrorException;
class Error;
class CompileError;
class ParseError;
class TypeError;
class ArgumentCountError;
class ValueError;
class ArithmeticError;
class DivisionByZeroError;
class UnhandledMatchError;
class RequestParseBodyException;
class Closure;
class Generator;
class ClosedGeneratorException;
class WeakReference;
class WeakMap;
class Attribute;
class ReturnTypeWillChange;
class AllowDynamicProperties;
class SensitiveParameter;
class SensitiveParameterValue;
class Override;
class Deprecated;
class Fiber;
class FiberError;
class stdClass;
class CurlHandle;
class CurlMultiHandle;
class CurlShareHandle;
class CURLFile;
class CURLStringFile;
class DateTimeZone;
class DateInterval;
class DatePeriod;
class DateError;
class DateObjectError;
class DateRangeError;
class DateException;
class DateInvalidTimeZoneException;
class DateInvalidOperationException;
class DateMalformedStringException;
class DateMalformedIntervalStringException;
class DateMalformedPeriodStringException;
class DOMException;
class DOMNode;
class DOMNameSpaceNode;
class DOMDocumentFragment;
class DOMNodeList;
class DOMNamedNodeMap;
class DOMCharacterData;
class DOMAttr;
class DOMElement;
class DOMText;
class DOMComment;
class DOMDocument;
class DOMCdataSection;
class DOMDocumentType;
class DOMImplementation;
class DOMNotation;
class DOMEntity;
class DOMEntityReference;
class DOMProcessingInstruction;
class DOMXPath;
class finfo;
class GdImage;
class GdFont;
class HashContext;
class JsonException;
class LibXMLError;
class mysqli_sql_exception;
class mysqli_driver;
class mysqli_warning;
class OpenSSLCertificate;
class OpenSSLCertificateSigningRequest;
class OpenSSLAsymmetricKey;
class PDOException;
class PDOStatement;
class PDO;
class PDORow;
class PharException;
class Redis;
class RedisArray;
class RedisCluster;
class RedisClusterException;
class RedisSentinel;
class RedisException;
class ReflectionException;
class Reflection;
class ReflectionGenerator;
class ReflectionNamedType;
class ReflectionUnionType;
class ReflectionIntersectionType;
class ReflectionExtension;
class ReflectionZendExtension;
class ReflectionReference;
class ReflectionAttribute;
class ReflectionFiber;
class ReflectionConstant;
class PropertyHookType;
class SessionHandler;
class Shmop;
class SimpleXMLElement;
class SimpleXMLIterator;
class Socket;
class AddressInfo;
class SodiumException;
class LogicException;
class BadFunctionCallException;
class BadMethodCallException;
class DomainException;
class InvalidArgumentException;
class LengthException;
class OutOfRangeException;
class RuntimeException;
class OutOfBoundsException;
class OverflowException;
class RangeException;
class UnderflowException;
class UnexpectedValueException;
class RecursiveIteratorIterator;
class IteratorIterator;
class CallbackFilterIterator;
class RecursiveCallbackFilterIterator;
class ParentIterator;
class LimitIterator;
class CachingIterator;
class RecursiveCachingIterator;
class NoRewindIterator;
class InfiniteIterator;
class RegexIterator;
class RecursiveRegexIterator;
class EmptyIterator;
class RecursiveTreeIterator;
class ArrayObject;
class ArrayIterator_;
class AppendIterator;
class RecursiveArrayIterator;
class SplDoublyLinkedList;
class SplQueue;
class SplStack;
class SplMinHeap;
class SplMaxHeap;
class SplPriorityQueue;
class SplFixedArray;
class SplObjectStorage;
class MultipleIterator;
class SQLite3Exception;
class SQLite3Result;
class SQLite3Stmt;
class SQLite3;
class __PHP_Incomplete_Class;
class AssertionError;
class RoundingMode;
class php_user_filter;
class StreamBucket;
class Directory;
class co;
class chan;
class PhpToken;
class XMLParser;
class XMLReader;
class XMLWriter;
class XSLTProcessor;
class ZipArchive;
class InflateContext;
class DeflateContext;
class DateTime;
class DateTimeImmutable;
class mysqli_result;
class mysqli;
class mysqli_stmt;
class ReflectionFunction;
class ReflectionParameter;
class ReflectionMethod;
class ReflectionProperty;
class ReflectionClass;
class ReflectionClassConstant;
class ReflectionObject;
class ReflectionEnum;
class ReflectionEnumUnitCase;
class ReflectionEnumBackedCase;
class SplFileInfo;
class SplFileObject;
class PharFileInfo;
class DirectoryIterator;
class FilesystemIterator;
class RecursiveDirectoryIterator;
class GlobIterator;
class SplTempFileObject;
class Phar;
class PharData;
    namespace Dom {
        class AdjacentPosition;
        class Node;
        class NamespaceInfo;
        class NodeList;
        class CharacterData;
        class Attr;
        class NamedNodeMap;
        class Text;
        class Comment;
        class CDATASection;
        class DocumentType;
        class Notation;
        class Entity;
        class DtdNamedNodeMap;
        class EntityReference;
        class ProcessingInstruction;
        class XPath;
        class TokenList;
        class DocumentFragment;
        class HTMLCollection;
        class Element;
        class HTMLDocument;
        class XMLDocument;
        class Implementation;
        class HTMLElement;
    }  // namespace Dom
    namespace dom {
        class domexception;
    }  // namespace dom
    namespace Pcntl {
        class QosClass;
    }  // namespace Pcntl
    namespace Pdo {
        class Mysql;
        class Sqlite;
    }  // namespace Pdo
    namespace Random {
        class RandomError;
        class BrokenRandomEngineError;
        class RandomException;
        class IntervalBoundary;
        class Randomizer;
    }  // namespace Random
    namespace Random {
        namespace Engine {
            class Mt19937;
            class PcgOneseq128XslRr64;
            class Xoshiro256StarStar;
            class Secure;
        }  // namespace Engine
    }  // namespace Random
    namespace BcMath {
        class Number;
    }  // namespace BcMath
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
    namespace Swoole {
        namespace Atomic {
            class Long;
        }  // namespace Atomic
    }  // namespace Swoole
    namespace Swoole {
        namespace Timer {
            class Iterator;
        }  // namespace Timer
    }  // namespace Swoole
    namespace Swoole {
        namespace Coroutine {
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
        }  // namespace Coroutine
    }  // namespace Swoole
    namespace co {
        class iterator;
        class context;
        class system;
        class scheduler;
        class channel;
        class socket;
        class client;
    }  // namespace co
    namespace Swoole {
        namespace Coroutine {
            namespace Curl {
                class Exception;
            }  // namespace Curl
        }  // namespace Coroutine
    }  // namespace Swoole
    namespace co {
        namespace coroutine {
            namespace curl {
                class exception;
            }  // namespace curl
        }  // namespace coroutine
    }  // namespace co
    namespace Swoole {
        namespace Process {
            class Pool;
        }  // namespace Process
    }  // namespace Swoole
    namespace Swoole {
        namespace Coroutine {
            namespace Socket {
                class Exception;
            }  // namespace Socket
        }  // namespace Coroutine
    }  // namespace Swoole
    namespace co {
        namespace socket {
            class exception;
        }  // namespace socket
    }  // namespace co
    namespace Swoole {
        namespace Client {
            class Exception;
        }  // namespace Client
    }  // namespace Swoole
    namespace Swoole {
        namespace Async {
            class Client;
        }  // namespace Async
    }  // namespace Swoole
    namespace Swoole {
        namespace Coroutine {
            namespace Http {
                namespace Client {
                    class Exception;
                }  // namespace Client
            }  // namespace Http
        }  // namespace Coroutine
    }  // namespace Swoole
    namespace co {
        namespace http {
            namespace client {
                class exception;
            }  // namespace client
        }  // namespace http
    }  // namespace co
    namespace Swoole {
        namespace Coroutine {
            namespace Http2 {
                namespace Client {
                    class Exception;
                }  // namespace Client
            }  // namespace Http2
        }  // namespace Coroutine
    }  // namespace Swoole
    namespace co {
        namespace http2 {
            namespace client {
                class exception;
            }  // namespace client
        }  // namespace http2
    }  // namespace co
    namespace Swoole {
        namespace Http2 {
            class Request;
            class Response;
        }  // namespace Http2
    }  // namespace Swoole
    namespace Swoole {
        namespace Coroutine {
            namespace Http2 {
                class Client;
            }  // namespace Http2
        }  // namespace Coroutine
    }  // namespace Swoole
    namespace co {
        namespace http2 {
            class client;
        }  // namespace http2
    }  // namespace co
    namespace FTP {
        class Connection;
    }  // namespace FTP
    namespace Swoole {
        namespace Server {
            class Task;
            class Event;
            class Packet;
            class PipeMessage;
            class StatusInfo;
            class TaskResult;
            class Port;
        }  // namespace Server
    }  // namespace Swoole
    namespace Swoole {
        namespace Connection {
            class Iterator;
        }  // namespace Connection
    }  // namespace Swoole
    namespace Swoole {
        namespace Http {
            class Request;
            class Cookie;
            class Server;
            class Response;
        }  // namespace Http
    }  // namespace Swoole
    namespace Swoole {
        namespace WebSocket {
            class Frame;
            class Server;
            class CloseFrame;
        }  // namespace WebSocket
    }  // namespace Swoole
    namespace Swoole {
        namespace Coroutine {
            namespace Http {
                class Client;
                class Server;
            }  // namespace Http
        }  // namespace Coroutine
    }  // namespace Swoole
    namespace co {
        namespace http {
            class client;
            class server;
        }  // namespace http
    }  // namespace co
    namespace Swoole {
        namespace Redis {
            class Server;
        }  // namespace Redis
    }  // namespace Swoole
    namespace Swoole {
        namespace NameResolver {
            class Context;
        }  // namespace NameResolver
    }  // namespace Swoole
    namespace Swoole {
        namespace Thread {
            class Error;
            class Atomic;
            class Lock;
            class Barrier;
            class Queue;
            class Map;
            class ArrayList;
        }  // namespace Thread
    }  // namespace Swoole
    namespace Swoole {
        namespace Thread {
            namespace Atomic {
                class Long;
            }  // namespace Atomic
        }  // namespace Thread
    }  // namespace Swoole
}  // namespace php

#include "class/standard.h"
#include "class/bcmath.h"
#include "class/core.h"
#include "class/curl.h"
#include "class/date.h"
#include "class/dom.h"
#include "class/fileinfo.h"
#include "class/gd.h"
#include "class/hash.h"
#include "class/json.h"
#include "class/libxml.h"
#include "class/mysqli.h"
#include "class/openssl.h"
#include "class/pcntl.h"
#include "class/pdo.h"
#include "class/pdo_mysql.h"
#include "class/pdo_sqlite.h"
#include "class/spl.h"
#include "class/phar.h"
#include "class/random.h"
#include "class/redis.h"
#include "class/reflection.h"
#include "class/session.h"
#include "class/shmop.h"
#include "class/simplexml.h"
#include "class/sockets.h"
#include "class/sodium.h"
#include "class/sqlite3.h"
#include "class/swoole.h"
#include "class/tokenizer.h"
#include "class/xml.h"
#include "class/xmlreader.h"
#include "class/xmlwriter.h"
#include "class/xsl.h"
#include "class/zip.h"
#include "class/zlib.h"
