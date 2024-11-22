// class Solution {
//     public int solve(int [][]grid, int i, int j, int m, int[][] dp){
//         if(j<0 ||j>=m) return 1000000;
//         if(i==0) return grid[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         int top,topleft,topright;
        
//              top = grid[i][j] + solve(grid,i-1,j,m,dp);
//              topleft =  grid[i][j] + solve(grid,i-1,j-1,m,dp);
//              topright =  grid[i][j] + solve(grid,i-1,j+1,m,dp);
            
        
//         return dp[i][j] = Math.min(top,Math.min(topleft,topright));
//         // for(int k=-1;k<=1;k++){
//         //     int idx = j+k;
//         //     if(idx>=0 && idx<=m-1){
//         //         int temp = solve(grid, i-1, idx, m, dp);
//         //         ans = Math.min(ans, temp);
//         //     }
//         // }
//         // return dp[i][j] = ans + grid[i][j];
//     }
//     public int minFallingPathSum(int[][] matrix) {
//         int n = matrix.length;
//         int m = matrix[0].length;
//         if(n==1) return matrix[0][0];
//         int [][]dp = new int[n][m];
//         for(int i=0;i<n;i++){
//             Arrays.fill(dp[i],-1);
//         }
//         int ans = Integer.MAX_VALUE;
//         for(int i=0;i<m;i++){
//             ans = Math.min(ans, solve(matrix, n-1, i, m, dp));
//             // for(int k=-1;k<=1;k++){
//             //     int idx = i+k;
//             //     if(idx>=0 && idx<=m-1){
//             //        int temp = matrix[n-1][i] + solve(matrix,n-2,idx, m, dp);
//             //        ans = Math.min(ans, temp); 
//             //     }
//             // }
//         }
//         return ans;
//     }
// }

class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int[][] memo = new int[n][n]; 
        for (int i = 0; i < n; i++) {
            Arrays.fill(memo[i], Integer.MAX_VALUE);
        }

        int minSum = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            minSum = Math.min(minSum, helper(matrix, 0, i, n, memo));
        }
        return minSum;
    }

    private int helper(int[][] matrix, int i, int j, int n, int[][] dp) {
        if (i == n - 1) {
            return matrix[i][j];
        }
        if (dp[i][j] != Integer.MAX_VALUE) {
            return dp[i][j];
        }
        
        int left = Integer.MAX_VALUE, right = Integer.MAX_VALUE;
        if (j > 0) left = matrix[i][j] + helper(matrix, i + 1, j - 1, n, dp);
        int down = matrix[i][j] + helper(matrix, i + 1, j, n, dp);
        if (j < n - 1) right = matrix[i][j] + helper(matrix, i + 1, j + 1, n, dp);

        return dp[i][j] = Math.min(Math.min(left, down), right);
    }
}