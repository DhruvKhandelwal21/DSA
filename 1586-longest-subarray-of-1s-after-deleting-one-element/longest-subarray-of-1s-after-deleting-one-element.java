class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int ans = 0;
        int maxLen = 1, zeroCnt=0;
        int i=0,j=0;
        while(j<n){
            if(nums[j]==0){
                zeroCnt++;
                if(zeroCnt>1){
                    while(zeroCnt>1){
                        if(nums[i]==0) zeroCnt--;
                        i++;
                    }
                }
            }
            ans = Math.max(ans, j-i);
            j++;
        }

        // int []suffix = new int[n];
        // int suffixCnt = 0, totalOneCnt = 0;
        // boolean isZeroPresent = false;
        // suffix[n-1] = 0;
        // for(int i=n-1;i>=0;i--){
        //     if(nums[i]==1){
        //         suffixCnt++;
        //         totalOneCnt++;
        //     }else{
        //         isZeroPresent = true;
        //         suffix[i] = suffixCnt;
        //         suffixCnt = 0;
        //     }
        // }
        // if(!isZeroPresent) return totalOneCnt-1;
        // int ans = 0;
        // int temp = 0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==1){
        //         temp++;
        //     }else{
        //         int suffixOnes = suffix[i];
        //         int tempans = temp + suffixOnes;
        //         ans = Math.max(ans, tempans);
        //         temp = 0;
        //     }
        // }
        return ans;
    }
}