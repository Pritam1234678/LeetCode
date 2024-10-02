
class Solution {
public:
int level(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(level(root->left), level(root->right));
}

    int maxDepth(TreeNode* root) {
        return level(root);
    }
};
