class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int pro = 1;
        int zerocnt = 0;
        int n = nums.size();
        vector<int> ans(n,0);
        for(auto it:nums){
          if(it!=0){
              pro*=it;
          }else{
              zerocnt++;
          }
        }
        cout<<zerocnt<<endl;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(zerocnt>1){
                    ans[i] = 0;
                }else{
                    ans[i] = pro;
                }
            }else{
                if(zerocnt>0){
                    ans[i] = 0;
                }else{
                    ans[i] = pro/nums[i];
                }
            }
        }
        return ans;
    }
};