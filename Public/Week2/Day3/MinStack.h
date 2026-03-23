//
// Created by wcx on 2026/2/12.
//

#ifndef ALGORITHM_MINSTACK_H
#define ALGORITHM_MINSTACK_H
#include <limits.h>


class MinStack {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode* pre;
        int currentMin = INT_MAX;
        ListNode() : val(0), next(nullptr), pre(nullptr) {}
        ListNode(int x) : val(x), next(nullptr), pre(nullptr) {}
    };

    MinStack(): head(new ListNode()), tail(head) {
    }

    void push(int val) {
        tail->next = new ListNode(val);
        tail->next->pre = tail;
        tail = tail->next;
        tail->currentMin = val < tail->pre->currentMin ? val : tail->pre->currentMin;
    }

    void pop() {
        ListNode* tmp = tail->pre;
        tmp->next = nullptr;
        delete tail;
        tail = tmp;


    }

    int top() {
        return tail->val;
    }

    int getMin() {
        return tail->currentMin;
    }

private:
    ListNode* head;
    ListNode *tail;
    int min = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


#endif //ALGORITHM_MINSTACK_H