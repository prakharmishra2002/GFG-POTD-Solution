class Solution {
public:
    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls.back() - stalls.front(), mid;

        while (low <= high) {
            mid = low + (high - low) / 2;
            int count = 1, last = stalls[0];
            for (int i = 1; i < stalls.size(); i++)
                if (stalls[i] - last >= mid) { count++; last = stalls[i]; }
            if (count >= k) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};