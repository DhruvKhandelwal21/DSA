class Solution {
    int solve(String s, String t, int i, int j, int [][]dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        for(int k=i;k>=0;k--){
            if(s.charAt(k)==t.charAt(j)){
                if(k>0 && j>0 && dp[k-1][j-1]!=-1){
                    ans+=dp[k-1][j-1];
                }else{
                  ans+=solve(s,t,k-1,j-1,dp);  
                }
            }
        }
        // if(s.charAt(i)==t.charAt(j)){
        //     ans = solve(s,t, i-1, j-1, dp) + solve(s,t,i-1,j,dp);
        // }else{
        //     ans = solve(s,t,i-1,j,dp);
        // }
        // for(int k = i;k>=0;k--){
        //     if(s.charAt(k)==t.charAt(j)){
        //       if(dp[k-1][j-1]==-1]){
        //          ans+=solve(s,t,k-1,j-1,dp);   
        //         }else{
        //             ans+=dp[k-1][j-1];
        //         }
        //     }
        //     }
            return dp[i][j] = ans;
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