/**
Reverse a linked list
Time: O(N)
Space: O(1)
Resources:
https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
https://www.geeksforgeeks.org/reverse-linked-list-groups-given-size-set-2/
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
    int getListLength(ListNode *head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *reverseListInGroup(ListNode *head, int groupSize, int remainingListLen) {
        if(remainingListLen<groupSize) return head;
        ListNode *prev = NULL, *nextNode = NULL, *curr = head;
        int count = 0;
        while(curr && count<groupSize) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++, remainingListLen--;
        }
        if(nextNode) head->next = reverseListInGroup(nextNode, groupSize, remainingListLen);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int listLen = getListLength(head);
        return reverseListInGroup(head, k, listLen);
    }
};
