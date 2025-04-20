class Solution(object):
    def numRabbits(self, answers):
        answers.sort()
        hash = defaultdict(int)
        for a in answers:
            rabbit = a+1
            hash[rabbit]+=1
        ans=0
        for key in hash:
            temp = hash[key]%key
            grp = hash[key]//key
            if temp!=0:
                grp+=1
            ans+=(key)*grp
        return ans




        """
        :type answers: List[int]
        :rtype: int
        """
        