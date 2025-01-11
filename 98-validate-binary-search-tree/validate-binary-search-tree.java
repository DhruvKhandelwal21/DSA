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
class Solution {
    public boolean solve(TreeNode root, long mx, long mn) {
        if (root == null) return true;
            
        if((root.val>=mx) || (root.val<=mn)) return false;
        return solve(root.left, root.val, mn) && solve(root.right, mx, root.val);
    }

    public boolean isValidBST(TreeNode root) {
        
        return solve(root, Long.MAX_VALUE, Long.MIN_VALUE);
    }
}