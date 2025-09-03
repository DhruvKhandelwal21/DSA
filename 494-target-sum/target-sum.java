class Solution {
    public int solve(int []nums, int idx, int target, int [][] dp, int sum){
        if(idx>=nums.length){
            if(target==0){ 
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[idx][sum+target]!=-1) return dp[idx][sum + target];
        
        int temp1 = solve(nums, idx+1, target-nums[idx], dp, sum);
        int temp2 = solve(nums, idx+1, target+nums[idx], dp, sum);
        return dp[idx][sum+target] = temp1 + temp2;
    }
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        int sum = 0;
        for(int num: nums){
            sum+=num;
        }
        if(Math.abs(target)>sum) return 0;
        int [][]dp = new int[n+1][target+2*sum+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(nums, 0, target, dp, sum);
    }
}