/**
Time: O(N+M)~O(N)
Space: O(1)

According to the problem , there's no cycle, so list will end with NULL.
So if there's no intersection, then in this solution (two pointer approach), pointers will eventually meet at null,
as I'm running the loop till currA!=currB
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA = headA, *currB = headB;
        while(currA!=currB) {
            if(currA) currA = currA->next;
            else currA = headB;

            if(currB) currB = currB->next;
            else currB = headA;
        }
        return currA;
    }
};
