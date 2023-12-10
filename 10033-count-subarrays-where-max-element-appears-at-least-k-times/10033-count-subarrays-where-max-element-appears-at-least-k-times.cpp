class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long mx = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int i=0,j=0;
        long long cnt = 0;
        long long ans = 0;
       
            while(j<n){
                if(nums[j]==mx){
                    cnt++;
                }
                if(cnt==k){
                    while(i<=j){
                        ans+=(long long)(n-j);
                        if(nums[i]!=mx){
                            i++;
                        }else{
                            cnt--;
                            i++;
                            break;
                        }
                    }
                }
                j++;
            }
        
     
        return ans;
    }
};