class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp1;
        unordered_map<string,int> mp2;
        vector<string> st1, st2;
        int idx = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                string temp = s1.substr(idx,i-idx);
                st1.push_back(temp);
                mp1[temp]++;
                idx = i+1;
            }
        }
        string temp = s1.substr(idx,s1.size()-idx);
        st1.push_back(temp);
        mp1[temp]++;
        
        idx = 0;
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' '){
                string temp = s2.substr(idx,i-idx);
                st2.push_back(temp);
                mp2[temp]++;
                idx = i+1;
            }
        }
        string tempx = s2.substr(idx,s2.size()-idx);
        st2.push_back(tempx);
        mp2[tempx]++;
        
        vector<string> ans;
        int m = st1.size()-1, n = st2.size()-1;
        while(m>=0 || n>=0){
            if(m>=0){
               if(mp2.find(st1[m])==mp2.end() && mp1[st1[m]]<2){
                   ans.push_back(st1[m]);
               }
            m--;
            }
            if(n>=0){
                if(mp1.find(st2[n])==mp1.end() && mp2[st2[n]]<2){
                    ans.push_back(st2[n]);
                }
                n--;
            }
        }
      return ans;
    }
};