class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int const& num : nums) {
            s.insert(num);
        }
        int ans = 0;
        for (int const& num : nums) {
            if (s.find(num - 1) == s.end()) {
                int size = 1;
                while (s.find(num + size) != s.end()) {
                    size++;
                }
                ans = max(ans, size);
            }
        }
        return ans;
    }
};
