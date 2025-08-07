class Solution {
  public:
    int minDifference(vector<string> &arr) {
        auto timeToSeconds = [](const string &t) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            int s = stoi(t.substr(6, 2));
            return h * 3600 + m * 60 + s;
        };

        vector<int> seconds;
        for (const string &t : arr) {
            seconds.push_back(timeToSeconds(t));
        }

        sort(seconds.begin(), seconds.end());

        int minDiff = INT_MAX;
        for (int i = 1; i < seconds.size(); ++i) {
            minDiff = min(minDiff, seconds[i] - seconds[i - 1]);
        }

        // Wrap-around difference between last and first time
        int wrapDiff = 86400 - seconds.back() + seconds.front();
        minDiff = min(minDiff, wrapDiff);

        return minDiff;
    }
};
