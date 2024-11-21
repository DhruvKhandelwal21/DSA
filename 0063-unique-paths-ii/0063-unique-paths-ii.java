class Solution {
    public int solve(int [][] grid, int i, int j, int[][] dp){
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int top = 0, left = 0;
        if(i>0 && grid[i-1][j]!=1) left = solve(grid, i-1,j, dp);
        if(j>0 && grid[i][j-1]!=1) top = solve(grid,i,j-1, dp);
        return dp[i][j] = left + top;
        
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid[0].length;
        int n = obstacleGrid.length;
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1) return 0;
        int [][]dp = new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(obstacleGrid, n-1, m-1, dp);
    }
}