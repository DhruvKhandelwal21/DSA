
class Solution {
public:
    int subarraysWithKDistinctAtMostK(vector<int>& nums,int k){
        int n=nums.size();
        int i=0,j=0;
        unordered_map<int,int>m;
        int count=0;
        while(j<n){
            m[nums[j]]++;
            while(i<=j && m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithKDistinctAtMostK(nums,k)-subarraysWithKDistinctAtMostK(nums,k-1);
    }
};