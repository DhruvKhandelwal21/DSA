class Solution {
    public int maxSum(int[] nums) {
        int ans = 0;
        int n = nums.length;
        Arrays.sort(nums);
        int mn = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            mn = Math.max(mn, nums[i]);
            if(nums[i]<0) continue;
            if(i>0 && nums[i]==nums[i-1]) continue;
            ans+=nums[i];
        }
        return mn<0 ? mn : ans;
    }
}