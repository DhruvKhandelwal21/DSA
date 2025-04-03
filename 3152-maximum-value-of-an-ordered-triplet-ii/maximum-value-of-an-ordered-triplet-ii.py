class Solution(object):
    def maximumTripletValue(self, nums):
        n = len(nums)
        pre_max = [0]*n
        su_max = [0]*n
        for i in range(1,n):
            pre_max[i] = max(pre_max[i-1], nums[i-1])
        
        for i in range(n-2, -1, -1):
            su_max[i] = max(su_max[i+1], nums[i+1])
        
        ans = 0

        for i in range(0,n):
            ans = max(ans, (pre_max[i]-nums[i])*su_max[i])
        
        if ans < 0:
            return 0
        
        return ans


        """
        :type nums: List[int]
        :rtype: int
        """
        