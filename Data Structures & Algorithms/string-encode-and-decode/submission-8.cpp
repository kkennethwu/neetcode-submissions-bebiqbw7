class Solution {
public:
    vector<int> idxs;
    string encode(vector<string>& strs) {
        int size = strs.size();
        idxs = vector<int>(size);
        string latent = "";
        for (int i = 0; i < strs.size(); i++) {
            idxs[i] = strs[i].size();
            latent += strs[i];
        }
        return latent;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int start = 0;
        for (auto const& idx : idxs) {
            ans.push_back(s.substr(start, idx));
            start += idx;
        }
        return ans;
    }
};
