class Solution {
//     public static int solve(int i, int j, int [] nums, int [][] dp){
//         if(i>j) return 0;
//         int ans = 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         for(int k=i;k<=j;k++){
//             int coins = nums[k]*nums[i-1]*nums[j+1] + solve(i,k-1, nums, dp) + solve(k+1,j,nums, dp);  
//             ans = Math.max(ans, coins);
//         }
//         return dp[i][j]= ans;
        
//     }
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] newNums = new int[n+2];
        newNums[0] = 1;
        newNums[n+1] = 1;
        for(int i=1;i<=n;i++){
            newNums[i] = nums[i-1];
        }
        int [][] dp = new int[n+2][n+2];
        for (int i = 0; i <= n; i++) {
          Arrays.fill(dp[i], 0); 
        }
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int ans = 0;
                for(int k=i;k<=j;k++){
                    int coins = newNums[k]*newNums[i-1]*newNums[j+1] + dp[i][k-1]+dp[k+1][j];
                    ans = Math.max(ans,coins);
                }
                dp[i][j] = ans;
            }
        }
        
        return dp[1][n];
    }
}