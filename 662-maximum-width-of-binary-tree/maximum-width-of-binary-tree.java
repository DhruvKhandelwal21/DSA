/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Tuple {
    TreeNode node;
    int idx;

    public Tuple(TreeNode node, int idx) {
        this.node = node;
        this.idx = idx;
    }
}

class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null)
            return 0;
        Queue<Tuple> q = new LinkedList<>();
        q.offer(new Tuple(root, 0));
        int ans = 1;
        while (!q.isEmpty()) {
            int n = q.size();
            int mn = q.peek().idx, mx = 0;
            for (int i = 0; i < n; i++) {
                Tuple temp = q.poll();
                int currId = temp.idx-mn;
                if (temp.node.left != null) {
                    q.offer(new Tuple(temp.node.left, 2 * (currId) + 1));
                }
                if (temp.node.right != null) {
                    q.offer(new Tuple(temp.node.right, 2 * (currId) + 2));
                }
                mx = temp.idx;
            }
                ans = Math.max(ans, mx - mn + 1);
        }
        return ans;
    }
}