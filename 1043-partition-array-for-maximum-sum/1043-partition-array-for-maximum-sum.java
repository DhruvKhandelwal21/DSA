class Solution {

    public static int solve(int[] arr, int currIdx, int k, int[] dp) {
        if (currIdx < 0) return 0;
        if (dp[currIdx] != -1) return dp[currIdx];
        int ans = Integer.MIN_VALUE;
        int mxSum = arr[currIdx];
        for (int i = 0; i < k; i++) {
            if (currIdx - i < 0) continue;
            mxSum = Math.max(mxSum, arr[currIdx - i]);
            int tempAns = (i + 1) * mxSum + solve(arr, currIdx - i - 1, k, dp);
            ans = Math.max(ans, tempAns);
        }
        return dp[currIdx] = ans;
    }

    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        // dp[0] = 0;
        for (int currIdx = 0; currIdx < n; currIdx++) {
            int ans = Integer.MIN_VALUE;
            int mxSum = arr[currIdx];
            for (int i = 0; i < k; i++) {
                if (currIdx -i < 0) continue;
                mxSum = Math.max(mxSum, arr[currIdx - i]);
                int tempAns = (i + 1) * mxSum +  (currIdx - i - 1< 0 ? 0 : dp[currIdx - i - 1]);
                ans = Math.max(ans, tempAns);
            }
             dp[currIdx] = ans;
        }
        // return solve(arr,n,k,dp);
        return dp[n-1];
    }
}
