class Solution {
    public int solve(int[][] grid, int n, int m, int [][]dp){
        if(n==0 && m==0) return grid[0][0];
        if(n<0 || m<0) return Integer.MAX_VALUE;
        if(dp[n][m]!=-1) return dp[n][m];
        int top = solve(grid, n-1, m, dp);
        int left = solve(grid, n, m-1, dp);
        int ans = grid[n][m] + Math.min(top, left);
        return dp[n][m] = ans;
    }
    public int minPathSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int [][]dp = new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(grid, n-1,m-1, dp);
    }
}