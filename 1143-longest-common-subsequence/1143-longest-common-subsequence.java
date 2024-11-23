class Solution {
    public int solve(String text1, String text2, int n, int m, int [][]dp){
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int temp1 = 0, temp2 = 0;
        if(text1.charAt(n) == text2.charAt(m)){
            temp1 = 1+solve(text1, text2, n-1, m-1, dp);
        }
            temp2 = Math.max(solve(text1, text2, n-1,m, dp), solve(text1, text2, n, m-1, dp));
        
        return dp[n][m] = Math.max(temp1, temp2);
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        int [][]dp = new int [n+1][m+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(text1,text2, n-1,m-1,dp);
    }
}