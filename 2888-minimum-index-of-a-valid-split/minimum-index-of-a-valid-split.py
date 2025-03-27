class Solution(object):
    def minimumIndex(self, nums):
        numcnt = defaultdict(int)
        maxnum = -1
        n = len(nums)
        for num in nums:
            numcnt[num]+=1
            if numcnt[num] > n/2:
                maxnum = num
        
        tempcnt = 0
        flag = False
        ans = -1
        ansFlag = False
        for i in range(0,n):
            if maxnum==nums[i]:
                tempcnt+=1
                if flag == False:
                    if tempcnt > (i+1)/2:
                        ans = i
                        tempcnt = 0
                        flag = True
                else:
                    if tempcnt > (n-ans-1)/2:
                        ansFlag = True
        
        if ansFlag:
            return ans
        return -1
        
        """
        :type nums: List[int]
        :rtype: int
        """
        