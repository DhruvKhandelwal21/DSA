class Solution {
    public static int solve(int [][]pairs,int prev, int curr, int n, int [][] dp){
        if(curr>=n) return 0;
        if(dp[prev+1][curr]!=-1) return dp[prev+1][curr];
        int pick = 0, noPick = 0;
        if(prev==-1 || pairs[prev][1]<pairs[curr][0]){
            pick = 1 + solve(pairs,curr, curr+1, n, dp);
        }
        noPick = solve(pairs, prev, curr+1, n, dp);
        return dp[prev+1][curr] = Math.max(pick, noPick);
    }
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> Integer.compare(a[0], b[0]));
        int n = pairs.length;
        int [][] dp = new int [n+1][n+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(pairs,-1,0,n,dp);
    }
}