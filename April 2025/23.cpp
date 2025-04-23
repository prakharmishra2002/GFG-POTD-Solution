#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int xor_sum = 0;
        for (int num : arr) {
            xor_sum ^= num;
        }

        // Find the rightmost set bit
        int rightmost_set_bit = xor_sum & -xor_sum;

        int num1 = 0, num2 = 0;
        for (int num : arr) {
            if (num & rightmost_set_bit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        return {min(num1, num2), max(num1, num2)};
    }
};
