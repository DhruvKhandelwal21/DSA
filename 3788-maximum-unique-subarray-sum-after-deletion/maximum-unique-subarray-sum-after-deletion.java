class Solution {
    public int maxSum(int[] nums) {
        int ans = 0;
        int n = nums.length;
        int sum = 0;
        HashSet<Integer> st = new HashSet<Integer>();
        for(int i=0;i<n;i++){
            st.add(nums[i]);
        }
        int mn = Integer.MIN_VALUE;
        for(Integer i: st){
            mn = Math.max(mn, i);
            if(i>=0) ans+=i;
        }
        return ans==0 && mn<0 ? mn : ans;
    }
}