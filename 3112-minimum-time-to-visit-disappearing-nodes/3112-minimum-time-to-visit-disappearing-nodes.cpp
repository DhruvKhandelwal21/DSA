class Solution
{
    public:
    typedef pair<int,int> p;
        vector<int> minimumTime(int n, vector<vector < int>> &edges, vector< int > &disappear) {
            vector<vector<pair<int,int>>> graph(n);
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int t = it[2];
                graph[u].push_back({v,t});
                graph[v].push_back({u,t});
                
            }
            priority_queue<p,vector<p>, greater<p>> pq;
            pq.push({0,0});
            vector<int> dist(n,INT_MAX);
            dist[0] = 0;
            vector<int> vis(n,0);
                while(!pq.empty()){
                auto curr = pq.top();
                pq.pop();
                int node = curr.second;
                int nodedist = curr.first;
                if(vis[node]) continue;
                vis[node] = 1;
                for(auto it:graph[node]){
                    int adjNode = it.first;
                    int adjdist = it.second;
                    int tempdist = nodedist + adjdist;
                    if(!vis[adjNode] && dist[adjNode]>nodedist + adjdist){
                        if(tempdist<disappear[adjNode]){
                            dist[adjNode] = nodedist + adjdist;
                            pq.push({dist[adjNode], adjNode});
                        }
                    }
                }
            }
            for(int i=0;i<n;i++){
                if(dist[i]==INT_MAX){
                    dist[i] = -1;
                }
            }
            return dist;
        }
};