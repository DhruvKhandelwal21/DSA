class Solution {
    public int solve(int[][] grid, int n, int m, int[][] dp) {
        if (n < 0 || m < 0 || grid[n][m] == 1)
            return 0;
        if (n == 0 && m == 0)
            return 1;
        if (dp[n][m] != -1)
            return dp[n][m];
        int left = solve(grid, n, m - 1, dp);
        int top = solve(grid, n - 1, m, dp);
        return dp[n][m] = left + top;
    }

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length;
        int m = obstacleGrid[0].length;

        int[][] dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            if (obstacleGrid[i][0] == 1)
                break;
            dp[i][0] = 1;
        }

        for (int j = 0; j < m; j++) {
            if (obstacleGrid[0][j] == 1)
                break;
            dp[0][j] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
}