class Solution(object):
    def minBitFlips(self, start, goal):
        targetbits = start^goal
        ans = 0
        for i in range(0, 31):
            if(targetbits & (1<<i)):
                ans+=1
        
        return ans
        """
        :type start: int
        :type goal: int
        :rtype: int
        """
        