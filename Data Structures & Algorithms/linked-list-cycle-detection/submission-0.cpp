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
    bool hasCycle(ListNode* head) {
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        while (node2 && node2->next) {
            if (node1 == node2 || node2->next == node1) return true;
            node1 = node1->next;
            node2 = node2->next->next;
        }
        return false;
    }
};
