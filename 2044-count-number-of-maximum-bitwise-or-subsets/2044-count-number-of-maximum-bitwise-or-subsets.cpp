class Solution {
public:
    int solve(vector<int> &nums, int idx, int curr,int maxor){
        if(idx<0){
            return maxor==curr;
        }
        int ans1 = solve(nums,idx-1,curr|nums[idx],maxor);
        int ans2=  solve(nums,idx-1,curr,maxor);
        
        return ans1+ans2;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxor = 0;
        for(auto it:nums){
            maxor|=it;
        }
        int maxi = solve(nums,n-1,0,maxor);
        return maxi;
    }
};