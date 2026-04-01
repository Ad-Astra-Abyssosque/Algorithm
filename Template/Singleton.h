//
// Created by wcx on 2026/4/1.
//

#ifndef ALGORITHM_SINGLETON_H
#define ALGORITHM_SINGLETON_H

#include <atomic>
#include <mutex>

// 线程安全的懒汉式
class Singleton1
{
private:
    Singleton1() {}
    ~Singleton1() {}

    static Singleton1* instance;
    static std::mutex mtx;

public:
    Singleton1(const Singleton1& s) = delete;
    Singleton1& operator=(const Singleton1& s) = delete;

    static Singleton1* GetInstance()
    {
        std::lock_guard<std::mutex> lk(mtx);
        if (instance == nullptr)
        {
            instance = new Singleton1();
        }
        return instance;
    }

    static Singleton1* GetInstance_DCLP()
    {

        if (instance == nullptr)
        {
            // 当两个线程同时进入这里时
            // 假设线程A先拿到锁，构造了instance，释放锁
            // 需要确保B拿到锁后，不会重复构造，因此加锁后还要检查是否为空
            std::lock_guard<std::mutex> lk(mtx);
            if (instance == nullptr)
            {
                instance = new Singleton1();
            }
        }
        return instance;
    }
};

class Singleton2
{
private:
    Singleton2() = default;
    ~Singleton2() = default;

public:
    Singleton2(const Singleton2& s) = delete;
    Singleton2& operator=(const Singleton2& s) = delete;

    static Singleton2& GetInstance()
    {
        static Singleton2 instance;
        return instance;
    }

};

class Singleton3
{
private:
    Singleton3() = default;
    ~Singleton3() = default;

    static std::atomic<Singleton3*> instance;
    static std::mutex mtx;

public:

    static Singleton3* GetInstance()
    {
        Singleton3* p = instance.load(std::memory_order_acquire);
        if (p == nullptr)
        {
            std::lock_guard<std::mutex> lock(mtx);
            p = instance.load(std::memory_order_relaxed);
            if (p == nullptr)
            {
                p = new Singleton3();
                instance.store(p, std::memory_order_release);
            }
        }
        return p;
    }

};

#endif //ALGORITHM_SINGLETON_H