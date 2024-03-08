class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxcnt = 0;
        int ans = 0;
        for(auto it:nums){
            mp[it]++;
            maxcnt = max(maxcnt,mp[it]);
        }
        for(auto it:mp){
            if(it.second==maxcnt) ans+=maxcnt;
        }
        return ans;
        
    }
};