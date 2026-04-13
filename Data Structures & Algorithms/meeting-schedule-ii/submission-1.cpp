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
    int minMeetingRooms(vector<Interval>& intervals) {
        // key: the number of room required is maximum overlapping at any points
        // sort the intervals accroding to start time
        sort(intervals.begin(), intervals.end(), cmp);
        auto cmp2 = [](const Interval& a, const Interval& b) {
            return a.end > b.end;
        };
        priority_queue<Interval, vector<Interval>, decltype(cmp2)> minHeap(cmp2);
        
        int res = 0;
        if (intervals.size() == 0) return res;
        minHeap.push(intervals[0]); res++;
        for (int i = 1; i < intervals.size(); i++) {

            int cnt = minHeap.size();
            while (intervals[i].start < minHeap.top().end && i < intervals.size()) {
                minHeap.push(intervals[i]);
                cnt++;
                i++;
            }
            res = max(res, cnt);
            minHeap.pop();
            minHeap.push(intervals[i]);
        }
        return res;
    }
};
