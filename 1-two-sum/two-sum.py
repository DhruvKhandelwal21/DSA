class Solution(object):
    def twoSum(self, nums, target):
        d = {}
        for i in range(len(nums)):
            d[nums[i]] = i
        for i in range(len(nums)):
            x = nums[i]
            z = target - x
            if z in d and i!=d[z]:
               return [i, d[z]]
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        