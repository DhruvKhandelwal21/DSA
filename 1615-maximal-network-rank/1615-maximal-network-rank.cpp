class Solution {
public:

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> outD(n,0);
        vector<vector<int>> graph(n);
        int ans = 0;
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            outD[u]++;
            outD[v]++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               int commonEdge = 0;
               for(int k=0;k<graph[i].size();k++){
                   if(graph[i][k]==j){
                       commonEdge = 1;
                       break;
                   }
               }
               ans = max(ans, outD[i]+outD[j]-commonEdge);
            }
        }
       
        return ans;
    }
};