class Solution(object):
    def longestNiceSubarray(self, nums):
        mask = 0
        i=0 
        j=0 
        l = len(nums)
        ans = 0
        while(j<l):
            if mask & nums[j]!=0:
                mask^=nums[i]
                i+=1
            else:
                mask |=nums[j]
                ans = max(ans,j-i+1)
                j+=1
        
        return ans

        """
        :type nums: List[int]
        :rtype: int
        """
        