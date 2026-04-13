class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> vec(3, vector<int>());
        for (int i = 0; i < triplets.size(); i++) {
            const auto& triplet = triplets[i];
            for (int j = 0; j < 3; j++) {
                if (triplet[j] == target[j] && 
                    triplet[(j+1)%3] <= target[(j+1)%3] &&
                    triplet[(j+2)%3] <= target[(j+2)%3]) {
                    vec[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            if (vec[i].size() == 0) return false;
        }

        return true;
    }
};
