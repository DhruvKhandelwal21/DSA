class Solution {
    typedef pair<int, int> PII;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& E) {
        long mod = 1e9 + 7;
        vector<vector<pair<long, int>>> G(n+1);
        for (auto &e : E) {
            int u = e[0], v = e[1], w = e[2];
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        vector<long> dist(n+1, INT_MAX), cnt(n+1, 0);
        dist[n] = 0;
        cnt[n] = 1;
        pq.emplace(0, n);
        while (pq.size()) {
            auto [w, u] = pq.top();
            cout<<u<<" "<<w<<endl;
            pq.pop();
            if (w > dist[u]) continue;
            for (auto &[v, d] : G[u]) {
                if (dist[v] > w + d) {
                    dist[v] = w + d;
                    pq.emplace(dist[v], v);
                }
                if (w > dist[v]) {
                    cnt[u] = (cnt[u] + cnt[v]) % mod;
                }
            }
        }
        return cnt[1];
    }
};

// class Solution {
// public:
//     typedef pair<int,int> p;
//    // std::vector<int> dp(20001,-1);
//     int MOD=1e9+7;
//     int dfs(vector<vector<pair<int,int>>> &graph, vector<int> &dist, vector<int> &dp, int node, int end){
//         long long int ans = 0;
//         if(node==end) return 1;
      
//         for(auto it: graph[node]){
//             if(it.first!=node && dist[node]>dist[it.first]){
//                 if(dp[it.first]!=-1){
//                     ans=(ans+dp[it.first])%MOD;
//                 }else {
//                     ans=(ans+dfs(graph,dist,dp, it.first, end))%MOD;
//                 }
//             }
//         }
//         return dp[node] = ans;
//     }
//     int countRestrictedPaths(int n, vector<vector<int>>& edges) {
//         vector<vector<pair<int,int>>> graph(n+1);
//         for(int i=0;i<edges.size();i++){
//             int a = edges[i][0];
//             int b = edges[i][1];
//             int c = edges[i][2];
//             graph[a].push_back({b,c});
//             graph[b].push_back({a,c});
//         }
//         priority_queue<p, vector<p>, greater<p>> pq;
//         queue<int> q;
//         q.push(1);
//         pq.push({0,n});
//         vector<int> dist(n+1,INT_MAX);
//         vector<int> vis(n+1,0);
//         dist[n] = 0;
//         while(!pq.empty()){
//             auto temp = pq.top();
//             int node = temp.second;
//             int nodedist = temp.first;
//             pq.pop();
//             if(vis[node]) continue;
//             vis[node] = 1;
//             for(auto it: graph[node]){
//                 int adjNode = it.first;
//                 int adjDist = it.second;
//                 if(dist[adjNode]>nodedist+adjDist){
//                     dist[adjNode] = nodedist+adjDist;
//                     pq.push({dist[adjNode], adjNode});
//                 }
//             }
//         }
//      // vector<int> newVis(n+1,0);
//     vector<int> dp(n+1,-1);
//      int ans = dfs(graph, dist,dp, 1, n);
        
//      // while(!q.empty()){
//      //     int node = q.front();
//      //     q.pop();
//      //     for(auto it: graph[node]){
//      //         if(it.first==n){
//      //             ans++;
//      //             continue;
//      //         }
//      //         if( it.first!=node && dist[node]>dist[it.first]){
//      //             q.push(it.first);
//      //         }
//      //     }
//      // }
//         return ans;
//     }
// };