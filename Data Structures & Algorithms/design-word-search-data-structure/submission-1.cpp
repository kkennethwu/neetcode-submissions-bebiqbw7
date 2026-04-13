class WordDictionary {
private:
    struct TrieNode {
        bool isWord = false;
        int idx = 0;
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
                node->children[c]->idx = node->idx + 1;
            }
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        stack<TrieNode*> s;
        s.push(root);

        while (!s.empty()) {
            TrieNode* node = s.top(); s.pop();
            int idx = node->idx;
            char c = word[idx];
            if (idx == word.size()) {
                if (node->isWord) return true;
                else continue;
            } 
            
            if (c != '.') {
                if (node->children.count(c)) {
                    s.push(node->children[c]);
                }
            } else {
                for (auto it = node->children.begin(); it != node->children.end(); it++) {
                    s.push(it->second);
                }
            }
        }
        return false;
    }
};
