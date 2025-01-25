# Node Class
class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None

class Solution:
    def findFirstNode(self, head):
        # Initialize slow and fast pointers
        slow = head
        fast = head
        
        # Detect if there is a loop using Floyd's Cycle-Finding Algorithm
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break
        
        # If no loop is found, return None
        if not fast or not fast.next:
            return None
        
        # Find the start of the loop
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        
        return slow  # Return the node itself
