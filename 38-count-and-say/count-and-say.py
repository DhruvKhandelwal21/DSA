class Solution(object):
    def countAndSay(self, n):
        if n==1:
            return "1"

        def generateRleString(temp):
            cnt = 1
            op = ""
            for i in range(1, len(temp)):
                if temp[i]==temp[i-1]:
                    cnt+=1
                else:
                    op+=str(cnt) + temp[i-1]
                    cnt = 1
            
            op += str(cnt) + temp[-1]
            return op




        def solve(x, temp):
            if x>n:
                return temp
            
            updated_str = generateRleString(temp)
            return solve(x+1, updated_str)

        temp = "1"
        return solve(2, temp)

        """
        :type n: int
        :rtype: str
        """
        