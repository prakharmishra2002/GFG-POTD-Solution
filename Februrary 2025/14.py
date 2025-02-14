class Solution:
    def correctBST(self, root):
        self.first = self.middle = self.last = self.prev = None

        def inorder(node):
            if not node:
                return
            inorder(node.left)
            if self.prev and node.data < self.prev.data:
                if not self.first:
                    self.first, self.middle = self.prev, node
                else:
                    self.last = node
            self.prev = node
            inorder(node.right)

        inorder(root)
        self.first.data, (self.last or self.middle).data = (self.last or self.middle).data, self.first.data
