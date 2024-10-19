class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> graph(n+1);
        for(int i=1;i<n;i++){
            graph[i].push_back(i+1);
            graph[i+1].push_back(i);
        }
        graph[x].push_back(y);
        graph[y].push_back(x);
        vector<vector<int>> mat(n+1,vector<int>(n+1,INT_MAX));
        for(int i=1;i<=n;i++){
            // vector<int> dist(n+1,0);
            // dist[i] = 0;
            mat[i][i] = 0;
            queue<pair<int,int>> q;
            q.push({0,i});
            while(!q.empty()){
                auto x = q.front();
                q.pop();
                int node = x.second;
                int val = x.first;
                for(auto it:graph[node]){
                    if(mat[i][it]>val+1){
                        mat[i][it] = val+1;
                        q.push({mat[i][it],it});
                    }
                }
            }
        }
        vector<int> ans;
        for(int k=1;k<=n;k++){
            int cnt = 0;
            for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    if(mat[i][j]==k){
                     cnt++;   
                    }
                }
            }
        }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};