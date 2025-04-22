class Solution(object):
    def numberOfArrays(self, differences, lower, upper):
        curr = 0
        mx = 0
        mn = 0
        for d in differences:
            curr+=d
            mx = max(mx, curr)
            mn = min(mn, curr)
            if (upper-mx)-(lower-mn) + 1<0:
                return 0

        return  (upper-mx)-(lower-mn) + 1
        
        """
        :type differences: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        