class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) { 
        sort(intervals.begin(), intervals.end(), cmp);

        int res = 0;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            const auto& interval = intervals[i];
            if (interval[0] >= prevEnd) {
                prevEnd = interval[1];
            } else {
                prevEnd = min(prevEnd, interval[1]);
                res++;
            }
        }
        return res;
    }
};
