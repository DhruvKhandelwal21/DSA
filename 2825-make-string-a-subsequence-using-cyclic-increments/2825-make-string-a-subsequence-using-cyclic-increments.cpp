class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int idx = 0;
        int n = str2.size();
        for(int i=0;i<str1.size();i++){
            if(idx>=n) return true;
            if(str1[i]==str2[idx]){
                idx++;
            }else{
                if(str2[idx]-str1[i]==1 || str1[i]-str2[idx]==25){
                    idx++;
                }
            }
        }
        if(idx==n) return true;
        return false;
    }
};