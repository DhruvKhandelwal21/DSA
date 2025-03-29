class Solution(object):
    def isValid(self, i,j,m,n):
        return i>=0 and j>=0 and i<n and j<m
    
    def maxPoints(self, grid, queries):
        n = len(grid)
        m = len(grid[0])
        upd_queries = sorted((queries[i], i) for i in range(len(queries)))
        visited = [[-1] * m for _ in range(n)]
        u = [-1, 0 ,1, 0]
        v = [0, 1, 0, -1]
        count = 0
        ans = [0]*len(queries)
        pq = [(grid[0][0], 0, 0)]
        visited[0][0] = 1
        for val, idx in upd_queries:
            while(pq and pq[0][0]<val):
                count+=1
                _, x, y = heapq.heappop(pq)
                for i in range(4):
                    newx, newy = x + u[i], y + v[i]
                    if(self.isValid(newx, newy, m, n) and visited[newx][newy]==-1):
                        visited[newx][newy] = 1
                        heapq.heappush(pq, (grid[newx][newy], newx, newy))
            ans[idx] = count
        return ans


        """
        :type grid: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        