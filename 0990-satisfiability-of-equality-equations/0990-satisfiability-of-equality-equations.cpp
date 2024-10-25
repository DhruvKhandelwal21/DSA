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
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(1000);
        unordered_map<int,unordered_set<int>> mp;
        for(int i=0;i<equations.size();i++){
            string temp = equations[i];
            int node1 = temp[0]-'a';
            int node2 = temp[3]-'a';
        
            if(temp[1]=='='){
                ds.unionBySize(node1, node2);
            }
            // if(temp[1]=='='){
            //     if(temp=="e==b"){
            //         cout<<pNode1<<" "<<pNode2<<endl;
            //     }
            // if(mp[pNode1].count(pNode2) || mp[pNode2].count(pNode1) ) return false;
            //     ds.unionBySize(node1, node2);
            // }else{
            //     if(ds.findUpar(node1)==ds.findUpar(node2)){
            //         return false;
            //     }else {
            //         mp[pNode1].insert(pNode2);
            //         mp[pNode2].insert(pNode1);
            //     }
            // }
        }
        for(int i=0;i<equations.size();i++){
            string temp = equations[i];
            int node1 = temp[0]-'a';
            int node2 = temp[3]-'a';
            if(temp[1]=='!'){
                if(ds.findUpar(node1)==ds.findUpar(node2)) return false;
            }
        }
        return true;
    }
};