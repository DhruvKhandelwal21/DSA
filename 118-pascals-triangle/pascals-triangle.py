class Solution(object):
    def generate(self, numRows):
        ansList = []
        prev = []
        i=0
        while(i<numRows):
            if(i==0):
                prev = [1]
                ansList.append(prev)
            else:
                curr = [1]
                j = 1
                while(j<i):
                    curr.append(prev[j-1]+prev[j])
                    j+=1
                curr.append(1)
                ansList.append(curr)
                prev = curr
            i+=1
        return ansList
        
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        