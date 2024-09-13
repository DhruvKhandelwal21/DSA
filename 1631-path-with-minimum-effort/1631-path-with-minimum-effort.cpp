class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        // dist[0][0] = 0;
        priority_queue<p,vector<p>, greater<p>> pq;
        pq.push({0,{0,0}});
        vector<int> x = {-1, 0, 1, 0};
        vector<int> y = {0, 1, 0, -1};
        
        while(!pq.empty()){
            auto cell = pq.top();
            pq.pop();
            pair<int,int> celloc = cell.second;
            int celldist = cell.first;
            for(int i=0;i<4;i++){
                int prevx = celloc.first;
                int prevy = celloc.second;
                int currx = prevx + x[i];
                int curry = prevy + y[i];
                if(currx>=0 && currx<n && curry>=0 && curry<m){
                    int curreffort = max(celldist, abs(heights[currx][curry] - heights[prevx][prevy]));
                    if(curreffort<dist[currx][curry]){
                      dist[currx][curry] = curreffort;
                      pq.push({curreffort, {currx, curry}});  
                    }
                }
            }
        }
     return dist[n-1][m-1]==INT_MAX ? 0 : dist[n-1][m-1];
    }
};