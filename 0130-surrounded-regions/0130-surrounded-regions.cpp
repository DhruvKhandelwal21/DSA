class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board[0].size();
        int n = board.size();
        queue<pair<int,int>> q;
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){ 
                board[0][j] = 'Y';
                q.push({0,j});
             }
            
            if(board[n-1][j]=='O'){ 
                board[n-1][j] = 'Y';
                q.push({n-1,j});
            }
        }
        
        for(int j=0;j<n;j++){
            if(board[j][0]=='O'){ 
                board[j][0] = 'Y';
                q.push({j,0});
            }
            if(board[j][m-1]=='O'){
                board[j][m-1] = 'Y';
                q.push({j,m-1});
            }
        }
        
        vector<int> x = {-1,0,1,0};
        vector<int> y = {0,-1,0,1};
        
        while(!q.empty()){
            auto [a,b] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int currx = a+x[i];
                int curry = b+y[i];
        if(currx>=0 && curry>=0 && currx<n && curry<m && board[currx][curry]=='O'){
                    board[currx][curry] = 'Y';
                    q.push({currx,curry});
             }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){ 
                    board[i][j]='X';
                }else if(board[i][j]=='Y') {
                    board[i][j]='O';
                }
            }
        }
        return;
    }
};