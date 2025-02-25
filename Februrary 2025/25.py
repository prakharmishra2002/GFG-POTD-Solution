class Solution:
    def getMaxArea(self, arr):
        # Initialize an empty stack and max area
        stack = []
        max_area = 0
        index = 0

        while index < len(arr):
            # If this bar is higher than the bar at stack top, push it to the stack
            if not stack or arr[stack[-1]] <= arr[index]:
                stack.append(index)
                index += 1
            else:
                # Pop the top
                top_of_stack = stack.pop()
                # Calculate the area with arr[top_of_stack] as the smallest (or minimum height) bar 'h'
                area = (arr[top_of_stack] * ((index - stack[-1] - 1) if stack else index))
                # Update max_area, if needed
                max_area = max(max_area, area)

        # Now, pop the remaining bars from stack and calculate area with each popped bar
        while stack:
            top_of_stack = stack.pop()
            area = (arr[top_of_stack] * ((index - stack[-1] - 1) if stack else index))
            max_area = max(max_area, area)

        return max_area
