class Solution {
public:
    unordered_set<string> st;
    void solve(string tiles,vector<int> &vis, int &cnt, string temp,int curridx, int n){
            if(st.find(temp)==st.end()&&temp!=""){
                st.insert(temp);
                cnt++;
            }
            
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                temp+=tiles[i];
                vis[i] = 1;
                solve(tiles,vis,cnt,temp,curridx+1,n);
                temp.pop_back();
                vis[i] = 0;
            }
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        int cnt = 0;
        vector<int> vis(n,0);
        string temp="";
        solve(tiles,vis,cnt,temp,0,n);
        return cnt;
    }
};