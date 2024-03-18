bool comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),comp);
        int end = points[0][1];
        int ans = 1;
        for(int i=1;i<n;i++){
            if(points[i][0]>end){
                ans++;
                end = points[i][1];
            }
        }
        return ans;
        
    }
};