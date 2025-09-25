class Solution {
    public int solve(int[][] grid, int i, int j1, int j2, int[][][] dp) {
        if (j1 < 0 || j2 < 0 || j1 >= grid[0].length || j2 >= grid[0].length)
            return (int)-1e8;
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        if (i == grid.length - 1) {
            if (j1 == j2)
                return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        int maxi = (int)-1e8;
        for (int al = -1; al <= 1; al++) {
            for (int bo = -1; bo <= 1; bo++) {
                if (j1 == j2) {
                    maxi = Math.max(maxi, grid[i][j1] + solve(grid, i + 1, j1 + al, j2 + bo, dp));
                } else {
                    maxi = Math.max(maxi, grid[i][j1] + grid[i][j2] + solve(grid, i + 1, j1 + al, j2 + bo, dp));
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][][] dp = new int[n][m][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        return solve(grid, 0, 0, m - 1, dp);
    }
}