class Solution
{
    public:
        void solve(vector<int> &nums, vector<vector< int >> &ans, vector<int> &temp, int idx, int n)
        {
            if (idx == n)
            {
                ans.push_back(nums);
                return;
            }
            
            for (int i = idx; i < n; i++) {
                   swap(nums[i],nums[idx]);
                   solve(nums,ans,temp,idx+1,n);
                   swap(nums[idx],nums[i]);
                
            }
            return;
        }
    vector<vector < int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector< int >> ans;
        vector<int> temp;
        solve(nums, ans, temp, 0, n);
        return ans;
    }
};