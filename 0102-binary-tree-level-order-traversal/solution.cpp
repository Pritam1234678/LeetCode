
class Solution {
public:
    int level(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    void fun(TreeNode* root, vector<vector<int>>& v,
             int curr) // left ORDER displaypre
    {
        if (root == nullptr)
            return;
        v[curr].push_back(root->val);
        fun(root->left, v, curr + 1);
        fun(root->right, v, curr + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        for (int i = 1; i <= level(root); i++) {
            vector<int> w;
            v.push_back(w);
        }
        fun(root, v, 0);
        return v;
    }
};
