//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class iPair {
    int first, second;

    iPair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class DriverClass {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int V = Integer.parseInt(str[0]);
            int E = Integer.parseInt(str[1]);

            ArrayList<ArrayList<iPair>> adj = new ArrayList<ArrayList<iPair>>();
            for (int i = 0; i < V; i++) {
                adj.add(new ArrayList<iPair>());
            }

            int i = 0;
            while (i++ < E) {
                String S[] = read.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                int w = Integer.parseInt(S[2]);
                iPair t1 = new iPair(v, w);
                iPair t2 = new iPair(u, w);
                adj.get(u).add(t1);
                adj.get(v).add(t2);
            }

            int src = Integer.parseInt(read.readLine());

            Solution ob = new Solution();

            ArrayList<Integer> res = ob.dijkstra(adj, src);

            for (i = 0; i < V; i++) System.out.print(res.get(i) + " ");
            System.out.println();

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


/*
class iPair {
    int first, second;

    iPair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
*/

// User function Template for Java
class Solution {
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    ArrayList<Integer> dijkstra(ArrayList<ArrayList<iPair>> adj, int src) {
        
      int n = adj.size();
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        // Min-Heap PriorityQueue (Sorting by Distance)
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1,o2)->o1[0]-o2[0]);
        pq.add(new int[]{0, src}); // {distance, node}

        while (!pq.isEmpty()) {
            int[] temp = pq.poll();
            int currDist = temp[0];
            int currNode = temp[1];

            // Safety check to prevent accessing non-existing nodes
            if (currNode >= n || adj.get(currNode) == null) continue;

            // Relaxation Step
            for (iPair curr : adj.get(currNode)) {
                int nNode = curr.first;
                int nDist = curr.second;

                // Prevent accessing invalid indices
                if (nNode >= n) continue;

                if (dist[nNode] > currDist + nDist) {
                    dist[nNode] = currDist + nDist;
                    pq.add(new int[]{dist[nNode], nNode}); // Maintain Min-Heap Order
                }
            }
        }

        // Convert dist[] to ArrayList
        ArrayList<Integer> sol = new ArrayList<>();
        for (int d : dist) {
            sol.add(d);
        }
        return sol;
       
    }
}