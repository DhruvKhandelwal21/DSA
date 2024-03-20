class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k=k-1;
        string ans="";
        while(true){
            ans=ans+to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;
    }
};

// class Solution {
// public:
//     string getPermutation(int n, int k) {
//         vector<int> nums;
//         int fact = 1;
//         for(int i=1;i<n;i++){
//             fact = fact*1;
//             nums.push_back(i);
//         }
//         nums.push_back(n);
//         k = k-1;
//         string ans="";
//         while(true){
//             if(fact==0){
//                 ans+=to_string(nums[0]);
//                 nums.erase(nums.begin()+0);
//             }else{
//                 ans=ans+to_string(nums[k/fact]);
//                 nums.erase(nums.begin()+k/fact);
//             }
             
//             if(nums.size()==0){
//                 break;
//             }
//             k=k%fact;
//             fact=fact/nums.size();
//         }
//         return ans;
            
//     }
// };