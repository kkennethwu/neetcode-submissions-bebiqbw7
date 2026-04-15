class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        bt(nums, 0, res, subset);
        return res;
    }

    void bt(vector<int>& nums, int idx, vector<vector<int>>& res, vector<int>& subset) {
        res.push_back(subset);
        if (idx == nums.size()) return;

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            bt(nums, i + 1, res, subset);
            subset.pop_back();
        }
    }
};
