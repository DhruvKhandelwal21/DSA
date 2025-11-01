class Solution {
    public int solve(int[] prices, int buyFlag, int idx, int[][][] dp, int k) {
        if (idx >= prices.length)
            return 0;

        if (dp[idx][buyFlag][k] != -1)
            return dp[idx][buyFlag][k];
        int pick = 0, noPick = 0;
        if (k == 0) {
            if (buyFlag == 0) {
                pick = -prices[idx] + solve(prices, 1, idx + 1, dp, k);
            } else {
                pick = prices[idx] + solve(prices, 0, idx + 1, dp, 1);
            }
        }
        if (k == 1) {
            noPick = solve(prices, buyFlag, idx + 1, dp, 0);
        } else {
            noPick = solve(prices, buyFlag, idx + 1, dp, k);
        }
        return dp[idx][buyFlag][k] = Math.max(pick, noPick);
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][][] dp = new int[n][2][2];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        return solve(prices, 0, 0, dp, 0);
    }
}