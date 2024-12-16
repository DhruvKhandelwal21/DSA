//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second; // Sort by end time
}
    int maxMeetings(vector<int>& start, vector<int>& end) {
       vector<pair<int,int>> v;
       for(int i=0;i<start.size();i++){
           v.push_back({start[i], end[i]});
       }
       sort(v.begin(),v.end(), comparator);
       int maxTimeLimit = 0;
       int cnt=0;
       for(int i=0;i<v.size();i++){
           if(i==0 || v[i].first>maxTimeLimit){
               cnt++;
               maxTimeLimit = v[i].second;
           }
       }
       return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends