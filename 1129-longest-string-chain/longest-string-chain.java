class Solution {
    public boolean isOrderValid(String a, String b) {
        if (Math.abs(a.length() - b.length()) != 1)
            return false;
        int i = 0, j = 0;
        int diff = 0;

        while (i < a.length() && j < b.length()) {
            if (a.charAt(i) != b.charAt(j)) {
                diff++;
                j++;
                if (diff > 1)
                    return false;
            } else {
                i++;
                j++;
            }
        }
        return true;
    }

    public int longestStrChain(String[] words) {
        Arrays.sort(words, (x, y) -> x.length() - y.length());
        int n = words.length;
        int[] dp = new int[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (isOrderValid(words[j], words[i]) && dp[i] < dp[j] + 1) {
                    // System.out.println(words[i] + " " + words[j]);
                    dp[i] = dp[j] + 1;
                }
            }
            ans = Math.max(dp[i], ans);
        }
        return ans;
    }
}