class Solution {
    public int solve(List<List<Integer>> triangle, int n, int m, int[][] dp) {
        if (n < 0 || m < 0 || m >= triangle.get(n).size())
            return Integer.MAX_VALUE;
        if (n == 0 && m == 0)
            return triangle.get(0).get(0);

        if (dp[n][m] != Integer.MAX_VALUE)
            return dp[n][m];
        int left = solve(triangle, n - 1, m - 1, dp);
        int top = solve(triangle, n - 1, m, dp);
        return dp[n][m] = triangle.get(n).get(m) + Math.min(left, top);
    }

    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int m = triangle.get(n - 1).size();
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < triangle.get(n - 1).size(); i++) {
            int recur = solve(triangle, n - 1, i, dp);
            ans = Math.min(ans, recur);
        }
        return ans;
    }
}