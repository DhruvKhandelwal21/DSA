/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    String serialCode = "";

    public void preOrder(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append("#").append(","); // Use '#' to mark null nodes
            return;
        }
        sb.append(root.val).append(","); // Append the value and a delimiter
        preOrder(root.left, sb);
        preOrder(root.right, sb);
    }

    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        preOrder(root, sb);
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        Queue<String> q = new LinkedList<>(Arrays.asList(data.split(",")));
        // ArrayList<String> arr = new ArrayList<>(Arrays.asList(data.split(",")));
        // System.out.println(arr);
        // String top = arr.get(0);

        // if (top.equals("#")) {
        //     return null;
        // }
        // int num = Integer.valueOf(top);
        // TreeNode root = new TreeNode(num);
        // q.offer(root);
        // int idx = 1;
        // while (!q.isEmpty()) {
        //     TreeNode temp = q.poll();
        //     if (idx < arr.size()) {
        //         String leftVal = arr.get(idx++);
        //         if (!leftVal.equals("#")) {
        //             TreeNode leftNode = new TreeNode(Integer.valueOf(leftVal));
        //             temp.left = leftNode;
        //             q.offer(leftNode);
        //         }
        //     }

        //     // Process right child
        //     if (idx < arr.size()) {
        //         String rightVal = arr.get(idx++);
        //         if (!rightVal.equals("#")) {
        //             TreeNode rightNode = new TreeNode(Integer.valueOf(rightVal));
        //             temp.right = rightNode;
        //             q.offer(rightNode);
        //         }
        //     }
        // }
        TreeNode root = buildTree(q);
        return root;
    }

    public TreeNode buildTree(Queue<String> q){
    String top = q.poll();
    if(top.equals("#")) return null;
    TreeNode root = new TreeNode(Integer.valueOf(top));
    root.left = buildTree(q);
    root.right = buildTree(q);
    return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));