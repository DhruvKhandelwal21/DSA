class Solution
{
    public:
        typedef pair<int, int> p;
    struct MinHeapComparator
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            if (a.first == b.first)
            {
                return a.second > b.second;	// Compare second elements if first elements are equal
            }
            return a.first > b.first;	// Compare first elements otherwise
        }
    };
    long long findScore(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> vis(n, 0);
        priority_queue<p, vector < p>, MinHeapComparator> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({ nums[i],i });
        }
        long long int ans = 0;
        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int num = x.first;
            int idx = x.second;
          
            if (vis[idx] != 1)
            {
                if (idx - 1 >= 0)
                {
                    vis[idx - 1] = 1;
                }
               
                if (idx + 1 <= n - 1)
                {
                    vis[idx + 1] = 1;
                }
                vis[idx] = 1;
                ans += num;
            }
        }
        return ans;
    }
};