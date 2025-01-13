class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        int i = 0, k = 0, j = n - 1;
        while (k <= j) {
            if (nums[k] == 1) {
                k++;
            } else if (nums[k] == 0) {
                int temp = nums[k];
                nums[k] = nums[i];
                nums[i] = temp;
                i++;
                k++;
            } else if (nums[k] == 2) {
                int temp = nums[k];
                nums[k] = nums[j];
                nums[j] = temp;
                j--;
            }
        }
        return;
    }
}