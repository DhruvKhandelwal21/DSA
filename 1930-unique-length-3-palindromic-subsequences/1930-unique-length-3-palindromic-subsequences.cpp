class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> mincount(26,INT_MAX);
        vector<int> maxcount(26,INT_MIN);
        for(int i=0;i<s.size();i++){
            int idx = s[i]-'a';
            mincount[idx] = min(i,mincount[idx]);
            maxcount[idx] = max(i,maxcount[idx]);
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(mincount[i]==INT_MAX||maxcount[i]==INT_MIN){
                continue;
            }
            unordered_set<char> st;
            for(int j = mincount[i] +1;j<maxcount[i];j++){
                st.insert(s[j]);
            }
            ans+=st.size();
            
        }
        return ans;
    }
};