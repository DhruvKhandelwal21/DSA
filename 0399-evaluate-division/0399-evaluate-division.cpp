class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        unordered_set<string> st;
        
        for(int i=0;i<equations.size();i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double x = values[i];
            mp[a].push_back({b,x});
            mp[b].push_back({a,1.0/x});
            st.insert(a);
            st.insert(b);
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            string a = queries[i][0];
            string b = queries[i][1];
            if(!st.count(a) || !st.count(b)){
                ans.push_back(-1.0);
                continue;
            }
            queue<pair<string, double>> q;
            unordered_set<string> vis;
            q.push({a,1.0});
            bool found = false;
            double sol = -1.0;
            while(!q.empty()){
                auto temp = q.front();
                string node = temp.first;
                double dest = temp.second;
                if(node==b){
                    sol = dest;
                    found = true;
                    break;
                }
                vis.insert(node);
                q.pop();
                for(auto it: mp[node]){
                    string nexNode = it.first;
                    double d = it.second;
                    if(!vis.count(nexNode)){
                        q.push({nexNode, d*dest});
                    }
                }
            }
            ans.push_back(found ? sol : -1.0);
        }
        return ans;
    }
};