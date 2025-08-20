class Solution {
    public int solve(int i, int j, int m, int n, int [][] matrix, int [][] dp){
        if(i>=n || j>=m || matrix[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = solve(i, j+1,m,n, matrix, dp);
        int bottom = solve(i+1, j,m,n, matrix, dp);
        int diag = solve(i+1, j+1,m,n, matrix, dp);
        return dp[i][j] = 1 + Math.min(right, Math.min(bottom, diag));
    }
    public int countSquares(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int cnt = 0;
        int [][] dp = new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    cnt+=solve(i,j,m,n,matrix, dp);
                }
            }
        }
        return cnt;
    }
}