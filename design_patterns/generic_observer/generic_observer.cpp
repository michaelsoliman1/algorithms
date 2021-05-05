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
    typedef std::function<void(Args...)> CBType;

    class CBID
    {
    public:
        CBID() : valid(false) {}
    private:
        friend class Dispatcher<Args...>;
        CBID(typename std::list<CBType>::iterator i)
        : iter(i), valid(true)
        {}

        typename std::list<CBType>::iterator iter;
        bool valid;
    };

    // register to be notified
    CBID addCB(CBType cb)
    {
        if (cb)
        {
            cbs.push_back(cb);
            return CBID(--cbs.end());
        }
        return CBID();
    }

    // unregister to be notified
    void delCB(CBID &id)
    {
        if (id.valid)
        {
            cbs.erase(id.iter);
        }
    }

    void broadcast(Args... args)
    {
        for (auto &cb : cbs)
        {
            cb(args...);
        }
    }

private:
    std::list<CBType> cbs;
};


// a dummy enum for this example
enum EventEnum {EVENT1, EVENT2, EVENT3};

int main(int argc, char *argv[])
{
    // 2 example dispatchers, any number of arguments and types can be used:
    Dispatcher<string, EventEnum> d1;// here any cb(string, EventEnum) can register
    Dispatcher<int, long, double> d2;// here any cb(int, long, double) can register

    // From the "most simple" lambda usage example ...

    auto cbid1 = d1.addCB([](string str, EventEnum evt) {
                          cout << "CB1:" << str << " got event " << evt << endl;
                          });
    auto cbid2 = d1.addCB([](string str, EventEnum evt) {
                          cout << "CB2:" << str << " got event " << evt << endl;
                          });

    d1.broadcast("** Dispatching to 2 is **", EVENT1);
    d1.broadcast("**       E a s y       **", EVENT2);

    d1.delCB(cbid1); // remove the first callback
    d1.broadcast("** Dispatching to 1 is **", EVENT1);
    d1.broadcast("**       E a s y       **", EVENT2);

    d1.delCB(cbid2); // remove the second callback
    d1.broadcast("** No one will see this **",EVENT3);

    // ... to the "most complex" **live** instance (not copy) usage example:

    class MyClassWithMethod {
		//movementSystem
    public:
        void registerCB(Dispatcher<int, long, double> &dispatcher) {
            using namespace std::placeholders;
            dispatcher.addCB(std::bind(&MyClassWithMethod::listener, this, _1, _2, _3));
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
    instance1.registerCB(d2);
    instance2.registerCB(d2);
    /// will be used in glfw callbacks
    d2.broadcast(65000, 12345678910, 3.14159265);
    d2.broadcast(56000, 1987654321, 14159265.3);


    return 0;
}
