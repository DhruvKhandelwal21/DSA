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
        int [][]dp = new int[n+1][n+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],0);
        }
        for(int j=n-1;j>=0;j--){
            for(int i=j-1;i>=-1;i--){
                int take = 0, notake = 0;
                if(i==-1 || nums[i]<nums[j]){
                    take = 1 + dp[j+1][j+1];
                }
                notake = dp[i+1][j+1];
                dp[i+1][j] = Math.max(take, notake);
            }
        }
        return dp[0][0];
        // return solve(nums,-1,0, dp);
    }
}