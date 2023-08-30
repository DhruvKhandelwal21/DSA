class Solution {
public:
    int solve(int maxmin,int maxi,int &operations){
        int temp = maxi/maxmin;
        int rem = maxi%maxmin;
        operations+=(maxi/maxmin);
        maxmin = maxi/(temp+rem);
        // while(maxi>maxmin){
        //     maxi-=maxmin;
        //     operations++;
        // }
        return maxmin;
    }
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long maxmin = nums[n-1];
        long long operations = 0;
        for(int i=n-2;i>=0;i--){
            long long parts = ceil(nums[i]/double(maxmin));
            operations+=parts-1;
            maxmin = nums[i]/parts;
        }
        return operations;
    }
};