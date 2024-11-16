class Solution {
    public static int solve(int []piles, int i, int j, int [][] dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int lsum = 0, rsum = 0;
        lsum = piles[i] + Math.max(solve(piles,i+2,j,dp),solve(piles,i+1,j-1,dp));
        rsum = piles[j] + Math.max(solve(piles,i,j-2,dp), solve(piles,i+1,j-1,dp));
           //  asum = Math.max((piles[i] + solve(piles, i+1, j, dp)),
           // piles[j] + solve(piles, i, j-1, dp));
       
        return dp[i][j] = Math.max(lsum, rsum);
    }
    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        int [][] dp = new int [n][n];
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=piles[i];
            Arrays.fill(dp[i],-1);
        }
        int alexSum = solve(piles,0,n-1,dp);
        return alexSum > (sum-alexSum);
    }
}