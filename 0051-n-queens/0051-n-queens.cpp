class Solution {
public:
    bool check(vector<string> &curr,int dupcol,int duprow,int n){
     int col = dupcol;
     int row = duprow;
        // column wise check
     while(col>=0){
        if(curr[row][col]=='Q'){
            return false;
        } 
        col--;
     }
      col = dupcol;
      row = duprow;
    //lower diagonal check
      while(row<n&&col>=0){
          if(curr[row][col]=='Q'){
              return false;
          }
          col--;
          row++;
      }
     col = dupcol;
     row = duprow;
    // //upper diagonal check
      while(row>=0&&col>=0){
          if(curr[row][col]=='Q'){
              return false;
          }
          col--;
          row--;
      }
        return true;
    }
    
    void solve(vector<vector<string>> &ans, vector<string> &curr, int col,int n){
        if(col==n){
            ans.push_back(curr);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(check(curr,col,row,n)){
                curr[row][col] = 'Q';
                solve(ans,curr,col+1,n);
                curr[row][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string temp(n,'.');
        vector<string> curr;
        for(int i=0;i<n;i++){
            curr.push_back(temp);
        }
        solve(ans,curr,0,n);
        return ans;
    }
};