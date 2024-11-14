class Solution {
    public boolean solve(int []nums, int target, int idx, int [][]dp){
        if(target==0) return true;
        if(idx<0) return false;
        if(dp[idx][target]!=-1) return dp[idx][target]==1 ? true : false;
        boolean pick = false, noPick = false;
        if(target>=nums[idx]){
            pick = solve(nums,target-nums[idx],idx-1,dp);
        }   
        noPick = solve(nums,target,idx-1,dp);
        dp[idx][target] = (pick || noPick) ? 1 : 0;
        return pick || noPick;
    }
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        int n = nums.length;
        int [][] dp = new int[n+1][target+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(nums,target,n-1,dp);
    }
}