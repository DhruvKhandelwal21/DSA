class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j = 0;
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if(i==target[j]){
                ans.push_back("Push");
                j++;
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            
            if(j==target.size()){
                break;
            }
        }
        return ans;
    }
};