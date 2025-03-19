class Solution(object):
    def minOperations(self, nums):
        ops = 0
        n = len(nums)
        for i in range(0, n-2):
            if nums[i]==0:
                nums[i] = 1 - nums[i]
                nums[i+1] = 1 - nums[i+1]
                nums[i+2] = 1 - nums[i+2]
                ops+=1
        
        if(nums[n-1]==0 or nums[n-2]==0): 
            return -1
        return ops


        """
        :type nums: List[int]
        :rtype: int
        """
        