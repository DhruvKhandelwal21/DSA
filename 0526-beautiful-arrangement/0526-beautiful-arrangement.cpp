class Solution {
public:
    bool check(string temp,int n){
        
        for(int i=1;i<=n;i++){
            if((temp[i-1]-'0')%i!=0&&i%(temp[i-1]-'0')!=0){
                return false;
            }
        }
        return true;
    }
    void solve(vector<int> temp,int &ans,int idx, int n){
        if(idx>=n){
             ans++;
            return;
        }
        for(int i=idx;i<n;i++){
            
            if((temp[i]%(idx+1)==0 || (idx+1)%temp[i]==0)){      
            swap(temp[i],temp[idx]);
            solve(temp,ans,idx+1,n);
            swap(temp[idx],temp[i]);
            }
        }
    }
    int countArrangement(int n) {
        vector<int> temp;
        for(int i=1;i<=n;i++){
            temp.push_back(i);
        }
        
        int ans = 0;
        solve(temp,ans,0,n);
        return ans;
    }
};