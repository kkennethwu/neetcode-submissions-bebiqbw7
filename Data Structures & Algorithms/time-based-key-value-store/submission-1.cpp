class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> M;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (!M.count(key)) {
            M[key] = {{timestamp, value}};
        }
        else {
            M[key].push_back({timestamp, value});
        }
    }
    
    string binarySearch(vector<pair<int, string>>& vec, int timestamp) {
        int n = vec.size();
        int left = 0, right = n - 1;
        // upper_bound: find the first value <= timestamp
        int mid;
        string ans = "";
        while (left <= right) {
            mid = (left + right) / 2;
            if (timestamp >= vec[mid].first) {
                ans = vec[mid].second;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }

    string get(string key, int timestamp) {
        if (!M.count(key)) return "";
        return binarySearch(M[key], timestamp);
    }
};
