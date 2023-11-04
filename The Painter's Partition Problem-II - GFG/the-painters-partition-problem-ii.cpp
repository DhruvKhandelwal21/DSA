//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    int solve(int arr[],int mid,int n,int k){
        int cnt = 1;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }else{
                sum = arr[i];
                cnt++;
            }
        }
        if(cnt<=k) return true;
        return false;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long lo = *max_element(arr,arr+n);
        long long hi = 0;
        for(int i=0;i<n;i++){
            hi+=arr[i];
        }
        while(lo<=hi){
            in mid = hi + (lo-hi)/2;
            if(solve(arr,mid,n,k)){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return lo;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends