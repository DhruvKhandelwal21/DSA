class Solution {
public:
    bool solve(vector<vector<char>>& board,vector<vector<int>> &vis, int i,int j, string &temp, string &word, int m, int n){
        if(temp.size()==word.size()){
            if(temp==word){
                return true;
            }
            return false;
        }
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j]==1) return false;
        
        temp.push_back(board[i][j]);
        vis[i][j] = 1;
        
        if(solve(board,vis,i+1,j,temp,word,m,n) || solve(board,vis,i,j+1,temp,word,m,n) || solve(board,vis,i-1,j,temp,word,m,n) || solve(board,vis,i,j-1,temp,word,m,n) ){
            return true;
        }
        temp.pop_back();
        vis[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        string temp = "";
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    bool check = solve(board,vis,i,j,temp,word,m,n);
                   if(check) return true; 
                }
              
            }
        }
        return false;
    }
};