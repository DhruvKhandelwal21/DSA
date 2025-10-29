class Solution {
    int solve(int[] nums, int i, int j, int[][] dp) {
        if (j == nums.length)
            return 0;
        if (dp[i + 1][j] != -1)
            return dp[i + 1][j];
        int take = 0, notake = 0;
        if (i == -1 || nums[i] < nums[j]) {
            take = 1 + solve(nums, j, j + 1, dp);
        }
        notake = solve(nums, i, j + 1, dp);
        return dp[i + 1][j] = Math.max(take, notake);
    }

    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] dp = new int[n];
        int[] hash = new int[n];
        int maxi = 0, lastIdx = 0;
          for (int i = 0; i < n; i++) {
            dp[i] = 1;      // at least the element itself
            hash[i] = i;    // point to itself by default

            for (int j = 0; j < i; j++) {
                // check whether current (larger) number is divisible by previous (smaller)
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }

            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIdx = i;
            }
        }
        List<Integer> ans = new ArrayList<Integer>();
        int cur = lastIdx;
        while (hash[cur] != cur) {
            ans.add(nums[cur]);
            cur = hash[cur];
        }
        ans.add(nums[cur]); // add the root
        Collections.reverse(ans);
        return ans;

    }
}