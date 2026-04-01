//
// Created by wcx on 2026/2/22.
//

#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H
#include <vector>
#include <iostream>
#include "../Solution.h"
using namespace std;

class QuickSort: Solution
{
public:
    void quicksort(vector<int>& array, int left, int right)
    {
        if (left >= right) return;
        // int p = partition_hoare(array, left, right);
        // int p = partition_dig(array, left, right);
        int p = partition_hoare2(array, left, right);
        quicksort(array, left, p - 1);
        quicksort(array, p + 1, right);
    }

    virtual void main() override
    {
         vector<int> a = {5, -1, 4, 2, 8, 5, 0, 10, 7};
//        vector<int> a = {1, 2, 3, 4, 5};
        quicksort_hoare(a, 0, (int)a.size() - 1);

        for (int x : a) cout << x << " ";
        cout << "\n";
        return;
    }

private:
    int partition_lomuto_left(vector<int>& a, int l, int r)
    {
        int pre = l;            // 维护“<= pivot 区间”的边界
        int curr = pre + 1;     // curr找到pre指向元素之后的下一个小于pivot的元素
        int pivot = a[l];
        while (curr <= r)
        {
            if (a[curr] <= pivot)
            {
                pre++;
                swap(a[pre], a[curr]);
            }
            curr++;
        }
        swap(a[l], a[pre]);
        return pre;
    }

    int partition_lomuto_right(vector<int>& a, int l, int r)
    {
        int pre = l;            // 维护“<= pivot 区间”的边界
        int curr = pre;     // curr找到pre指向元素之后的下一个小于pivot的元素
        int pivot = a[r];
        while (curr < r)
        {
            if (a[curr] <= pivot)
            {
                swap(a[pre], a[curr]);
                pre++;
            }
            curr++;
        }
        swap(a[r], a[pre]);
        return pre;
    }

    void quicksort_hoare(vector<int>& a, int l, int r);

    int partition_hoare2(vector<int>& a, int l, int r)
    {
        int pivot = a[l];
        int i = l - 1;
        int j = r + 1;
        while (true) {
            do { i++; } while (a[i] < pivot);
            do { j--; } while (a[j] > pivot);
            if (i >= j) return j;
            swap(a[i], a[j]);
        }
    }

    int partition_dig(vector<int>& a, int l, int r)
    {
        int pivot = a[l];
        // pivot暂存了a[l]的值，因此a[l]现在可以存放其他数据 => a[l]的位置现在是一个坑（空位）
        int i = l, j = r;
        while (i != j)
        {
            // j一定先走，因为坑在左边
            while (i != j && a[j] >= pivot) { j--; }
            a[i] = a[j];
            while (i != j && a[i] <= pivot) { i++; }
            a[j] = a[i];
        }
        a[i] = pivot;
        return i;
    }
};


#endif //ALGORITHM_QUICKSORT_H