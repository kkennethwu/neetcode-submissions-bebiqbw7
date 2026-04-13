/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        go(head, head);
    }

    void go(ListNode* &left, ListNode* right) {
        if (!right) return;
        go(left, right->next);
        if (!left) return;
        
    
        if (left == right || left->next == right) {
            right->next = nullptr;
            left = nullptr;
            return;
        }
        ListNode* tmp = left->next;
        left->next = right;
        right->next = tmp;

        left = tmp; // 推進左指標
    } 
};
