class Solution {
    public int solve(int[][] grid, int n, int m, int [][]dp){
        if(n<0 || m<0 || grid[n][m]==1) return 0;
        if(n==0 && m==0) return 1;
        if(dp[n][m]!=-1) return dp[n][m];
        int left = solve(grid, n, m-1, dp);
        int top = solve(grid, n-1, m, dp);
        return dp[n][m] = left + top; 
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length;
        int m = obstacleGrid[0].length;

        int [][]dp = new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(obstacleGrid, n-1,m-1, dp);
    }
}