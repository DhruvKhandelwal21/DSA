class Solution(object):
    def myPow(self, x, n):
        def solve(x,n):
            if n == 0:
                return 1
            elif n < 0:
                return 1 / solve(x, -n)
        
            half = solve(x, n // 2)
            if n % 2 == 0:
                return half * half
            else:
                return x * half * half
            return solve(x,n)
        return solve(x,n)


        """
        :type x: float
        :type n: int
        :rtype: float
        """
        