class Solution(object):
    def combinationSum2(self, candidates, target):
        candidates.sort()
        cache = set()
        temp = []
        ans = []
        n = len(candidates)
        def solve(idx, total):
            if total ==target:
                cache.add(tuple(sorted(temp[:])))
                return
            
            for k in range(idx, n):
                if(k>idx  and candidates[k]==candidates[k-1]):
                    continue
                if total + candidates[k] > target:
                    break
                temp.append(candidates[k])
                solve(k+1, total + candidates[k])
                temp.pop()
        
        solve(0,0)
        unique_lists = [list(t) for t in cache]
        return unique_lists
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        