class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int m = bank.size();
        int n = bank[0].size();
        for(int i=0;i<m;i++){
            bool flag = false;
            string temp = bank[0];
            int tempcnt = 0;
            for(int j=0;j<n;j++){
                if(bank[i][j]=='1'){
                    tempcnt++;
                }
            }
            int cnt = 0;
            for(int k = i+1;k<m;k++){
                if(!flag){
                    for(int l = 0;l<n;l++){
                    if(bank[k][l]=='1'){
                        cnt++;
                        flag = true;
                    }
                }
             }   
           }
            ans+=cnt*tempcnt;
        }
        return ans;
    }
};