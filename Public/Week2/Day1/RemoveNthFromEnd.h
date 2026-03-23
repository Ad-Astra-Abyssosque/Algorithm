//
// Created by wcx on 2026/2/8.
//

#ifndef ALGORITHM_REMOVENTHFROMEND_H
#define ALGORITHM_REMOVENTHFROMEND_H

#include "../Type.h"
#include <vector>

class RemoveNthFromEnd {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* cursor = head;
        std::vector<ListNode*> v;
        while (cursor) {
            length++;
            v.push_back(cursor);
            cursor = cursor->next;

        }

        int targetPos = length - n;
        int prePos = targetPos - 1;
        if (prePos < 0) {
            head = head->next;
        }
        else {
            v[prePos]->next = v[targetPos]->next;
        }
        return head;
    }
};

#endif //ALGORITHM_REMOVENTHFROMEND_H