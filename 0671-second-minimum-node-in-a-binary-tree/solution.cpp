#include <algorithm>

class Solution {
public:
    int secondMinimumValue = -1;
    int findSecondMinimumValue(TreeNode* root) {
        depthFirstSearch(root, root->val);
        return secondMinimumValue;
    }

    void depthFirstSearch(TreeNode* node, int firstMinValue) {
        if (!node)
            return;
        depthFirstSearch(node->left, firstMinValue);
        depthFirstSearch(node->right, firstMinValue);
        if (node->val > firstMinValue) {
            secondMinimumValue = (secondMinimumValue == -1)
                ? node->val :min(secondMinimumValue, node->val);
        }
    }
};
