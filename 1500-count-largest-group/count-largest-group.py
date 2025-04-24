class Solution(object):
    def countLargestGroup(self, n):
        hash = defaultdict(int)
        maxcnt = 0
        for i in range(1,n+1):
            digit_sum = sum(int(digit) for digit in str(i))
            hash[digit_sum]+=1
            maxcnt = max(maxcnt, hash[digit_sum])
        ans = 0
        for key in hash:
            if hash[key]==maxcnt:
                ans+=1
        
        return ans



        """
        :type n: int
        :rtype: int
        """
        