class Solution {
    public void nextPermutation(int[] nums) {
        int lastHigh= -1;
        int i=1;
        while(i<nums.length){
            if(nums[i]>nums[i-1]){
                lastHigh = i;
            }
            i++;
        }
        if(lastHigh==-1){
            Arrays.sort(nums);
            return;
        }
        int secHigh = lastHigh-1, pos = lastHigh;
        for(int k=lastHigh;k<nums.length;k++){
            if(nums[k]>nums[secHigh] && nums[k]<nums[lastHigh]){
              pos = k;
            }
        }
        System.out.println(secHigh);
        int temp = nums[secHigh];
                nums[secHigh] = nums[pos];
                nums[pos] = temp;
        Arrays.sort(nums, lastHigh, nums.length);
    }
}