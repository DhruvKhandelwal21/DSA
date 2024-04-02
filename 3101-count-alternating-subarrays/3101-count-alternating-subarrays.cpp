class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans=  0;
        int i=0,j=1;
        int n = nums.size();
        while(j<n){
            if(nums[j]==nums[j-1]){
                long long len = j-i;
                long long temp = (len*(len+1))/2;
                ans+=temp;
                i = j;
            }
            j++;
        }
        long long extralen = n-i;
        long long extra = (extralen*(extralen+1))/2;
        ans+=extra;
        
        return ans;
    }
};