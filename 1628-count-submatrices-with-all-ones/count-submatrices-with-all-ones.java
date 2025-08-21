class Solution {
    public int solve(int []arr){
        int total = 0;
        int concnt = 0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]==0){
                concnt=0;
            }else{
                concnt++;
            }
            total+=concnt;
        }
        return total;
    }
    public int numSubmat(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int ans = 0;
        for(int start_row=0;start_row<n;start_row++){
            int []temp = new int[m];
            Arrays.fill(temp, 1);
            for(int end_row=start_row;end_row<n;end_row++){
                for(int col=0;col<m;col++){
                temp[col] = (mat[end_row][col] != 0 && temp[col] == 1) ? 1 : 0;
            }
            ans+=solve(temp);
        }
        }
        return ans;
    }   
};