class Solution {
    public int solve(int[] nums, int idx, int curr, int maxor){
        if(idx>=nums.length){
            return maxor==curr ? 1 : 0;
        }
        int temp1 = solve(nums, idx+1, curr|nums[idx], maxor);
        int temp2 = solve(nums, idx+1, curr, maxor);
        return temp1 + temp2;
    }
    public int countMaxOrSubsets(int[] nums) {
        int maxor = 0;
        for(int m: nums){
            maxor|=m;
        }
        int ans = solve(nums,0,0,maxor);
        return ans;
    }
}