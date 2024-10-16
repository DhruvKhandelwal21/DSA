class Solution
{
    public:
    vector<int> x= {-1,0,1,0};
    vector<int> y = {0,-1,0,1};
//     bool solve(vector<vector < int>> &grid, vector< vector< int>> vis, int health, int i, int j, int n, int m)
//     {
//         if(grid[i][j]==1){
//             health--;
//         }
//         if(health<=0){
//             return false;
//         }

//         if (i == n - 1 && j == m - 1){ 
//             return true;
//         }
        
//         vis[i][j] = 1;
//         bool ans = false;
//         for (int k = 0; k < 4; k++)
//         {
//             int currx = i + x[k];
//             int curry = j + y[k];
//             bool temp = false;
//             if (currx >= 0 && currx < n && curry >= 0 && curry < m && health > 0 && !vis[currx][curry])
//             {
//                 temp = solve(grid, vis, health, currx, curry, n, m);
//             }
//             if (temp) return true;
//             ans |= temp;
//         }
//         return ans;
//     }
    typedef pair<int, pair<int,int>> p;
    bool findSafeWalk(vector<vector < int>> &grid, int health)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector < int>> vis(n, vector<int> (m, 0));
        priority_queue<p> pq;
        pq.push({health, {0,0}});
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int currHealth = node.first;
            auto currNode = node.second;
            
            int a = currNode.first;
            int b = currNode.second;
            
            if(grid[a][b]==1) currHealth--;
            if(currHealth<=0 || vis[a][b]==1){ 
                continue;
            }
            if(a==n-1 && b==m-1) return true;
           vis[a][b] = 1;
            for(int i=0;i<4;i++){
                int currx = a + x[i];
                int curry = b + y[i];
                // if(currx==n-1 && curry==m-1){ 
                //     cout<<currHealth<<endl;
                //     return true;
                // }
                if(currx >= 0 && currx < n && curry >= 0 && curry < m && currHealth > 0){
                    pq.push({currHealth, {currx, curry}});
                }
            }
        }
        return false;
    }
};