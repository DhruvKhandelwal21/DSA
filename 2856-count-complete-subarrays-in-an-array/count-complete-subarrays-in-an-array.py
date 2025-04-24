class Solution(object):
    def countCompleteSubarrays(self, nums):
        hash1 = defaultdict(int)
        for num in nums:
            hash1[num]+=1
        sz = len(hash1)
        i,j,n = 0,0,len(nums)
        hash2 = defaultdict(int)
        ans = 0
        while j<n:
            hash2[nums[j]]+=1
            while(len(hash2)==sz):
                ans+=n-j
                hash2[nums[i]]-=1
                if hash2[nums[i]]==0:
                    hash2.pop(nums[i])
                i+=1
            j+=1
        
        return ans


        """
        :type nums: List[int]
        :rtype: int
        """
        