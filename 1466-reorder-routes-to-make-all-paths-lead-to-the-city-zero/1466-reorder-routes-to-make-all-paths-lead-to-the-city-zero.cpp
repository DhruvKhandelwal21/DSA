class Solution {
public:
    void dfs(vector<unordered_set<int>> &graph, vector<unordered_set<int>> &tempGraph, int node, int &ans, vector<int> &vis){
        vis[node] = 1;
        for(auto it: tempGraph[node]){
            if(!vis[it]){
                if(graph[node].count(it)) ans++;
                dfs(graph, tempGraph, it, ans, vis);
            }
            
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<unordered_set<int>> graph(n), tempGraph(n);
        for(auto it: connections){
            tempGraph[it[0]].insert(it[1]);
            tempGraph[it[1]].insert(it[0]);
            graph[it[0]].insert(it[1]);
        }
        int ans = 0;
        vector<int> vis(n,0);
        dfs(graph, tempGraph, 0, ans, vis);
        return ans;
    }
};