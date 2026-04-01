//
// Created by wcx on 2026/3/26.
//

#ifndef ALGORITHM_CARRAYQUEUE_H
#define ALGORITHM_CARRAYQUEUE_H

#include <iostream>
#include <new>          // placement new
#include <utility>      // std::move, std::forward
#include <stdexcept>
#include <string>

template <typename T>
class CArrayQueue {
public:
    explicit CArrayQueue(size_t cap)
        : capacity_(cap), size_(0), head_(0), tail_(0)
    {
        if (capacity_ == 0) {
            throw std::invalid_argument("capacity must be > 0");
        }

        // 申请一块“原始内存”，还没有构造 T 对象
        data_ = static_cast<T*>(::operator new(sizeof(T) * capacity_));
    }

    ~CArrayQueue() {
        clear();
        ::operator delete(data_);
    }

    // 禁止拷贝，避免浅拷贝问题；面试时也可以进一步实现深拷贝
    CArrayQueue(const CArrayQueue&) = delete;
    CArrayQueue& operator=(const CArrayQueue&) = delete;

    // 支持移动
    CArrayQueue(CArrayQueue&& other) noexcept
        : data_(other.data_),
          capacity_(other.capacity_),
          size_(other.size_),
          head_(other.head_),
          tail_(other.tail_) {
        other.data_ = nullptr;
        other.capacity_ = 0;
        other.size_ = 0;
        other.head_ = 0;
        other.tail_ = 0;
    }

    CArrayQueue& operator=(CArrayQueue&& other) noexcept {
        if (this != &other) {
            clear();
            ::operator delete(data_);

            data_ = other.data_;
            capacity_ = other.capacity_;
            size_ = other.size_;
            head_ = other.head_;
            tail_ = other.tail_;

            other.data_ = nullptr;
            other.capacity_ = 0;
            other.size_ = 0;
            other.head_ = 0;
            other.tail_ = 0;
        }
        return *this;
    }

public:
    bool empty() const {
        return size_ == 0;
    }

    bool full() const {
        return size_ == capacity_;
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }

    // 入队：拷贝版本
    bool push(const T& value) {
        if (full()) {
            return false;
        }

        new (data_ + tail_) T(value);   // placement new 构造对象
        tail_ = nextIndex(tail_);
        ++size_;
        return true;
    }

    // 入队：移动版本
    bool push(T&& value) {
        if (full()) {
            return false;
        }

        new (data_ + tail_) T(std::move(value));
        tail_ = nextIndex(tail_);
        ++size_;
        return true;
    }

    // 原地构造
    template <typename... Args>
    bool emplace(Args&&... args) {
        if (full()) {
            return false;
        }

        new (data_ + tail_) T(std::forward<Args>(args)...);
        tail_ = nextIndex(tail_);
        ++size_;
        return true;
    }

    // 查看队头
    T& front() {
        if (empty()) {
            throw std::out_of_range("queue is empty");
        }
        return data_[head_];
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("queue is empty");
        }
        return data_[head_];
    }

    // 出队并获取元素
    bool pop(T& out) {
        if (empty()) {
            return false;
        }

        out = std::move(data_[head_]);  // 先取值
        data_[head_].~T();              // 再显式析构
        head_ = nextIndex(head_);
        --size_;
        return true;
    }

    // 只出队，不取值
    bool pop() {
        if (empty()) {
            return false;
        }

        data_[head_].~T();
        head_ = nextIndex(head_);
        --size_;
        return true;
    }

    // 查找元素：返回逻辑下标（相对于队头），没找到返回 -1
    int find(const T& target) const {
        for (size_t i = 0; i < size_; ++i) {
            size_t idx = physicalIndex(i);
            if (data_[idx] == target) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    // 获取逻辑位置上的元素（第0个就是队头）
    T* get(size_t logicalIndex) {
        if (logicalIndex >= size_) {
            return nullptr;
        }
        return &data_[physicalIndex(logicalIndex)];
    }

    const T* get(size_t logicalIndex) const {
        if (logicalIndex >= size_) {
            return nullptr;
        }
        return &data_[physicalIndex(logicalIndex)];
    }

    void clear() {
        while (!empty()) {
            pop();
        }
    }

private:
    size_t nextIndex(size_t idx) const {
        return (idx + 1) % capacity_;
    }

    size_t physicalIndex(size_t logicalIndex) const {
        return (head_ + logicalIndex) % capacity_;
    }

private:
    T* data_ = nullptr;      // 原始内存起始地址
    size_t capacity_ = 0;    // 容量
    size_t size_ = 0;        // 当前元素个数
    size_t head_ = 0;        // 队头位置
    size_t tail_ = 0;        // 下一个可插入位置
};

#endif //ALGORITHM_CARRAYQUEUE_H