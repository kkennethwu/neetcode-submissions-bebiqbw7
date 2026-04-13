class LRUCache {
public:
    struct ListNode {
        int key, val;
        ListNode* prev;
        ListNode* next;
        ListNode(int x, int y) : key(x), val(y), prev(nullptr), next(nullptr) {};
        ~ListNode() = default;
    };
    int capacity;
    unordered_map<int, ListNode*> cache;
    ListNode *head, *tail; // use dummy to avoid troublesome nullptr logic
    

    LRUCache(int cap) : capacity(cap) {
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void remove(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertBeforeTail(ListNode* node) {
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }
    
    int get(int key) {
        // return -1 if dosen't exists
        if (cache.find(key) == cache.end()) return -1;
        
        ListNode* node = cache[key];
        remove(node);
        insertBeforeTail(node);
        return node->val;
    }
    
    void put(int key, int value) {
        // update order if exists
        if (cache.find(key) != cache.end()) {
            ListNode* node = cache[key];
            node->val = value;
            remove(node);
            insertBeforeTail(node);
            return;
        }
        
        if (cache.size() == capacity) {
            ListNode* lru = head->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
        ListNode* node = new ListNode(key, value);
        cache[key] = node;
        insertBeforeTail(node);
    }
};
