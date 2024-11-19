//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {
    public int solve(int []arr, int idx, int k, int n, int []dp){
        if(idx==n-1){
            return Math.abs(arr[n-1]-arr[idx]);
        }
        if(dp[idx]!=-1) return dp[idx];
        int ans = 100000;
        for(int i=idx+1;i<=k+idx && i<n;i++){
            int temp = Math.abs(arr[idx]-arr[i]) + solve(arr, i, k, n, dp);
            ans = Math.min(ans, temp);
        }
        return dp[idx] = ans;
    }
    public int minimizeCost(int k, int arr[]) {
      int n = arr.length;
      int [] dp = new int[n+1];
      Arrays.fill(dp,-1);
      return solve(arr,0,k,n,dp);
    }
}


//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;
            Solution obj = new Solution();
            int res = obj.minimizeCost(k, arr);

            System.out.println(res);

            System.out.println("~");
        }
    }
}
// } Driver Code Ends