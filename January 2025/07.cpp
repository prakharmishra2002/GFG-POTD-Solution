#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int countPairs(vector<int> &arr, int target) {
        // Dictionary to store the frequency of elements
        unordered_map<int, int> freq;
        int count = 0;
        
        for (int num : arr) {
            // Calculate the complement that would form the target sum
            int complement = target - num;
            
            // If the complement exists in the dictionary, add its frequency to the count
            if (freq.find(complement) != freq.end()) {
                count += freq[complement];
            }
            
            // Update the frequency of the current number
            freq[num]++;
        }
        
        return count;
    }
};
