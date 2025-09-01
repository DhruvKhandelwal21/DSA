class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int n = str1.length();
        int m = str2.length();
        int [][]dp = new int[n+1][m+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) dp[i][j] = 0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1.charAt(i-1)==str2.charAt(j-1)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int p = n;
        int q = m;

        StringBuilder ans = new StringBuilder("");
        while(p>0 && q>0){
            if(str1.charAt(p-1)==str2.charAt(q-1)){
                ans.append(str1.charAt(p-1));
                p--;
                q--;
            }else if(dp[p][q-1]<dp[p-1][q]){
                ans.append(str1.charAt(p-1));
                p--;
            }else{
                ans.append(str2.charAt(q-1));
                q--;
            }
        }
        while(p>0){
            ans.append(str1.charAt(p-1));
            p--;
        }
        while(q>0){
            ans.append(str2.charAt(q-1));
            q--;
        }
        String temp = ans.reverse().toString();
        return temp; 
    }
}