class Solution {
public:
    string compare(string temp,string ans){
        int i=0,j=0;
        int m = temp.size();
        int n = ans.size();
        while(i<m&&j<n){
            if(temp[i]=='0'&&ans[j]=='1'){
                return temp;
            }else if(temp[i]=='1'&&ans[j]=='0'){
                return ans;
            }
            i++;
            j++;
        }
        return ans;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i=0,j=0;
        string ans=  "";
        int len = INT_MAX;
        int cnt = 0;
        while(j<n){
            if(s[j]=='1'){
                cnt++;
            }
            while(cnt==k){
                if(j-i+1<len){
                    len = j-i+1;
                    ans = s.substr(i,j-i+1);
                }else if(j-i+1==len){
                    string temp = s.substr(i,j-i+1);
                    if(temp.compare(ans) < 0){
                        ans = temp;
                    }
                }
                if(s[i]=='1'){
                    cnt--;
                    i++;
                }else{
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};