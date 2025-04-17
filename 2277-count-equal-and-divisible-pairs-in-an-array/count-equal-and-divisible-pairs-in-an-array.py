from collections import defaultdict
class Solution(object):
    def countPairs(self, nums, k):
        hash = defaultdict(list)
        cnt = 0
        for i in range(0, len(nums)):
            if hash[nums[i]] is not None:
                for j in hash[nums[i]]:
                    if (j*i)%k==0:
                        cnt+=1
            hash[nums[i]].append(i)
        
        return cnt


        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        