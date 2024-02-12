class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                cnt = 1;
            }else{
                cnt++;
            }
            if(cnt>n/2){
                return nums[i];
            }
            
        }
        return nums[0];
    }
};