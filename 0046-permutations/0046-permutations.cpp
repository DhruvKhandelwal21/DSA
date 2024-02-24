class Solution
{
    public:
        void solve(vector<int> &nums, vector<vector< int >> &ans, unordered_set<int> &st,vector<int> &temp, int n)
        {
            if (st.size() == n)
            {
                ans.push_back(temp);
                return;
            }
            
            for (int i = 0; i < n; i++) {
                if(st.find(nums[i])==st.end()){
                    st.insert(nums[i]);
                    temp.push_back(nums[i]);
                    solve(nums,ans,st,temp,n);
                    st.erase(nums[i]);
                    temp.pop_back();
                }
            }
            return;
        }
    vector<vector < int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector < int>> ans;
        vector<int> temp;
        unordered_set<int> st;
        solve(nums, ans, st, temp, n);
        return ans;
    }
};