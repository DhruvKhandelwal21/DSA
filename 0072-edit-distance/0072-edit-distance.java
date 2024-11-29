class Solution {
    int solve(String word1, String word2, int i, int j, int [][]dp){
        if(j<0){
          return i+1;  
        }
        if(i<0) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];
        int op1=0, op2=0, op3=0;
        if(word1.charAt(i)==word2.charAt(j)){
            return dp[i][j] = solve(word1, word2, i-1, j-1,dp);
        }
        // replace
        op1 = 1 + solve(word1, word2, i-1, j-1,dp);
        
        // delete
       
        op2 = 1 + solve(word1, word2, i-1, j,dp);    
        
        // insert
        op3 = 1 + solve(word1, word2, i, j-1,dp);
        
        int ans = Math.min(op1, Math.min(op2, op3));
        return dp[i][j] = ans;
    }
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        int [][]dp = new int[n+1][m+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(word1, word2, n-1, m-1, dp);
    }
}