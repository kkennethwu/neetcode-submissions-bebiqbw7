class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        visited = vector<bool>(n, false);
        vector<vector<int>> res;
        vector<int> subset;
        bt(nums, 0, res, subset);
        return res;
    }

    void bt(vector<int>& nums, int i, vector<vector<int>>& res, vector<int>& subset) {
        bool allVisited = true;
        for (bool vis : visited) {
            allVisited &= vis;
        }
        if (allVisited) {
            res.push_back(subset);
            return;
        }

        for (int j = 0; j < nums.size(); j++) {
            if (visited[j]) continue;
            visited[j] = true;
            subset.push_back(nums[j]);
            bt(nums, j, res, subset);
            subset.pop_back();
            visited[j] = false;
        }
    }
};
