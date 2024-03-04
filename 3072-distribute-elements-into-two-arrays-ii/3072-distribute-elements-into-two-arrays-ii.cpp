#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        ordered_set os1,os2;
        vector<int> arr1,arr2,ans;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        os1.insert(nums[0]);
        os2.insert(nums[1]);
        
        for(int i=2;i<n;i++){
            int val = nums[i];
            int a = os1.order_of_key(val);
            int b = os2.order_of_key(val);
            if(a>b){
                os1.insert(val);
                arr1.push_back(val);
            }else if(a<b){
                os2.insert(val);
                arr2.push_back(val);
            }else if(a==b){
                if(os1.size()<=os2.size()){
                  os1.insert(val);
                  arr1.push_back(val);   
                }else{
                    os2.insert(val);
                    arr2.push_back(val);
                }
            }
        }
        ans = arr1;
        for(auto it:arr2){
            ans.push_back(it);
        }
        return ans;
        
        
        //---------------------->Brute Force<----------------------//
//         vector<int> arr1,arr2,temparr1,temparr2,ans;
//         priority_queue<int> pq1,pq2;
    
//         arr1.push_back(nums[0]);
//         temparr1.push_back(nums[0]);
//         arr2.push_back(nums[1]);
//         temparr2.push_back(nums[1]);
        
//         for(int i=2;i<n;i++){
//             int ele = nums[i];
//             int a = temparr1.size();
//             int b = temparr2.size();
//             auto idx1 = upper_bound(temparr1.begin(),temparr1.end(),ele);
//             auto idx2 = upper_bound(temparr2.begin(),temparr2.end(),ele);
//             int len1 = a-(idx1-temparr1.begin());
//             int len2 = b-(idx2-temparr2.begin());
//             // cout<<idx1<< " "<<idx2<<endl;
//             // cout<<len1<< " "<<len2<<endl;
            
//             if(len1>len2){
//                 arr1.push_back(ele);
//                 temparr1.insert(idx1, ele);
//             }else if(len1<len2){
//                 arr2.push_back(ele);
//                 cout<<temparr2.end() - idx2<<endl;
//                 temparr2.insert(idx2, ele);
//             }else if(len1 == len2){
//                 if(a<=b){
//                     temparr1.insert(idx1, ele);
//                     arr1.push_back(ele);
//                 }else{
//                     temparr2.insert(idx2, ele);
//                     arr2.push_back(ele);
//                 }
//             }    
            
//         }
        
//         for(auto it:arr1){
//             ans.push_back(it);
//         }
//         for(auto it:arr2){
//             ans.push_back(it);
//         }
//         return ans;
        
        
    }
};