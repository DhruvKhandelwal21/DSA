class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        float med;
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int k = nums1.size();
        
        if(k%2!=0){
            med = nums1[((k+1)/2)-1];
        }
        else{
            med = (nums1[(k/2 - 1)] + nums1[(k/2)] )/2.0;
            
        }
        return med;
    }
};