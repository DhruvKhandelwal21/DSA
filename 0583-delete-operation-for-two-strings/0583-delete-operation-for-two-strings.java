class Solution {
    public int solve(String word1, String word2, int n, int m, int [][]dp){
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int temp1=0, temp2=0;
        if(word1.charAt(n)==word2.charAt(m)){
            temp1 = 1 + solve(word1, word2, n-1, m-1, dp);
        }else{
            temp2 = Math.max(solve(word1, word2, n-1, m, dp),solve(word1, word2, n, m-1, dp) );
        }
        return dp[n][m] = Math.max(temp1, temp2);
    }
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        int [][] dp = new int[n+1][m+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        int len = solve(word1, word2, n-1, m-1, dp);
        return n+m-2*len;
    }
}