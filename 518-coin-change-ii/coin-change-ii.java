class Solution {
    int solve(int[] coins, int amount, int[][] dp, int idx) {
        if (amount == 0)
            return 1;
        if (idx == 0 && amount > 0)
            return 0;
        if (idx > 0 && amount < 0)
            return 0;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];
        int ans1 = 0, ans2 = 0;
        if (amount >= coins[idx - 1]) {
            ans1 = solve(coins, amount - coins[idx - 1], dp, idx);
        }
        ans2 = solve(coins, amount, dp, idx - 1);
        return dp[idx][amount] = ans1 + ans2;
    }

    public int change(int amount, int[] coins) {
        int n = coins.length;
        int[][] dp = new int[n + 1][amount + 1];
        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(coins, amount, dp, n);
    }
}