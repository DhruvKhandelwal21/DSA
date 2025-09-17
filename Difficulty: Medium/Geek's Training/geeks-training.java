// User function Template for Java

class Solution {
    public int solve(int [][]arr, int [][]dp, int idx, int prev){
        if(idx<0) return 0;
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        int ans = 0;
        for(int i=0;i<3;i++){
            if(prev!=i){
                ans = Math.max(ans, arr[idx][i] + solve(arr, dp, idx-1, i));
            }
        }
        return dp[idx][prev] = ans;
    }
    public int maximumPoints(int arr[][]) {
        int n = arr.length;
        int [][]dp = new int[n][3];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        int mx = 0;
        for(int i=0;i<3;i++){
            mx = Math.max(mx, arr[n-1][i] + solve(arr, dp, n-2, i));
        }
        return mx;
    }
}