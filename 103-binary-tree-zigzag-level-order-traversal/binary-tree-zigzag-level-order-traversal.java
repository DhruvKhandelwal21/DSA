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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root==null) return ans;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean flag = false;
        while (q.isEmpty() == false) {
            int n = q.size();
            List<Integer> arr = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                TreeNode temp = q.poll();
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
                arr.add(temp.val);
            }
            if (flag == false) {
                ans.add(arr);
                flag = true;
            } else {
                Collections.reverse(arr);
                ans.add(arr);
                flag = false;
            }
        }
        return ans;
    }
}