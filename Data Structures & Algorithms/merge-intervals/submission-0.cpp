class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);
        for (auto& interval : intervals) {
            minHeap.push(interval);
        }

        vector<vector<int>> res;
        auto slow = minHeap.top(); minHeap.pop();
        bool merging = false;
        while (!minHeap.empty()) {
            auto fast = minHeap.top(); minHeap.pop();
            if (slow[1] < fast[0]) {
                res.push_back(slow);
                slow = fast;
            } else if (slow[1] >= fast[0]) {
                slow[1] = max(slow[1], fast[1]);
            }
        }
        res.push_back(slow);
        return res;
    }
};
