class Solution(object):
    def generateParenthesis(self, n):
        ans = []

        def solve(temp, cntx, cnty):
            if cntx > cnty or cntx < 0:
                return
            if cntx==0 and cnty==0:
                ans.append(temp)
                return

            temp+='('
            solve(temp, cntx-1, cnty)
            temp = temp[:-1]

            temp+=')'
            solve(temp, cntx, cnty-1)
            temp = temp[:-1]
        
        solve("", n, n)

        return ans

        """
        :type n: int
        :rtype: List[str]
        """
        