class Solution {
public:
    int solve(vector<int>& nums, int target, int n, vector<vector<int>> &dp){
        if(target==0){
            return 0;
        }
        if(n<0){
            return -1e9;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int pick = -1e9;
        if(target>=nums[n]){
            pick = 1 + solve(nums,target-nums[n],n-1,dp);
        }
        int nopick = solve(nums,target,n-1,dp);
        return dp[n][target] = max(pick,nopick);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans = solve(nums,target,n-1,dp);
        return ans<=0?-1:ans;
    }
};