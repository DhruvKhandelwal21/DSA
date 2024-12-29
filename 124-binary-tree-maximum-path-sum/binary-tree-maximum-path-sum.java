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
    private int maxi = Integer.MIN_VALUE;
    int solve(TreeNode root){
        if(root==null) return 0;
        int lh = Math.max(0, solve(root.left));
        int rh = Math.max(0, solve(root.right));
        
        maxi = Math.max(maxi, lh + rh + root.val);
        return Math.max(lh, rh) + root.val;
    }
    public int maxPathSum(TreeNode root) {
        solve(root);
        return maxi;
    }
}