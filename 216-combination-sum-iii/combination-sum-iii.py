class Solution(object):
    def combinationSum3(self, k, n):
        ans = []

        def solve(k, n, idx, temp):
            if k<0 or n<0:
                return
            if n==0 and k==0:
                ans.append(temp[:])
                return
            
            for i in range(idx,10):
                temp.append(i)
                solve(k-1, n-i, i+1, temp)
                temp.pop()
            
        solve(k,n, 1, [])
        return ans
            
                
        
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        