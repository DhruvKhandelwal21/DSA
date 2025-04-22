class Solution(object):
    def combinationSum(self, candidates, target):
        fuckThisAns=[]
        def fuckThisWorld(idx, target, temp):
            if idx==len(candidates):
                if target==0:
                    fuckThisAns.append(temp[:])
                return
            
            if candidates[idx] <= target:
                temp.append(candidates[idx])
                fuckThisWorld(idx, target-candidates[idx], temp)
                temp.pop()
            fuckThisWorld(idx+1, target, temp)
        
        fuckThisWorld(0,target, [])
        
        return fuckThisAns
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        