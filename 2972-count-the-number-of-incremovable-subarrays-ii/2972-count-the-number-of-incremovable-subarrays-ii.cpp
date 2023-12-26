#define ll long long int
//:-> Review this for more detail
// https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-ii/discuss/4447351/C%2B%2B-or-Two-pointer-or-O(N)-or-Detailed-Explanation
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        ll n = nums.size();
        ll leftIdx = 0;
        ll rightIdx = n-1;
// Thing we must remember is that we are allowed to remove only one subarray to make it strictly increasing.
// We will move to the left and right to find the strictly increasing subarrays as we can't take find a strictly increasing subarray from middle because here we have to remove 2 subarrays which is not allowed.
// First we will get left idx and then right idx and then we will calculate subarrays for right idx including a complete empty array and after that we can combine them with the left ones and simultaneously count the left ones too.
// We can solve it with both binary search and 2 pointers(more efficient)

        while(leftIdx<n-1&&nums[leftIdx]<nums[leftIdx+1]){
            leftIdx++;
        }
        while(rightIdx>0&&nums[rightIdx]>nums[rightIdx-1]){
            rightIdx--;
        }
        if(rightIdx<=leftIdx){
            return ((n)*(n+1))/2;
        }
        ll count = (n-rightIdx+1) + (leftIdx+1);
// Binary Search :------- O(NlogN)
        // ll count = (n-rightIdx+1)
        // for(ll i=0;i<=leftIdx;i++){
        //     ll idxOnRight = upper_bound(nums.begin()+rightIdx,nums.end(),nums[i]) - nums.begin();
        //     count+=n-idxOnRight+1;
        // }

// 2 Pointers solution:- O(N)
        int i = 0,j=rightIdx;
        while(i<=leftIdx&&j<n){
            if(nums[j]>nums[i]){
                count+=n-j;
                i++;
            }else{
                j++;
            }
        }
        return count;
    }
};