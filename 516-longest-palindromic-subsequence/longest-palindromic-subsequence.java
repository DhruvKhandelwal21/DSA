class Solution {
    public int solve(String s, String r, int n, int m, int [][]dp){
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int ans = 0;
        if(s.charAt(n-1)==r.charAt(m-1)){
            ans = 1 + solve(s,r,n-1,m-1, dp);
        }else{
            ans = Math.max(solve(s,r,n-1,m,dp), solve(s,r,n,m-1,dp));
        }
        return dp[n][m] = ans;
    }
    public int longestPalindromeSubseq(String s) {
        String r = new StringBuilder(s).reverse().toString();
        int n = s.length();
        int [][]dp = new int[n+1][n+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(s,r,n,n,dp);
    }
}