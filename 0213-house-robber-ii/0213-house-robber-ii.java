class Solution {
    public int solve(int []nums, int idx, boolean flag, int []dp){
        if(!flag){
            if(idx<=0 && idx!=nums.length-1) return 0;
        }
        if(flag){
            if(idx<0) return 0;
        }
        int pick = 0, noPick = 0;
        if(dp[idx]!=-1) return dp[idx];
        pick = nums[idx] + solve(nums, idx-2, flag, dp);
        noPick = solve(nums, idx-1,flag, dp);
        return dp[idx] = Math.max(pick, noPick);
        // if(dp[idx][numFlag]!=-1) return dp[idx][numFlag];
        // if(idx==nums.length-1){
        //    pick = nums[idx] + solve(nums, idx-2,true, dp); 
        // }else if(idx==0){
        //     if(!flag){
        //         pick = nums[idx] + solve(nums, idx-2,true, dp);
        //     }
        // } else{
        //     pick = nums[idx] + solve(nums, idx-2, flag, dp);
        // }
        // noPick = solve(nums, idx-1,flag, dp);
        // return dp[idx][numFlag] = Math.max(pick, noPick);
    }
    public int rob(int[] nums) {
        int n = nums.length;
        int [] dp = new int[n+1];
        int [] dp1 = new int [n+1];
        Arrays.fill(dp,-1);
        Arrays.fill(dp1,-1);
        
        return Math.max(solve(nums,n-1, false, dp), solve(nums,n-2,true,dp1));
    }
}