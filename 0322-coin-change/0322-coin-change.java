class Solution {
    public static int solve(int []coins, int amount, int [][]dp, int idx){
        if(amount==0) return 0;
        if(idx==0){
            if(amount==0) return 0;
            if(amount%coins[0]==0){
                return amount/coins[0];
            } else{ 
                return Integer.MAX_VALUE;
            }
        }
        if (amount < 0) return Integer.MAX_VALUE;

        if(dp[idx][amount]!=-1){ 
            return dp[idx][amount];
        }
        int pickCurr = Integer.MAX_VALUE, noPick = Integer.MAX_VALUE;
       
        int res = solve(coins, amount - coins[idx], dp, idx);
         if (res != Integer.MAX_VALUE) {
        pickCurr = 1 + res;
    }
        noPick = solve(coins, amount, dp, idx-1);
        return dp[idx][amount] = Math.min(pickCurr, noPick);
    }
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int [][] dp = new int[n+1][amount+1];
        for (int i = 0; i <= n; i++) {
    Arrays.fill(dp[i], -1); 
}
        int ans = solve(coins, amount, dp, n-1);
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}