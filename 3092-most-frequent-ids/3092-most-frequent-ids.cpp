class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        map<int,long long> mp;
        int n = nums.size();
        vector<long long> res;
        priority_queue<pair<long long,int>> pq;
        for(int i=0;i<n;i++){
            mp[nums[i]]+=freq[i];
            pq.push({mp[nums[i]],nums[i]});
            while(!pq.empty()&&mp[pq.top().second]!=pq.top().first){
                pq.pop();
            }
            res.push_back(pq.top().first);
             
        }
        
        return res;
    }
};