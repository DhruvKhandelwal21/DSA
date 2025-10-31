class Solution {
    public int maxProfit(int[] prices) {
        int maxi = 0;
        int prev = 0;
        int diff = 0;
        for(int i=1;i<prices.length;i++){
            if(prices[i]<prices[prev]){
                prev = i;
                diff = 0;
            }else{
                diff = prices[i]-prices[prev];
                maxi = Math.max(maxi, diff);
            }
        }
        return maxi;
    }
}