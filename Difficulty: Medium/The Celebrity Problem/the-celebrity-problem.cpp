//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int i=0, j = n-1;
        int celeb = -1;
        while(i<j){
            if(mat[i][j]==1){
                i++;
            } else if(mat[j][i]==1){
                j--;
            }else{
                i++;
                j--;
            }
        }
        if(i>j) return -1;
        for(int idx= 0;idx<n;idx++){
            if(idx==i) continue;
            if(mat[idx][i]==0 || mat[i][idx]==1) return -1;
        }
        return i;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends