class Solution(object):
    def findTheWinner(self, n, k):
        ans = 0
        for i in range(1,n+1):
            ans = (ans+k)%i
        
        return ans+1


        """
        :type n: int
        :type k: int
        :rtype: int
        """
        