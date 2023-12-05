class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int cnt = 0;
        long long presum = 0;
        int idx = 0;
        int n = coins.size();
        sort(coins.begin(),coins.end());
        for(int t=1;t<=target;t++){
            if(idx<n&&coins[idx]<=t){
                presum+=coins[idx];
                idx++;
            }else{
                if(presum>=t){
                    continue;
                }
                presum+=t;
                cnt++;
            }
        }
        return cnt;
    }
};