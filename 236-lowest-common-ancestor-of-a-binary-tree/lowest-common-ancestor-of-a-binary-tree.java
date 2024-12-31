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
    private HashMap<TreeNode, ArrayList<TreeNode>> map = new HashMap<>();
    public void solve(TreeNode root){
        if(root==null) return;
        if(root.left!=null){
            ArrayList<TreeNode> childList = new ArrayList<>();
            childList.add(root.left);
            if (map.containsKey(root)) {
                childList.addAll(map.get(root));
            }
            map.put(root.left, childList);
            solve(root.left);
        }
        if(root.right!=null){
            ArrayList<TreeNode> childList = new ArrayList<>();
            childList.add(root.right);
            if (map.containsKey(root)) {
                childList.addAll(map.get(root));
            }
            map.put(root.right, childList);
            solve(root.right);
        }
        return;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null) return null;
        map.put(root, new ArrayList<>(List.of(root)));
        solve(root);
        ArrayList<TreeNode> temp1 = map.get(p);
        ArrayList<TreeNode> temp2 = map.get(q);
        System.out.println(temp1);
        System.out.println(temp2);
        
        for (TreeNode node1 : temp1) {
            for (TreeNode node2 : temp2) {
                if (node1 == node2) {
                    return node1;
                }
            }
        }
        return null;
    }
}