#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canServe(vector<int>& arr) {
        int five = 0, ten = 0;

        for (int bill : arr) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else if (bill == 20) {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 5, 5, 10, 20};
    cout << (sol.canServe(arr) ? "true" : "false") << endl;  // Output: true
    return 0;
}
