
class Solution {
    static void tempLis(int[] nums, int []prefix) {
        int n = nums.length;
          for (int i = 0; i < n; i++) {
            prefix[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && prefix[j] + 1 > prefix[i]) {
                    prefix[i] = prefix[j] + 1;
                }
            }
        }
    }
    
    public static int LongestBitonicSequence(int n, int[] nums) {
         int []prefix = new int[n];
         int []suffix = new int[n];
         Arrays.fill(prefix,1);
         Arrays.fill(suffix,1);
         
         for (int i = 0; i < n; i++) {
            prefix[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && prefix[j] + 1 > prefix[i]) {
                    prefix[i] = prefix[j] + 1;
                }
            }
        }
        
        for (int i = n-1; i>=0; i--) {
            for (int j = n-1; j > i; j--) {
                if (nums[i] > nums[j] && suffix[j] + 1 > suffix[i]) {
                    suffix[i] = suffix[j] + 1;
                }
            }
        }
         int ans = 0;
         for(int i=0;i<n;i++){
             if(prefix[i]>1 && suffix[i]>1){
              ans = Math.max(ans, suffix[i]+prefix[i]-1);   
             }
         }
         return ans;
    }
}
