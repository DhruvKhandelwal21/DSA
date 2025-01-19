class Solution {
    public int solve(int []prices, int idx, int buy, int[][]dp){
        if(idx>=prices.length) return 0;
        if(dp[buy][idx]!=-1) return dp[buy][idx];
        int ans = 0;
        if(buy==1){
            ans = Math.max(-prices[idx] + solve(prices, idx+1, 0, dp), solve(prices, idx+1, buy, dp));
        }else{
            ans = Math.max(prices[idx] + solve(prices, idx+1, 1, dp), solve(prices, idx+1, buy, dp));
        }
        return dp[buy][idx] = ans;
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int [][]dp = new int[2][n];
        for(int i=0;i<2;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(prices, 0, 1, dp);
    }
}