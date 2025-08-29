class Solution {
    public int solve(String s, String p, int n, int m, int [][]dp){
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int ans = 0;
        if(s.charAt(n-1)==p.charAt(m-1)){
            ans = 1 + solve(s,p,n-1,m-1,dp);
        }else{
            ans = Math.max(solve(s,p,n-1,m,dp), solve(s,p,n,m-1,dp));
        }
        return dp[n][m] = ans;
    }
    public int minInsertions(String s) {
        String p = new StringBuilder(s).reverse().toString();
        int n = s.length();
        int [][]dp = new int[n+1][n+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        int longestCommonSubSequence = solve(s,p,n,n,dp);
        return n-longestCommonSubSequence;
    }
}