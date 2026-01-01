'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''

class Solution:
    def intersectPoint(self, head1, head2):
        # If either list is empty, no intersection possible
        if not head1 or not head2:
            return None  # or -1 as per platform expectation
        
        # Step 1: Get lengths and tails
        len1, tail1 = self.get_length_and_tail(head1)
        len2, tail2 = self.get_length_and_tail(head2)
        
        # If tails are different → no intersection (though problem guarantees intersection)
        if tail1 != tail2:
            return -1
        
        # Step 2: Make both pointers start from same relative position
        longer = head1 if len1 > len2 else head2
        shorter = head2 if len1 > len2 else head1
        diff = abs(len1 - len2)
        
        # Move pointer of longer list ahead by 'diff' nodes
        for _ in range(diff):
            longer = longer.next
        
        # Step 3: Traverse both lists together until intersection found
        while shorter != longer:
            shorter = shorter.next
            longer = longer.next
        
        # Return the intersection node (or its data if required)
        return shorter  # this is the intersection node

    def get_length_and_tail(self, head):
        length = 0
        curr = head
        while curr.next:
            length += 1
            curr = curr.next
        return length + 1, curr  # +1 because we count the head too
