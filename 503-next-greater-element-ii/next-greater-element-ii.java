class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer> st = new Stack<>();
        int []ans = new int[nums.length];
        for(int i=nums.length-1;i>=0;i--){
            if(st.isEmpty()){
                ans[i] = Integer.MIN_VALUE;
            }else{
                while(!st.isEmpty() && st.peek()<=nums[i]){
                    st.pop();
                }
                if(st.isEmpty()){
                    ans[i] = Integer.MIN_VALUE;
                }else{
                    ans[i] = st.peek();
                }
            }
            st.push(nums[i]);
        }
        for(int i=0;i<nums.length;i++){
            if(ans[i]==Integer.MIN_VALUE){
                for(int j=0;j<i;j++){
                    if(nums[j]>nums[i]){
                        ans[i] = nums[j];
                        break;
                    }
                }
                if(ans[i]==Integer.MIN_VALUE) ans[i] = -1;
            }
        }
        return ans;
    }
}