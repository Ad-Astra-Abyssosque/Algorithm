//
// Created by wcx on 2026/2/8.
//

#ifndef ALGORITHM_TYPE_H
#define ALGORITHM_TYPE_H


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //ALGORITHM_TYPE_H