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
    private HashMap<Integer, Integer> map = new HashMap<>();

    public TreeNode solve(int[] preorder, int[] inorder, int pst, int pnd, int ist, int ind) {
        if ((pst > pnd) || (ist > ind)) {
            return null;
        }
        int inIdx = map.get(preorder[pst]);
        int len = inIdx - ist;
        TreeNode node = new TreeNode(preorder[pst]);
        node.left = solve(preorder, inorder, pst + 1, pst + len, ist, inIdx - 1);
        node.right = solve(preorder, inorder, pst + len + 1, pnd, inIdx + 1, ind);
        return node;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = inorder.length;
        for (int i = 0; i < n; i++) {
            map.put(inorder[i], i);
        }
        TreeNode ans = solve( preorder,inorder, 0, n - 1, 0, n - 1);
        return ans;
    }
}