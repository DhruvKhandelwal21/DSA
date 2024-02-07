class Solution {
public:
    bool check(string &s,int &idx,int &n){
        return s.substr(0,n-idx) == s.substr(idx,n-idx);
    }
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        int cnt = 1;
        for(int i=k;i<n;i+=k){
            if(check(word,i,n)){
                return cnt;
            }
            cnt++;
        }
        return cnt;
    }
};