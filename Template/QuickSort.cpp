//
// Created by wcx on 2026/2/22.
//

#include "QuickSort.h"

void QuickSort::quicksort_hoare(vector<int> &a, int l, int r) {
    if (l >= r) { return; }

    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;
    // 7 8 9 10 11 12 1, i->7, j->1
    // 1 8 9 10 11 12 7, i->8, j->1
    while (i < j) {
        do { i++; } while (a[i] < pivot);
        do { j--; } while (a[j] > pivot);
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    quicksort_hoare(a, l, j);
    quicksort_hoare(a, j + 1, r);

}
