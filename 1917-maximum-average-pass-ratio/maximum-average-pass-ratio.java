class Node {
    int pass;
    int total;

    Node(int pass, int total) {
        this.pass = pass;
        this.total = total;
    }

    // compute current ratio
    double ratio() {
        return (double) pass / total;
    }

    // compute gain if one more student is added
    double gain() {
        return (double) (pass + 1) / (total + 1) - ratio();
    }
}
class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<Node> maxHeap = new PriorityQueue<>(
            (a, b) -> Double.compare(b.gain(), a.gain()) // max heap by gain
        );
        for(int i=0;i<classes.length;i++){
            int a = classes[i][0];
            int b = classes[i][1];
            maxHeap.add(new Node(a, b));
        }
        while (extraStudents-- > 0) {
            Node top = maxHeap.poll();
            top.pass++;
            top.total++;
            maxHeap.add(top);
        }
        double sum = 0.0;
        int n = classes.length;
        while (!maxHeap.isEmpty()) {
            Node node = maxHeap.poll();
            sum += node.ratio();
        }

        return sum / n;
    }
}