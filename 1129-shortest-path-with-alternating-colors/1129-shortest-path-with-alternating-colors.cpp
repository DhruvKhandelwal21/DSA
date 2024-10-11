class Solution
{
    public:
        typedef pair<int, pair<int, int>> p;
    vector<int> shortestAlternatingPaths(int n, vector<vector < int>> &redEdges, vector< vector< int>> &blueEdges)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < redEdges.size(); i++)
        {
            int u = redEdges[i][0];
            int v = redEdges[i][1];
            graph[u].push_back({ v,
                0 });
        }
        for (int i = 0; i < blueEdges.size(); i++)
        {
            int u = blueEdges[i][0];
            int v = blueEdges[i][1];
            graph[u].push_back({ v,
                1 });
        }
        queue<p> pq;
        pq.push({ 0,
            { 0,
                -1 } });
        vector<int> dist(n, INT_MAX);
        vector<int> redExp(n, -1);
        vector<int> blueExp(n, -1);
        dist[0] = 0;
        while (!pq.empty())
        {
            auto curr = pq.front();
            pq.pop();
            int currdist = curr.first;
            auto node = curr.second;
            int prevEdge = node.second;
            int currNode = node.first;
            for (auto it: graph[currNode])
            {
                auto adjNode = it.first;
                auto adjEdge = it.second;
                if (adjNode == 2)
                {
                    cout << prevEdge << " " << adjEdge << endl;
                }

                if (adjEdge != prevEdge || prevEdge == -1)
                {
                    if (adjEdge == 1 && blueExp[adjNode] == 1) continue;
                    if (adjEdge == 0 && redExp[adjNode] == 1) continue;
                    if (adjEdge == 0) redExp[adjNode] = 1;
                    if (adjEdge == 1) blueExp[adjNode] = 1;
                    if (dist[adjNode] > currdist + 1)
                    {
                        dist[adjNode] = currdist + 1;
                    }
                    pq.push({ currdist + 1,
                        {
                            adjNode,
                            adjEdge
                        } });
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }
        return dist;
    }
};