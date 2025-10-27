class Solution {
    int solve(int[] nums, int i, int j, int [][]dp){
        if(j==nums.length) return 0;
        if(dp[i+1][j]!=-1) return dp[i+1][j];
        int take=0, notake = 0;
        if(i==-1 || nums[i]<nums[j]){
            take = 1 + solve(nums, j, j+1, dp);
        }
        notake = solve(nums,i, j+1, dp);
        return dp[i+1][j] = Math.max(take, notake);
    }
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int [][]dp = new int[n+1][n];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(nums,-1,0, dp);
    }
}