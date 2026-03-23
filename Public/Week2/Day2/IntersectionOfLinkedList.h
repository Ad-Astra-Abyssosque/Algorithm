//
// Created by wcx on 2026/2/9.
//

#ifndef ALGORITHM_INTERSECTIONOFLINKEDLIST_H
#define ALGORITHM_INTERSECTIONOFLINKEDLIST_H

#include "../Type.h"

class IntersectionOfLinkedList {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cursorA = headA;
        ListNode* cursorB = headB;
        bool flagA = false, flagB = false;
        while (cursorA && cursorB && cursorA != cursorB) {
            cursorA = cursorA->next;
            cursorB = cursorB->next;
            if (cursorA == nullptr && !flagA) {
                cursorA = headB;
                flagA = true;
            }
            if (cursorB == nullptr && !flagB) {
                cursorB = headA;
                flagB = true;
            }

        }
        return cursorA;
    }
};
#endif //ALGORITHM_INTERSECTIONOFLINKEDLIST_H