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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int i = 0;
        while (cur) {
            cur = cur->next;
            i++;
        }
        i = i - n - 1;
        
        cur = head;
        while(cur) {
            if (i > 0) {
                cur = cur->next;
                i--;
            }
            else if (i == -1) {
                head = head->next;
                break;
            }
            else if (i == 0) {
                if (!cur->next) {
                    cur = nullptr;
                }
                else cur->next = cur->next->next;
                break;
            }
        }

        return head;
    }
};
