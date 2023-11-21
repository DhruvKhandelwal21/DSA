class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long mod = 1e9 + 7;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            string temp = to_string(nums[i]);
            reverse(temp.begin(),temp.end());
            int rev = stoi(temp);
            int diff = nums[i] - rev;
            cnt = (cnt + mp[diff])%mod;
            mp[diff]++;
        }
        
        return cnt;
    }
};