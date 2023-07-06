class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        int mn = INT_MAX;
        int sum = 0;
        while(j<n){
            sum+=nums[j];
            if(sum>=target){
                while(sum>=target){
                     mn = min(mn,j-i+1);
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
            
        }
        return mn==INT_MAX?0:mn;
    }
};