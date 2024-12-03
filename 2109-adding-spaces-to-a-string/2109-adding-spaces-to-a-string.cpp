class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int idx = 0;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(idx<spaces.size() && i==spaces[idx]){
                ans.push_back(' ');
                ans.push_back(s[i]);
                idx++;
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};