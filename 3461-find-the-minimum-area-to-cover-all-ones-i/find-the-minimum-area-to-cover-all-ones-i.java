class Solution {
    public int minimumArea(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int rmn = Integer.MAX_VALUE;
        int rmx = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    rmn = Math.min(rmn, i);
                    rmx = Math.max(rmx, i);
                }
            }
        }
        
        int cmn = Integer.MAX_VALUE;
        int cmx = Integer.MIN_VALUE;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cmn = Math.min(cmn, j);
                    cmx = Math.max(cmx, j);
                }
            }
        }

        return (rmx-rmn+1)*(cmx-cmn+1);
    }
}