class Solution {
public:
    bool isOperator(char x){
        if(x=='+'||x=='-'||x=='*'){
            return true;
        }
        return false;
    }
    vector<int> solve(string &s,int i,int j,vector<vector<vector<int>>> &dp){
        if(!dp[i][j].empty()) {
            return dp[i][j];
        }
       if(j-i+1<=2){
           return dp[i][j] = {stoi(s.substr(i,j-i+1))};
       }
        vector<int> res;
      for(int idx=i;idx<=j;idx++){
          if(isOperator(s[idx])){
              vector<int> left = solve(s,i,idx-1,dp);
              vector<int> right = solve(s,idx+1,j,dp);
              for(auto l:left){
                  for(auto r:right){
                      if(s[idx]=='+'){
                          res.push_back(l+r);
                      }else if(s[idx]=='-'){
                          res.push_back(l-r);
                      }else if(s[idx]=='*'){
                          res.push_back(l*r);
                      }
                  }
              }
          }
      }
        return dp[i][j] = res;   
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int n = expression.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n));
        ans = solve(expression,0,n-1,dp);
        return ans;
    }
};