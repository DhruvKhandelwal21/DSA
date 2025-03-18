class Solution(object):
    def singleNumber(self, nums):
        l = len(nums)
        ans = 0
        for i in range(0,32):
            cnt = 0
            for j in range(0, l):
                if (nums[j] & (1<<i)):
                    cnt+=1
            if(cnt%3==1):
                ans = ans | (1<<i)
        if ans >= (1 << 31):
            ans -= (1 << 32)
        return ans
        """
        :type nums: List[int]
        :rtype: int
        """
        