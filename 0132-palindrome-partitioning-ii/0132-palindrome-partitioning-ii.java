class Solution {
    public static boolean isPal(String s, int i, int j){
        while(i<j){
            if(s.charAt(i)!=s.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }
    public static int solve(int i, int j, String s, int [][] dp, int [][] dpPal){
        if(i==j) return 0;

        if(dpPal[i][j]==-1){
            dpPal[i][j] = isPal(s,i,j) ? 1 : 0;
        }
        if(dpPal[i][j]==1) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = s.length()-1;
        for(int k=i;k<j;k++){
            if(isPal(s,i,k)){
              int partitions = 1 + solve(k+1,j,s,dp,dpPal);
              ans = Math.min(ans, partitions);  
            }
        }
        return dp[i][j] = ans;
    }
    public int minCut(String s) {
        int n = s.length();
        int j = s.length()-1;
        int i = 0;
        int [][] dp = new int[n][n];
        int [][] dpPal = new int[n][n];
        for(int x=0;x<n;x++){
            Arrays.fill(dp[x], -1);
        }
        for(int x=0;x<n;x++){
            Arrays.fill(dpPal[x], -1);
        }
        int ans = solve(i,j,s, dp, dpPal);
        return ans;
    }
}