//
// Created by wcx on 2026/2/8.
//

#ifndef ALGORITHM_MERGETWOSORTEDLISTS_H
#define ALGORITHM_MERGETWOSORTEDLISTS_H

#include "../Type.h"

class MergeTwoSortedLists {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cursor1 = list1;
        ListNode* cursor2 = list2;
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (cursor1 && cursor2) {
            if (cursor1->val < cursor2->val) {
                insertTail(tail, cursor1);
                cursor1 = cursor1->next;
            }
            else {
                insertTail(tail, cursor2);
                cursor2 = cursor2->next;
            }
        }
        if (!cursor1 && cursor2) {
            tail->next = cursor2;
        }
        else if (cursor1 && !cursor2) {
            tail->next = cursor1;
        }
        return head->next;
    }

    void insertTail(ListNode*& tail, ListNode* newNode) {
        if (!tail) {
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

#endif //ALGORITHM_MERGETWOSORTEDLISTS_H