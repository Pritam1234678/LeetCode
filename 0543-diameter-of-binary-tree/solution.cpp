
class Solution {
public:
    int maxd = 0;
    int level(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    void helper(TreeNode*root,  int& maxd) {
        if (root == NULL)
            return;
        int dia = level(root->left) + level(root->right);
        maxd = max(maxd, dia);
        helper(root->right,maxd);
        helper(root->left,maxd);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        int maxd=0;
        helper(root,maxd);
        return maxd;
    }
};
