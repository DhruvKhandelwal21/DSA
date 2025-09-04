class Solution {
    public boolean solve(String s, String p, int idx1, int idx2, int [][]dp) {
        if (idx1 >= s.length() && idx2 >= p.length()) {
            return true;
        }

        if (idx1 < s.length() && idx2 >= p.length()) {
            return false;
        }

        if (idx1 >= s.length() && idx2 <= p.length()) {
            for (int i = idx2; i < p.length(); i++) {
                if (p.charAt(i) != '*')
                    return false;
            }
            return true;
        }

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2]==0 ? false : true;

        boolean ans = false;

        if (s.charAt(idx1) == p.charAt(idx2) || p.charAt(idx2) == '?') {
            ans = solve(s, p, idx1 + 1, idx2 + 1, dp);
        } else if (p.charAt(idx2) == '*') {
           ans = solve(s, p, idx1, idx2+1, dp) || solve(s, p, idx1+1, idx2, dp);
        } else {
            ans = false;
        }
        dp[idx1][idx2] = ans ? 1 : 0;
        return ans;
    }

    public boolean isMatch(String s, String p) {
        int [][]dp = new int[s.length()][p.length()];
        for(int i=0;i<s.length();i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(s, p, 0, 0, dp);
    }
}