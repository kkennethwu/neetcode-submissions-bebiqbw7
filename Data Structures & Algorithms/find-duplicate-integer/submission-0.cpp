class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        long long check = 0;
        for (auto num : nums) {
            if (check & (1 << num)) return num;
            check |= (1 << num);
        }
        return 0;
    }
};
