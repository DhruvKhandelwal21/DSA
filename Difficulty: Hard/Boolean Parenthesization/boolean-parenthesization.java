//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int N = Integer.parseInt(in.readLine());
            String S = in.readLine();
            
            Solution ob = new Solution();
            System.out.println(ob.countWays(N, S));
        
System.out.println("~");
}
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int MOD = 1003;
    public static int solve(String s, int i, int j, boolean val, int [][]dpT, int [][]dpF){
    
        if(i==j){
            if(val==true){
                return s.charAt(i) == 'T' ? 1 : 0;
            } else{
                return s.charAt(i) == 'F' ? 1 : 0;
            }
        }
        int ans = 0;
        if(val){
            if(dpT[i][j]!=-1){
                return dpT[i][j];
            }
        }else{
            if(dpF[i][j]!=-1){
                return dpF[i][j];
            }
        }
        for(int k=i+1;k<j;k+=2){
            int tLeft = solve(s, i,k-1, true, dpT, dpF);
            int tRight = solve(s, k+1,j, true, dpT, dpF);
            int fLeft = solve(s, i,k-1, false, dpT, dpF);
            int fRight = solve(s, k+1,j, false, dpT, dpF);
            if(s.charAt(k)=='^'){
               if(val){
                ans = (ans + (tLeft*fRight) + (tRight*fLeft))%MOD;   
               }else {
                ans = (ans + (tLeft*tRight) + (fLeft*fRight))%MOD;
               }
            }else if(s.charAt(k)=='|'){
                if(val){
                    ans = (ans + (tLeft*tRight) + (tLeft*fRight) + (tRight*fLeft))%MOD;
                }else {
                    ans = (ans + (fLeft*fRight))%MOD;
                }
            }else if(s.charAt(k)=='&'){
                if(val){
                    ans = (ans + (tLeft*tRight))%MOD;
                }else {
                 ans = (ans + (fLeft*fRight) + (tLeft*fRight) + (tRight*fLeft))%MOD;   
                }
            }
        }
        if (val) {
    return dpT[i][j] = ans%MOD;
} 
  
    return dpF[i][j] = ans%MOD;
    }
    static int countWays(int n, String s){
        int [][] dpT = new int[n+1][n+1];
        int [][] dpF = new int[n+1][n+1];
        for (int[] row : dpT) {
            Arrays.fill(row, -1);
         }
        for (int[] row : dpF) {
            Arrays.fill(row, -1);
        }
        return solve(s, 0, n-1, true, dpT, dpF);
    }
}