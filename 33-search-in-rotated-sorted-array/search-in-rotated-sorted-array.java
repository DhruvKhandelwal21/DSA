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
            if(mid>0 && mid<nums.length-1){
if (nums[mid] < nums[mid-1] && nums[mid] < nums[mid + 1]) {
                smallestIdx = mid;
                break;
            } else if (nums[mid] < nums[lo]) {
                hi = mid - 1;
            } else if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            }
            }else{
                smallestIdx = mid;
                break;
            }
            
        }
        System.out.println(smallestIdx);
        if (nums[smallestIdx] == target)
            return smallestIdx;
        int p1 = applyBinarySearch(nums, 0, smallestIdx - 1, target);
        int p2 = applyBinarySearch(nums, smallestIdx + 1, nums.length - 1, target);
        if (p1 != -1)
            return p1;
        if (p2 != -1)
            return p2;
        return -1;
    }
}