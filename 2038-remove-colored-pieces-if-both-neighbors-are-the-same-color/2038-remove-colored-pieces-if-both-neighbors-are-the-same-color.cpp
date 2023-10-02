class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int cntA=0,cntB=0;
        for(int i=1;i<n-1;i++){
           char curr = colors[i];
            char prev = colors[i-1];
            char nex = colors[i+1];
            if(colors[i]=='A'&&curr==prev&&curr==nex){
                cntA++;
            }
            if(colors[i]=='B'&&curr==prev&&curr==nex){
                cntB++;
            }
        }
        return cntA>cntB;
    }
};