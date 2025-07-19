class Solution {
    static boolean solve(int arr[], int target, int idx, int[][] dp){
        if(target==0) return true;
        if(idx == 0 || target < 0) return false;
        if(dp[idx][target]!=-1){
            return dp[idx][target]==1;
        }
        boolean pick = solve(arr, target-arr[idx-1], idx-1, dp);
        boolean noPick = solve(arr, target, idx-1, dp);
        boolean result = pick || noPick;
        dp[idx][target] = result ? 1 : 0;
        return result;
    }
    static Boolean isSubsetSum(int arr[], int sum) {
        int n = arr.length;
        int dp[][] = new int[n+1][sum+1];
        for (int i = 0; i <=n; i++) {
            Arrays.fill(dp[i], -1);
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j==0) dp[i][j] = 1;
                if(i==0) dp[i][j] = 0;
                if(i==0 && j==0) dp[i][j] = 1;
            }
        }
        return solve(arr, sum, n, dp);
    }
}