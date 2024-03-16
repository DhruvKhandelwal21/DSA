class Solution {
public:
    string minimizeStringValue(string s) {
        string ans = s;
        vector<int> prefix(26,0);
        // vector<int> suffix(26,0);
        int n = s.size();
        vector<char>temp;
        int unknownchars = 0;
        for(int i=0;i<n;i++){
            if(s[i]!='?'){
                prefix[s[i]-'a']++;
            }else{
                unknownchars++;
            }
        }
        while(unknownchars>0){
            int mn = INT_MAX;
            char mnchar;
            for(int i=0;i<26;i++){
                if(mn>prefix[i]){
                    mn = prefix[i];
                    mnchar = i+'a';
                }
            }
            temp.push_back(mnchar);
            prefix[mnchar-'a']++;
            unknownchars--;
        }
        sort(temp.begin(),temp.end());
        int k = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                ans[i] = temp[k];
                k++;
            }
        }
        return ans;       
    }
};