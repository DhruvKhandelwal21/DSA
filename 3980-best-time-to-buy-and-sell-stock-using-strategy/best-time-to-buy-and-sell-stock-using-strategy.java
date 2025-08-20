class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {
        long ans = 0;
        int n = prices.length;
        long []prefix = new long[n];
        long []prefixProfit = new long[n];
        for(int i=0;i<n;i++){
            long temp = (long)prices[i]*(long)strategy[i];
            if(i==0){
                prefix[i] = (long)prices[i];
                prefixProfit[i] = temp;
            }else{
                prefix[i]=prices[i]+prefix[i-1];
                prefixProfit[i] = temp + prefixProfit[i-1];
            }
        }
        int i=0,j=0;
        long tempAns = prefixProfit[n-1];
        ans = prefixProfit[n-1];
        while(j<n){
            if(j-i+1==k){
                int mid = (j+i)/2;
                long newProfit = prefix[j]-prefix[mid];
                long profitToRemove = i==0 ? prefixProfit[j] : prefixProfit[j]-prefixProfit[i-1];
                System.out.println(profitToRemove);
                System.out.println(newProfit);
                long updatedProfit = tempAns - profitToRemove + newProfit;
                ans = Math.max(ans, updatedProfit);
                i++;
            }
            j++;
        }
        return ans;
    }
}