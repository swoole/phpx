#include "phpx.h"

#include <iostream>
#include <list>

BEGIN_EXTERN_C()
#include "queue_arginfo.h"
END_EXTERN_C()

using namespace php;
using namespace std;

struct QueueObject {
    size_t size;
    list<Variant> storage;
};

#define DEFAULT_QUEUE_SIZE 64
#define VERBOSE 0

// destructor
void queueResDtor(zend_resource *res) {
    QueueObject *qo = static_cast<QueueObject *>(res->ptr);
    delete qo;
}

PHPX_METHOD(Queue, __construct) {
    QueueObject *queue = new QueueObject();

    if (args.exists(0)) {
        queue->size = args[0].toInt();
    } else {
        queue->size = DEFAULT_QUEUE_SIZE;
    }
    _this.oSet("queue_ptr", "QueueResource", queue);
    return nullptr;
}

PHPX_METHOD(Queue, count) {
    QueueObject *queue = _this.oGet<QueueObject>("queue_ptr", "QueueResource");
    return static_cast<zend_long>(queue->storage.size());
}

PHPX_METHOD(Queue, isEmpty) {
    QueueObject *queue = _this.oGet<QueueObject>("queue_ptr", "QueueResource");
    return queue->storage.empty();
}

PHPX_METHOD(Queue, isFull) {
    QueueObject *queue = _this.oGet<QueueObject>("queue_ptr", "QueueResource");
    return queue->storage.size() == queue->size;
}

PHPX_METHOD(Queue, push) {
    QueueObject *queue = _this.oGet<QueueObject>("queue_ptr", "QueueResource");

    if (queue->storage.size() == queue->size) {
        zend_error(E_USER_WARNING, "Queue is full, queue's max size is limited to %d", DEFAULT_QUEUE_SIZE);
        return false;
    }
#if VERBOSE
    if (args[0].type() == IS_ARRAY) {
        Array arr(args[0]);
        cout << '[';
        for (auto it = arr.begin(); it != arr.end(); it++) {
            cout << it.value().toStdString();
        }
        cout << ']' << endl;
    } else {
        cout << args[0].toStdString() << endl;
    }
#endif
    queue->storage.emplace_back(args[0]);

    return true;
}

PHPX_METHOD(Queue, pull) {
    QueueObject *queue = _this.oGet<QueueObject>("queue_ptr", "QueueResource");
    if (queue->storage.empty()) {
        return false;
    }
    queue->storage.pop_front();
    return true;
}

PHPX_METHOD(Queue, first) {
    QueueObject *queue = _this.oGet<QueueObject>("queue_ptr", "QueueResource");
    if (queue->storage.empty()) {
        return nullptr;
    }
    return queue->storage.front();
}

PHPX_METHOD(Queue, traverse) {
    QueueObject *queue = _this.oGet<QueueObject>("queue_ptr", "QueueResource");

    for (auto iter = queue->storage.begin(); iter != queue->storage.end(); iter++) {
        if (iter->type() == IS_ARRAY) {
            cout << '[';
            Array arr(*iter);
            for (auto it = arr.begin(); it != arr.end(); it++) {
                cout << it.value().toStdString() << ' ';
            }
            cout << "] ";
        } else {
            cout << iter->toStdString() << ' ';
        }
    }
    cout << endl;

    return nullptr;
}

PHPX_EXTENSION() {
    Extension *extension = new Extension("queue", "1.0.2");

    extension->onStart = [extension]() noexcept {
        extension->registerConstant("QUEUE_VERSION", 10002);

        Class *c = new Class("Queue");
        c->addProperty("queue_ptr", nullptr, ZEND_ACC_PUBLIC);
        c->registerFunctions(class_Queue_methods);
        extension->registerClass(c);
        extension->registerResource("QueueResource", queueResDtor);
    };

    extension->info({"queue support", "enabled"},
                    {
                        {"author", "Jiang Weilong"},
                        {"version", extension->version},
                        {"date", "2021-02-07"},
                    });

    return extension;
}
