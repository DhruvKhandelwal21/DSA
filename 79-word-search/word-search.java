class Solution {
    public boolean solve(char[][] board,int [][] vis, String word, StringBuilder temp, int n, int m, int i, int j){
        if (temp.length() == word.length()) {
        return temp.toString().equals(word);
    }
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1) return false;
        temp.append(board[i][j]);
        vis[i][j] = 1;
        if(solve(board, vis, word, temp,n,m, i+1,j) || solve(board, vis, word, temp,n,m, i-1,j) || solve(board, vis, word, temp,n,m, i,j+1) || solve(board, vis, word, temp,n,m, i,j-1)) return true;

        temp.deleteCharAt(temp.length() - 1);
        vis[i][j] = 0;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        int n = board.length;
        int m = board[0].length;
        int [][]vis = new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(vis[i],0);
        }
        StringBuilder temp = new StringBuilder();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word.charAt(0)){
                    boolean ans = solve(board, vis, word, temp, n,m, i, j);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
}