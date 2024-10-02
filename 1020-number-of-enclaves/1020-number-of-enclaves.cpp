class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(i==n-1 || j==m-1 || i==0 || j==0) {
                    if(grid[i][j]==1){
                        q.push({i,j});
                        grid[i][j] = 0;
                    }
                }
            }
        }
        vector<int> u = {-1,0,1,0};
        vector<int> v = {0,-1,0,1};
        
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int currx = x+u[i];
                int curry = y+v[i];
            if(currx>=0 && curry>=0 && currx<n && curry<m && grid[currx][curry]){
                    grid[currx][curry] = 0;
                    q.push({currx,curry});
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]) cnt++;
            }
        }
        return cnt;
    }
};