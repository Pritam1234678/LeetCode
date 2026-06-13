/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
       public List<Integer> preorderTraversal(TreeNode root){
        List<Integer> res= new ArrayList<>();
        if(root==null){
            return res;
        }
        Stack<TreeNode>st= new Stack<>();
        st.push(root);
        while (!st.empty()) {
            TreeNode ts= st.pop();
            res.add(ts.val);
            if(ts.right!=null)st.push(ts.right);
            if(ts.left!=null)st.push(ts.left);
            
        }
        return res;
    }
}
