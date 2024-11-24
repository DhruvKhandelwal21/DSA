//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S1 = read.readLine().trim();
            String S2 = read.readLine().trim();

            Solution ob = new Solution();
            System.out.println(ob.longestCommonSubstr(S1, S2));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    int ans = 0;
     int solveMem(int i, int j, String s1, String s2, int [][] dp){
        if(i <0 || j <0){
            return 0;
        }
        if(dp[i][j] != - 1){
            return dp[i][j];
        }
        int take = 0;
        if(s1.charAt(i) == s2.charAt(j)){
            take = 1 + solveMem(i-1,j-1,s1,s2,dp);
            ans = Math.max(ans,take);
        }
        int nontake1 = solveMem(i-1,j,s1,s2,dp);
        int nontake2 = solveMem(i,j-1,s1,s2,dp);
        return dp[i][j] = take;
    }
    public int longestCommonSubstr(String s1, String s2) {
       int n = s1.length();
        int m = s2.length();
        
        int [][] dp = new int[n+1][m+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        solveMem(n-1, m-1, s1, s2, dp);
        return ans;
    }
}