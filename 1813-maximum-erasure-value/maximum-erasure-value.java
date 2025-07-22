class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int i=0,j=0;
        int n = nums.length;
        Set<Integer> set = new HashSet<>();
        int sum = 0, ans=0;
        while(j<n){
            if(set.contains(nums[j])){
                while(set.contains(nums[j])){
                    set.remove(nums[i]);
                    sum-=nums[i];
                    i++;
                }
            }
            set.add(nums[j]);
            sum+=nums[j];
            ans = Math.max(sum, ans);
            j++;
        }
        return ans;
    }
}