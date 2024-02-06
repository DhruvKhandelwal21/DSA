class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=  strs.size();
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            string st = strs[i];
            sort(st.begin(),st.end());
            mp[st].push_back(strs[i]);
        }
        for(auto it:mp){
            vector<string> temp = it.second;
            ans.push_back(temp);
        }
        // vector<int> vis(n,0);
//         for(int i=0;i<n;i++){   
//             if(vis[i]!=0){
//                 continue;
//             }else{
//                  vector<string> tempans;
//                  unordered_map<char,int> temp1;
//                 for(auto it:strs[i]){
//                     temp1[it]++;
//                 }
//                 vis[i] = 1;
//                 tempans.push_back(strs[i]);
//                 for(int j=0;j<n;j++){
//                     if(vis[j]==0){
//                         unordered_map<char,int> temp2;
//                         for(auto it:strs[j]){
//                             temp2[it]++;
//                         }
                        
//                         if(temp1==temp2){
//                             tempans.push_back(strs[j]);
//                             vis[j] = 1;
//                         }
//                     }
//                 }
//                ans.push_back(tempans); 
//             }
//         }
        return ans;
    }
};