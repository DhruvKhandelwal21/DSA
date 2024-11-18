class Solution {
public:
    int solve(vector<int> &nums, int idx, vector<int> &dp){
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick = 0, noPick = 0;
        pick = nums[idx] + solve(nums, idx-2, dp);
        noPick = solve(nums, idx-1, dp);
        return dp[idx] = max(pick, noPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int pick = nums[i-1] + (i>1 ? dp[i-2] : 0);
            int noPick = dp[i-1];
            dp[i] = max(pick, noPick);
        }
        return dp[n];
        // return solve(nums, n-1, dp);
    }
};