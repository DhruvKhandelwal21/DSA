class Solution {
public:
    typedef pair<int,int> p;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> graph(26);
        int n = cost.size();
        for(int i=0;i<n;i++){
            graph[original[i]-'a'].push_back({(changed[i]-'a'),cost[i]});
        }
        long long ans = 0;
        unordered_map<int,vector<pair<int,int>>> mp;
        vector<long long> finalDest(26,-1);
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]) continue;
            if(graph[source[i]-'a'].size()==0) return -1;
            int temp = 0;
            if(mp.count(source[i]-'a')){
                for(auto it: mp[source[i]-'a']){
                    if(it.first==target[i]-'a'){
                        temp=it.second;
                        break;
                    }
                }
            }
            if(temp!=0){
                ans+=temp;
                continue;
            }
            priority_queue<p,vector<p>, greater<p>> pq;
            pq.push({0,(source[i]-'a')});
            vector<long long> dist(26,INT_MAX);
            dist[source[i]-'a'] = 0;
            while(!pq.empty()){
                auto curr = pq.top();
                pq.pop();
                int node = curr.second;
                int nodedist = curr.first;
                if(node==target[i]-'a'){
                       temp = nodedist;
                       ans+=temp;
                       mp[source[i]-'a'].push_back({target[i]-'a',nodedist});
                       break;
                }
                for(auto it:graph[node]){
                    int adjNode = it.first;
                    int adjdist = it.second;
                    if(dist[adjNode]>nodedist + adjdist){
                        dist[adjNode] = nodedist + adjdist;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }
            if(dist[target[i]-'a']==INT_MAX){
                return -1;
            }
        }
        return ans;
    }
};