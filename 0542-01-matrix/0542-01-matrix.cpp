class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>>ans(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){ 
                    q.push({i,j});
                } else{
                    cnt++;
                }
            }
        }
        vector<int> x = {-1,0,1,0};
        vector<int> y = {0,-1,0,1};
        int time = 0;
        while(!q.empty()){
            int sz = q.size();
            time++;
            for(int i=0;i<sz;i++){
                auto [currx,curry] = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int a = currx + x[i];
                    int b = curry + y[i];
                    if(a>=0 && b>=0 && a<n && b<m && mat[a][b]){
                        mat[a][b] = 0;
                        ans[a][b] = time;
                        q.push({a,b});
                    }
                }
            }
        }
        return ans;
    }
};