/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==p || root==q || root==null)return root;
        TreeNode temp1 = lowestCommonAncestor(root.left, p, q);
        TreeNode temp2 = lowestCommonAncestor(root.right, p, q);
        if(temp1==null){
            return temp2;
        }else if(temp2==null){
            return temp1;
        }else{
            return root;
        }

    }
}