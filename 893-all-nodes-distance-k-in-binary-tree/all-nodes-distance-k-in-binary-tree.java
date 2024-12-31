/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private HashMap<TreeNode, TreeNode> map = new HashMap<>();
    private HashMap<TreeNode, ArrayList<TreeNode>> graph = new HashMap<>();

    void buildTreeMap(TreeNode root) {
        if (root == null)
            return;
        if (root.left != null) {
            map.put(root.left, root);
            buildTreeMap(root.left);
        }
        if (root.right != null) {
            map.put(root.right, root);
            buildTreeMap(root.right);
        }
        return;
    }

    void buildGraph(TreeNode root) {
        if (root == null)
            return;
        ArrayList<TreeNode> temp = new ArrayList<>();
        if (root.left != null) {
            temp.add(root.left);
        }
        if (root.right != null) {
            temp.add(root.right);
        }
        if (map.get(root) != null) {
            temp.add(map.get(root));
        }
        graph.put(root, temp);
        buildGraph(root.left);
        buildGraph(root.right);
        return;
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        map.put(root, null);
        if (k == 0) {
            List<Integer> result = new ArrayList<>();
            result.add(target.val);
            return result;
        }
        buildTreeMap(root);
        buildGraph(root);
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(target);
        int cnt = 0;

        HashSet<TreeNode> set = new HashSet<>();
        List<Integer> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            int n = q.size();
            cnt++;
            for (int i = 0; i < n; i++) {
                TreeNode temp = q.poll();
                set.add(temp);
                for (TreeNode x : graph.get(temp)) {
                    if (!set.contains(x)) {
                        q.offer(x);
                    }
                }
            }
            if (cnt == k)
                break;
        }
        while (!q.isEmpty()) {
            TreeNode temp = q.poll();
            ans.add(temp.val);
        }
        return ans;
    }
}