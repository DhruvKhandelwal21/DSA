class Solution {
public:
    bool isPal(string x){
        int i=0,j=x.size()-1;
        while(i<=j){
            if(x[i]!=x[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans,vector<string>temp,string &s,int curr, int n){
        if(curr>=n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=curr;i<n;i++){
            string x = s.substr(curr,i-curr+1);
           
            if(isPal(x)){
                temp.push_back(x);
                solve(ans,temp,s,i+1,n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        int n = s.size();
        solve(ans,temp,s,0,n);
        return ans;
        
    }
};