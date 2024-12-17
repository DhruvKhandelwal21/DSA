class Solution {
public:
    static bool comparator(char a, char b){
        return a>b;
    }
    string repeatLimitedString(string s, int k) {
      priority_queue<pair<char,int>> pq;
        unordered_map<char,int> mp;
        for(auto it: s){
            mp[it]++;
        }
        for(auto it: mp){
           pq.push({it.first, it.second});
        }
        string ans = "";
        while(!pq.empty()){
            auto [c, cnt] = pq.top();
            pq.pop();
            int x = min(cnt, k);
            for(int i=0;i<x;i++){
                ans.push_back(c);
            }
            
            if(cnt-k>0){
                if(!pq.empty()){
                auto [c1, cnt1] = pq.top();
                ans.push_back(c1);
                pq.pop();
                if(cnt1>1){
                   pq.push({c1, cnt1-1});
                }
                    pq.push({c, cnt-k});
             }else{
                    break;
                }
            }
        }
        return ans;
    }
};