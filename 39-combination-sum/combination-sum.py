class Solution(object):
    def combinationSum(self, candidates, target):
        cache = set()
        temp = []
        ans = []
        n = len(candidates)
        def solve(idx, total):
            if total ==target:
                cache.add(tuple(sorted(temp[:])))
                return
            if idx >= n or total > target:
                return

            temp.append(candidates[idx])
            solve(idx, total + candidates[idx])
            temp.pop()
            solve(idx+1, total)
        
        solve(0,0)
        unique_lists = [list(t) for t in cache]
        return unique_lists


        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        