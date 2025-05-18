class Solution(object):
    def subsetsWithDup(self, nums):
        n = len(nums)
        nums.sort()
        ans = []
        temp = []
        cache = set()
        def solve(idx, n):
            if idx>=n:
                cache.add(tuple((temp[:])))
                return
            temp.append(nums[idx])
            solve(idx+1, n)
            temp.pop()
            solve(idx+1, n)
        
        solve(0,n)
        unique_lists = [list(t) for t in cache]
        return unique_lists
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        