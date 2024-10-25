class Solution {
public:
    static bool sortEle(pair<string, int> a, pair<string, int> b)
{
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<string, int> mp;
        queue<pair<int,int>> q;
        q.push({id,0});
        int n = friends.size();
        vector<int> vis(n,0);
        int lvl = 0;
        while(!q.empty()){
            auto [node, currLvl] = q.front();
            q.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            if(currLvl==level){
                for(int i=0;i<watchedVideos[node].size();i++){
                    mp[watchedVideos[node][i]]++;
                }
            }
            for(auto it: friends[node]){
                if(!vis[it] && currLvl<level){
                    q.push({it, currLvl+1});
                }
            }
        }
        vector<pair<string,int>> v;
        for(auto it:mp){
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end(), sortEle);
        vector<string> ans;
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};