class Solution {
public:
    string invert(string x){
        for(int i=0;i<x.size();i++){
            if(x[i]=='0'){
                x[i] = '1';
            }else{
                x[i] = '0';
            }
        }
        return x;
    }
    string solve(int n){
        if(n==1){
            return "0";
        }
        string helper = solve(n-1);
        string temp = invert(helper);
        reverse(temp.begin(),temp.end());
        return helper + "1" + temp;
    }
    char findKthBit(int n, int k) {
        string ans = solve(n);
        return ans[k-1];
    }
        
        
};