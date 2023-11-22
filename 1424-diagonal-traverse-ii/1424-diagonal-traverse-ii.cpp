class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> mp;
        vector<int> ans;
        int maxSum = INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                int sum = i + j;
                mp[sum].push_back(nums[i][j]);
                maxSum = max(sum,maxSum);
            }
        }
        for(int i=0;i<=maxSum;i++){
            vector<int> temp = mp[i];
            int n = temp.size();
            for(int i=n-1;i>=0;i--){
                ans.push_back(temp[i]);
            }
        }
        
        return ans;
    }
};