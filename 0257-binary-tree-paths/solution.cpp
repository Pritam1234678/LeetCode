/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 void helper(TreeNode* root,string s,vector<string>&v){
    if(root==nullptr)return;
    string a=to_string(root->val);
    if(root->left==NULL&&root->right==NULL){
        s+=a;
        v.push_back(s);
        return;
    }
    helper(root->left,s+a+"->",v);
    helper(root->right,s+a+"->",v);
 }
    vector<string> binaryTreePaths(TreeNode* root) {
          vector<string> v;  
          helper(root,"",v);
          return v;
 
    }
};
