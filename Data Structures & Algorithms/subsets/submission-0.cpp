class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, res, subset);
        return res;
    }

    void dfs(vector<int>& nums, int i, vector<vector<int>>& res, vector<int>& subset) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }
        // opt 1. include it
        subset.push_back(nums[i]);
        dfs(nums, i + 1, res, subset);
        // opt 2. exclude it
        subset.pop_back();
        dfs(nums, i + 1, res, subset);
    }
};
