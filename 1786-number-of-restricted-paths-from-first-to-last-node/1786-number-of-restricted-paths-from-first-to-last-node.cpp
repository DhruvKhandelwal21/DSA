class Solution {
public:
    typedef pair<int,int> p;
   // std::vector<int> dp(20001,-1);
    int MOD=1e9+7;
    int dfs(vector<vector<pair<int,int>>> &graph, vector<int> &dist, vector<int> &dp, int node, int end){
        long long int ans = 0;
        if(node==end) return 1;
      
        for(auto it: graph[node]){
            if(it.first!=node && dist[node]>dist[it.first]){
                if(dp[it.first]!=-1){
                    ans=(ans+dp[it.first])%MOD;
                }else {
                    ans=(ans+dfs(graph,dist,dp, it.first, end))%MOD;
                }
            }
        }
        return dp[node] = ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            graph[a].push_back({b,c});
            graph[b].push_back({a,c});
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        queue<int> q;
        q.push(1);
        pq.push({0,n});
        vector<int> dist(n+1,INT_MAX);
        vector<int> vis(n+1,0);
        dist[n] = 0;
        while(!pq.empty()){
            auto temp = pq.top();
            int node = temp.second;
            int nodedist = temp.first;
            pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            for(auto it: graph[node]){
                int adjNode = it.first;
                int adjDist = it.second;
                if(dist[adjNode]>nodedist+adjDist){
                    dist[adjNode] = nodedist+adjDist;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
     // vector<int> newVis(n+1,0);
    vector<int> dp(n+1,-1);
     int ans = dfs(graph, dist,dp, 1, n);
        
     // while(!q.empty()){
     //     int node = q.front();
     //     q.pop();
     //     for(auto it: graph[node]){
     //         if(it.first==n){
     //             ans++;
     //             continue;
     //         }
     //         if( it.first!=node && dist[node]>dist[it.first]){
     //             q.push(it.first);
     //         }
     //     }
     // }
        return ans;
    }
};