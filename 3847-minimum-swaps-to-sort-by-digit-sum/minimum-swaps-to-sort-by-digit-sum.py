class Solution(object):
    def minSwaps(self, nums):
        temp = []
        for i in range(0,len(nums)):
            digit_sum = sum(int(d) for d in str(nums[i]))
            temp.append((digit_sum, nums[i], i))
        
        temp.sort(key=lambda x: (x[0], x[1]))
        n = len(nums)
        res = 0
        vis = [False] * n

        for i in range(0, n):
            if vis[i]==True or temp[i][2]==i:
                continue
            c = 0
            j = i
            while not vis[j]:
                vis[j] = True
                j = temp[j][2]
                c+=1
            if c > 1:
                res+=c-1
        
        return res


        


        """
        :type nums: List[int]
        :rtype: int
        """
        