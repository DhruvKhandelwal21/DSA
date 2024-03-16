class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+= nums[i]==1 ? 1 : -1;
            if(sum==0){
                ans = max(ans,i+1);
            }
            if(mp.find(sum)!=mp.end()){
                ans = max(ans,i-mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
        return ans;
    }
};