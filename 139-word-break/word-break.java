class Solution {
    public boolean solve(String s, int idx, HashSet<String> st, int[] dp){
        if(idx>=s.length()) return true;
        if(dp[idx]!=-1){
            return dp[idx]==1;
        }

        for(int i=idx;i<=s.length();i++){
            String temp = s.substring(idx,i);
            if(st.contains(temp)){
                if (solve(s, i, st, dp)) {
                    dp[idx] = 1;
                    return true;
                }
            }
        }
        dp[idx] = 0;
        return false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String> st = new HashSet<>();
        for(String word: wordDict){
            st.add(word);
        }
        int n = s.length();
        int []dp = new int[n+1];
        Arrays.fill(dp,-1);

        return solve(s, 0, st, dp);
    }
}