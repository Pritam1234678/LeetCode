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
    public TreeNode helper(int pre[],int in[],int plo,int phi, int inlo, int inhi){
        if(inlo>inhi || plo>phi) return null;
        int r=0;
        while(in[r]!=pre[plo])r++;
        int ls=r-inlo;
        TreeNode root =new TreeNode(pre[plo]);
        root.left= helper(pre,in,plo+1,plo+ls,inlo,r);
        root.right= helper(pre,in,plo+ls+1,phi,r+1,inhi);
        return root;
    }
    public TreeNode buildTree(int[] pre, int[] in) {
        int n= in.length;
       return  helper(pre,in,0,n-1,0,n-1);
        
    }
}
