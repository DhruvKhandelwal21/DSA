class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int idx = 0;
        int n = nums.size();
        int ans = 0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                cnt++;
            }else{
                ans+=cnt*idx;
                idx++;
                cnt = 1;
            }
        }
        ans+=idx*cnt;
        return ans;
        
    }
};