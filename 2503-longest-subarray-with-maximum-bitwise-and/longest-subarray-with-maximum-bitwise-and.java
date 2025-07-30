class Solution {
    public int longestSubarray(int[] nums) {
        int mx = 0;
        for(int num: nums){
            mx = Math.max(mx, num);
        }
        int ans = 0;
        int cnt = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==mx){
                cnt++;
                ans = Math.max(ans, cnt);
            }else{
                cnt = 0;
            }
        }
        return ans;

    }
}