class Solution(object):
    def maxProfit(self, prices):
        maxi = 0
        curr = 0
        for i in range(1, len(prices)):  
          if(prices[i]>prices[curr]):
            maxi = max(maxi, prices[i]-prices[curr])
          else:
            curr = i
        
        return maxi
 
        """
        :type prices: List[int]
        :rtype: int
        """
        