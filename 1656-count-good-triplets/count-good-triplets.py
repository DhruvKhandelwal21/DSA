class Solution(object):
    def countGoodTriplets(self, arr, a, b, c):
        n = len(arr)
        cnt = 0
        for i in range(0,n):
            for j in range(i+1,n):
                for k in range(j+1,n):
                    if abs(arr[i]-arr[j])<=a and abs(arr[j]-arr[k])<=b and abs(arr[i]-arr[k])<=c:
                        cnt+=1
        
        return cnt
                        

        """
        :type arr: List[int]
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        