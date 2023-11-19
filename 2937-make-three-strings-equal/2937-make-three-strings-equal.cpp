class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int cnt = 0;
        int idx = -1;
        int len1 = s1.size(),len2 = s2.size(),len3 = s3.size();
        int minlen = min(len1,max(len2,len3));
        
       
       
            for(int i=0;i<minlen;i++){
                if(s1[i]==s2[i]&&s2[i]==s3[i]){
                    idx = i+1;
                }else{
                    break;
                }
            }
        
        return idx==-1?-1: len1 + len2 + len3 - 3*(idx);
       
    }
};