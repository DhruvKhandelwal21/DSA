class Pair{
    int first;
    int second;
    public Pair(int first,int second){
        this.first = first;
        this.second = second;
    }
}
class Tuple {
    int first, second, third; 
    Tuple(int first, int second, int third) {
        this.first = first; 
        this.second = second;
        this.third = third; 
    }
}
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        ArrayList<ArrayList<Pair>> graph = new ArrayList<>();
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<Pair>());
        }
        for(int i=0;i<flights.length;i++){
            graph.get(flights[i][0]).add(new Pair(flights[i][1], flights[i][2]));
        }
        Queue<Tuple> q = new LinkedList<>();
        q.offer(new Tuple(src,0,0));
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        while(!q.isEmpty()){
            Tuple curr = q.poll();
            int node = curr.first;
            int price = curr.second;
            int stop = curr.third;
            for(Pair arr: graph.get(node)){
               int neighbourNode = arr.first;
               int nPrice = arr.second;
               if(stop<=k){
                 if(dist[neighbourNode]> price + nPrice){
                    dist[neighbourNode] = price + nPrice;
                    q.offer(new Tuple(neighbourNode, price + nPrice, stop+1));
                 }
               }
            }
        }
        return dist[dst]==Integer.MAX_VALUE ? -1 : dist[dst];

    }
}