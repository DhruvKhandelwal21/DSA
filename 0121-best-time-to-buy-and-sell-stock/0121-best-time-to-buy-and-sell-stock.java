class Solution {
    public int maxProfit(int[] prices) {
        int mx = 0;
        int n = prices.length;
        int diff = 0;
        int curr =prices[0];
        for(int i=1;i<n;i++){
            int currDiff = prices[i]-curr;
            if(currDiff<0){
                curr = prices[i];
                diff = 0;
            }else{
               if(currDiff>diff){
                   diff = currDiff;
                   mx = Math.max(mx, currDiff);
               }
            }
        }
        return mx;
    }
}