class Solution(object):
    def canPartition(self, nums):
        def solve(nums, target, idx, dp):
            if target==0:
                return True
            if idx<0:
                return False
            
            if dp[idx][target] != -1:
                return dp[idx][target]

            dp[idx][target] = solve(nums, target - nums[idx], idx - 1, dp) or solve(nums, target, idx - 1, dp)
            return dp[idx][target]
    

        sum = 0
        for num in nums:
            sum+=num
        if sum%2!=0:
            return False
        target = sum/2
        idx = len(nums)
        dp = [[-1 for _ in range(target + 1)] for _ in range(idx + 1)]
        return solve(nums,target, idx-1, dp)
    

        """
        :type nums: List[int]
        :rtype: bool
        """
        