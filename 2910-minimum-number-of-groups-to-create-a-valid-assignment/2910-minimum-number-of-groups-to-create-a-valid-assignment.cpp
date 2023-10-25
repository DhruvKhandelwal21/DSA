class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> temp;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            temp.push_back(it.second);
        }
        sort(temp.begin(),temp.end());
        
      
        
        for(int i=1;i<=temp[0];i++){
            int a = i,b = i+1;
            int num = 0;
             bool flag = false;
        
             for(int i=0;i<temp.size();i++){
                 int curr = temp[i];
                 int mn = INT_MAX;
                 int cnt = 0;
            while(curr>=0){
                if(curr%a==0){
                    mn = cnt + curr/a;
                }
                curr-=b;
                cnt++;
            }
                 
        if(mn==INT_MAX){
            flag = true;
            break;
        }
                num+=mn;
            
        }
            if(!flag){
                ans = min(ans,num);
            }
            
        }
       
       
        return ans;
        
    }
};