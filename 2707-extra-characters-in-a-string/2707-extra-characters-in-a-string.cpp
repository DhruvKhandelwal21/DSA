class Solution {
public:
    unordered_set<string> st;
    int solve(string &s,int idx,int n,vector<int> &dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        string temp = "";
        int ans = s.size();
        for(int currIdx = idx;currIdx<n;currIdx++){
            temp.push_back(s[currIdx]);
            int count = 0;
            if(st.find(temp)!=st.end()){
                count = solve(s,currIdx+1,n,dp);
            }else{
                count = temp.size() + solve(s,currIdx+1,n,dp);
            }
            ans = min(ans,count);      
        }
        return dp[idx] = ans;
        
        
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        for(auto it:dictionary){
            st.insert(it);
        }
        // string temp = ""
        vector<int> dp(n,-1);
        return solve(s,0,n,dp);
    }
};