class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {position[i], speed[i]};
        }
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        // if the time to target of the front car is larger than a back car, it will cause car fleet
        vector<double> s;
        for (const auto& pair : vec) {
            double t = (double)(target - pair.first) / pair.second;
            s.push_back(t);
            if (s.size() >= 2 && t <= s[s.size() - 1 - 1]) {
                s.pop_back();
            }
        } 
        return s.size();
    }
};
