class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int n = str1.length(), m = str2.length();
        
        int [][]dp = new int[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j] = 0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int temp1=0, temp2=0;
                if(str1.charAt(i-1)==str2.charAt(j-1)){
                    temp1 = 1 + dp[i-1][j-1];
                }else{
                    temp2 = Math.max(dp[i][j-1], dp[i-1][j]);
                }
                dp[i][j] = Math.max(temp1, temp2);
            }
        }
        String temp = "";
        int i = n, j = m;
        while(i>0 && j>0){
            if(str1.charAt(i-1)==str2.charAt(j-1)){
                temp+=str1.charAt(i-1);
                i--;
                j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    temp+=str1.charAt(i-1);
                    i--;
                    
                }else{
                    temp+=str2.charAt(j-1);
                    j--;
                }
            }
        }
        while(i>0){
            temp+=str1.charAt(i-1);
            i--;
        }
        while(j>0){
            temp+=str2.charAt(j-1);
            j--;
        }

        String ans = new StringBuilder(temp).reverse().toString();
        return ans;
        
    }
}