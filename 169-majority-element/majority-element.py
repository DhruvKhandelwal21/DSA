class Solution(object):
    def majorityElement(self, nums):
        major = nums[0]
        cnt = 1
        for i in range(1,len(nums)):
            if(cnt==0):
                major = nums[i]
            if nums[i]==major:
                cnt+=1
            else:
                cnt-=1
        return major
        """
        :type nums: List[int]
        :rtype: int
        """
        