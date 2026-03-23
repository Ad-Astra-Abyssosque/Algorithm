//
// Created by wcx on 2026/2/27.
//

#ifndef ALGORITHM_BINARYTREELEVELORDERTRAVERSAL_H
#define ALGORITHM_BINARYTREELEVELORDERTRAVERSAL_H

#include <queue>

#include "../TreeNode.h"
#include <vector>

class BinaryTreeLevelOrderTraversal
{
public:
    std::vector<std::vector<int>> levelOrder_Better(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) return result;

        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            std::vector<int> currentLevel;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);
                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }
            result.push_back(currentLevel);
        }
        return result;
    }

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) return result;

        std::queue<TreeNode*> q;
        q.push(root);
        int len = 1;
        while (true)
        {
            std::vector<int> currentLevel;
            int valid_count = 0;
            for (int i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node)
                {
                    currentLevel.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                    valid_count++;
                }
            }
            if (currentLevel.empty()) { return result; }
            result.push_back(currentLevel);
            len = valid_count << 1;
        }
    }
};

#endif //ALGORITHM_BINARYTREELEVELORDERTRAVERSAL_H