class Solution:
    
    # Function to check if two strings are rotations of each other or not.
    def areRotations(self, s1, s2):
        # Check if lengths of two strings are equal or not
        if len(s1) != len(s2):
            return False
        # Concatenate s1 with itself and see if s2 is a substring of it
        return s2 in (s1 + s1)