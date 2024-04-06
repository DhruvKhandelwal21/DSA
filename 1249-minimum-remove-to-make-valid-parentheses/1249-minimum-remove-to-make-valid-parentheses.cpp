class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        unordered_set<int>sm;
        string ans = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push({'(',i});
            }else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    sm.insert(i);
                }
            }
        }
        while(!st.empty()){
             int idx = st.top().second;
            sm.insert(idx);
            st.pop();
        }
        for(int i=0;i<n;i++){
            if(sm.find(i)==sm.end()){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};