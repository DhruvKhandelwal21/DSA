class Solution(object):
    def minOperations(self, grid, x):
        nums = sorted([num for row in grid for num in row])
        median = nums[len(nums)//2]
        for num in nums:
            if((num-nums[0])%x!=0):
                return -1
        
        return sum(abs(num-median) // x for num in nums)
        """
        :type grid: List[List[int]]
        :type x: int
        :rtype: int
        """
        