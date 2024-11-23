class Solution {
    public int solve(List<List<Integer>> triangle, int i, int j, int [][]dp){
        if(j>=triangle.get(i).size() || j<0) return Integer.MAX_VALUE; 
        if(i==0 && j==0) return triangle.get(i).get(j);
        if(dp[i][j]!=Integer.MAX_VALUE) return dp[i][j];
        int top = Integer.MAX_VALUE, topLeft = Integer.MAX_VALUE;
        top = solve(triangle, i-1, j, dp);
        topLeft = solve(triangle, i-1, j-1, dp);
        return dp[i][j] = triangle.get(i).get(j) + Math.min(top, topLeft);
    }
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int [][] dp = new int[n][n];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        int ans = Integer.MAX_VALUE;
        for(int i=0;i<triangle.get(n-1).size();i++){
            ans = Math.min(ans, solve(triangle, n-1, i, dp));
        }
        return ans;
    }
}