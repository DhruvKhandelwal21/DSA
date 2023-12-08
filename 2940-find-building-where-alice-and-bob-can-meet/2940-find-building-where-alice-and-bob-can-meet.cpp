class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n,-1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<n;i++){
            int al = queries[i][0];
            int bo = queries[i][1];
            if(al==bo){
                ans[i] = bo;
            }else if(al<bo&&h[bo]>h[al]){
                ans[i] = bo;
            }else if(al>bo&&h[al]>h[bo]){
                ans[i] = al;
            }else{
                mp[max(al,bo)].push_back({max(h[al],h[bo]),i});
            }
            
        }
        
        for(int i=0;i<h.size();i++){
            int currh = h[i];
            while(!pq.empty()&&pq.top().first<currh){
                ans[pq.top().second] = i;
                pq.pop();
            }
            auto currqueries = mp[i];
            for(auto it:currqueries){
                cout<<it.first<<endl;
                pq.push(it);
            }
        }
        return ans;
    }
};