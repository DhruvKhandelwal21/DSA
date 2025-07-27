class Solution {
    public int countHillValley(int[] nums) {
        int j=0;
        int n = nums.length;
        int cnt = 0;
        for(int i=1;i<n-1;){
            if((nums[i-1]<nums[i] && nums[i+1]<nums[i]) || (nums[i-1]>nums[i] && nums[i]<nums[i+1])){
                cnt++;
            }else if(nums[i]==nums[i+1]){
                j = i+1;
                while(nums[i]==nums[j] && j<n-1){
                    j++;
                }
                if((nums[i-1]<nums[i] && nums[j]<nums[i]) || (nums[i-1]>nums[i] && nums[i]<nums[j])){
                    cnt++;
                }
                i = j-1;
            }
            i++;
        }
        return cnt;
    }
}