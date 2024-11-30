class Solution {
    int solve(int []prices, int idx, int buy, int [][]dp){
        if(idx>=prices.length) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int pick=0, noPick=0;
        if(buy==1){
            pick = -prices[idx]+ solve(prices, idx+1, 0, dp);
        }else{
            pick = prices[idx] + solve(prices,idx+1, 1,dp);
        }
        noPick = solve(prices, idx+1, buy, dp);
        int ans = Math.max(pick, noPick);
         return dp[idx][buy] = ans;
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int [][]dp = new int[n][2];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(prices,0,1,dp);
    }
}