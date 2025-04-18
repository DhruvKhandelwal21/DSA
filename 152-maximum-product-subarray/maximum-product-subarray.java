class Solution {
    public int maxProduct(int[] nums) {
        int ans = Integer.MIN_VALUE;
        int prod = 1;
        for(int i=0;i<nums.length;i++){
            if(prod==0){
                prod = 1;
            }
            prod*=nums[i];
            ans = Math.max(ans, prod);
        }
        prod = 1;
        for(int i=nums.length-1;i>=0;i--){
            if(prod==0){
                prod = 1;
            }
            prod*=nums[i];
            ans = Math.max(ans, prod);
        }
        return ans;
    }
}