class Solution:
    def cloneGraph(self, node):
        if not node: return None
        m, q = {node: Node(node.val)}, [node]
        while q:
            for n in q[0].neighbors:
                if n not in m:
                    m[n] = Node(n.val)
                    q.append(n)
                m[q[0]].neighbors.append(m[n])
            q.pop(0)
        return m[node]
