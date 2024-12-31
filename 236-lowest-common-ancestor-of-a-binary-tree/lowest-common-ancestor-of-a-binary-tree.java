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
    private HashMap<TreeNode, TreeNode> map = new HashMap<>();
    public void solve(TreeNode root){
        if(root==null) return;
        if(root.left!=null){
            map.put(root.left, root);
            solve(root.left);
        }
        if(root.right!=null){
            map.put(root.right, root);
            solve(root.right);
        }
        return;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null) return null;
        map.put(root, null);
        solve(root);
        HashSet<TreeNode> ancestor = new HashSet<>();
        ancestor.add(p);
        TreeNode temp1 = p;
        while(p!=null){
          TreeNode x = map.get(p);
          ancestor.add(x);
          p = x;
        }
        System.out.println(ancestor);
        while(q!=null){
            TreeNode x = map.get(q);
            if(ancestor.contains(q)) return q;
            if(ancestor.contains(x)) return x;
            q = x;
        }
        return null;
    }
}