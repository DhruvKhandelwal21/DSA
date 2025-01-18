class Solution {
    int applyBinarySearch(int[] nums, int l, int h, int target) {
        int lo = l, hi = h;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }

    public int search(int[] nums, int target) {
        int n = nums.length;
        int lo = 0, hi = nums.length - 1;
        int smallestIdx = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[lo] <= nums[hi]) {
                smallestIdx = lo;
                break;
            }
            if (nums[(mid + n - 1) % n] >= nums[mid] && nums[(mid + 1) % n] >= nums[mid]) {
                smallestIdx = mid;
                break;
            }
            if (nums[mid]<=nums[lo]) {
                hi = mid;
            }else if(nums[hi] < nums[mid]){
                lo = mid+1;
            }
        }
    
        if(nums[smallestIdx]==target) return smallestIdx;
        int p1 = applyBinarySearch(nums, 0, smallestIdx - 1, target);
        int p2 = applyBinarySearch(nums, smallestIdx + 1, nums.length - 1, target);
        if (p1 != -1)
            return p1;
        if (p2 != -1)
            return p2;
        return -1;
    }
}