class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        
        int i=0,j=n-1,k=n-1;
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                ans[k--] = pow(nums[i],2);
                i++;
            }else{
                ans[k--] = pow(nums[j],2);
                j--;
            }
        }
        return ans;
    }
};