//
// Created by wcx on 2026/2/27.
//

#ifndef ALGORITHM_MAXDEPTHOFBINARYTREE_H
#define ALGORITHM_MAXDEPTHOFBINARYTREE_H

#include <queue>
#include <stack>

#include "../TreeNode.h"

class MaxDepthOfBinaryTree
{
public:
    int maxDepth_BFS(TreeNode* root) {
        if (!root) return 0;

        int depth = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            depth++;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }
        }
        return depth;
    }

    int maxDepth_DFS(TreeNode* root)
    {
        if (!root) return 0;
        std::stack<std::pair<TreeNode*, int>> st;
        int depth = 0;
        st.emplace(root, 1);
        while (!st.empty())
        {
            TreeNode* node = st.top().first;
            int current_depth = st.top().second;
            depth = std::max(depth, current_depth);
            st.pop();
            if (node->right) { st.emplace(node->right, current_depth + 1); }
            if (node->left) { st.emplace(node->left, current_depth + 1); }
        }
        return depth;
    }
};

#endif //ALGORITHM_MAXDEPTHOFBINARYTREE_H