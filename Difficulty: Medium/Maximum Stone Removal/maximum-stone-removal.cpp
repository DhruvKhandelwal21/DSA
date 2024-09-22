//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet {
	    vector<int> rank, parent, size;
	    public:
	      DisjointSet(int n){
	          rank.resize(n+1,0);
	          size.resize(n+1);
	          parent.resize(n+1);
	          for(int i=0;i<=n;i++){
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
    int maxRemove(vector<vector<int>>& stones, int k) {
        int n=0,m=0;
      for(int i=0;i<k;i++){
          int x = stones[i][0];
          int y = stones[i][1];
          n = max(n,x);
          m = max(m,y);
      }
      DisjointSet ds(n+m+1);
      unordered_map<int,int> mp;
      for(int i=0;i<k;i++){
          int node1 = stones[i][0];
          int node2 = stones[i][1]+n+1;
          ds.unionBySize(node1, node2);
          mp[node1] = 1;
          mp[node2] = 1;
      }
      
      int cnt = 0;
      for(auto it: mp){
          if(ds.findUpar(it.first)==it.first) cnt++;
      }
      
    //   unordered_map<int,int> mp;
    //   int totalNodes = n+m+1;
    //   for(int i=0;i<totalNodes;i++){
    //       mp[ds.findUpar(i)]++;
    //   }
    //   int cnt = 0;
    //   for(auto it: mp){
    //       if(it.second>=2){
    //           cout<<it.first<<" "<<it.second<<endl;
    //           cnt++;
    //       }
    //   }
      return k-cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends