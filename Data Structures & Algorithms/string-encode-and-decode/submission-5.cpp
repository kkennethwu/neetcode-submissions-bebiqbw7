class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string str : strs) {
            int len = str.size();
            ans += (to_string(len) + "#" + str);
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int index = 0;
        while(index < s.size()) {
            int tmp = index;
            while(s[index++] != '#');
            int len = stoi(s.substr(tmp, index - tmp));
            ans.push_back(s.substr(index, len));
            index += len;   
        }
        return ans;
    }
};
