//
// Created by wcx on 2026/2/27.
//

#ifndef ALGORITHM_VALIDATEBINARYSEARCHTREE_H
#define ALGORITHM_VALIDATEBINARYSEARCHTREE_H

#include <algorithm>
#include <pstl/execution_defs.h>

#include "../TreeNode.h"
#include "../../../Solution.h"

class ValidateBinarySearchTree: public Solution
{
public:
    bool isValidBST(TreeNode* root) {
        return work(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }

    bool work(TreeNode* node, long long notLessThan, long long notGreaterThan)
    {
        if (!node) { return true; }
        if (node->val >= notGreaterThan || node->val <= notLessThan) { return false; }
        return work(node->left, notLessThan, node->val) && work(node->right, node->val, notGreaterThan);
    }

    virtual void main() override
    {
        TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
        isValidBST(root);
    }
};

#endif //ALGORITHM_VALIDATEBINARYSEARCHTREE_H