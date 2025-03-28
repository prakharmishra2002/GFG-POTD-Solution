class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int, int>> activities;
        for (int i = 0; i < start.size(); i++) activities.push_back({finish[i], start[i]});
        sort(activities.begin(), activities.end());
        int count = 1, end = activities[0].first;
        for (int i = 1; i < activities.size(); i++) {
            if (activities[i].second > end) {
                count++;
                end = activities[i].first;
            }
        }
        return count;
    }
};



2)
class Solution {
public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < start.size(); i++) 
            arr.emplace_back(finish[i], start[i]);
        sort(arr.begin(), arr.end());
        int ans = 0, finishtime = -1;
        for (auto &activity : arr) 
            if (activity.second > finishtime) 
                finishtime = activity.first, ans++;
        return ans;
    }
};
