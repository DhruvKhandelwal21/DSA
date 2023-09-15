class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> visited(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        int ans = 0;
        pq.push({0,0});
        while(!pq.empty()){
            auto edge = pq.top();
            pq.pop();
            int cost = edge.first;
            int u = edge.second;
            if (visited[u]) {
                continue;
            }
            ans+=cost;
            visited[u] = true;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                     int dist = abs(points[u][0]-points[i][0]) + abs(points[u][1]-points[i][1]);
                if(mp.find(i)==mp.end()||dist<mp[i]){
                    mp[i] = dist;
                    pq.push({dist,i});
                }
                }
               
            }
        }
        return ans;
    }
};