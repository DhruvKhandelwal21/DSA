class Solution {
public:
    bool isOperator(char x){
        if(x=='+'||x=='-'||x=='*'){
            return true;
        }
        return false;
    }
    vector<int> solve(string &s,int i,int j){
       if(j-i+1<=2){
           return {stoi(s.substr(i,j-i+1))};
       }
        vector<int> res;
      for(int idx=i;idx<=j;idx++){
          if(isOperator(s[idx])){
              vector<int> left = solve(s,i,idx-1);
              vector<int> right = solve(s,idx+1,j);
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
        return res;   
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int n = expression.size();
        ans = solve(expression,0,n-1);
        return ans;
    }
};