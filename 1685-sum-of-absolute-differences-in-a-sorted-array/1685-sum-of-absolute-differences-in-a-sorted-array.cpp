class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        
        int presum = nums[0];
        int sufsum = nums[n-1];
        for(int i=1;i<n;i++){
           presum+=nums[i];
            ans[i]+=abs(presum-(i+1)*nums[i]);
        }
        for(int i = n-2;i>=0;i--){
            sufsum+=nums[i];
            ans[i]+=abs(sufsum-(n-i)*nums[i]);
        }
        return ans;
    }
};