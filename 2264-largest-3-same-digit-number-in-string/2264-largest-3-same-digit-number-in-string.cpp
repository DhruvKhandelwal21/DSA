class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string temp = "";
        int i = 0,j=2;
        int maxi = 0;
        while(j<n){
            if(num[i+1]==num[j]&&num[i]==num[i+1]){
                if(num[i]-'0'>=maxi){
                    temp = num.substr(i,3);
                    maxi = num[i]-'0';
                }
            }
            j++;
            i++;
        }
        
        return temp;
    }
};