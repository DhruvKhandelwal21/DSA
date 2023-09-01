class Solution {
public:
    bool solve(vector<int>& arr, int m, int k, int day){
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){
                cnt++;
            }else{
                ans+=(cnt/k);
                cnt = 0;
            }
        }
        ans+=(cnt/k);
        if(ans>=m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int hi = *max_element(bloomDay.begin(),bloomDay.end());
        int lo = *min_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        // long long pro = m*k;
        // if(bloomDay.size()<pro){
        //     return ans;
        // }
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(solve(bloomDay,m,k,mid)){
                hi = mid-1;
                ans = mid;
            }else{
                lo = mid+1;
            }
        }
        return ans;
        
    }
};