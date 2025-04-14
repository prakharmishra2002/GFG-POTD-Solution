class Solution:
    @staticmethod
    def findOrder(words):
        from collections import deque, defaultdict
        g = defaultdict(list)
        in_deg = [0] * 26
        seen = [0] * 26
        for w in words:
            for c in w:
                seen[ord(c) - 97] = 1
        for i in range(len(words) - 1):
            a, b = words[i], words[i + 1]
            j, n = 0, min(len(a), len(b))
            while j < n and a[j] == b[j]: j += 1
            if j == n and len(a) > len(b): return ""
            if j < n:
                u, v = ord(a[j]) - 97, ord(b[j]) - 97
                g[u].append(v)
                in_deg[v] += 1
        q = deque(i for i in range(26) if seen[i] and in_deg[i] == 0)
        res = []
        while q:
            u = q.popleft()
            res.append(chr(u + 97))
            for v in g[u]:
                in_deg[v] -= 1
                if in_deg[v] == 0: q.append(v)
        return "".join(res) if sum(seen) == len(res) else ""
