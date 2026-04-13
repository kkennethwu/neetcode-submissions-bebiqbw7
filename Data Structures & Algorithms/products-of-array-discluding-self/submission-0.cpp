class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // a1, a1a2, a1a2a3, a1a2a3a4
        // a1a2a3a4, a2a3a4, a3a4, a4
        // 1, 2, 8, 48
        // 48, 48, 24, 6

        int size = nums.size();
        vector<int> forward(size), backward(size);
        forward[0] = nums[0];
        backward[size - 1] = nums[size - 1];
        for (int i = 1; i < size; i++) {
            forward[i] = forward[i - 1] * nums[i];
            backward[size - 1 - i] = backward[size - i] * nums[size - 1 - i];
        }
        vector<int> ans(size);
        ans[0] = backward[1];
        for (int i = 1; i < size - 1; i++) {
            ans[i] = forward[i - 1] * backward[i + 1];
        }
        ans[size - 1] = forward[size - 2];
        return ans;
    }
};
