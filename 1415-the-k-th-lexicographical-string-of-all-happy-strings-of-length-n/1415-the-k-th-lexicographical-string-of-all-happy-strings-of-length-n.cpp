class Solution {
public:
    vector<char> y = {'a','b','c'};
    void solve(int n,vector<string> &temp,string x,char prev){
        if(x.size()==n){
            temp.push_back(x);
            return;
        }
        for(int i=0;i<3;i++){
            if(y[i]!=prev){
                x.push_back(y[i]);
                solve(n,temp,x,y[i]);
                x.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
       vector<string> temp;
        string x= "";
        solve(n,temp,x,'#');
        if(k>temp.size()) return "";
        return temp[k-1];
    }
};