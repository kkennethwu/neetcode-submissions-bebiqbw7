class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // start_i < end_i < start_j < end_j
        int start = newInterval[0], end = newInterval[1];
        vector<vector<int>> res;
        bool in_merging = false;
        
        for (int i = 0; i < intervals.size(); i++) {
            const auto& interval = intervals[i];
            if (interval[1] < start) {
                res.push_back(interval);
            } else if (interval[0] > end) {
                res.push_back(newInterval);
                while (i < intervals.size()) {
                    res.push_back(intervals[i++]);
                }
                return res;
            } else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};
