class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> M;
        for (auto num : nums) {
            if (!M.count(num)) {
                M[num] = true;
            }
            else return true;
        }
        return false;
    }
};