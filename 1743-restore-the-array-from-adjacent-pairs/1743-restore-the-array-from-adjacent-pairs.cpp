class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>> p;
        for(int i=0;i<adjacentPairs.size();i++)
        {
            p[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            p[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        vector<int> v;
        for(auto& i:p)
        if(i.second.size()==1)
        {
            v.push_back(i.first);
            v.push_back(i.second[0]);
            break;
        }
        int i=1;
        while(true)
        {
            if(p[v[i]].size()==1)
            {
                if(p[v[i]][0]!=v[i-1])
                v.push_back(p[v[i]][0]);
                break;
            }
            else
            {
                if(p[v[i]][0]==v[i-1])
                {
                    v.push_back(p[v[i]][1]);
                }
                else
                {
                    v.push_back(p[v[i]][0]);
                }
            }
            i++;
        }
        return v;
    }
};