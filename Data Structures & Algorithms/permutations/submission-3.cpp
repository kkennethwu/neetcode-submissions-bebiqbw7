class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        bt(nums, 0, res);
        return res;
    }

    void bt(vector<int>& nums, int i, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            bt(nums, i + 1, res);
            swap(nums[j], nums[i]);
        }
    }
    // TC: 
};
