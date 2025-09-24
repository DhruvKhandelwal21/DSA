class Solution {
    public int solve(int[][] matrix, int i, int j, int [][]dp){
        if(j<0 || j>=matrix[0].length) return Integer.MAX_VALUE;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=Integer.MAX_VALUE) return dp[i][j];
        int top = solve(matrix, i-1, j, dp);
        int left = solve(matrix, i-1, j-1, dp);
        int right = solve(matrix, i-1, j+1, dp);
        return dp[i][j] = matrix[i][j] + Math.min(top, Math.min(left, right));
    }
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int [][]dp = new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],Integer.MAX_VALUE);
        }
        int ans = Integer.MAX_VALUE;
        for(int i=0;i<matrix[n-1].length;i++){
            ans = Math.min(ans, solve(matrix, n-1, i, dp));
        }
        return ans;
    }
}