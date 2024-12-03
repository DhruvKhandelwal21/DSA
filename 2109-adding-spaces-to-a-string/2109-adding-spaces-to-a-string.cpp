class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        unordered_set<int> st;
        for(auto it: spaces){
            st.insert(it);
        }
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(st.count(i)){
                ans.push_back(' ');
                ans.push_back(s[i]);
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};