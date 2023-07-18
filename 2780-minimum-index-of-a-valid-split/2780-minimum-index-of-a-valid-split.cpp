class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int maxi = INT_MIN;
        int temp = 0;
        for(auto it: nums){
            mp[it]++;
            if(mp[it]>maxi){
                maxi = mp[it];
                temp = it;
            }
        }
        int count = 0;
        int ans = 0;
      mp.clear();
        for(int i=0;i<n;i++){
            if(nums[i]==temp){
                count++;
            }
            if(count*2>i+1){
                ans = i;
                break;
            }
        }
        
        return ((maxi-count)*2>n-ans-1)?ans:-1;
        
    }
};