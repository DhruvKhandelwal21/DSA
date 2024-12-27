//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        priority_queue<pair<double,int>> pq;
        int n = val.size();
        for(int i=0;i<val.size();i++){
            double temp = (double)val[i]/wt[i];
            pq.push({temp, i});
        }
        double ans = 0;
        while(!pq.empty() && capacity>0){
            auto tempVal = pq.top();
            int idx = tempVal.second;
            pq.pop();
            int value = val[idx];
            int weight = wt[idx];
            if(weight<=capacity){
                ans+=value;
                capacity-=weight;
            }else{
                ans += tempVal.first * capacity;
                capacity=0;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends