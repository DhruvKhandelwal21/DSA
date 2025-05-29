class Solution:
    # Function to find all possible paths
    def ratInMaze(self, maze):
        ans = []
        n = len(maze)
        m = len(maze[0])
        
        u = [0,-1,0,1]
        v = [1,0,-1,0]
        visited = [[False for _ in range(m)] for _ in range(n)]
        
        def check(i,j):
            if i>=n or i<0 or j>=m or j<0 or maze[i][j]==0:
                return False
            return True
        
        def movement(u,v):
            if u==0 and v==1:
                return 'R'
            elif u==-1 and v==0:
                return 'U'
            elif u==1 and v==0:
                return 'D'
            elif u==0 and v==-1:
                return 'L'
            
        
        def solve(temp,i, j, visited):
            if i==n-1 and j==m-1:
                ans.append(temp)
                return
            
            visited[i][j] = 1
            
            for k in range(4):
                newx = i + u[k]
                newy = j + v[k]
                if check(newx, newy) and not visited[newx][newy]:
                    x = movement(u[k], v[k])
                    solve(temp + x, newx, newy, visited)
                
            visited[i][j] = 0
            
            return;
            
            
            
        
        solve("",0,0, visited)
        final_ans = sorted(ans)
        return final_ans
        
        