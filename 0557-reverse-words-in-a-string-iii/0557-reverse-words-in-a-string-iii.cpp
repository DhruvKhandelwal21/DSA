class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<char> st;
        string temp = "";
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                while(!st.empty()){
                    temp+=st.top();
                    st.pop();
                }
                ans+=temp;
                ans+= " ";
                temp = "";
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        ans+=temp;
        return ans;
    }
};