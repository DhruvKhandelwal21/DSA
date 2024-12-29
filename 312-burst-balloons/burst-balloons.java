class Solution {
    int solve(int[] nums, int i, int j, int[][] dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        for (int k = i; k <= j; k++) {
            int temp = nums[k] * nums[i - 1] * nums[j + 1] + solve(nums, i, k - 1, dp) + solve(nums, k + 1, j, dp);
            ans = Math.max(ans, temp);
        }
        return dp[i][j] = ans;
    }

    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] tempNums = new int[n + 2];
        Arrays.fill(tempNums, 1);
        for (int i = 1; i <= n; i++) {
            tempNums[i] = nums[i - 1];
        }

        int[][] dp = new int[n + 2][n + 2];
        for (int i = 0; i < n + 2; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(tempNums, 1, n, dp);
    }
}