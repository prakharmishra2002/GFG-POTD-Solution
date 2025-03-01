class Solution:
    def decodedString(self, s):
        stack = []
        current_num = 0
        current_string = ''
        
        for char in s:
            if char.isdigit():
                current_num = current_num * 10 + int(char)
            elif char == '[':
                stack.append((current_string, current_num))
                current_string = ''
                current_num = 0
            elif char == ']':
                last_string, num = stack.pop()
                current_string = last_string + num * current_string
            else:
                current_string += char
        
        return current_string
