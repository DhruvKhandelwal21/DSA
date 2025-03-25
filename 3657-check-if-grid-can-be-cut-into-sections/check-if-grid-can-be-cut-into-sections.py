class Solution(object):
    def checkValidCuts(self, n, rectangles):
        rectangles.sort(key=lambda rect: rect[0])
        xlast = 0
        cnt = 0
        for i in range(0, len(rectangles)):
            st, end = rectangles[i][0], rectangles[i][2]
            if st>=xlast:
                cnt+=1
            xlast = max(xlast, end)
        
        if(cnt>2):
            return True
        
        rectangles.sort(key=lambda rect: rect[1])
        cnt = 0
        ylast = 0
        for i in range(0, len(rectangles)):
             st, end = rectangles[i][1], rectangles[i][3]
             if st>=ylast:
                cnt+=1
             ylast = max(ylast, end)
        if(cnt>2):
            return True
        
        return False

        """
        :type n: int
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        