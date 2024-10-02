
class Solution {
public:
    int level(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    void displaypre(TreeNode* root, int curr, int max,
                    vector<int>& w) // left ORDER displaypre
    {
        if (root == nullptr)
            return;
        if (curr == max) {
            w.push_back(root->val);
            return;
        }
        displaypre(root->left, curr + 1, max, w);
        displaypre(root->right, curr + 1, max, w);
    }
    void displayprerev(TreeNode* root, int curr, int max,
                       vector<int>& w) // left ORDER displaypre
    {
        if (root == nullptr)
            return;
        if (curr == max) {
            w.push_back(root->val);
            return;
        }
        displayprerev(root->right, curr + 1, max, w);
        displayprerev(root->left, curr + 1, max, w);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        for (int i = 1; i <= level(root); i++) {
            vector<int> w;
            if (i % 2 == 0) {
                displayprerev(root, 1, i, w);
            } else {
                displaypre(root, 1, i, w);
            }
            v.push_back(w);
            cout << endl;
        }
        return v;
    }
};
