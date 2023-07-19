class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int st = intervals[0][0];
        int end = intervals[0][1];
        int prev = 0;
        int count = 1;
       for(int i=1;i<n;i++){
           if(intervals[i][0]<end){
               end = min(end,intervals[i][1]);
           }else{
               count++;
               st = intervals[i][0];
               end = intervals[i][1];
           }
       }
        
        return n-count;
        
    }
};