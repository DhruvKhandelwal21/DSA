class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;
        for(int diff = 0 ; diff < n ; diff++){
            for(int i = 0 , j = diff ; j < n ; i++, j++){
                if(diff == 0) dp[i][j] = true;
                else if(diff == 1){
                    if(s[i] == s[j]) dp[i][j] = true;
                }
                else{
                    if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                }
                if(dp[i][j] == true) count++;
            }
        }
        return count;
    }
};