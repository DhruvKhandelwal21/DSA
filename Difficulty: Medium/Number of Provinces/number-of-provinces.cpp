//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
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
    void dfs(int node, vector<vector<int>> &graph, vector<int> &vis){
        vis[node] = 1;
        for(auto it: graph[node]){
            if(!vis[it]){
                dfs(it, graph, vis);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // DisjointSet ds(V);
        int n = adj.size();
        int m = adj[0].size();
        int mx = max(n,m);
        vector<vector<int>> graph(mx);
        vector<int> vis(mx,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(adj[i][j]==1 && i!=j){
                    graph[i].push_back(j);
                }
            }
        }
        
        for(int i=0;i<mx;i++){
            if(!vis[i]){
                dfs(i,graph,vis);
                cnt++;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends