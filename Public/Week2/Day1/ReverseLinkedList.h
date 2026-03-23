//
// Created by wcx on 2026/2/8.
//

#ifndef ALGORITHM_REVERSELINKEDLIST_H
#define ALGORITHM_REVERSELINKEDLIST_H

#include "../Type.h"

class ReverseLinkedList {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* result = nullptr;
        while (head) {
            if (!result) {
                result = new ListNode(head->val);
            }
            else {
                ListNode* temp = new ListNode(head->val);
                temp->next = result;
                result = temp;
            }
            head = head->next;
        }
        return result;
    }
};

#endif //ALGORITHM_REVERSELINKEDLIST_H