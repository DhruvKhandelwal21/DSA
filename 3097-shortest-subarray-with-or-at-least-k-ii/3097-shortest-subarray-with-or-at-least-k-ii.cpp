class Solution {
public:
    void updateORvalue(vector<int> &bits,long long &sz,int val){
        sz|=val;
        for(int i=0;i<32;i++){
            bits[i]+= val&(1<<i) ? 1 : 0;
        }
    }
    void nullifyOR(vector<int> &bits,long long &sz,int val){
        for(int i=0;i<32;i++){
            bits[i]+=val&(1<<i) ? -1 : 0;
            if(bits[i]==0) sz = sz &(~(1<<i));
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        int len = INT_MAX;
        long long sz = 0;
        vector<int> bits(32,0);
        while(j<n){
            updateORvalue(bits,sz,nums[j]);
            if(sz>=k){
                while(sz>=k&&i<=j){
                    len = min(len,j-i+1);
                    nullifyOR(bits,sz,nums[i]);
                    i++;
                }
            }
            j++;
        }
        return len==INT_MAX ? -1 : len;
    }
};