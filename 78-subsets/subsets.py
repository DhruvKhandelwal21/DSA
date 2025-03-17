class Solution(object):
    def subsets(self, nums):
        l = len(nums)
        n = 1 << l
        ans = []
        for i in range(0,n):
            temp = []
            for j in range(0,l):
                if i & (1 << j):
                    temp.append(nums[j])
            ans.append(temp)
        
        return ans
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        