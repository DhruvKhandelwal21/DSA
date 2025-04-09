class Solution(object):
    def minOperations(self, nums, k):
        hashmap = defaultdict(int)
        for num in nums:
            hashmap[num]+=1
            if num<k:
                return -1
        
        if hashmap[k] is not None:
            return len(hashmap) - 1
        return len(hashmap)
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        