class Solution {
public:
    string encode(vector<string>& strs) {
        string latent = "";
        for (auto const str : strs) {
            latent += (to_string(str.size()) + '#' + str);
        }
        return latent;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int start = 0;
        while(start < s.size()) {
            // 3#abc6#asdefx
            int count = 0;
            while (s[start + count++] != '#');
            int len = stoi(s.substr(start, count));
            ans.emplace_back(s.substr(start + count, len));
            start = start + count + len;
        }
        return ans;
    }
};
