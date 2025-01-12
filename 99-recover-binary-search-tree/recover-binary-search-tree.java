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
    TreeNode prev = null;
    TreeNode first = null;
    TreeNode last = null;
    public void solve(TreeNode root){
        if(root==null) return;
        solve(root.left);
        if(prev!=null && prev.val>root.val){
                if(first==null){
                 first = prev;
                last = root;
                }else{
                    last = root;  
            }
        }
        prev = root;
        solve(root.right);
        return;
    }
    public void recoverTree(TreeNode root) {
        solve(root);
        int temp = first.val;
        first.val = last.val;
        last.val = temp;
        return;
    }
}