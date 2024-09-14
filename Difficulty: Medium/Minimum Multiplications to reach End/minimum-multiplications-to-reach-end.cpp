//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  typedef pair<int,int> p;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end) return 0;
        queue<int> q;
        vector<int> v(100000,0);
        v[start] = 1;
        q.push(start);
        
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            cnt++;
            while(n>0){
                int node = q.front();
                q.pop();
            for(int i=0;i<arr.size();i++){
                int dist = (node*arr[i])%100000;
                if(dist==end){
                    return cnt;
                }
                if(!v[dist]){
                    v[dist] = 1;
                    q.push(dist);
                }
             }
             n--;
            }
           
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends