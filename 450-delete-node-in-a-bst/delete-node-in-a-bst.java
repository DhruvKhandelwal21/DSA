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
    TreeNode parent;
    public TreeNode solve(TreeNode root){
        if(root.left==null && root.right==null) return null;
        
        if(root.left==null){
            return root.right;
        }
        if(root.right==null){
            return root.left;
        }
        TreeNode temp = getRight(root.left);
        temp.right = root.right;
        return root.left;
    }
    public TreeNode getRight(TreeNode root){
        TreeNode temp = root;
        while(temp.right!=null){
            temp = temp.right;
        }
        return temp;
    }
    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode temp = root;
        parent = root;
        if(root==null) return null;
        if(root.val==key){
            return solve(root);
        }
        while(temp!=null){
            if(temp.val>key){
                parent = temp;
                temp = temp.left;
            }else if(temp.val<key){
                parent = temp;
                temp = temp.right;
            }else{
             if(parent.left!=null && parent.left.val==temp.val){
                    parent.left = solve(temp);
                }else if(parent.right!=null && parent.right.val==temp.val){
                    parent.right = solve(temp);
                }
                break;
            }
        }
        return root;
    }
}