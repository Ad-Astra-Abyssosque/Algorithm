//
// Created by wcx on 2026/3/4.
//

#ifndef ALGORITHM_DIAMETEROFBINARYTREE_H
#define ALGORITHM_DIAMETEROFBINARYTREE_H

#include <algorithm>

#include "../TreeNode.h"

class DiameterOfBinaryTree {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }

    int dfs(TreeNode* node) {
        if (!node) { return 0; }
        int depth_left = dfs(node->left);
        int depth_right = dfs(node->right);
        diameter = std::max(diameter, depth_left + depth_right + 1);
        return std::max(depth_left, depth_right) + 1;
    }

    int diameter = 0;
};

#endif //ALGORITHM_DIAMETEROFBINARYTREE_H