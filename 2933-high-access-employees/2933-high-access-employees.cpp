class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>> mp;
        vector<string> ans;
        for(auto it:access_times){
            int minutes = stoi(it[1]);
            mp[it[0]].push_back(minutes);
        }
        
        for(auto it:mp){
            vector<int> minutes = it.second;
            if(minutes.size()<3){
                continue;
            }
            sort(minutes.begin(),minutes.end());
            for(int i=2;i<minutes.size();i++){
                if(minutes[i] - minutes[i-2]<100){
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};