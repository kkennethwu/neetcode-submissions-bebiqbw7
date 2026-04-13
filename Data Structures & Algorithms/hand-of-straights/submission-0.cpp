class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> m;
        int minHand = 0;
        int maxHand = 1000;
        for (const auto& h : hand) {
            m[h]++;
            minHand = min(minHand, h);
            maxHand = max(maxHand, h);
        }
        // e.g. group size 4
        // 0 0 0 3 3 3 4 1 1 1 

        int left = minHand;
        while (left + groupSize - 1 <= maxHand) {
            int right = left + groupSize - 1;

            int jumpIdx = right + 1;
            for (int i = left + 1; i <= right; i++) {
                if (m[i] < m[left]) return false;
                else {
                    if (m[i] > m[left]) {
                        jumpIdx = min(jumpIdx, i);
                    }
                    m[i] -= m[left];
                }
            }
            left = jumpIdx;
        }

        return true;
    }
};
