class Solution(object):
    def partition(self, s):
        ans = []
        def isPal(i,j):
            while(i<=j):
                if s[i]!=s[j]:
                    return False
                i+=1
                j-=1
            return True
        def solve(tempans, idx):
            if idx >= len(s):
                ans.append(tempans[:])
                return
            
            for i in range(idx, len(s)):
                if isPal(idx, i):
                    tempans.append(s[idx:i+1])
                    solve(tempans, i+1)
                    tempans.pop()
            
        
        solve([], 0)
        return ans
                    


        """
        :type s: str
        :rtype: List[List[str]]
        """
        