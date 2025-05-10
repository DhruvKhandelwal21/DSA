#{ 
 # Driver Code Starts
import sys
sys.setrecursionlimit(10008)


# } Driver Code Ends

#User function Template for python3
class Solution:
    def deleteMid(self, stack):
        if len(stack)==0:
            return
        
        def solve(stack, k):
            if k==1:
                stack.pop()
                return
            temp = stack.pop()
            solve(stack, k-1)
            stack.append(temp)
            return
        
        k = (len(stack) // 2) + 1
        solve(stack,k)
        return

#{ 
 # Driver Code Starts.


if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        line = input().strip()
        stack = list(map(int, line.split()))

        # Reverse the list to mimic stack behavior (LIFO)

        ob = Solution()
        ob.deleteMid(stack)

        # Reverse again to print in expected order
        stack.reverse()
        print(" ".join(map(str, stack)))
        print("~")

# } Driver Code Ends