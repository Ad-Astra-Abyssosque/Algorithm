//
// Created by wcx on 2026/2/25.
//

#ifndef ALGORITHM_MAXHEAP_H
#define ALGORITHM_MAXHEAP_H


#include <vector>
#include <cstddef>
#include <stdexcept>
#include <utility>   // std::swap

#include "../Solution.h"

// 练习用：大根堆（Max Heap）
// - 0-based index
// - 默认以 int 为例；你也可以自己改成模板类（如 template<class T, class Compare>）
class MaxHeap: Solution {
public:
    // ====== 构造/析构 ======
    MaxHeap() = default;

    // 用数组/向量建堆（建议你实现 buildHeap）
    explicit MaxHeap(const std::vector<int>& data);
    explicit MaxHeap(std::vector<int>&& data);

    // ====== 基本查询 ======
    std::size_t size() const noexcept { return size_; }
    bool empty() const noexcept;

    // 返回堆顶（最大值）。空堆建议抛异常或自行处理
    const int& top() const { return a_[0]; };

    // ====== 修改操作 ======
    void push(int value);      // 插入元素
    void pop();                // 删除堆顶
    int  extractMax();         // 删除并返回堆顶（可选练习：返回值版本）

    void clear() noexcept;

    // ====== 建堆/堆排序练习 ======
    // 将当前内部数组调整为合法大根堆（从底向上 heapify）
    void buildHeap();

    // 返回堆内底层存储（用于调试/校验）
    const std::vector<int>& data() const noexcept;

    // 静态工具：对数组原地堆排序（升序：先建大根堆，再不断把最大值换到末尾）
    static void heapSort(std::vector<int>& arr);

    // 可选：校验当前是否满足大根堆性质（用于你自测）
    bool isValidHeap() const noexcept;

    virtual void main() override;

private:
    std::vector<int> a_;
    std::size_t size_;

    // ====== 下标辅助 ======
    static std::size_t parent(std::size_t i) noexcept { return (i - 1) / 2; }
    static std::size_t left(std::size_t i) noexcept { return i * 2 + 1; }
    static std::size_t right(std::size_t i) noexcept { return i * 2 + 2; }

    // ====== 核心调整操作 ======
    // 上滤：用于 push 后恢复堆性质
    void siftUp(std::size_t i);

    // 下滤：用于 pop/heapify 后恢复堆性质
    void siftDown(std::size_t i);

    // 在 buildHeap 或 heapSort 中常用：从 i 开始下滤，且限制有效堆大小为 heapSize
    void siftDown(std::size_t i, std::size_t heapSize);

    // 可选：交换并做边界检查等
    void swapAt(std::size_t i, std::size_t j) noexcept;
};


#endif //ALGORITHM_MAXHEAP_H