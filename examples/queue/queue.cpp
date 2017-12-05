#include "queue.h"

using namespace php;
using namespace std;

#define DEFAULT_QUEUE_SIZE 64
struct QueueObject{
    int start;
    int end;
    int size;
    int eleNum;
    Variant *storage;
};

//destructor
void queueResDtor(zend_resource *res){
    QueueObject *qo = static_cast<QueueObject *>(res->ptr);
    efree(qo->storage);
    efree(qo);
}

PHPX_METHOD(Queue,__construct){
    QueueObject *queue = (QueueObject *)emalloc(sizeof(QueueObject));

    queue->storage = (Variant *)ecalloc(DEFAULT_QUEUE_SIZE, sizeof(Variant));
    queue->start = 0;
    queue->end = 0;
    queue->size = DEFAULT_QUEUE_SIZE + 1;
    queue->eleNum = 0;

    _this.oSet("queue_ptr", "QueueResource", queue);
}

PHPX_METHOD(Queue,count){
    QueueObject *queue = _this.oGet<QueueObject>("queue_ptr", "QueueResource");

    retval = queue->eleNum;
}

PHPX_METHOD(Queue,isEmpty){
    QueueObject *queue = _this.oGet <QueueObject>("queue_ptr", "QueueResource");

    retval = queue->eleNum == 0;
}

PHPX_METHOD(Queue,isFull){
    QueueObject *queue = _this.oGet <QueueObject>("queue_ptr", "QueueResource");

    retval = queue->eleNum == queue->size - 1;
}

PHPX_METHOD(Queue,push){
    QueueObject *queue = _this.oGet <QueueObject>("queue_ptr", "QueueResource");

    //队列满
    if((queue->end+1)%queue->size == queue->start){
        zend_error(E_USER_WARNING, "Queue is full, queue's max size is limited to %d", DEFAULT_QUEUE_SIZE);
        retval = false;
        return;
    }
    if(args[0].type()==IS_ARRAY){
        Array arr(args[0]);
        cout << '[';
        for (auto it = arr.begin(); it != arr.end();it++){
            cout << it.value().toString();
        }
        cout << ']' << endl;
    }else{
        cout << args[0].toString() << endl;
    }
    queue->storage[queue->end] = args[0];
    queue->end = (queue->end + 1) % queue->size;
    queue->eleNum += 1;

    retval = true;
}

PHPX_METHOD(Queue,pull){
    QueueObject *queue = _this.oGet <QueueObject>("queue_ptr", "QueueResource");

    if(queue->eleNum<=0){
        retval = false;
        return;
    }
    queue->start = (queue->start + 1) % queue->size;
    queue->eleNum -= 1;

    retval = true;
}

PHPX_METHOD(Queue,first){
    QueueObject *queue = _this.oGet <QueueObject>("queue_ptr", "QueueResource");

    if(queue->eleNum <= 0){
        retval = nullptr;
        return;
    }
    retval = queue->storage[queue->start];
}

PHPX_METHOD(Queue,traverse){
    QueueObject *queue = _this.oGet <QueueObject>("queue_ptr", "QueueResource");

    for (int s = queue->start; s != queue->end;s = (s+1)%queue->size){
        if(queue->storage[s].type()==IS_ARRAY){
            Array arr(queue->storage[s]);
            cout << '[';
            for (auto it = arr.begin(); it != arr.end();it++){
                cout << it.value().toString() << ' ';
            }
            cout << "] ";
        }else{
            cout << queue->storage[s].toString() << ' ';

        }
    }
    cout << endl;
}

PHPX_EXTENSION() {
    Extension *extension = new Extension("queue", "0.0.1");

    extension->onStart = [extension]() noexcept {
        extension->registerConstant("QUEUE_VERSION", 1001);

        Class *c = new Class("Queue");
        c->addMethod(PHPX_ME(Queue, __construct), CONSTRUCT);
        c->addMethod(PHPX_ME(Queue, count));
        c->addMethod(PHPX_ME(Queue, isEmpty));
        ArgInfo *pushArgi = new ArgInfo(1);
        pushArgi->add("value","Variant");
        c->addMethod(PHPX_ME(Queue, push), PUBLIC, pushArgi);
        c->addMethod(PHPX_ME(Queue, pull));
        c->addMethod(PHPX_ME(Queue, first));
        c->addMethod(PHPX_ME(Queue, traverse));

        extension->registerClass(c);

        extension->registerResource("QueueResource", queueResDtor);
    };

    //extension->onShutdown = [extension]() noexcept {
    //};

    //extension->onBeforeRequest = [extension]() noexcept {
    //    cout << extension->name << "beforeRequest" << endl;
    //};

    //extension->onAfterRequest = [extension]() noexcept {
    //    cout << extension->name << "afterRequest" << endl;
    //};

    extension->info({"queue support", "enabled"},
                    {
                        {"author", "Jiang Weilong"},
                        {"version", extension->version},
                        {"date", "2017-11-26"},
                    });

    return extension;
}