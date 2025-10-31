class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int []dp = new int[n];
        int []cnt = new int[n];
        int mx = 0;
        for(int i=0;i<n;i++){
            dp[i] = 1;
            cnt[i] = 1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]+1>=dp[i]){
                    if(dp[i]==dp[j]+1){
                        cnt[i]+=cnt[j];
                    }else{
                        dp[i] = dp[j] + 1;
                        cnt[i]=cnt[j];
                    }
                }
            }
            mx = Math.max(mx, dp[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==mx){
                ans+=cnt[i];
            }
        }
        return ans;
    }
}