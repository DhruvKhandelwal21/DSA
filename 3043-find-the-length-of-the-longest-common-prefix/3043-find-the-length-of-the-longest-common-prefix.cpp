class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int i=0;i<arr1.size();i++){
            int num = arr1[i];
            while(num>0){
                st.insert(num);
                num = num/10;
            }
        }
        int ans = 0;
        for(int i=0;i<arr2.size();i++){
           int digits = log10(arr2[i]) +1;
           int num = arr2[i];
           while(num>0){
               if(st.find(num)!=st.end()){
                   ans = max(ans,digits);
                   break;
               }
               num = num/10;
               digits--;
           }
        }
        return ans;
    }
};