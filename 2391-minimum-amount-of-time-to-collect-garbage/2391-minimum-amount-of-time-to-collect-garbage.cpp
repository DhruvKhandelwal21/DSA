class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size(),m = travel.size();
        int m_count=  0,p_count = 0,g_count = 0,midx = -1,gidx = -1, pidx = -1;
        vector<int> prefix(m);
        int sum = 0;
        for(int i=0;i<m;i++){
            sum+=travel[i];
            prefix[i] = sum;
        }
        
        for(int i=0;i<n;i++){
            string temp = garbage[i];
            for(int j = 0;j<temp.size();j++){
                if(temp[j]=='G'){
                    g_count++;
                    gidx = i;
                }else if(temp[j]=='P'){
                    p_count++;
                    pidx = i;
                }else if(temp[j]=='M'){
                    m_count++;
                    midx = i;
                }
            }
        }
        int distsum = 0;
        if(midx>0){
            distsum+=prefix[midx-1];
        }
        if(gidx>0){
            distsum+=prefix[gidx-1];
        }
        if(pidx>0){
            distsum+=prefix[pidx-1];
        }
        
        return p_count + g_count + m_count + distsum;
    }
};