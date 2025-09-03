class Solution {
    public int solve(int []nums, int idx, int target){
        if(idx>=nums.length){
            if(target==0){ 
                return 1;
            }else{
                return 0;
            }
        }
        int temp1 = solve(nums, idx+1, target-nums[idx]);
        int temp2 = solve(nums, idx+1, target+nums[idx]);
        return temp1 + temp2;
    }
    public int findTargetSumWays(int[] nums, int target) {
        return solve(nums, 0, target);
    }
}