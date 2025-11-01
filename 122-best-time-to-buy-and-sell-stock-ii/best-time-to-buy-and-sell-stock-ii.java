class Solution {
    public int solve(int[] prices, int buyFlag, int idx, int [][]dp){
        if(idx>=prices.length) return 0;
        int pick = 0, noPick = 0;
        if(dp[idx][buyFlag]!=-1) return dp[idx][buyFlag];
        if(buyFlag==0){
            pick = -prices[idx] + solve(prices, 1, idx+1, dp);
        }else{
            pick = prices[idx] + solve(prices, 0, idx+1, dp);
        } 
        noPick = solve(prices, buyFlag, idx+1, dp);
        return dp[idx][buyFlag] = Math.max(pick, noPick);
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int [][]dp = new int[n][2];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(prices, 0, 0, dp);
    }
}