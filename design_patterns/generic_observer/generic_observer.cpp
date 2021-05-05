#include <functional>
#include <list>
#include <iostream>
#include <string>

using namespace std;

/// https://www.theimpossiblecode.com/blog/c11-generic-observer-pattern/


template <typename... Args>
class Dispatcher
{
public:
    typedef std::function<void(Args...)> callbackType;

    class callbackID
    {
    public:
        callbackID() : valid(false) {}
    private:
        friend class Dispatcher<Args...>;
        callbackID(typename std::list<callbackType>::iterator i)
        : iter(i), valid(true)
        {}

        typename std::list<callbackType>::iterator iter;
        bool valid;
    };

    // register to be notified
    callbackID addCallback(callbackType callback)
    {
        if (callback)
        {
            callbacks.push_back(callback);
            return callbackID(--callbacks.end());
        }
        return callbackID();
    }

    // unregister to be notified
    void deleteCallback(callbackID &id)
    {
        if (id.valid)
        {
            callbacks.erase(id.iter);
        }
    }

    void broadcast(Args... args)
    {
        for (auto &callback : callbacks)
        {
            callback(args...);
        }
    }

private:
    std::list<callbackType> callbacks;
};


// a dummy enum for this example
enum EventEnum {EVENT1, EVENT2, EVENT3};

int main(int argc, char *argv[])
{
    // 2 example dispatchers, any number of arguments and types can be used:
    Dispatcher<string, EventEnum> dispatcher1;// here any cb(string, EventEnum) can register
    Dispatcher<int, long, double> dispatcher2;// here any cb(int, long, double) can register

    // From the "most simple" lambda usage example ...

    auto id_1 = dispatcher1.addCallback([](const string& str, EventEnum evt) {
        cout << "CB1:" << str << " got event " << evt << endl;
    });
    auto id_2 = dispatcher1.addCallback([](const string& str, EventEnum evt) {
        cout << "CB2:" << str << " got event " << evt << endl;
    });

    dispatcher1.broadcast("** Dispatching to 2 is **", EVENT1);
    dispatcher1.broadcast("**       E a s y       **", EVENT2);

    dispatcher1.deleteCallback(id_1); // remove the first callback
    dispatcher1.broadcast("** Dispatching to 1 is **", EVENT1);
    dispatcher1.broadcast("**       E a s y       **", EVENT2);

    dispatcher1.deleteCallback(id_2); // remove the second callback
    dispatcher1.broadcast("** No one will see this **", EVENT3);

    // ... to the "most complex" **live** instance (not copy) usage example:

    class MyClassWithMethod {
		//movementSystem
    public:
        void registerCB(Dispatcher<int, long, double> &dispatcher) {
            using namespace std::placeholders;
            dispatcher.addCallback(std::bind(&MyClassWithMethod::listener, this, _1, _2, _3));
        }
    private:
        // any method with the right signature can be used:
        void listener(int i, long l, double d) {
            cout << "listener() for " << this << ", got: " <<
            i << ", " << l << ", " << d << endl;
        }
    };

    MyClassWithMethod instance1;
    MyClassWithMethod instance2;
    instance1.registerCB(dispatcher2);
    instance2.registerCB(dispatcher2);
    /// will be used in glfw callbacks
    dispatcher2.broadcast(65000, 12345678910, 3.14159265);
    dispatcher2.broadcast(56000, 1987654321, 14159265.3);


    return 0;
}
