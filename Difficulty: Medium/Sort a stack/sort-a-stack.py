class Solution:
    # your task is to complete this function
    # function sort the stack such that top element is max
    # funciton should return nothing
    # s is a stack
    def Sorted(self, s):
        def insertInSortedStack(s, num):
            if not s or s[-1] <= num:
                s.append(num)
                return
            
            temp = s.pop()
            
            insertInSortedStack(s, num)
            s.append(temp)
        
        if not s:
            return
        temp = s.pop()
        self.Sorted(s)
        insertInSortedStack(s, temp)


#{ 
 # Driver Code Starts

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ob.Sorted(arr)
        for e in range(len(arr)):
            print(arr.pop(), end=" ")
        print()


        print("~")
# } Driver Code Ends