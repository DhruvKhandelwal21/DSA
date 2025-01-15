class Solution {
    public void nextPermutation(int[] nums) {
        int lastHigh = Integer.MAX_VALUE;

        int i = 1, n = nums.length;
        while (i < n) {
            if (nums[i] > nums[i - 1]) {
                lastHigh = i;
            }
            i++;
        }
        if (lastHigh == Integer.MAX_VALUE) {
            Arrays.sort(nums);
            return;
        }
        int pos = lastHigh;
        for (int k = lastHigh; k < n; k++) {
            if (nums[lastHigh - 1] < nums[k] && nums[k] < nums[lastHigh]) {
                pos = k;
            }
        }
 
        int temp = nums[lastHigh - 1];
        nums[lastHigh - 1] = nums[pos];
        nums[pos] = temp;
        Arrays.sort(nums, lastHigh, nums.length);
    }
}