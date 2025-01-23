class Solution:
    def cloneLinkedList(self, head):
        if head is None:
            return None

        # Create the clone nodes and insert them next to original nodes
        t = head
        while t:
            n = Node(t.data)
            n.next = t.next
            t.next = n
            t = n.next

        # Set the random pointers for the clone nodes
        t = head
        while t:
            if t.random:
                t.next.random = t.random.next
            t = t.next.next

        # Separate the clone list from the original list
        t = head
        newHead = head.next
        while t:
            temp = t.next
            t.next = temp.next
            if temp.next:
                temp.next = temp.next.next
            t = t.next

        return newHead
