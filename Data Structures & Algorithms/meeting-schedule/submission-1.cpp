/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        if (intervals.size() < 2) return true;
        int prevEnd = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            const auto& interval = intervals[i];
            if (interval.start >= prevEnd) {
                prevEnd = interval.end;
            } else return false;
        }
        return true;
    }
};
