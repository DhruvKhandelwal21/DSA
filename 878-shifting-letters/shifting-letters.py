class Solution(object):
    def shiftingLetters(self, s, shifts):
        """
        shift[i] + s[i] / 25  //-> it will give me the idx on which char will go
        """
        ans=""
        cnt = 0
        for i in range(len(shifts)-1, -1, -1):
            cnt+=shifts[i]
            temp = ord(s[i]) - ord('a')
            updated_temp = (temp + cnt) % 26
            upd_char = chr(ord('a') + updated_temp)
            ans += upd_char
        finalans = ans[::-1]
        return finalans


            

        """
        :type s: str
        :type shifts: List[int]
        :rtype: str
        """
        