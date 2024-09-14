class Solution {
public:
    typedef pair<long long,long long> p;
    int countPaths(int n, vector<vector<int>>& roads) {
        long long int M = 1e9 + 7;
        vector<vector<pair<long long,long long>>> graph(n);
        for(auto it: roads){
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0], it[2]});  
    }
     
    priority_queue<p,vector<p>, greater<p>> pq;
    vector<long long> dist(n,1e15);
    vector<long long> vis(n,0);
    vis[0] = 1;
    dist[0] = 0;
    pq.push({0,0});
    int cnt = 0;
    while(!pq.empty()){
        auto temp = pq.top();
        long long node = temp.second;
        long long nodedist = temp.first;
        pq.pop();
       
        for(auto it: graph[node]){
            long long adjnode = it.first;
            long long adjwt = it.second;
            long long temp = (nodedist + adjwt);
            if(temp<dist[adjnode]){
                dist[adjnode] = temp;
                vis[adjnode] = vis[node];
                pq.push({dist[adjnode],adjnode});
            }
              else if(temp == dist[adjnode]){
                   vis[adjnode]=(vis[adjnode] + vis[node])%M;
            }
        }
        
      }
   return vis[n-1]%M;
    }
};