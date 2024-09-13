//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) { 
         if(grid[destination.first][destination.second]==0) return -1;
         if(source==destination) return 0;

        queue<pair<int,pair<int,int>>> q;
        q.push({0, source});
        vector<int> x = {-1, 0, 1, 0};
        vector<int> y = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[source.first][source.second] = 0;
        while(!q.empty()){
            auto cell = q.front();
            q.pop();
            pair<int,int> celloc = cell.second;
            int celldist = cell.first;
            for(int i=0;i<4;i++){
                int currx = x[i] + celloc.first;
                int curry = y[i] + celloc.second;
                if(currx>=0 && currx<n && curry>=0 && curry<m && grid[currx][curry]!=0){
                    if(dist[currx][curry]>celldist + 1){
                        dist[currx][curry] = celldist + 1;
                        q.push({dist[currx][curry], {currx, curry}});
                        if(currx==destination.first && curry==destination.second){
                            return dist[currx][curry];
                        }
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends