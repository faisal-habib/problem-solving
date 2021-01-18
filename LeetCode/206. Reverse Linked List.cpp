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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode *currNode = head, *nextNode = NULL, *prevNode = NULL;
        while(currNode) {
            nextNode = currNode->next;
            currNode->next = prevNode;  // reversing the link
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
};
