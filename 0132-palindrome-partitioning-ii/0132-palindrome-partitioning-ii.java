class Solution {
    public static boolean isPal(int i, int j, String s){
        while(i<j){
            if(s.charAt(i)!=s.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }
    public int minCut(String s) {
        int n = s.length();
        int []dp = new int[n+1];
        Arrays.fill(dp,-1);
        
        for(int i=n-1;i>=0;i--){
            int temp = Integer.MAX_VALUE;
            for(int j=i;j<n;j++){
                if(isPal(i,j,s)){
                    int partitions = 1 + dp[j+1];
                    temp = Math.min(temp, partitions);
                }
            }
            dp[i] = temp;
        }
        return dp[0];
        
    }
}