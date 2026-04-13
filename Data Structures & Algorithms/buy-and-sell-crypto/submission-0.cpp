class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int left = 0, right = left + 1;
        while (left < right && right < n) {
            ans = max(ans, prices[right] - prices[left]);
            if (prices[right] < prices[left]) left = right;
            right++;
        }
        return ans;
    }
};
