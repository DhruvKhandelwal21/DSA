class Solution {
    public int solve(int []nums, int idx, boolean flag, int [][]dp){
        if(idx<0) return 0;
        int pick = 0, noPick = 0;
        int numFlag = flag ? 1 : 0;
        if(dp[idx][numFlag]!=-1) return dp[idx][numFlag];
        if(idx==nums.length-1){
           pick = nums[idx] + solve(nums, idx-2,true, dp); 
        }else if(idx==0){
            if(!flag){
                pick = nums[idx] + solve(nums, idx-2,true, dp);
            }
        } else{
            pick = nums[idx] + solve(nums, idx-2, flag, dp);
        }
        noPick = solve(nums, idx-1,flag, dp);
        return dp[idx][numFlag] = Math.max(pick, noPick);
    }
    public int rob(int[] nums) {
        int n = nums.length;
        int [][] dp = new int[n+1][2];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(nums,n-1, false, dp);
    }
}