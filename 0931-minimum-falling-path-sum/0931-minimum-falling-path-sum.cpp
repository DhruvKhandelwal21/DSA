class Solution {
public:
    int solve(vector<vector<int>>&mat, int i , int j,vector<vector<int>>&dp){
        int n = mat.size();
        int m = mat[0].size();

        
        if (j < 0 || j >= m) return 1e9;

        if (i == 0) return mat[0][j];
        
        if(dp[i][j]!= -1) return dp[i][j] ;
        
        int s = solve(mat, i - 1, j,dp);
        int lg = solve(mat, i - 1, j - 1,dp);
        int rd = solve(mat, i - 1, j + 1,dp);


        return dp[i][j] = mat[i][j] + min({s, lg, rd});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(n);
        int ans = 1e8;
        for(int i=0;i<n;i++){
          dp[i] = matrix[0][i];
        }
        for(int i=1;i<m;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                int top=0;
                int topleft=1e8;
                int topright=1e8;
                top = matrix[i][j] + dp[j];
                if(j>0){
                    topleft = matrix[i][j] + dp[j-1];
                }
                if(j<n-1){
                    topright = matrix[i][j] + dp[j+1];
                }
                temp[j] = min(top,min(topleft,topright));
            }
            dp = temp;
        }
        for(int j=0;j<n;j++){
            ans = min(ans,dp[j]);
        }
        return ans;
//         int n = matrix.size() ;
//         int m = matrix[0].size() ;
//         vector<vector<int>>dp(n, vector<int>(m,-1)) ;

//         int mini = 1e9 ;
//         for(int j = 0 ;j<m ; j++){
//             mini = min(mini ,solve(matrix,n-1,j,dp)) ;
//         }

//         return mini ;
    }
};
