class Solution(object):
    def subsets(self, nums):
        n = len(nums)
        ans = []
        temp = []
        def solve(idx, n):
            if idx>=n:
                ans.append(temp[:])
                return
            temp.append(nums[idx])
            solve(idx+1, n)
            temp.pop()
            solve(idx+1, n)
        
        solve(0,n)
        return ans

        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        