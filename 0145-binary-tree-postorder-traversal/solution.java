class Solution {

    public List<Integer> postorderTraversal(TreeNode root) {

        List<Integer> res = new ArrayList<>();

        if (root == null)
            return res;

        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;

        while (node != null || !stack.isEmpty()) {

            if (node != null) {
                stack.push(node);
                node = node.left;
            }

           else if (stack.peek().right != null) {
                node = stack.peek().right;
            } else {

                TreeNode temp = stack.pop();
                res.add(temp.val);

                while (!stack.isEmpty() &&
                       temp == stack.peek().right) {

                    temp = stack.pop();
                    res.add(temp.val);
                }
            }
        }

        return res;
    }
}
