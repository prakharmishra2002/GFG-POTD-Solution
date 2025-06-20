#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        if (arr.size() % k != 0) return false;

        unordered_map<int, int> freq;
        for (int num : arr)
            freq[num]++;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto &p : freq)
            minHeap.push(p.first);

        while (!minHeap.empty()) {
            int first = minHeap.top();

            for (int i = first; i < first + k; i++) {
                if (freq[i] == 0) return false;
                freq[i]--;
                if (freq[i] == 0 && i != minHeap.top()) {
                    // lazy removal: will get cleaned up on next round
                }
            }

            // Remove top if its count reached 0
            while (!minHeap.empty() && freq[minHeap.top()] == 0)
                minHeap.pop();
        }

        return true;
    }
};
