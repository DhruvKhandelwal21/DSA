class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        int fresh = 0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){ 
                    q.push({i,j});
                }else if(grid[i][j]==1) {
                    fresh++;
                }
            }
        }
        vector<int> x = {-1,0,1,0};
        vector<int> y = {0,-1,0,1};
        int minutes = -1;
        if(fresh == 0) return 0;
        if(q.empty()) return -1;
       
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto cell = q.front();
                q.pop();
                int currx = cell.first;
                int curry = cell.second;
                for(int j=0;j<4;j++){
                  int a = x[j]+ currx ;
                    int b = y[j] + curry;
                    if(a<n && a>=0 && b<m && b>=0 && grid[a][b] == 1){
                        grid[a][b] = 2;
                        fresh--;
                        q.push({a, b});
                    }
                }
            }
            minutes++;
        }
      
        return fresh==0 ? minutes : -1;
    }
};