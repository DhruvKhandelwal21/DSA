class Solution
{
    public:
        vector<int> gardenNoAdj(int n, vector<vector < int>> &paths)
        {
            vector<vector < int>> graph(n + 1);
            for (int i = 0; i < paths.size(); i++)
            {
                int u = paths[i][0];
                int v = paths[i][1];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
            vector<int> flower(n + 1, -1);
            queue<int> q;

            for (int i = 1; i <= n; i++)
            {
                q.push(i);
                if (flower[i] == -1)
                {
                    while (!q.empty())
                    {
                        int garden = q.front();
                        q.pop();
                        vector<int> v(5, -1);

                        for (auto it: graph[garden])
                        {
                            if (flower[it] == -1)
                            {
                                q.push(it);
                            }
                            else
                            {
                                v[flower[it]] = 0;
                            }
                        }
                        for (int i = 1; i < 5; i++)
                        {
                            if (v[i] == -1)
                            {
                                flower[garden] = i;
                            }
                        }
                    }
                }
            }
            flower.erase(flower.begin());
            return flower;
        }
};