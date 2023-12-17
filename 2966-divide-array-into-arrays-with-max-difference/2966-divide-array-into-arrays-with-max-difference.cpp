class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> finalans;
        int n = nums.size();
        for(int i=0;i<n;i = i+3){
            if((nums[i+2]<=nums[i]+k)&&(nums[i+2]<=nums[i+1]+k)){
                vector<int> ans(3,0);
                ans[0] = nums[i];
                ans[1] = nums[i+1];
                ans[2] = nums[i+2];
                finalans.push_back(ans);
            }else{
                return vector<vector<int>>();
            }
        }
        return finalans;
    }
};