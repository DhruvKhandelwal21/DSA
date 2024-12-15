class Solution {
public:
    typedef pair<double, vector<int>> p;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<p> pq;
        for(auto it: classes){
            double growth = (double)(it[0]+1)/(it[1]+1) - (double)it[0]/it[1];
            pq.push({growth, it});
        }
        while(!pq.empty() && extraStudents>0){
            auto [avg, myClass] = pq.top();
            pq.pop();
            int pass = myClass[0];
            int total = myClass[1];
            pass++;
            total++;
            double newGrowth = (double)(pass+1)/(total+1) - (double)pass/total;
            pq.push({newGrowth, {pass, total}});
            extraStudents--;
        }
        double ans = 0;
        while(!pq.empty()){
            auto [avg, myClass] = pq.top();
            double temp = (double)myClass[0]/myClass[1];
            ans+=temp;
            pq.pop();
        }
        return (double)ans/(classes.size());
    }
};