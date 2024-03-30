class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int> temp,int curr,int n,int k){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i=curr;i<=n;i++){
            temp.push_back(i);
            solve(ans,temp,i+1,n,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,1,n,k);
        return ans;
    }
};