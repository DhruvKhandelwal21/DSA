class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        for(int i=0;i<arr1.size();i++){
            string x = to_string(arr1[i]);
            string temp = "";
            for(int j=0;j<x.size();j++){
                temp.push_back(x[j]);
                st.insert(temp);
            }
        }
        int ans = 0;
        for(int i=0;i<arr2.size();i++){
            string x = to_string(arr2[i]);
            string temp = "";
            for(int j=0;j<x.size();j++){
                temp.push_back(x[j]);
                if(st.find(temp)!=st.end()){
                    ans = max(ans, j+1);
                }
            }
        }
        return ans;
    }
};