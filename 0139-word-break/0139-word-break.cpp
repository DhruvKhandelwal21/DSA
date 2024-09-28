class Solution {
public:
    unordered_set<string> st;
    bool solve(string &s, int curr, int &n, vector<int> &dp){
        if(curr>=n) return true;
        if(dp[curr]!=-1) return dp[curr];
        bool ans = false;
        string temp = "";
        for(int idx = curr;idx<n;idx++){
            temp.push_back(s[idx]);
            if(st.count(temp)){
                ans = ans || solve(s,idx+1,n,dp);
            }
        }
        return dp[curr] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it: wordDict){
            st.insert(it);
        }
        
        int n = s.size();
        vector<int> dp(n+1,-1);
        dp[n] = true;
        return solve(s,0,n, dp);
    }
};