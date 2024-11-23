class Solution {
    public int solve(int [][]grid, int i, int j1, int j2, int n, int m, int[][][]dp){
        if(j1<0 || j2<0 || j1>=m || j2>=m) return Integer.MIN_VALUE;
        if(i==n-1){
            if(j1==j2){ 
                return grid[i][j1];
            }else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans = Integer.MIN_VALUE;
        for(int k=-1;k<=1;k++){
            for(int j=-1;j<=1;j++){
                int value = 0;
                if(j1==j2){ 
                    value = grid[i][j1];
                }else{
                   value = grid[i][j1] + grid[i][j2]; 
                }
                int nextMove = solve(grid, i + 1, j1 + k, j2 + j, n, m, dp);
                ans = Math.max(ans, value + nextMove);  
            }
        }
        return dp[i][j1][j2] = ans;
           
    }
    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int [][][]dp = new int[70][70][70];
        for (int i = 0; i < 70; i++) {
    for (int j = 0; j < 70; j++) {
        for (int k = 0; k < 70; k++) {
            dp[i][j][k] = -1;
        }
    }
}
        return solve(grid, 0, 0, m-1,n, m, dp);
    }
}