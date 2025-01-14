class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int []ans = new int[n];
        int idxPos = 0, idxNeg = 1;
        for(int i=0;i<n;i++){
          if(nums[i]<0 && idxNeg<n){
            ans[idxNeg] = nums[i];
            idxNeg+=2;
          }else if(nums[i]>=0&& idxPos<n){
            ans[idxPos] = nums[i];
            idxPos+=2;
          }
        }
        return ans;
    }
}