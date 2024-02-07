class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        string ans = "";
        int n = s.size();
        for(auto it:s){
            mp[it]++;
        }
        vector<vector<char>> bucket(n+1);
        for(auto it:mp){
            bucket[it.second].push_back(it.first);
        }
        for(int fq=n;fq>=0;fq--){
            for(auto ch:bucket[fq]){
                ans.append(fq,ch);
            }
        }
        
        return ans;
    }
};