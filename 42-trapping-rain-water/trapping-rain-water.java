class Solution {
    public int trap(int[] height) {
        int l = 0, r = height.length-1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>=lmax){
                    lmax = height[l];
                    l++;
                }else{
                    ans+=(lmax-height[l]);
                    l++;
                }
            } else {
                if(height[r]>=rmax){
                    rmax = height[r];
                    r--;
                }else{
                    ans+=(rmax-height[r]);
                    r--;
                }
            }
        }
        return ans;
    }
}