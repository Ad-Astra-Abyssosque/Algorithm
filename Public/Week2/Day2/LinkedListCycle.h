//
// Created by wcx on 2026/2/9.
//

#ifndef ALGORITHM_LINKEDLISTCYCLE_H
#define ALGORITHM_LINKEDLISTCYCLE_H

#include "../Type.h"
#include "../../../Solution.h"

class LinkedListCycle: public Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode* beacon = nullptr;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                beacon = head;
                break;
            }
        }
        if (beacon == nullptr) {
            return nullptr;
        }
        while (beacon != slow) {
            beacon = beacon->next;
            slow = slow->next;
        }
        return beacon;
    }

    virtual void main() override {
        ListNode *head = new ListNode(3);
        head->next = new ListNode(2);
        head->next->next = new ListNode(0);
        head->next->next->next = new ListNode(-4);
        head->next->next->next->next = head->next;
        detectCycle(head);
    }
};

#endif //ALGORITHM_LINKEDLISTCYCLE_H