class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        int presentScore = 0;
        vector<int> suffixScore(n);
        int ans = -1;
        suffixScore[n-1] = possible[n-1]==0 ? -1 : 1;
        for(int i=n-2;i>=0;i--){
            if(possible[i]==1){
                suffixScore[i] = suffixScore[i+1] + 1; 
            }else{
                suffixScore[i] = suffixScore[i+1] - 1; 
            }
        }
        for(int i=0;i<n-1;i++){
            if(possible[i]==1){
                presentScore++;
            }else{
                presentScore--;
            }
            if(presentScore>suffixScore[i+1]){
                cout<<presentScore<<endl;
                cout<<suffixScore[i+1]<<endl;
                ans = i+1;
                break;
            }
        }
        return ans;
    }
};