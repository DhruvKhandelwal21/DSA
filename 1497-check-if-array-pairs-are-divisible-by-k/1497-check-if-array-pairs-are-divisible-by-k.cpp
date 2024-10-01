class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto it: arr){
            int md = (it%k + k)%k;
            mp[md]++;
        }
        
        for(auto it: mp){
            if(it.first==0){
                if(it.second%2!=0) return false;
            }else if(mp[it.first]!=mp[k-it.first]){
                return false;
            }
        }
        return true;
    }
};