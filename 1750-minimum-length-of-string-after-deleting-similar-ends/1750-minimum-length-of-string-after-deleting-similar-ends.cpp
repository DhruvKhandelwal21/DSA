class Solution {
public:
    int minimumLength(string s) {
        int n=  s.size();
        int i=0,j=n-1,curri=-1,currj=n;
        int ans = n;
        while(i<j){
            if(s[i]==s[j]){
                while(i<j&&(i+1!=j)&&s[i]==s[i+1]){
                    i++;
                }
                while(i<j&&(i!=j-1)&&s[j]==s[j-1]){
                    j--;
                }
                int temp = (i - curri) + (currj-j);
                ans-=temp;
                curri = i;
                currj = j;
                i++;
                j--;
            }else{
                break;
            }
        }
        return ans;
    }
};