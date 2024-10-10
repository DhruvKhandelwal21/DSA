class Solution
{
    public:
        vector<int> gardenNoAdj(int n, vector<vector < int>> &paths)
        {
            vector<vector < int>> graph(n);
            for (int i = 0; i < paths.size(); i++)
            {
                int u = paths[i][0];
                int v = paths[i][1];
                graph[u-1].push_back(v-1);
                graph[v-1].push_back(u-1);
            }
            vector<int> ans(n,0);
            for(int i=0;i<n;i++){
                if(!ans[i]){
                 vector<int> used(5,0);
                  for(auto it: graph[i]){
                      if(ans[it]!=0){
                          used[ans[it]] = 1;
                      }
                  }
                  for(int k=1;k<5;k++){
                      if(!used[k]){
                          ans[i] = k;
                          break;
                      }
                  }
                }
            }
            return ans;

        }
};