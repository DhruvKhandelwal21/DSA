class Solution {
    boolean solve(String s1, String s2, String s3, int i, int j, int k, int [][][]dp){
        if(i<=0 && j<=0 && k<=0) return true;
        if((i<=0 || j<=0) && k<=0) return false;
        if(dp[i][j][k]!=-1){
            return dp[i][j][k]==1 ? true : false;
        }
        boolean temp = false;
        if(i>0 && s1.charAt(i-1)==s3.charAt(k-1)){
            temp = solve(s1,s2,s3,i-1,j,k-1,dp);
        }
        if(j>0 && !temp && s2.charAt(j-1)==s3.charAt(k-1)){
            temp = solve(s1,s2,s3,i,j-1,k-1,dp);
        }
       dp[i][j][k] = temp ? 1 : 0;
        return temp;
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if(n1+n2!=n3) return false;
        int [][][] dp = new int [n1+1][n2+1][n3+1];
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                for(int k=0;k<=n3;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(s1, s2, s3, n1, n2, n3, dp);
    }
}