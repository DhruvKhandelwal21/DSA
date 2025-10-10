class Solution {
    int solve(int[] coins, int amount, int[][] dp, int idx) {
        if(amount==0) return 0;
        if(idx==0 && amount>0) return Integer.MAX_VALUE;
        if(idx>0 && amount<0) return Integer.MAX_VALUE;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];
        int ans1 = Integer.MAX_VALUE, ans2 = Integer.MAX_VALUE;
        if (amount >= coins[idx - 1]) {
            int temp = solve(coins, amount - coins[idx - 1], dp, idx);
            if(temp!=Integer.MAX_VALUE){
                ans1 = 1 + temp;
            }
        }
        ans2 = solve(coins, amount, dp, idx - 1);
        return dp[idx][amount] = Math.min(ans1, ans2);
    }

    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int[][] dp = new int[n + 1][amount + 1];
        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        int ans= solve(coins, amount, dp, n);
        return ans==Integer.MAX_VALUE ? -1 : ans;
    }
}