/**
The Tortoise and the Hare approach/ Two Pointer
time: O(N)
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
    ListNode* middleNode(ListNode* head) {
        ListNode *fastPointer = head, *slowPointer = head;
        while(fastPointer && fastPointer->next) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        return slowPointer;
    }
};
