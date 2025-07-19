class Solution {
    boolean solve(int [] nums, int target, int idx, int[][] dp){
        if (target==0) return true;
        if(idx==0 || target<0) return false;
        if(dp[idx][target]!=-1){
            return dp[idx][target]==1;
        }
        boolean pick = solve(nums, target-nums[idx-1], idx-1, dp);
        boolean noPick = solve(nums, target, idx-1, dp);
        boolean result = pick || noPick;
        dp[idx][target] = result ? 1 : 0;
        return result;
    }
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if (sum%2!=0) return false;
        int target = sum/2;
        int [][]dp = new int[n+1][target+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(i==0) dp[i][j] = 0;
                if(j==0) dp[i][j] = 1;
            }
        }
        return solve(nums, target, n, dp);
    }
}