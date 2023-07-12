class Solution {
public:
   
    
    bool dfs(int node,vector<int>&state,vector<vector<int>>& graph) {
        state[node] = 1;
        for(auto it: graph[node]){
           
            if(state[it]==0){
                if(dfs(it,state,graph)){
                    state[node] =3;
                    return true;
                }
            }else if(state[it]!=2){
                state[it] = 3;
                return true;
            }
            
        }
        state[node] = 2;
     return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
      
        vector<int> vis(n,0);
       
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,vis,graph);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==2){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};