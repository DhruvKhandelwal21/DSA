class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
         for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) matrix[i][j] = 0;
                }
            }
        for(auto it: edges){
            matrix[it[0]][it[1]] = it[2];
            matrix[it[1]][it[0]] = it[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        
        int ans = -1, maxcnt = INT_MAX;
        
        for(int i=0;i<n;i++){
               int cnt = 0;
                for(int j=0;j<n;j++){
                    if(i!=j && matrix[i][j]<=distanceThreshold){
                        cnt++;
                    }
                }
              if(cnt<=maxcnt){
                  maxcnt = cnt;
                  ans = i;
              }
        }
        return ans;
    }
};