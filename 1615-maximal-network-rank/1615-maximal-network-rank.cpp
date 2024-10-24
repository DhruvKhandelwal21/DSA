class Solution {
public:

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> outD(n,0);
        vector<unordered_set<int>> graph(n);
        int ans = 0;
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            graph[u].insert(v);
            graph[v].insert(u);
            outD[u]++;
            outD[v]++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               int commonEdge = 0;
               if(graph[i].count(j)) commonEdge = 1;
               ans = max(ans, outD[i]+outD[j]-commonEdge);
            }
        }
       
        return ans;
    }
};