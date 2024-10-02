
class Solution {
public:
    void display(TreeNode* root, vector<int>& v) // left ORDER DISPLAY
    {
        if (root == nullptr)
            return;
        v.push_back(root->val);
        display(root->left,v);
        display(root->right,v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        display(root, v);
        return v;
    }
};
