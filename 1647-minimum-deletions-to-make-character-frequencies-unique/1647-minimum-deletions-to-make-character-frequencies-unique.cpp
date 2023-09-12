class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        int count = 0;
        for(auto it:s){
            mp[it]++;
        }
        unordered_set<int> st;
       for(auto it:mp){
           if(st.find(it.second)==st.end()){
               st.insert(it.second);
           }else{
               while(st.find(it.second)!=st.end()){
                   it.second--;
                   count++;
               }
               if(it.second>0){
                   st.insert(it.second);
               }
           }
       }
        return count;
    }
};