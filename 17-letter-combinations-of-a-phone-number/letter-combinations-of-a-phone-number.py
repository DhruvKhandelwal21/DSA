class Solution(object):
    def letterCombinations(self, digits):
        ans = []
        if len(digits)==0:
            return ans
        hash = defaultdict(str)
        hash['2'] = ["a","b","c"]
        hash['3'] = ["d", "e","f"]
        hash['4'] = ["g", "h","i"]
        hash['5'] = ["j","k","l"]
        hash['6'] = ["m","n","o"]
        hash['7'] = ["p","q","r","s"]
        hash['8'] = ["t", "u", "v"]
        hash['9'] = ["w","x","y","z"]

        def solve(idx, temp):
            if idx >= len(digits):
                ans.append(temp[:])
                return
            numData = hash[digits[idx]]
            for i in range(0, len(numData)):
                temp+=numData[i]
                solve(idx+1, temp)
                temp = temp[:-1]
        
        solve(0, "")
        return ans





        
        


        """
        :type digits: str
        :rtype: List[str]
        """
        