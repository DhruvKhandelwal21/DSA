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
            Arrays.fill(dp[i],-1);
        }
        return solve(m-1,n-1,dp);
    }
}