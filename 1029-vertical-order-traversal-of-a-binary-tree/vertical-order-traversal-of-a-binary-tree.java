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
class Tuple {
    TreeNode node;
    int row;
    int col;

    public Tuple(TreeNode node, int row, int col) {
        this.node = node;
        this.col = col;
        this.row = row;
    }
}

class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        Queue<Tuple> q = new LinkedList<>();
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();
        q.offer(new Tuple(root, 0, 0));
        while (!q.isEmpty()) {
            Tuple tuple = q.poll();
            TreeNode node = tuple.node;
            int col = tuple.row;
            int lvl = tuple.col;
            if (!map.containsKey(col)) {
                map.put(col, new TreeMap<>());
            }
            if (!map.get(col).containsKey(lvl)) {
                map.get(col).put(lvl, new PriorityQueue<>());
            }
            map.get(col).get(lvl).offer(node.val);
            if (node.left != null) {
                q.offer(new Tuple(node.left, col - 1, lvl + 1));
            }
            if (node.right != null) {
                q.offer(new Tuple(node.right, col + 1, lvl + 1));
            }
        }
        List<List<Integer>> list = new ArrayList<>();

        for(TreeMap<Integer,PriorityQueue<Integer>> ys : map.values()){
            list.add(new ArrayList<>());
            for(PriorityQueue<Integer> nodes: ys.values()){
                while(!nodes.isEmpty()){
                list.get(list.size() - 1).add(nodes.poll());
                }
            }

        } 
        return list;     
    }
}