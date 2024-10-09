class Solution {
public:
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
         int n = edges.size();
         vector<int> currPar(n+1,-1);
        int ansByIndegree = -1;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(currPar[v]!=-1){
                ansByIndegree = i;
            }else{
                currPar[v] = u;
            }
        }
        DisjointSet ds(n);
        int ansByRoot = -1;
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(ansByIndegree==i) continue;
            if(ds.findUpar(u)==ds.findUpar(v)){
                ansByRoot = i;
            }else {
                ds.unionBySize(v,u);
            }
        }
         if (ansByIndegree == -1) {
            return edges[ansByRoot];
        } 
        else {
            if (ansByRoot != -1) {
                return {currPar[edges[ansByIndegree][1]], edges[ansByIndegree][1]};
            } else {
                return edges[ansByIndegree];
            }
        }
        return {};
    }
};
