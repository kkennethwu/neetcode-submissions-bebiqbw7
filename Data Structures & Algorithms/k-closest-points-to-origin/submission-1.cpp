class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            return pow(a.first, 2) + pow(a.second, 2) > pow(b.first, 2) + pow(b.second, 2);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        vector<vector<int>> ans(k);
        for (auto& point : points) {
            pq.push({point[0], point[1]});
        }
        while (k--) {
            ans[k] = {pq.top().first, pq.top().second}; pq.pop();
        }
        return ans;
    }
};
