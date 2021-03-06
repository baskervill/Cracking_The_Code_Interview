## 题目

原文：

Implement a singleton design pattern as a template such that, for any given class Foo, you can call Singleton::instance() and get a pointer to an instance of a singleton of type Foo. Assume the existence of a class Lock which has acquire() and release() methods. How could you make your implementation thread safe and exception safe?

译文：

实现一个单例模式的模板，当给一个类Foo时，你可以通过Singleton::instance() 来得到一个指向Foo类单例的指针。假设我们现在已经有了Lock类，其中有acquire() 和release()两个方法，你要如何使你的实现线程安全且异常安全？

## 解答

```cpp
#include <iostream>
using namespace std;

/* 线程同步锁 */
class Lock {
public:
    Lock() { /* 构造锁 */ }
    ~Lock() { /* 析构锁 */ }
    void AcquireLock() { /* 加锁操作 */ }
    void ReleaseLock() { /* 解锁操作 */ }
};

// 单例模式模板，只实例化一次
template <typename T>
class Singleton{
private:
    static Lock lock;
    static T* object;
protected:
    Singleton() { };
public:
    static T* Instance();
};

template <typename T>
Lock Singleton<T>::lock;

template <typename T>
T* Singleton<T>::object = NULL;

template <typename T>
T* Singleton<T>::Instance(){
    if (object == NULL){// 如果object未初始化，加锁初始化
        lock.AcquireLock();
        //这里再判断一次，因为多个线程可能同时通过第一个if
        //只有第一个线程去实例化object，之后object非NULL
        //后面的线程不再实例化它
        if (object == NULL){
            object = new T;
        }
        lock.ReleaseLock();
    }
    return object;
}
class Foo{
    
};
int main(){
    Foo* singleton_foo = Singleton<Foo>::Instance();
    return 0;
}

```

使一个程序线程安全的一般方法是，当线程获得对共享资源的写权限时，需要对共享资源加锁。 这样一来，当一个线程在修改资源时，另外的线程就不能修改它。

关于这个问题，可以参考《剑指offer》中的面试题2：实现Singleton模式。 那里有详细的解答。