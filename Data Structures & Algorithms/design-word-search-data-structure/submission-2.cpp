class WordDictionary {
private:
    struct TrieNode {
        bool isWord = false;
        unordered_map<char, TrieNode*> children;
    };
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        stack<pair<TrieNode*, int>> s;
        s.push({root, 0});

        while (!s.empty()) {
            TrieNode* node = s.top().first;
            int idx = s.top().second;
            s.pop();
            char c = word[idx];
            if (idx == word.size()) {
                if (node->isWord) return true;
                else continue;
            } 
            
            if (c != '.') {
                if (node->children.count(c)) {
                    s.push({node->children[c], idx + 1});
                }
            } else {
                for (auto it = node->children.begin(); it != node->children.end(); it++) {
                    s.push({it->second, idx + 1});
                }
            }
        }
        return false;
    }
};
