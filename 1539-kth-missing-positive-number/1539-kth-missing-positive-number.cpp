class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int hi = n-1;
        int lo = 0;
        while(lo<=hi){
            int mid = hi + (lo-hi)/2;
            int missing = arr[mid] - (mid+1);
            if(missing<k){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        
        return hi + 1 + k;
        
    }
};