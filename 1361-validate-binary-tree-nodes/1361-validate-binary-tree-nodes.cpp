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
	      
	      bool unionBySize(int u, int v){
	          int parU = findUpar(u);
	          int parV = findUpar(v);
	          if(parU==parV) return false;
	          
	          if(size[parU]>size[parV]){
	              parent[parV] = parU;
	          } else if(size[parU]<size[parV]){
	              parent[parU] = parV;
	          }else {
	              parent[parU] = parV;
	              size[parV]+=size[parU];
	          }
              return true;
	      }
	};
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DisjointSet ds(n);   
        vector<int> parentCnt(n,0);
        for(int i=0;i<n;i++){
            int left = leftChild[i];
            int right = rightChild[i];
           if(left!=-1){
               parentCnt[left]++;
               if( parentCnt[left]>1 || !ds.unionBySize(left,i)){
                  return false; 
               }
           }
           if(right!=-1){
               parentCnt[right]++;
               if( parentCnt[right]>1 || !ds.unionBySize(right,i)){
                  return false; 
               }
           }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(i==ds.findUpar(i)) cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
};