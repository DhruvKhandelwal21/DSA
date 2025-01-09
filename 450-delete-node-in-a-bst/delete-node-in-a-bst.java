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
    TreeNode parent = null;
    public TreeNode helper(TreeNode delNode){
        if(delNode.left==null && delNode.right==null){
            return null;
        }
        if(delNode.right==null){
            return delNode.left;
        }
        if(delNode.left==null){
            return delNode.right;
        }
        TreeNode ans = findRight(delNode.left);
        ans.right = delNode.right;
        return delNode.left;
    }
    TreeNode findRight(TreeNode node){
        if(node.right==null){
            return node;
        }
        return findRight(node.right);
    }

    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode temp = root;
        parent = root;
        if(root==null) return null;
        if(root.val==key){
            return helper(root);
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
                    parent.left = helper(temp);
                }else if(parent.right!=null && parent.right.val==temp.val){
                    parent.right = helper(temp);
                }
                break;
            }
        }
        return root;
    }
}