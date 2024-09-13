class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> v(n);
        vector<int> ans(queries.size());
        v[0] = arr[0];
      for(int i=1;i<arr.size();i++){
          v[i] = arr[i]^v[i-1];
      }
     for(int i=0;i<queries.size();i++){
         int idx1 = queries[i][0];
         int idx2 = queries[i][1];
         if(idx1==0){
             ans[i] = v[idx2];
         }else {
             ans[i] = v[idx2]^v[idx1-1];
         }
     }
    return ans;
    }
};