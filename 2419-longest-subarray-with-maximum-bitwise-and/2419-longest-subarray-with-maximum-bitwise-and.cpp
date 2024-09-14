class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int n = nums.size(), curr=0, len=1;
        for(int i=0;i<n;i++){
           if(nums[i]==mx){
               curr++;
               len = max(len,curr);
           }else{
               curr=0;
           }
        }
        return len;
    }
};