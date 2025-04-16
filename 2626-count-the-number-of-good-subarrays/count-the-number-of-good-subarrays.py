class Solution(object):
    def countGood(self, nums, k):
        cnt = 0
        n = len(nums)
        i,j = 0,0
        hash = defaultdict(int)
        '''
        first find your first subarray with at least k valid pairs
        once you get it store the result in cnt ---> n-j
        ---> then start moving the ith pointer till it gives the valid result
        ---> 
        lessgo
        '''
        paircnt = 0
        while j<n:
            paircnt+=hash[nums[j]]
            hash[nums[j]]+=1
            if paircnt>=k:
                while paircnt>=k:
                    cnt+=n-j
                    left = nums[i]
                    hash[nums[i]]-=1
                    paircnt-=hash[nums[i]]
                    i+=1
            j+=1
        
        return cnt
            
            





        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        