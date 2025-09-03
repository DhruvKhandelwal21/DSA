class Solution {
    public int solve(String word1, String word2, int idx1, int idx2, int[][]dp){
        if(idx1==0) return idx2;
        if(idx2==0) return idx1;
    
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int ans=Integer.MAX_VALUE;
        if(word1.charAt(idx1-1)==word2.charAt(idx2-1)){
            ans = solve(word1, word2, idx1-1, idx2-1, dp);
        }else{
            int in = 1 + solve(word1, word2, idx1, idx2-1, dp);
            int del = 1 + solve(word1, word2, idx1-1, idx2, dp);
            int rep = 1 + solve(word1, word2, idx1-1, idx2-1, dp);
            ans = Math.min(in, Math.min(del, rep));
        }
        return dp[idx1][idx2] = ans;
    }
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        int [][]dp = new int[n+1][m+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(word1, word2, n, m, dp);
    }
}