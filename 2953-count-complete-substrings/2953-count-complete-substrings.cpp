class Solution {
public:
    bool check(vector<int> &freq,int j,int k){
        int cnt = 0;
//In this check function we are checking if we are getting all character count equal to k.
        for(int i=0;i<freq.size();i++){
            if(freq[i]==0) continue;
            if(freq[i]!=k) return false;
            cnt++;
        }
    
        // if(cnt>j) return false;
        return true;
    }
    long long solve(string temp,int k){
        int n = temp.size();
        long long cnt = 0;
//Now we will check for each window length and maintain a vector of characters for keeping the count.
        for(int j=1;j<=26;j++){
            int len = j*k;
            vector<int> freq(26,0);
            if(len>n){
                break;
            }
            int p=0,q=0;
            while(p<n){
                freq[temp[p]-'a']++;
                if(p-q+1==len){
                    if(check(freq,j,k)) cnt++;
                    freq[temp[q]-'a']--;
                    q++;
                }
                
                p++;
            }
            
        }
        return cnt;
    }
    int countCompleteSubstrings(string s, int k) {
      long long ans = 0;
        string temp = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            temp+=s[i];
//We are first checking the break where the difference between the character is greater than 2. So that we don't have to worry about second condition as characters before that would have difference less than 2.
            if(i<=n-2){
                if(abs(s[i+1]-s[i])>2){
                    ans+=solve(temp,k);
                    temp = "";
                }
            }
        }
        ans+=solve(temp,k);
        return (int)ans;
    }
};