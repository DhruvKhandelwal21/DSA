class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0],secondmaxi = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>=maxi){
                secondmaxi = maxi;
                maxi = nums[i];    
            }else{
                secondmaxi = max(secondmaxi,nums[i]);
            }
        }
        
        return (maxi-1)*(secondmaxi-1);
        
    }
};