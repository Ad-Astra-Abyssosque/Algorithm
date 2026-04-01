//
// Created by wcx on 2026/3/27.
//

#ifndef ALGORITHM_READWRITELOCK_H
#define ALGORITHM_READWRITELOCK_H

#include <mutex>
#include <condition_variable>

class BasicRWLock {
private:
    std::mutex mtx_count;
    std::mutex mtx_resource;
    int reader_count = 0;

public:
    void start_read() {
        std::lock_guard<std::mutex> lock(mtx_count);
        ++reader_count;
        if (reader_count == 1) {
            mtx_resource.lock(); // 第一个读者锁住资源，阻止写者
        }
    }

    void end_read() {
        std::lock_guard<std::mutex> lock(mtx_count);
        --reader_count;
        if (reader_count == 0) {
            mtx_resource.unlock(); // 最后一个读者释放资源
        }
    }

    void start_write() {
        mtx_resource.lock(); // 写者独占资源
    }

    void end_write() {
        mtx_resource.unlock();
    }
};


///////////////////////////////////////////////////
/// 解决写者饥饿
///////////////////////////////////////////////////

class RWLock {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int active_readers = 0;
    int waiting_writers = 0;
    bool is_writing = false;

public:
    void start_read() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]() {
            return !is_writing && waiting_writers == 0;
        });
        ++active_readers;
    }

    void end_read() {
        std::unique_lock<std::mutex> lock(mtx);
        --active_readers;
        if (active_readers == 0) {
            cv.notify_all();
        }
    }

    void start_write() {
        std::unique_lock<std::mutex> lock(mtx);
        ++waiting_writers;
        cv.wait(lock, [&]() {
            return !is_writing && active_readers == 0;
        });
        --waiting_writers;
        is_writing = true;
    }

    void end_write() {
        std::unique_lock<std::mutex> lock(mtx);
        is_writing = false;
        cv.notify_all();
    }
};


#endif //ALGORITHM_READWRITELOCK_H