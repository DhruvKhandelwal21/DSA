class Solution(object):
    class DisjointSet:
        def __init__(self, n):
            self.rank = [0] * (n + 1)
            self.parent = [i for i in range(n + 1)]
            self.size = [1] * (n + 1)

        def findUpar(self, node):
            if node == self.parent[node]:
                return node
            self.parent[node] = self.findUpar(self.parent[node])
            return self.parent[node]

        def unionByRank(self, u, v):
            parU = self.findUpar(u)
            parV = self.findUpar(v)
            if parU == parV:
                return
            if self.rank[parU] > self.rank[parV]:
                self.parent[parV] = parU
            elif self.rank[parU] < self.rank[parV]:
                self.parent[parU] = parV
            else:
                self.parent[parU] = parV
                self.rank[parV] += 1

        def unionBySize(self, u, v):
            parU = self.findUpar(u)
            parV = self.findUpar(v)
            if parU == parV:
                return
            if self.size[parU] > self.size[parV]:
                self.parent[parV] = parU
                self.size[parU] += self.size[parV]
            else:
                self.parent[parU] = parV
                self.size[parV] += self.size[parU]

    def accountsMerge(self, accounts):
        v = len(accounts)
        ds = self.DisjointSet(v)
        mydict = {}
        
        # Initialize an empty list of lists for merged account emails
        arr = [[] for _ in range(v)]
        
        # Step 1: Create the union-find structure
        for i in range(v):
            for j in range(1, len(accounts[i])):
                email = accounts[i][j]
                if email not in mydict:
                    mydict[email] = i
                else:
                    ds.unionBySize(mydict[email], i)

        # Step 2: Group emails by root parent
        for email, index in mydict.items():
            root = ds.findUpar(index)
            arr[root].append(email)

        ans = []

        # Step 3: Sort and prepare the final merged account list
        for i in range(v):
            if len(arr[i]) == 0:
                continue
            arr[i].sort()  # Sort emails for each account
            temp = [accounts[i][0]]  # Start with the account name
            temp.extend(arr[i])  # Add the sorted emails
            ans.append(temp)
        
        return ans
