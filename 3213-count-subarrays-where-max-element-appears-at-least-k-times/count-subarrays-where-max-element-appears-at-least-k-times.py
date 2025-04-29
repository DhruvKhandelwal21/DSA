class Solution(object):
    def countSubarrays(self, nums, k):
        mx = max(nums)
        i,j, n = 0,0,len(nums)
        cnt = 0
        ans=0
        while j<n:
            if nums[j]==mx:
                cnt+=1
            while(cnt==k):
                ans+=n-j
                if nums[i]==mx:
                    cnt-=1
                i+=1
            j+=1
        return ans
                
                



        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        