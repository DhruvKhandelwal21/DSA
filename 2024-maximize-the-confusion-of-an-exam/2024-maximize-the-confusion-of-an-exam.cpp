class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0,j = 0;
        int n = answerKey.size();
        int t=0,f=0;
        int mn = 0;
        while(j<n){
            t+=answerKey[j]=='T';
            f+=answerKey[j]=='F';
            while(t>k&&f>k){
                if(answerKey[i]=='T'){
                    t--;
                }else if(answerKey[i]=='F'){
                    f--;
                }

                i++; 
            }
            mn = max(mn,j-i+1);
            j++;
            
        }
        return mn;
    }
};