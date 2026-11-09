//
// Created by yoimiya on 2026/11/9.
//

#ifndef ALGORITHM_HOUSEROBBER3_BOTTOMTOTOP_H
#define ALGORITHM_HOUSEROBBER3_BOTTOMTOTOP_H

#include "../../../Solution.h"
#include "../../Week3/TreeNode.h"

struct StealValue {
    int steal;
    int notSteal;
};

class HouseRobber3_BottomToTop: public Solution {
public:
    int rob(TreeNode* root) {
        StealValue val = work(root);
        return std::max(val.steal, val.notSteal);
    }

    StealValue work(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }

        StealValue left = work(node->left);
        StealValue right = work(node->right);

        return {node->val + left.notSteal + right.notSteal,
            std::max(left.steal, left.notSteal) + std::max(right.steal, right.notSteal)};
    }
};

#endif //ALGORITHM_HOUSEROBBER3_BOTTOMTOTOP_H
