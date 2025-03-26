//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet {
	    public:
	    vector<int> rank, parent, size;
	      DisjointSet(int n){
	          rank.resize(n+1,0);
	          size.resize(n+1);
	          parent.resize(n+1);
	          for(int i=0;i<n;i++){
	              parent[i] = i;
	              size[i] = 1;
	          }
	      }
	      int findUpar(int node){
	          if(node==parent[node]){
	              return node;
	          }
	          return parent[node] = findUpar(parent[node]);
	      }
	      
	      void unionByRank(int u, int v){
	          int parU = findUpar(u);
	          int parV = findUpar(v);
	          if(parU==parV) return;
	          
	          if(rank[parU]>rank[parV]){
	              parent[parV] = parU;
	          } else if(rank[parU]<rank[parV]){
	              parent[parU] = parV;
	          }else {
	              parent[parU] = parV;
	              rank[parV]++;
	          }
	      }
	      
	      void unionBySize(int u, int v){
	          int parU = findUpar(u);
	          int parV = findUpar(v);
	          if(parU==parV) return;
	          
	          if (parU == parV) return;
    
    if (size[parU] > size[parV]) {
        parent[parV] = parU;
        size[parU] += size[parV];  // Fix: Increase parent size
    } else {
        parent[parU] = parV;
        size[parV] += size[parU];  // Fix: Increase parent size
    }
	      }
	};
	
class Solution
{
public:
    bool isValid(int i,int j, int n, int m){
        return i >= 0 && j >= 0 && i < n && j < m; 
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        DisjointSet ds(n*n);
vector<int> u = {-1,0,1,0};
vector<int> v = {0,1,0,-1};
        bool allOne = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && allOne) allOne = false;
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int currx = i + u[k];
                    int curry = j + v[k];
                    if(isValid(currx, curry, n, n) && grid[currx][curry]==1){
                        int node1 = n*i + j;
                        int node2 = n*currx + curry;
                        ds.unionBySize(node1, node2);
                    }
                }
            }
        }
        
        if(allOne) return n*n;
        
        int mx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                 unordered_set<int> st;
                 int tempcnt = 0;
                for(int k=0;k<4;k++){
                    int currx = i + u[k];
                    int curry = j + v[k];
                    if(isValid(currx, curry, n, n) && grid[currx][curry]==1){
                        int node = ds.findUpar(n*currx + curry);
                        st.insert(node);
                    }
                }
                
                for(it: st){
                   tempcnt+=ds.size[it];
                }
                mx = max(mx, tempcnt);
            }
        }
        
        return mx+1;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends