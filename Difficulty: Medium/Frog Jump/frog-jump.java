// User function Template for Java
class Solution {
    int solve(int idx, int [] height, int []dp){
        if(idx<=0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans1=Integer.MAX_VALUE, ans2=Integer.MAX_VALUE;
        if(idx>1){
            
            
            ans2 = Math.abs(height[idx]-height[idx-2]) + solve(idx-2, height, dp);
        }
        ans1 = Math.abs(height[idx]-height[idx-1]) + solve(idx-1, height, dp);
        return dp[idx] = Math.min(ans1, ans2);
    }
    int minCost(int[] height) {
        int n = height.length;
        int []dp = new int[n];
        Arrays.fill(dp,-1);
        return solve(n-1,height, dp);
    }
}