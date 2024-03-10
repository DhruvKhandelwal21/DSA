class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1,st2;
        vector<int> ans;
        for(auto it:nums1){
            st1.insert(it);
        }
        for(auto it:nums2){
            if(st2.find(it)==st2.end()&&st1.find(it)!=st1.end()){
                ans.push_back(it);
                st2.insert(it);
            }
        }
        return ans;
    }
};