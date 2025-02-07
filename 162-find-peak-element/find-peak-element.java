class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        int lo = 0, hi = n-1;
        if(nums.length==1) return 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(mid>0 && mid<n-1) {
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    return mid;
                }else if(nums[mid-1]>nums[mid]){
                    hi = mid-1;
                }else if(nums[mid+1]>nums[mid]){
                    lo = mid+1;
                }
            }else if(mid==0){
                if(nums[0]>nums[1]){
                    return 0;
                }else{
                    return 1;
                }
            }else if(mid==n-1){
                return n-1;
            }
        }
        return -1;
    }
}