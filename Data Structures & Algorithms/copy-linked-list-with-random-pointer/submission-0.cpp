/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, int> M;
        unordered_map<int, Node*> M_new;
        Node* cur = head;
        Node* new_head = new Node(head->val);
        Node* new_cur = new_head;

        int i = 0;
        while(true) {
            M[cur] = i;
            M_new[i] = new_cur;
            i++;
            if (!cur->next) {
                new_cur->next = nullptr;
                break;
            }
            new_cur->next = new Node(cur->next->val);

            cur = cur->next;
            new_cur = new_cur->next;
        }

        cur = head;
        new_cur = new_head;
        while (cur) {
            if (!cur->random) new_cur->random = nullptr;
            else {
                int idx = M[cur->random];
                cout << idx << endl;
                new_cur->random = M_new[idx];
            }
            cur = cur->next;
            new_cur = new_cur->next;
        }
        return new_head;
    }
};
