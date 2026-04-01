//
// Created by wcx on 2026/3/25.
//

#ifndef ALGORITHM_LRUCACHE_H
#define ALGORITHM_LRUCACHE_H
#include <list>
#include <unordered_map>

#include "../../../Solution.h"

using namespace std;

class LRUCache: public Solution {
public:
    struct Node
    {
        int key;
        int data;
        Node* pre;
        Node* next;
        Node(int key_, int data_): key(key_), data(data_), pre(nullptr), next(nullptr) {}
    };

    int _capacity;
    int currentLen = 0;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> table;

    LRUCache() {}

    LRUCache(int capacity): _capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-2, -1);
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (table.find(key) == table.end()) { return -1; }
        Node* x = table[key];
        remove_from_middle(x);
        insert_head(x);
        return x->data;
    }

    void insert_head(Node* x)
    {
        head->next->pre = x;
        x->next = head->next;
        x->pre = head;
        head->next = x;
    }

    void remove_from_middle(Node* x)
    {
        x->pre->next = x->next;
        x->next->pre = x->pre;
    }

    void put(int key, int value) {
        // 新增
        if (table.find(key) == table.end())
        {
            Node* x = new Node(key, value);
            insert_head(x);
            table[key] = x;
            currentLen++;
            // 移除
            if (currentLen > _capacity)
            {
                Node* y = tail->pre;
                // if (y == head) { return; }
                y->pre->next = tail;
                tail->pre = y->pre;
                table.erase(y->key);
                delete y;
                currentLen--;
            }
        }
        // 更新
        else
        {
            Node* x = table[key];
            x->data = value;
            remove_from_middle(x);
            insert_head(x);

        }
    }

    virtual void main() override
    {
        LRUCache lRUCache(2);
        lRUCache.put(1, 1); // 缓存是 {1=1}
        lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
        lRUCache.get(1);    // 返回 1
        lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
        lRUCache.get(2);    // 返回 -1 (未找到)
        lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
        lRUCache.get(1);    // 返回 -1 (未找到)
        lRUCache.get(3);    // 返回 3
        lRUCache.get(4);    // 返回 4
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //ALGORITHM_LRUCACHE_H