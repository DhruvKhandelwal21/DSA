class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
         int n = arr.size();

        int maxi = *max_element(arr.begin(), arr.end());
        if(k>maxi) return maxi; // if k is greater than maxi that means the array was rotated and maximum element comes at index 0.
        
        int winner = arr[0], cnt = 0;
        for(int i=0;i<n-1;i++)
        {
            if(winner > arr[i+1])
            {
                cnt++;
            }
            else{
                winner = arr[i+1];
                cnt = 1;
            }
            if(winner == maxi) return maxi; // in case if winner == maxi than no one can replace maxi, so simply return it
            if(cnt == k) return winner; // else when cnt == k return the winner
        }
        return -1;
    }
};