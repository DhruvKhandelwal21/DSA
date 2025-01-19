class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        int currIdx = 0;
        for(int i=1;i<prices.length;i++){
            if(prices[i]<=prices[currIdx]){
                currIdx = i;
            }else{
                ans = Math.max(ans, prices[i]-prices[currIdx]);
            }
        }
        return ans;
    }
}