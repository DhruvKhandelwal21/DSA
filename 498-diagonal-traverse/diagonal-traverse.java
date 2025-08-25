class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int []ans = new int[m*n];
        int idx = 0;
        boolean up = true;
        int r=0, c=0;

        while(idx<m*n){

            ans[idx] = mat[r][c];
            if(up){
                if(c==m-1){
                    r++;
                    up = false;
                }else if(r==0){
                    c++;
                    up = false;
                }else{
                    r--;
                    c++;
                }
            }else {
                if(r==n-1){
                    c++;
                    up = true;
                }else if(c==0){
                    r++;
                    up = true;
                }else{
                    r++;
                    c--;
                }
            }
            idx++;
        }
        return ans;
    }
}