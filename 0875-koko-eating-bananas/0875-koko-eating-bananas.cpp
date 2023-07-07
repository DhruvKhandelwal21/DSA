class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int hi = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;
        while(l<=hi){
            int mid = l + (hi-l)/2;
            long temp = 0;
            for(int i=0;i<piles.size();i++){
                temp+=ceil((double)piles[i]/mid);
            }
            if(temp<=h){
                ans = mid;
                hi = mid-1;
            }else{
                l = mid+1;
            }
            
        }
        return ans;
    }
};