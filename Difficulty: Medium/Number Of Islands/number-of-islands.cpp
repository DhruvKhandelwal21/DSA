//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet {
	    vector<int> rank, parent, size;
	    public:
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
	          
	          if(size[parU]>size[parV]){
	              parent[parV] = parU;
	          } else if(size[parU]<size[parV]){
	              parent[parU] = parV;
	          }else {
	              parent[parU] = parV;
	              size[parV]+=size[parU];
	          }
	      }
	};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
       vector<vector<int>> vis(n,vector<int> (m,0));
       DisjointSet ds(m*n);
       int ans = 0;
       vector<int> res;
       vector<int> p = {-1,0,1,0};
       vector<int> q = {0,1,0,-1};
       for(int i=0;i<operators.size();i++){
           int x = operators[i][0];
           int y = operators[i][1];
           if(vis[x][y]==1){
             res.push_back(ans);
             continue;
           }
           vis[x][y] = 1;
           ans++;
           for(int j=0;j<4;j++){
               int adjx = x + p[j];
               int adjy = y + q[j];
               if(adjx>=0 && adjx<n && adjy>=0 && adjy<m){
                   int node = m*x +y;
                   int adjnode = m*adjx + adjy;
                   if(vis[adjx][adjy]==1 && ds.findUpar(node)!=ds.findUpar(adjnode)){
                       ds.unionBySize(node, adjnode);
                       ans--;
                   }
               }
           }
           res.push_back(ans);
       }
       return res; 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends