class Solution {
public:
    bool eatUp(int rate, int h, vector<int>& piles) {
        for (int pile : piles) {
            h -= (pile / rate + ((pile % rate) > 0));
            if (h < 0) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1, right = 0;
        for (const int pile : piles) {
            right = max(right, pile);
        }
        int minRate = right;
        while (left <= right) {
            int rate = (left + right) / 2;
            if (eatUp(rate, h, piles)) {
                minRate = rate;
                right = rate - 1;
            }
            else {
                left = rate + 1;
            }
        }
        return minRate;
    }
};
