class Solution {
public:
    vector<int> maxOfSubarrays(const vector<int>& arr, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < arr.size(); ++i) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(arr[dq.front()]);
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<int> maxOfSubarrays(const vector<int>& arr, int k) {
        vector<int> res;
        multiset<int> window;
        for (int i = 0; i < arr.size(); ++i) {
            window.insert(arr[i]);
            if (i >= k - 1) {
                res.push_back(*window.rbegin());
                window.erase(window.find(arr[i - k + 1]));
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<int> maxOfSubarrays(const vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < arr.size(); ++i) {
            pq.emplace(arr[i], i);
            if (i >= k - 1) {
                while (pq.top().second <= i - k) pq.pop();
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};
