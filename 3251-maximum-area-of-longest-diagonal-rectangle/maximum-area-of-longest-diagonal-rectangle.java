class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int ans = 0;
        double maxDiag = 0;
        for(int i=0;i<dimensions.length;i++){
            int a = dimensions[i][0];
            int b = dimensions[i][1];
            double sum = Math.sqrt(Math.pow(a,2) + Math.pow(b,2));
            if(sum>maxDiag){
                ans = a*b;
                maxDiag = sum;
            }else if(sum==maxDiag){
                ans = Math.max(a*b,ans);
            }
        }
        return ans;
    }
}