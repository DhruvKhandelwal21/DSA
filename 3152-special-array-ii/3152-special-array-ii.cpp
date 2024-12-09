class Solution {
public:
    
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> badParity(n,0);
        int stIdx = 0;
        for(int i=1;i<nums.size();i++){
            if((nums[i-1]%2==0 && nums[i]%2==0) || (nums[i-1]%2!=0 && nums[i]%2!=0)){
                badParity[i] = badParity[i-1] + 1;
            }else{
                badParity[i] = badParity[i-1];
            }
        }

        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if(badParity[u]==badParity[v]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};