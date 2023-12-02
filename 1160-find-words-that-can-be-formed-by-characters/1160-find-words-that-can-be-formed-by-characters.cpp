class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        unordered_map<char,int> mp;
        for(int i = 0;i<chars.size();i++){
            mp[chars[i]]++;
        }
        for(int i=0;i<words.size();i++){
            bool check = true;
            string temp = words[i];
            unordered_map<char,int> x;
            for(auto it:temp){
                x[it]++;
            }
            for(int i=0;i<temp.size();i++){
                if(mp.find(temp[i])==mp.end()||x[temp[i]]>mp[temp[i]]){
                    check = false;
                    break;
                }
            }
            if(check){
                ans+=temp.size();
            }
        }
        return ans;
    }
};