class Solution(object):
    def __init__(self):
        self.memo = {}
    def solve(self, questions, idx, n):
        if idx>=n:
            return 0
        if idx in self.memo:
            return self.memo[idx]
        self.memo[idx] = max(questions[idx][0] + self.solve(questions, idx + questions[idx][1] + 1, n), self.solve(questions, idx + 1, n))
        return self.memo[idx]
    def mostPoints(self, questions):
        n = len(questions)
        return self.solve(questions, 0, n)

        """
        :type questions: List[List[int]]
        :rtype: int
        """
        