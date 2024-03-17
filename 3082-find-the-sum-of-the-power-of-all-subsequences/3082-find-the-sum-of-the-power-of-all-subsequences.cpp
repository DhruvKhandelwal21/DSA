class Solution {
public:
    vector<vector<vector<int>>> dp;
    int m = 1e9 + 7;
    // long long power(int n){
    //     if(n<=1) return n+1;
    //     int res = power(n/2);
    //     if(n%2) return ((res*res)%m);
    //     return (((res*res)%m)*2)%m;
    // }
     long long power(int n){
        if(n <= 1) return (n+1);
        long long res = power(n/2);
        if(n%2) return (((res*res)%m)*2)%m;
        return ((res*res)%m);
    }
    long long solve(vector<int> &nums,int k,int idx,int sum,int count){
        
        if(sum==k){
            return power(nums.size()-count);
        }
        if(sum>k || idx<0) return 0;
        
        if(dp[idx][sum][count]!=-1){
            return dp[idx][sum][count];
        }
        
        long long take = solve(nums,k,idx-1,sum+nums[idx],count+1);
        long long notake = solve(nums,k,idx-1,sum,count);
        return dp[idx][sum][count] = (take + notake)%m;
    }
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        dp.resize(100, vector<vector<int>>(101, vector<int>(101, -1)));
        return solve(nums,k,n-1,0,0);
    }
};