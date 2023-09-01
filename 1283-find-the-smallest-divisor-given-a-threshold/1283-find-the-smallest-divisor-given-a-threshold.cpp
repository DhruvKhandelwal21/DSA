class Solution {
public:
    bool check(vector<int>& nums,int threshold, int mid){
        int count = 0;
        for(int i=0;i<nums.size();i++){
            count += ceil(double(nums[i]) / mid);
        }
        // cout<<count<<endl;
        if(count<=threshold){
            return true;
        }
        return false;
        
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int hi = *max_element(nums.begin(),nums.end());
        int ans = -1;
        if(threshold==nums.size()){
            return hi;
        }
        // int lo = *min_element(nums.begin(),nums.end());
        int lo = 1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(nums,threshold,mid)){
                hi = mid-1;
                ans = mid;
                // cout<<ans<<endl;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};