class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp1;
        string x = s1 + " " + s2;
        int idx = 0;
        for(int i=0;i<x.size();i++){
            if(x[i]==' '){
                string temp = x.substr(idx,i-idx);
                mp1[temp]++;
                idx = i+1;
            }
        }
        string temp = x.substr(idx,s1.size()-idx);
        mp1[temp]++;
        
        vector<string> ans;
        for(auto it: mp1){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
       
      return ans;
    }
};