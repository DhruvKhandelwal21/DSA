class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        long curr = 0;
        int i = 0,j=0;
        long target = 0;
        int n = nums.size();
        while(j<n){
            target = nums[j];
            curr+=nums[j];
            if((j-i+1)*target - curr>k){
                curr-=nums[i];
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};