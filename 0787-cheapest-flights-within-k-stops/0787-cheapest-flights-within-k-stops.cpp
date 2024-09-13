class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<flights.size();i++){
            vector<int> temp = flights[i];
            graph[temp[0]].push_back({temp[1],temp[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
         while(!q.empty()){
             auto currstop = q.front();
             q.pop();
             int stops = currstop.first;
             auto curr = currstop.second;
             int dis = curr.second;
             int node = curr.first;
             for(auto it: graph[node]){
                 if(stops<=k){
                     int currdist = it.second;
                     int currnode = it.first;
                     if(dis + currdist<dist[currnode]){
                        dist[currnode] = dis + currdist;
                        q.push({stops+1,{currnode, dist[currnode]}}); 
                     }
                     
                 }
             }
         }
      return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};