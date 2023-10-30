class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0,sum2 = 0;
        int cnt1 = 0,cnt2 = 0;
        for(auto it:nums1){
            if(it==0){
                cnt1++;
            }
            sum1+=it;
        }
        for(auto it:nums2){
             if(it==0){
                cnt2++;
            }
            sum2+=it;
        }
        cout<<sum1<<endl;
        cout<<cnt2<<endl;
       if(cnt1==0&&cnt2==0){
           
           if(sum1!=sum2){
               return -1;
           }else{
               return sum1;
           }
       }else if(cnt1==0||cnt2==0){
           if(cnt1==0&&(sum2 + cnt2)>sum1){
               return -1;
           }
           if(cnt2==0&&(sum1 + cnt1)>sum2){
               return -1;
           }
       }
        return max(sum1 + cnt1,sum2 + cnt2);
    }
};