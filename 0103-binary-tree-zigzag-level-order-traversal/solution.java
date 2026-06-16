import java.util.*;

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null)
            return result; // edge case

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        
        // Start check at 0. Level 0 (root) is even, so it won't reverse.
        int check = 0; 
        
        while (!q.isEmpty()) {
            int size = q.size(); // current level size
            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode curr = q.poll();
                level.add(curr.val);

                if (curr.left != null)
                    q.offer(curr.left);
                if (curr.right != null)
                    q.offer(curr.right);
            }
            
            // If check % 2 == 1 (odd levels like Level 1, 3, etc.), reverse it
            if (check % 2 != 0) {
                Collections.reverse(level);
            } 
            
            // You don't need a dummy copy here anymore!
            // 'level' is created fresh inside the while-loop on line 16, 
            // so adding it directly to 'result' is perfectly safe.
            result.add(level);
            
            check += 1; // Move to the next level indicator
        }
        return result;
    }
}

