class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int []suffix = new int[n];
        int suffixCnt = 0, totalOneCnt = 0;
        boolean isZeroPresent = false;
        suffix[n-1] = 0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==1){
                suffixCnt++;
                totalOneCnt++;
            }else{
                isZeroPresent = true;
                suffix[i] = suffixCnt;
                suffixCnt = 0;
            }
        }
        if(!isZeroPresent) return totalOneCnt-1;
        int ans = 0;
        int temp = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                temp++;
            }else{
                int suffixOnes = suffix[i];
                int tempans = temp + suffixOnes;
                ans = Math.max(ans, tempans);
                temp = 0;
            }
        }
        return ans;
    }
}