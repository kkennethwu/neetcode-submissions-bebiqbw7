class LRUCache {
public:
    struct ListNode {
        int key;
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int x, int y) : key(x), val(y), prev(nullptr), next(nullptr) {};
        ~ListNode() = default;
    };
    unordered_map<int, ListNode*> M;
    ListNode *head_node, *last_node;
    int c, n; // capacity, nums

    LRUCache(int capacity) {
        c = capacity;
        n = 0;
        head_node = nullptr;
        last_node = nullptr;
    }

    void updateOrder(ListNode* node) {
        if (node == last_node) return;

        // detach from current position
        if (node->prev) node->prev->next = node->next;
        else head_node = node->next;

        if (node->next) node->next->prev = node->prev; 
        
        // move to tail
        last_node->next = node;
        node->prev = last_node;
        last_node = node;
    }
    
    int get(int key) {
        // return -1 if dosen't exists
        if (M.find(key) == M.end()) return -1;
        
        ListNode* node = M[key];
        updateOrder(node);
        return node->val;
    }
    
    void put(int key, int value) {
        // update order if exists
        if (M.find(key) != M.end()) {
            ListNode* node = M[key];
            node->val = value;
            updateOrder(node);
            return;
        }
        
        // insert new node to the cache
        ListNode* node = new ListNode(key, value);
        M[key] = node;
        if (n < c) {
            if (!head_node) { // n == 0
                head_node = node;
                last_node = node;
            }
            else {
                last_node->next = node;
                node->prev = last_node;
                last_node = node;
            }
            n++;
        }
        else { // remove the least used one (i.e. the head)
            ListNode* tmp = head_node->next;
            M.erase(head_node->key);
            delete head_node;
            head_node = tmp;
            if (head_node) head_node->prev = nullptr;
            
            // insert new at tail
            last_node->next = node;
            node->prev = last_node;
            last_node = node;
        }
    }
};
