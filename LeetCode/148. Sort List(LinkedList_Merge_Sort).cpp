/*
Problem link:
https://leetcode.com/problems/sort-list/
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
    ListNode *_mergeList(ListNode *leftList, ListNode *rightList) {
        if (!leftList) return rightList;
        if (!rightList) return leftList;
        
        ListNode *head = NULL;
        ListNode *curr = head;
        
        while(leftList && rightList) {
            if (leftList->val < rightList->val) {
                if (!curr) head = leftList, curr = leftList;
                else {
                    curr->next = leftList;
                    curr = curr->next;
                }
                leftList = leftList->next;
            }
            else {
                if (!curr) head = rightList, curr = rightList;
                else {
                    curr->next = rightList;
                    curr = curr->next;
                }
                rightList = rightList->next;
            }
        }
        
        if (leftList) curr->next = leftList;
        if (rightList) curr->next = rightList;
        
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *slowPointer = head;
        ListNode *fastPointer = head;
        ListNode *leftListEnd = head;
        
        while(fastPointer && fastPointer->next) {
            leftListEnd = slowPointer;
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        
        leftListEnd->next = NULL;
        ListNode *leftList = sortList(head);
        ListNode *rightList = sortList(slowPointer);
        
        return _mergeList(leftList, rightList);
    }
};