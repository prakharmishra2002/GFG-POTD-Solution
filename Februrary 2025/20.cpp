#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> max_heap; // Max heap for the lower half
        priority_queue<int, vector<int>, greater<int>> min_heap; // Min heap for the upper half
        vector<double> result;

        auto addNum = [&](int num) {
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();

            if (max_heap.size() < min_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        };

        auto findMedian = [&]() -> double {
            if (max_heap.size() > min_heap.size()) {
                return max_heap.top();
            }
            return (max_heap.top() + min_heap.top()) / 2.0;
        };

        for (int num : arr) {
            addNum(num);
            result.push_back(findMedian());
        }

        return result;
    }
};
