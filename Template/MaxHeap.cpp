//
// Created by wcx on 2026/2/25.
//

#include "MaxHeap.h"

#include <iostream>
#include <ostream>
#include <shared_mutex>

MaxHeap::MaxHeap(const std::vector<int>& data)
{
    a_ = data;
    size_ = data.size();
    buildHeap();
}

void MaxHeap::push(int value)
{
    if (a_.size() == size_)
    {
        a_.push_back(value);
    }
    else
    {
        a_[size_] = value;
    }
    siftUp(size_);
    size_++;
}

void MaxHeap::pop()
{
    if (size_ == 0) throw std::out_of_range("pop on empty heap");
    if (size_ == 1) { size_ = 0; return; }
    std::swap(a_[0], a_[size() - 1]);
    size_--;
    siftDown(0);
}

void MaxHeap::buildHeap()
{
    if (size_ < 2) return;
    // i-- > 0 是倒序遍历 size_t 的常见安全写法
    for (std::size_t i = parent(size_-1) + 1; i-- > 0; ) {
        siftDown(i);
    }
}

void MaxHeap::heapSort(std::vector<int>& arr)
{
    auto h = MaxHeap(arr);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        arr[i] = h.top();
        h.pop();
    }
}

void MaxHeap::main()
{
    std::vector<int> arr = {30, 27, 18, 48, 60, 7, 51, 19, 48, 53};
    heapSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void MaxHeap::siftUp(std::size_t i)
{
    // 当 i == 0 时，parent(0) 里 (i-1) 对 size_t 会下溢成超大数
    while ( i > 0 && a_[i] > a_[parent(i)])
    {
        std::swap(a_[i], a_[parent(i)]);
         i = parent(i);
    }
}

void MaxHeap::siftDown(std::size_t i)
{
    while (true)
    {
        auto l = left(i), r = right(i);
        std::size_t largest = i;
        if (l < size_ && a_[l] > a_[largest]) largest = l;
        if (r < size_ && a_[r] > a_[largest]) largest = r;
        if (largest == i) break;
        std::swap(a_[i], a_[largest]);
        i = largest;
    }
}
