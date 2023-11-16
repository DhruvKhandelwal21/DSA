class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //-------------------------->Brute Force<---------------------//
        // unordered_set<int> st;
        // int sz = nums.size();
        // for(int i=0;i<sz;i++){
        //     int temp = stoi(nums[i],0,2);
        //     st.insert(temp);
        // }
        // int n = pow(2,sz);
        // for(int i=0;i<=sz;i++){
        //     if(st.find(i)==st.end()){
        //         string temp = bitset<16>(i).to_string().substr(16-sz,sz);
        //         return temp;
        //     }
        // }
        // return "";
    //------------------------>optimised - O(1)<-----------------------------//
        int sz = nums.size();
        string ans = "";
        for(int i=0;i<sz;i++){
            if(nums[i][i]=='0'){
                ans+='1';
            }else if(nums[i][i]=='1'){
                ans+='0';
            }
        }
        return ans;
    }
};