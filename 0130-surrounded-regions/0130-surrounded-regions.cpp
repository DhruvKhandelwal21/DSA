class Solution {
public:
    vector<int> x = {-1,0,1,0};
    vector<int> y = {0,-1,0,1};
    
    void dfs(vector<vector<char>>& board, int i, int j, int &n, int &m){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='Y' || board[i][j]=='X') return;
        board[i][j]='Y';
        for(int k=0;k<4;k++){
            int currx = x[k] + i;
            int curry = y[k] + j;
            dfs(board,currx,curry,n,m);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board[0].size();
        int n = board.size();
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(board,0,j,n,m);
             }
            
            if(board[n-1][j]=='O'){
                dfs(board,n-1,j,n,m);
            }
        }
        
        for(int j=0;j<n;j++){
            if(board[j][0]=='O'){
                dfs(board,j,0,n,m);
            }
            if(board[j][m-1]=='O'){
                dfs(board,j,m-1,n,m);
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(board[i][j]=='Y'){
        //             dfs(board,i,j);
        //         }
        //     }
        // }

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