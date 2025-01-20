class Solution:
    def sortedMerge(self, head1, head2):
        # Create a dummy node to serve as the starting point of the merged list
        dummy = Node(0)
        tail = dummy

        # Traverse both lists and merge them in sorted order
        while head1 and head2:
            if head1.data <= head2.data:
                tail.next = head1
                head1 = head1.next
            else:
                tail.next = head2
                head2 = head2.next
            tail = tail.next

        # If either list has remaining nodes, append them to the merged list
        if head1:
            tail.next = head1
        elif head2:
            tail.next = head2

        # Return the head of the merged list
        return dummy.next
