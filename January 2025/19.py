class Solution:
    def rotate(self, head, k):
        if k == 0 or head is None:
            return head
        curr = head
        length = 1
        while curr.next is not None:
            curr = curr.next
            length += 1
        k %= length
        if k == 0:
            curr.next = None
            return head
        curr.next = head
        curr = head
        for _ in range(1, k):
            curr = curr.next
        newHead = curr.next
        curr.next = None
        return newHead
