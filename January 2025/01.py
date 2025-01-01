from collections import defaultdict

class Solution:
    def anagrams(self, arr):
        umap = defaultdict(list)
        for s in arr:
            sorted_s = ''.join(sorted(s))
            umap[sorted_s].append(s)
        
        return list(umap.values())