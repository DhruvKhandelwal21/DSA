/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode temp = root;
        if (p.val == root.val || q.val == root.val)
            return root;
        while (temp != null) {
            if ((temp.val >= p.val && temp.val <= q.val) || (temp.val <= p.val && temp.val >= q.val)) {
                return temp;
            } else if (temp.val > Math.min(p.val, q.val)) {
                temp = temp.left;
            } else if (temp.val < Math.min(p.val, q.val)) {
                temp = temp.right;
            }
        }
        return root;
    }
}