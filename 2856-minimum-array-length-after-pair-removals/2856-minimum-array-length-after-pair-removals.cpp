class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int maxCount = 0;
        for(auto it:nums){
            mp[it]++;
            maxCount = max(maxCount,mp[it]);
        }
        if(maxCount<=n/2){
            if(n%2==0){
                return 0;
            }else{
                return 1;
            }
        }else{
            return 2*maxCount - n;
        }
        
        return -1;
    }
};