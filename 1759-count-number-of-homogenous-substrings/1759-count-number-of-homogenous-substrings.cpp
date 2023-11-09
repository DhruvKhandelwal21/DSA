class Solution {
public:
    int countHomogenous(string s) {
        int i = 0,j=0, n = s.size();
        long long mod = 1e9 + 7;
        int cnt = 0;
        int temp = 0;
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            if(s[j]!=s[i]){
                cnt+=((long long)(temp)*(temp+1)/2)%mod;
                temp = 0;
                i = j;
            }
            temp++;
            j++;
        }
        int sec = temp;
        cnt+=((long long)(sec)*(sec+1)/2)%mod;
        
        return cnt;
        
    }
};