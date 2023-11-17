class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>> mp;
        vector<string> ans;
        for(auto it:access_times){
            string temp = it[1];
            int minutes = stoi(temp.substr(0,2))*60 + stoi(temp.substr(2));
            mp[it[0]].push_back(minutes);
        }
        
        for(auto it:mp){
            vector<int> minutes = it.second;
            if(minutes.size()<3){
                continue;
            }
            sort(minutes.begin(),minutes.end());
            int cnt = 1;
            int diff = 60;
            for(int i=2;i<minutes.size();i++){
                if(minutes[i] - minutes[i-2]<60){
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};