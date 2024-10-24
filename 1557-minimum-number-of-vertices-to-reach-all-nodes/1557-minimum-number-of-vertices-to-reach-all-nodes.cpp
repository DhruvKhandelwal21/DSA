class Solution {
public:
void topoDfs(vector<vector<int>> &graph, stack<int> &st, vector<int> &vis, int node){
        vis[node] = 1;
        for(auto it: graph[node]){
            if(!vis[it]){
                topoDfs(graph,st, vis, it);
            }
        }
        st.push(node);
    }
    void dfs(vector<vector<int>> &graph, vector<int> &vis, int node, int &cnt){
        vis[node] = 1;
        cnt--;
        for(auto it: graph[node]){
            if(!vis[it]){
                dfs(graph, vis, it, cnt);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        stack<int> st;
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoDfs(graph,st, vis, i);
            }
        }
        vector<int> finalVis(n,0);
        vector<int> ans;
        int cnt = n;
        while(!st.empty() && cnt>0){
            int node = st.top();
            st.pop();
            if(!finalVis[node]){
                ans.push_back(node);
               dfs(graph, finalVis, node, cnt);
            }
        }
        return ans;
    }
};