class Solution {
    public static int solve(int [] nums, int j, int diff, int [][] dp){
        if(j>=nums.length) return 0;
        if(dp[j][diff+500]!=-1) return dp[j][diff+500];
        int ans = 1;
        for(int idx = j+1;idx<nums.length;idx++){
            if(nums[idx]-nums[j]==diff){
                int cnt = 1 + solve(nums,idx,diff,dp);
                ans = Math.max(ans,cnt);
            }
        }
        return dp[j][diff+500] = ans;
    }
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length;
        int [][] dp = new int[n+1][1002];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        int ans = 1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff = nums[j] - nums[i];
                int cnt = 1 + solve(nums,j,diff,dp);
                ans = Math.max(ans,cnt);
            }
        }
        return ans;
    }
}