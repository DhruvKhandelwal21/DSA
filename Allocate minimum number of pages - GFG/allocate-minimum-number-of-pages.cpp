//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool check(int A[],int stud,int pages,int n){
        int cnt = 1;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(sum + A[i]<=pages){
                sum+=A[i];
            }else{
                cnt++;
                sum = A[i];
            }
            
        }
        if(cnt<=stud) return true;
        return false;
        
    }
    int findPages(int A[], int n, int m) 
    {
        if(m>n){
            return -1;
        }
          int lo = *max_element(A,A+n);
          int hi = 0;
          for(int i = 0;i<n;i++){
              hi+=A[i];
          }
          
          while(lo<=hi){
              int mid = hi + (lo-hi)/2;
              if(check(A,m,mid,n)){
                  hi = mid-1;
              }else{
                  lo = mid+1;
              }
          }
          return lo;
          
          
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends