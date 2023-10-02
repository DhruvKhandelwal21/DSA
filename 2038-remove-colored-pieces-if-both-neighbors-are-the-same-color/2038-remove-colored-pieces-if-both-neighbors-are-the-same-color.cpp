class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int cntA=0,cntB=0;
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(colors[i]=='A'){
                a++;
            }else{
                if(a>=3){
                    cntA+=a-2;
                }
                a = 0;
            }
        }
        for(int i=0;i<n;i++){
            if(colors[i]=='B'){
                b++;
            }else{
                if(b>=3){
                    cntB+=b-2;
                }
                b = 0;
            }
        }
        if(colors[n-1]=='A'){
            if(a>=3){
                cntA+=a-2;
            }
        }else{
            if(b>=3){
                cntB+=b-2;
            }
        }
        cout<<cntA<<endl;
        cout<<cntB<<endl;
        if(cntB>=cntA){
            return false;
        }
        return true;
    }
};