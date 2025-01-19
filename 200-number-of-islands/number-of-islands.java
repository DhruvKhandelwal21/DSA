class Solution {
    int []u = new int[]{-1,0,1,0};
    int []v = new int[]{0,-1,0,1};
    public void solve(char [][] grid, int [][] vis, int i, int j){
        if(i>=grid.length || j>=grid[0].length || i<0 || j<0 || grid[i][j]=='0' || vis[i][j]==1) return;
        vis[i][j] = 1;
      for(int k=0;k<4;k++){
        solve(grid, vis, i + u[k], j + v[k]);
      }
      return;
    }
    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int [][] vis = new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(vis[i], 0);
        }
        int cnt = 0;
        for(int i=0;i< n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    solve(grid, vis, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
}