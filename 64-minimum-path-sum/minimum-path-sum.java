class Solution {
    public int solve(int[][] grid, int n, int m, int[][] dp) {
        if (n == 0 && m == 0)
            return grid[0][0];
        if (n < 0 || m < 0)
            return Integer.MAX_VALUE;
        if (dp[n][m] != -1)
            return dp[n][m];
        int top = solve(grid, n - 1, m, dp);
        int left = solve(grid, n, m - 1, dp);
        int ans = grid[n][m] + Math.min(top, left);
        return dp[n][m] = ans;
    }

    public int minPathSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][] dp = new int[n][m];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        for (int i = 1; i < m; i++) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int top = dp[i - 1][j];
                int left = dp[i][j - 1];
                dp[i][j] = grid[i][j] + Math.min(top, left);
            }
        }

        return dp[n - 1][m - 1];
    }
}