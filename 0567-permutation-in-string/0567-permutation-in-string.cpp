class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i=0,j=0,n = s2.size();
        unordered_map<char,int> mp;
        for(auto it:s1) mp[it]++;
        int sz = s1.size();
        int cnt = mp.size();
        while(j<n){
          if(mp.find(s2[j])!=mp.end()){
            mp[s2[j]]--;
            if(mp[s2[j]]==0) cnt--;
          }
          if(j-i+1<sz){
            j++;
          }else if(j-i+1==sz){
            if(cnt==0) return true;
            if(mp.find(s2[i])!=mp.end()){
                mp[s2[i]]++;
                if(mp[s2[i]]==1) cnt++;
            }
            i++;
            j++;
          }
        }
        return false;
    }
};