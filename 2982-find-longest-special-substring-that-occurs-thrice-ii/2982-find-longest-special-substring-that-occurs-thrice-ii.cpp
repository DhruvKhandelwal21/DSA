class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int ans = -1;
        for(char cc = 'a';cc<='z';cc++){
            vector<int> counts;
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(s[i]==cc){
                    cnt++;
                }else{
                   if(cnt>0) counts.push_back(cnt);
                    cnt=  0;
                }  
            }
           if(cnt>0) counts.push_back(cnt);
            sort(counts.begin(),counts.end());
            reverse(counts.begin(),counts.end());
            int sz = counts.size();
            if(sz==1){
                ans = max(ans,counts[0]-2);
            }else if(sz==2){
                 ans = max(ans,counts[0]  - 2);
                if(counts[0]==counts[1]){
                    ans = max(ans,counts[0]-1);
                }else{
                    ans=  max(ans,counts[1]);
                }
            }else if(sz>=3){
                ans = max(ans,counts[0]-2);
                if(counts[0]==counts[1]){
                    ans=  max(ans,counts[0]-1);
                }else{
                   ans=  max(ans,counts[1]); 
                }
                ans = max(ans,counts[2]);
            }
        }
        return ans<=0?-1:ans;
        
        //Most Optimised Solution :- TC:- O(26*N)  SC:- O(1)
//         for(char cc = 'a';cc<='z';cc++){
//             int m1 = 0,m2 = 0,m3 = 0;
//             for(int i=0;i<n;i++){
//                 if(s[i]!=cc){
//                     continue;
//                 }
//                 int cnt = 0;
//                 int j = i;
//                 for(;j<n&&s[i]==s[j];j++){
//                     cnt++;
//                     if(cnt>m3){
//                         m1 = m2;
//                         m2 = m3;
//                         m3 = cnt;
//                     }else if(cnt>m2){
//                         m1 = m2;
//                         m2 = cnt;
//                     }else if(cnt>m1){
//                         m1 = cnt;
//                     }
//                 }
//                 i = j;
                
//             }
//             ans = max(ans,m1);
//         }
//         return ans==0?-1:ans;
        
    }
};