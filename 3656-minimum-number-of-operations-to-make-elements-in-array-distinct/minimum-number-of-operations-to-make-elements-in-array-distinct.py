class Solution(object):
    def minimumOperations(self, nums):
        hash = defaultdict(int)
        sz = len(nums)
        cnt=0
        for num in nums:
            hash[num]+=1
        if sz==len(hash):
            return 0
        for i in range(0, sz):
            if  i!=0 and i%3==0:
                cnt+=1
                if sz-i==len(hash):
                    return cnt
            hash[nums[i]]-=1
            if hash[nums[i]]==0:
                 hash.pop(nums[i])
        
        return cnt+1
            
        
        """
        :type nums: List[int]
        :rtype: int
        """
        