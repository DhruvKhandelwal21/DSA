class Solution {
    public int solve(int [][] obstacleGrid, int i, int j, int[][] dp){
        if(i<0 || j<0 || obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=0, top=0;
        left = solve(obstacleGrid, i-1,j, dp);
        top = solve(obstacleGrid, i, j-1, dp);
        return dp[i][j] = top + left;
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
          int n = obstacleGrid.length;
          int m = obstacleGrid[0].length;
          int [][] dp = new int[n][m];
          for(int i=0;i<n;i++){
            Arrays.fill(dp[i], -1);
          }
          return solve(obstacleGrid, n-1,m-1, dp);
    }
}