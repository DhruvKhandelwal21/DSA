class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<long long int> st1;
        unordered_set<long long int> st2;
        unordered_set<long long int> common;
        int n = nums1.size();
        int ans = 0;
        int limit = n/2;
        int dup = 0;
        for(auto it:nums1){
            st1.insert(it);
        }
        for(auto it:nums2){
            if(st1.find(it)!=st1.end()){
                common.insert(it);
            }
                 st2.insert(it);
            }
        for(auto it:common){
            st1.erase(it);
            st2.erase(it);
        }
        
        dup = common.size();
        int cnt1 = st1.size();
        int cnt2 = st2.size();
        cout<<cnt1<<endl;
        cout<<cnt2<<endl;
        if(cnt1<=limit&&cnt2<=limit){
            ans+= min(n,cnt1 + cnt2+dup);
        }else if(cnt1>limit&&cnt2<=limit){
            ans+=n/2 + min(n/2,cnt2+dup);
        }else if(cnt1<=limit&&cnt2>limit){
            ans+=n/2 + min(n/2,cnt1+dup);
        }else{
            ans+=n;
        }
        
        
        return ans;
        
    }
};