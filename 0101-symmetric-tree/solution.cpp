/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q) {
        if (!p and !q)
            return true;
         if (!p or !q)
            return false;
         if (p->val == q->val and helper(p->right ,q->left) and
                 helper(p->left ,q->right))
            return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return helper(root->right, root->left);
    }
};




