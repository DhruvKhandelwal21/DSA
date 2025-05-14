#User function Template for python3

from typing import List

class Solution:
    def reverse(self,St): 
        
        def test(St, temp):
            if len(St)==0:
                St.append(temp)
                return
            t = St.pop()
            test(St, temp)
            St.append(t)
        
        def solve(St):
            if len(St)==1:
                return
            temp = St.pop()
            solve(St)
            test(St, temp)
            
        
        n = len(St)
        if n==1:
            return St
        solve(St)
        return St
        


#{ 
 # Driver Code Starts

#Initial Template for Python 3

 
for _ in range(int(input())):
    N = int(input())
    St = list(map(int, input().split()))
    ob = Solution()
    ob.reverse(St)
    print(*St)
    print("~")
# } Driver Code Ends