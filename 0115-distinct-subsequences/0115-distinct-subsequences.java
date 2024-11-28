class Solution {
    int solve(String s, String t, int i, int j, int [][]dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans1 = 0, ans2=0;

        if(s.charAt(i)==t.charAt(j)){
            ans1 = solve(s,t, i-1, j-1, dp);
        }
            ans2 = solve(s,t,i-1,j,dp);
        
       
            return dp[i][j] = ans1 + ans2;
    }

    public int numDistinct(String s, String t) {
        int n = s.length();
        int m = t.length();
        int [][]dp = new int[n+1][m+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(s,t,n-1,m-1,dp);
    }
}