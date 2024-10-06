class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return dfs(root, root->val);
    }

    bool dfs(TreeNode* root, int val) {
        if (!root) return true;
        return root->val == val && dfs(root->left, val) && dfs(root->right, val);
    }
};
