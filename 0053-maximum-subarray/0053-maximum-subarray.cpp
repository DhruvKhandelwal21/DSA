class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, mx = -1e8;
        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            if(currSum>mx){
                mx = currSum;
            }
            if(currSum<0){
                currSum = 0;
            }
        }
        return mx;
    }
};