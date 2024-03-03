class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int mid = n/2;
        unordered_map<int,int> mpy;
        unordered_map<int,int> mpo;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //calculation for Y
                if((i<=mid&&j<=mid&&i==j) || (j==mid&&i>mid) || (j>mid&&i<mid&&i==(n-j-1))){
                    if(grid[i][j]==0){
                        mpy[0]++;
                    }else if(grid[i][j]==1){
                        mpy[1]++;
                    }else if(grid[i][j]==2){
                        mpy[2]++;
                    }
                }else{
                    //rest of the matrix
                    if(grid[i][j]==0){
                        mpo[0]++;
                    }else if(grid[i][j]==1){
                        mpo[1]++;
                    }else if(grid[i][j]==2){
                        mpo[2]++;
                    }
                }
            }
        }
        
        int total1 = mpo[0] + mpo[1] + mpo[2];
        int total2 = mpy[1] + mpy[2] + mpy[0];
        
        int mn = INT_MAX;
        
        for(auto it:mpy){
            int num = it.first;
            int cnt = it.second;
            int ans1 = total2 - cnt;
            for(auto kt:mpo){
                if(kt.first==it.first) continue;
                int numx = kt.first;
                int cntx = kt.second;
                int ans2 = total1 - cntx;
                mn = min(mn,ans1 + ans2);
            }  
        }
        return mn;  
    }
};