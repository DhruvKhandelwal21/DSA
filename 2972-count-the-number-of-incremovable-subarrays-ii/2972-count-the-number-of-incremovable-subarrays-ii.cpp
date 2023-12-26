#define ll long long int
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        ll n = nums.size();
        ll leftIdx = 0;
        ll rightIdx = n-1;
        while(leftIdx<n-1&&nums[leftIdx]<nums[leftIdx+1]){
            leftIdx++;
        }
        while(rightIdx>0&&nums[rightIdx]>nums[rightIdx-1]){
            rightIdx--;
        }
        if(rightIdx<=leftIdx){
            return ((n)*(n+1))/2;
        }
        ll count = n-rightIdx+1;
        for(ll i=0;i<=leftIdx;i++){
            ll idxOnRight = upper_bound(nums.begin()+rightIdx,nums.end(),nums[i]) - nums.begin();
            count+=n-idxOnRight+1;
        }
        return count;
    }
};