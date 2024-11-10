class Solution {
    
    // public static int solve(int i,int j, int [] cuts, int [][] dp){
    //     if(i>j) return 0;
    //     int ans = Integer.MAX_VALUE;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     for(int k=i;k<=j;k++){
    //         int cost = cuts[j+1]-cuts[i-1] + solve(i,k-1, cuts, dp) + solve(k+1,j, cuts, dp);       
    //                 ans = Math.min(ans,cost);
    //     }
    //     return dp[i][j] = ans;
    // }
    public int minCost(int n, int[] cuts) {
        int len = cuts.length;
        int[] newCuts = new int[len+2];
        newCuts[0] = 0;
        newCuts[len+1] = n;
        for(int i=1;i<=len;i++){
            newCuts[i] = cuts[i-1];
        }
        int[][] dp = new int[len+2][len+2];

// Initialize all elements to -1
        // for (int i = 0; i < n; i++) {
        //  Arrays.fill(dp[i], -1);
        // }
        for(int i=0;i<=len+1;i++){
            for(int j=0;j<=len+1;j++){
                    dp[i][j] = 0;
            }
        }
        
      Arrays.sort(newCuts);
 
        for(int i=len;i>=1;i--){
            for(int j=i;j<=len;j++){
                int ans = Integer.MAX_VALUE;
                for(int k=i;k<=j;k++){
                  if(i>j) continue;
                  int cost = newCuts[j+1]-newCuts[i-1] + dp[i][k-1] + dp[k+1][j];       
                    ans = Math.min(ans,cost);
                    }
                dp[i][j] = ans;
                }
            }
         return dp[1][len];
        }      
}