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
    public TreeNode solve(int[] preorder, int i, int j){
        if(i>j){
            return null;
        }
        TreeNode root = new TreeNode(preorder[i]);
        int lastIdx = i;
        for(int k=i+1;k<=j;k++){
            if(preorder[k]<preorder[i]){
               lastIdx++;
            }else{
                break;
            }
        }
        root.left = solve(preorder, i+1, lastIdx);
        root.right = solve(preorder, lastIdx+1,j);
        return root;

    }
    public TreeNode bstFromPreorder(int[] preorder) {
        int n = preorder.length;
        return solve(preorder, 0, n-1);
    }
}