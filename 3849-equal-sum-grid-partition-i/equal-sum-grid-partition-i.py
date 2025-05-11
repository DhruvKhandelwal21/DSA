class Solution(object):
    def canPartitionGrid(self, grid):
        prefixRows = []
        prefixCols = []
        for i in  range(0,len(grid)):
            sum=0
            for j in range(0,len(grid[0])):
                sum+=grid[i][j]
            if len(prefixRows)==0:
                prefixRows.append(sum)
            else:
                prefixRows.append(prefixRows[len(prefixRows)-1] + sum)
        
        for i in range(len(grid[0])):
            sum=0
            for j in range(len(grid)):
                sum+=grid[j][i]
            if len(prefixCols)==0:
                prefixCols.append(sum)
            else:
                prefixCols.append(prefixCols[len(prefixCols)-1] + sum)
        
        n = len(prefixRows)
        m = len(prefixCols)
        print(prefixRows)
        print(prefixCols)
        for i in range(0,n-1):
            if prefixRows[i] == (prefixRows[n-1]-prefixRows[i]):
                return True
        
        for i in range(0,m-1):
            if prefixCols[i] == (prefixCols[m-1]-prefixCols[i]):
                return True
        
        return False
        
                
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        