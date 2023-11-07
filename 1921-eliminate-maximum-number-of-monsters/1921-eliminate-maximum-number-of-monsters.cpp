class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
       int time_pass = 1;
        int count = 1;
        vector<int> time;
        for(int i=0;i<dist.size();i++){
            int temp = ceil((float)dist[i]/speed[i]);
            time.push_back(temp);
            cout<<temp<<endl;
        }
        sort(time.begin(),time.end());
        for(int i=1;i<dist.size();i++){
            if(time[i]-time_pass<=0){
                return count;
            }
              time_pass+=1;
            count++;
        }
        return count;
    }
};