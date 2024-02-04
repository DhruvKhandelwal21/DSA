class Solution
{
    public:
        string minWindow(string s, string t)
        {
            // if(s.size()<t.size()){
            //     return "";
            // }
            unordered_map<char, int> mp;
            for (auto it: t)
            {
                mp[it]++;
            }
            
            int cnt = mp.size();
            int i = 0, j = 0;
            int n = s.size();
            int len = INT_MAX;
            int idx = -1;
            string ans = "";
            while (j < n)
            {
                if(mp.find(s[j])!=mp.end()){
                    
                    mp[s[j]]--;
                    if(mp[s[j]]==0){
                        cnt--;
                    }
                }
                if (cnt==0)
                {
                    while (cnt==0&&i<=j)
                    {
                        
                        if(j-i+1<len){
                            idx = i;
                            len = j-i+1;
                        }
                        if(mp.find(s[i])!=mp.end()){
                            mp[s[i]]++;
                            if(mp[s[i]]==1){
                                cnt++;
                            }
                            i++;
                        }else{
                            i++;
                        }
                    }
                }
                j++;
            }

            return len==INT_MAX ? "":s.substr(idx,len);
        }
};