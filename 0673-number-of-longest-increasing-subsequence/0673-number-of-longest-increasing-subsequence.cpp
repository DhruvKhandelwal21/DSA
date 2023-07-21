class Solution {
public:
    int solve(vector<int> &nums,int n,int prev, int curr,vector<vector<int>> &dp){
        if(curr>=n){
            return 0;
        }
        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }
        int pick=0,nopick=0;
        if(prev==-1||nums[curr]> nums[prev]){
            pick = 1 + solve(nums,n,curr,curr+1,dp);
        }
        nopick = solve(nums,n,prev,curr+1,dp);
        return dp[prev+1][curr] = max(pick,nopick);
    }
    int findNumberOfLIS(vector<int>& nums) {
           int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>cnt(n, 1);
        int maxi = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i] && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                }
                else if(nums[j] < nums[i] && 1 + dp[j] == dp[i])
                    cnt[i] += cnt[j];
            }
            if(maxi < dp[i])
                maxi = dp[i];
        }    
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(dp[i] == maxi)
                count += cnt[i];
        }
        return count;
    }
};