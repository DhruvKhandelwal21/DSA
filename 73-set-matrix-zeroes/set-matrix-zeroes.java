class Solution {
    public void setZeroes(int[][] matrix) {
        boolean isRow0 = false, isCol0 = false;
        int n = matrix.length;
        int m = matrix[0].length;
        for(int j=0;j<m;j++){
            if(matrix[0][j]==0)
                isRow0=true;
        }
        
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0)
                isCol0=true;
        }
        for(int i=1;i<matrix.length;i++){
            for(int j=1;j<matrix[0].length;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
          for(int j=1;j<m;j++){
             if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
             }
           }
        }
        if(isRow0){
            for(int j=0;j<m;j++)
                matrix[0][j]=0;
        }
        if(isCol0){
            for(int i=0;i<n;i++)
                matrix[i][0]=0;
        }
    }
}