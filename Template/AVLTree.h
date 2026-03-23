//
// Created by wcx on 2026/3/17.
//

#ifndef ALGORITHM_AVLTREE_H
#define ALGORITHM_AVLTREE_H

#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree
{
private:
    struct Node
    {
        int val;
        int height;
        Node* left;
        Node* right;

        Node(int x)
            : val(x), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

private:
    // 获取节点高度
    int getHeight(Node* node)
    {
        if (node) { return node->height; }
        return 0;
    }

    // 更新节点高度
    void updateHeight(Node* node)
    {
        if (node)
        {
            int height_l = node->left ? node->left->height : 0;
            int height_r = node->right ? node->right->height : 0;
            node->height = max(height_l, height_r) + 1;
        }
    }

    // 获取平衡因子
    int getBalanceFactor(Node* node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // 右旋
    Node* rotateRight(Node* y)
    {
        Node* center = y->left;
        if (center->right)
        {
            y->left = center->right;
        }
        center->right = y;
        return center;
    }

    // 左旋
    Node* rotateLeft(Node* x)
    {
        Node* center = x->right;
        if (center->left)
        {
            x->right = center->left;
        }
        center->left = x;
        return center;
    }

    // 平衡调整
    Node* balance(Node* node)
    {
        // TODO
        return node;
    }

    // 插入
    Node* insert(Node* node, int val)
    {
        // TODO
        return node;
    }

    // 删除
    Node* remove(Node* node, int val)
    {
        // TODO
        return node;
    }

    // 查找最小节点
    Node* getMin(Node* node)
    {
        // TODO
        return node;
    }

    // 查找
    bool search(Node* node, int val)
    {
        // TODO
        return false;
    }

    // 中序遍历
    void inorder(Node* node)
    {
        if (node == nullptr) return;

        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    // 释放内存
    void destroy(Node* node)
    {
        if (node == nullptr) return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    AVLTree() : root(nullptr) {}

    ~AVLTree()
    {
        destroy(root);
    }

    void insert(int val)
    {
        root = insert(root, val);
    }

    void remove(int val)
    {
        root = remove(root, val);
    }

    bool search(int val)
    {
        return search(root, val);
    }

    void inorder()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    AVLTree tree;

    // 你可以自己测试
    // tree.insert(10);
    // tree.insert(20);
    // tree.insert(30);
    // tree.inorder();

    return 0;
}

#endif //ALGORITHM_AVLTREE_H