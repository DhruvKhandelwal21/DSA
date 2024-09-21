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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int v = accounts.size();
        DisjointSet ds(v);
        vector<vector<string>> ans;
        unordered_map<string,int> mp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                   mp[accounts[i][j]] = i; 
                }else{
                    ds.unionBySize(mp[accounts[i][j]],i);
                } 
            }
        }
        for(int i=0;i<v;i++){
        if(ds.findUpar(i)==i){
            vector<string> temp;
           for(auto it: mp){
                if(it.second==i || ds.findUpar(it.second)==i){
                    temp.push_back(it.first);
                }
            }
            sort(temp.begin(),temp.end());
            temp.insert(temp.begin(),accounts[i][0]);
            ans.push_back(temp);
        }
            
    }
        return ans;
    }
};