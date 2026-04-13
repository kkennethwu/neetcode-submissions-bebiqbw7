class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> vec = vector<int>(3, 0);
        for (int i = 0; i < triplets.size(); i++) {
            const auto& triplet = triplets[i];
            for (int j = 0; j < 3; j++) {
                if (triplet[j] == target[j] && 
                    triplet[(j+1)%3] <= target[(j+1)%3] &&
                    triplet[(j+2)%3] <= target[(j+2)%3]) {
                    vec[j]++;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            if (vec[i] == 0) return false;
        }

        return true;
    }
};
