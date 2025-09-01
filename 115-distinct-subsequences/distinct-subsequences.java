class Solution {
    public int solve(String s, String t, int n, int m, int [][]dp){
        if(m==0) return 1;
        if(n==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int a=0, b=0;
        if(s.charAt(n-1)==t.charAt(m-1)){
            a = solve(s,t,n-1,m-1,dp);
        }
        b = solve(s,t,n-1,m,dp);
        return dp[n][m] = a + b;
    }
    public int numDistinct(String s, String t) {
        int n = s.length();
        int m = t.length();
        int [][]dp = new int[n+1][m+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(s,t,n,m,dp);
    }
}