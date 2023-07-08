class Solution {
public:
    int arrangeCoins(int n) {
        int lo = 1;
        int hi = n;
        int ans = 0;
        while(lo<=hi){
            long mid = lo + (hi-lo)/2;
            long temp = mid*(mid+1)/2;
            if(temp>n){
                hi = mid-1;
            }else{
                ans = mid;
                lo = mid+1;
            }
        }

        return ans;
    }
};