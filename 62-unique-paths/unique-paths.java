class Solution {
    public int solve(int m, int n, int [][]dp){
        if(m<0 || n<0) return 0;
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int top = solve(m-1,n,dp);
        int left = solve(m,n-1,dp);
        return dp[m][n] = top + left;
    }
    public int uniquePaths(int m, int n) {
        int [][]dp = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        dp[0][0] = 1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int top = dp[i-1][j];
                int left = dp[i][j-1];
                dp[i][j] = top + left;
            }
        }
        return dp[m-1][n-1];
    }
}