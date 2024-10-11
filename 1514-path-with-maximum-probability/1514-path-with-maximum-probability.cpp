class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back({v,succProb[i]});
            graph[v].push_back({u, succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        vector<double> dist(n,0);
        dist[start_node] = 1.0;
        while(!pq.empty()){
            auto item = pq.top();
            pq.pop();
            int node = item.second;
            double prob = item.first;
            for(auto it: graph[node]){
                int adjNode = it.first;
                double adjProb = it.second;
                double res = adjProb*prob;
                if(dist[adjNode]<res){
                    pq.push({res, adjNode});
                    dist[adjNode] = res;
                }
            }
        }
        return dist[end_node];
    }
};