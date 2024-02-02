class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        for(int i=2;i<=s.size();i++){
            for(int j=0;j<=s.size()-i;j++){
                string x = s.substr(j,i);
                int temp = stoi(x);
                if(temp>=low&&temp<=high){
                    ans.push_back(temp);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};