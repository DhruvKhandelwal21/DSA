class Solution {
public:
    int solve(vector<int>& prices,int n, int idx, int freepur,vector<vector<int>> &dp){
       if(idx==n){
           return 0;
       }
        if(dp[idx][freepur]!=-1){
            return dp[idx][freepur];
        }
        int a = INT_MAX,b = INT_MAX;
        if(freepur!=0){
            a =  solve(prices,n,idx+1,freepur-1,dp);
        }
        b = prices[idx] + solve(prices,n,idx+1,idx+1,dp);
        return dp[idx][freepur] = min(a,b);
    }
    int minimumCoins(vector<int>& prices) {
        int freepur = 1;
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return prices[0] + solve(prices,n,1,freepur,dp);
    }
};