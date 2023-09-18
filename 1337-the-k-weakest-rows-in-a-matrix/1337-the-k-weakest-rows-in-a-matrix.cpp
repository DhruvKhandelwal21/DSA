class Solution {
public:
    typedef pair<int,int> p;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<p,vector<p>,greater<p>> pq;
        int m = mat.size();
        int n = mat[0].size();
            vector<int> ans;
            
        for(int i=0;i<m;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            pq.push({count,i});
        }
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};