class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int ans = Integer.MAX_VALUE;
        int i = 0, j = 0;
        int n = nums.length;
        int sum = 0;
        while (j < n) {
            if (sum >= target) {
                ans = Math.min(ans, j - i);
                sum -= nums[i];
                i++;
            } else {
                sum += nums[j];
                j++;
            }
        }
        if(sum>=target){
            while(i<n && sum>=target){
                sum-=nums[i];
                ans = Math.min(ans, j - i);
                i++;
            }
        }
        return ans==Integer.MAX_VALUE ? 0 : ans;
    }
}