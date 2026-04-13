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
    void sumTwo(ListNode* l1, ListNode* l2, int len1, int len2) {

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int carry = 0;
        ListNode* l1_prev = nullptr;
        ListNode* l2_prev = nullptr;
        int s = 0;
        while (l1 && l2) {
            s = l1->val + l2->val + carry;
            carry = s / 10;
            l1->val = s % 10;;
            
            l1_prev = l1;
            l2_prev = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (!l1 && !l2 && carry) {
            l1_prev->next = new ListNode(carry);
        }
        else if (l1) {
            while (carry && l1) {
                s = l1->val + carry;
                carry = s / 10;
                l1->val = s % 10;
                l1_prev = l1;
                l1 = l1->next;
            }
            if (carry) l1_prev->next = new ListNode(carry);
        }
        else if (l2) {
            l1_prev->next = l2;
            while (carry && l2) {
                s = l2->val + carry;
                carry = s / 10;
                l2->val = s % 10;
                l2_prev = l2;
                l2 = l2->next;
            }
            if (carry) l2_prev->next = new ListNode(carry);
        }
        
        return head1;


    }
};
