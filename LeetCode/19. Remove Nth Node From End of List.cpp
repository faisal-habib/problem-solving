/**
Sliding window, Two pointers
Time: O(N)
Space: Constant
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;   // as 1 <= n <= sz
        /* To maintain gap between two pointers, make a dummy node. Consider case like , L={1,2}, n = 2 */
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *leftPointer = dummy, *rightPointer = dummy;
        // moving right pointer to n+1 th position from head, so gap between leftPointer & rightPointer is n
        for(int i=0;i<=n && rightPointer;i++) {
            rightPointer = rightPointer->next;
        }
        // both pointers are exactly separated by n nodes apart
        while(rightPointer) {
            rightPointer = rightPointer->next;
            leftPointer = leftPointer->next;
        }
        /* left pointer is indicating n+1 th node from the last
           now delete next node of this */
        ListNode *tmp = leftPointer->next;
        leftPointer->next = leftPointer->next->next;
        delete(tmp);

        return dummy->next;
    }
};
