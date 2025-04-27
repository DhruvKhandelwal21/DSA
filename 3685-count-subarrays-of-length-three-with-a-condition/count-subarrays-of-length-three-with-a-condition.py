class Solution(object):
    def countSubarrays(self, nums):
        i,j,n=0,0,len(nums)
        sum=0
        while(j<n):
            if j-i+1==3:
                if (nums[i]+nums[j])==(nums[i+1] / 2.0):
                    sum+=1
                i+=1
            j+=1
        return sum
        

        """
        :type nums: List[int]
        :rtype: int
        """
        