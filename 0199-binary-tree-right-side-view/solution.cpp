
class Solution {
public:
    vector<int> res; // Stores the right-side view of the tree

    
    void rightorder(TreeNode* root, int level) {
        // Base case: null node
        if (root == nullptr) {
            return;
        }

        // Add the first node encountered at this level
        if (level == res.size()) {
            res.push_back(root->val);
        }

        // Traverse right child first
        if (root->right != nullptr) {
            rightorder(root->right, level + 1);
        }

        // Then traverse left child
        if (root->left != nullptr) {
            rightorder(root->left, level + 1);
        }
    }

   
    vector<int> rightSideView(TreeNode* root) {
        rightorder(root, 0);
        return res;
    }
};
