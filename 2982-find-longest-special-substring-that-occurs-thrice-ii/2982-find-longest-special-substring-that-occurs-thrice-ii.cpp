class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int ans = -1;
        for(char cc = 'a';cc<='z';cc++){
            int m1 = 0,m2 = 0,m3 = 0;
            for(int i=0;i<n;i++){
                if(s[i]!=cc){
                    continue;
                }
                int cnt = 0;
                int j = i;
                for(;j<n&&s[i]==s[j];j++){
                    cnt++;
                    if(cnt>m3){
                        m1 = m2;
                        m2 = m3;
                        m3 = cnt;
                    }else if(cnt>m2){
                        m1 = m2;
                        m2 = cnt;
                    }else if(cnt>m1){
                        m1 = cnt;
                    }
                }
                i = j;
                
            }
            ans = max(ans,m1);
        }
        return ans==0?-1:ans;
        
    }
};