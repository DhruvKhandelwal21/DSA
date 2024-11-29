class Solution {
    boolean solve(String s, String p, int i, int j, int [][]dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p.charAt(k)!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j]==1 ? true : false;
        boolean ans= false;
        if(s.charAt(i)==p.charAt(j) || p.charAt(j)=='?'){
            ans = solve(s,p,i-1,j-1,dp);
        }else if(p.charAt(j)=='*'){
            ans = solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp);
        }
    
         dp[i][j] = ans==true ? 1 : 0;
        return ans;
    }
    public boolean isMatch(String s, String p) {
        int n = s.length();
        int m = p.length();
        int [][]dp = new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(s,p,n-1,m-1,dp);
    }
}