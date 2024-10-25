class Solution {
public:
    class DisjointSet {
	    
	    public:
        vector<int> rank, parent, size;
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
	};
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(1000);
        unordered_map<int,unordered_set<int>> mp;
        for(int i=0;i<equations.size();i++){
            string temp = equations[i];
            int node1 = temp[0]-'a';
            int node2 = temp[3]-'a';
        
            if(temp[1]=='='){
                // ds.unionBySize(node1, node2);
                ds.parent[ds.findUpar(node1)] = ds.findUpar(node2);
            }
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