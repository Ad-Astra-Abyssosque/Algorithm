//
// Created by wcx on 2026/3/4.
//

#ifndef ALGORITHM_FLATTERNBINARYTREETOLINKEDLIST_H
#define ALGORITHM_FLATTERNBINARYTREETOLINKEDLIST_H

#include "../TreeNode.h"
#include "../../../Solution.h"

class FlatternBinaryTreeToLinkedList: Solution
{
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        dfs(root);

    }

    TreeNode* dfs(TreeNode* node)
    {
        if (!node) return nullptr;

        TreeNode* left_bottom = dfs(node->left);
        TreeNode* right_bottom = dfs(node->right);
        TreeNode* tmp = node->right;
        TreeNode* bottom = node;
        if (node->left && left_bottom)
        {
            node->right = node->left;
            node->left = nullptr;
            bottom = left_bottom;
        }
        if (tmp && right_bottom)
        {
            bottom->right = tmp;
            bottom = right_bottom;
        }
        return bottom;
    }

    virtual void main() override
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
        root->right = new TreeNode(5, nullptr, new TreeNode(6));
        flatten(root);
    }
};

#endif //ALGORITHM_FLATTERNBINARYTREETOLINKEDLIST_H