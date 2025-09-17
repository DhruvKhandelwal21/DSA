class Solution {
    public int solve(int[] nums, int[] dp, int idx, boolean flag) {
        if (idx == 0 && flag)
            return 0;
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int pick = nums[idx] + solve(nums, dp, idx - 2, flag);
        int nopick = solve(nums, dp, idx - 1, flag);
        return dp[idx] = Math.max(pick, nopick);
    }

    public int rob(int[] nums) {
        if(nums.length==1) return nums[0];
        int []dp1 = new int[nums.length];
        int []dp2 = new int[nums.length];
        Arrays.fill(dp1,-1);
        Arrays.fill(dp2, -1);
        return Math.max(solve(nums,dp1,nums.length-1, true), solve(nums,dp2,nums.length-2, false));

    }
}