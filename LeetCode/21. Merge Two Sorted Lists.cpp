/**
time: O(n)
space: O(1)
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *curr = NULL;
        while(true) {
            if(!l1 && !l2) return head;

            if( (l1 && l2 && l1->val<l2->val) || (l1 && !l2) ) {
                if(!head) {
                    head = curr = l1;
                }
                else {
                    curr->next = l1;
                    curr = curr->next;
                }
                l1 = l1->next;
            }
            else {
                if(!head) {
                    head = curr = l2;
                }
                else {
                    curr->next = l2;
                    curr = curr->next;
                }
                l2 = l2->next;
            }
        }

        return head;
    }
};
