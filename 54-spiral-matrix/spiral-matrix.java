class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<Integer>();
        if(matrix.length==0 || matrix[0].length==0) return ans;
        int top = 0, bottom = matrix.length-1, left = 0, right = matrix[0].length-1;
        while(true){
          for(int i=left;i<=right;i++){
            ans.add(matrix[top][i]);
          }
          top++;
          if(top>bottom || left>right) break;
          for(int i=top;i<=bottom;i++){
            ans.add(matrix[i][right]);
          }
          right--;
          if(top>bottom || left>right) break;
          for(int i=right;i>=left;i--){
            ans.add(matrix[bottom][i]);
          }
          bottom--;
          if(top>bottom || left>right) break;
          for(int i=bottom;i>=top;i--){
            ans.add(matrix[i][left]);
          }
          left++;
          if(top>bottom || left>right) break;
        }
        return ans;
    }
}