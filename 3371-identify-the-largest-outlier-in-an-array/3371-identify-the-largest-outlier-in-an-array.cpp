class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        for(auto it: nums){
            mp[it]++;
            sum+=it;
        }
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]--;
            int out = sum-2*nums[i];
            if(mp[out]>0){
                ans = max(ans, out);
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};