//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int N = sc.nextInt();
            int[][] arr = new int[N][3];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < 3; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }
            Solution obj = new Solution();
            int res = obj.maximumPoints(arr, N);
            System.out.println(res);
        
System.out.println("~");
}
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int solve(int arr[][], int currIdx, int avt, int n, int [][] dp){
        if(currIdx>=n) return 0;
        if(dp[currIdx][avt]!=-1) return dp[currIdx][avt];
        int ans = Integer.MIN_VALUE;
        for(int i=0;i<3;i++){
            if(i!=avt){
             int temp = arr[currIdx][i] + solve(arr, currIdx+1, i, n, dp); 
             ans = Math.max(ans, temp);
            }
        }
        return dp[currIdx][avt]= ans;
    }
    public int maximumPoints(int arr[][], int N) {
        int ans = Integer.MIN_VALUE;
        int [][] dp = new int[N][3];
        for(int i=0;i<N;i++){
            Arrays.fill(dp[i],-1);
        }
        for(int i=0;i<3;i++){
            ans = Math.max(ans, arr[0][i] + solve(arr,1,i,N, dp));
        }
        return ans;
    }
}