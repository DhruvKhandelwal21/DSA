class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it: arr){
            mp[it]++;
        }
        for(auto it: arr){
            mp[it]--;
                if(mp[it*2]>0) return true;
            mp[it]++;
        }
        return false;
        
    }
};