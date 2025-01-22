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
    private int ans = Integer.MIN_VALUE;
    int solve(TreeNode root){
        if(root==null) return 0;
        int le = Math.max(solve(root.left), 0);
        int ri = Math.max(solve(root.right), 0);
        ans = Math.max(ans, le+ri+root.val);
        return root.val + Math.max(le, ri);
    }
    public int maxPathSum(TreeNode root) {
        solve(root);
        return ans;
    }
}