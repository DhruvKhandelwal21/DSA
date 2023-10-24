class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        long long int ans = INT_MAX;
        vector<int> suffix(n,0);
        vector<int> prefix(n,0);
        suffix[n-1] = nums[n-1];
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = min(prefix[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffix[i] = min(suffix[i+1],nums[i]);
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]>prefix[i-1]&&nums[i]>suffix[i+1]){
                long long int temp = nums[i] + prefix[i-1] + suffix[i+1];
                ans = min(ans,temp);
            }
        }
        
        return ans==INT_MAX?-1:ans;
        
    }
};