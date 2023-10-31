class Solution {
public:
    bool solve(vector<int>& weights, int days, int mid){
        int load = 0;
        int ans = 1;
        for(int i=0;i<weights.size();i++){
            if(load + weights[i]>mid){
                ans++;
                load = weights[i];
            }else{
                load+=weights[i];
            }
        }
        
        if(ans>days) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 0;
        int hi = 0;
        int ans = -1;
        for(auto it:weights){
            hi+=it;
            lo = max(lo,it);
        }
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(solve(weights,days,mid)){
                cout<<mid<<endl;
                hi = mid-1;
                ans = mid;
            }else{
                lo = mid+1;
            }
        }
        return ans;
        
    }
};