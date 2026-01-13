class Solution:
    def canServe(self, arr):
        five, ten = 0, 0  # Track count of ₹5 and ₹10 notes

        for bill in arr:
            if bill == 5:
                five += 1
            elif bill == 10:
                if five == 0:
                    return False
                five -= 1
                ten += 1
            elif bill == 20:
                if ten > 0 and five > 0:
                    ten -= 1
                    five -= 1
                elif five >= 3:
                    five -= 3
                else:
                    return False

        return True
