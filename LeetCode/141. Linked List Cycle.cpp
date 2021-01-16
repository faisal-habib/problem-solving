/**
Floyd's cycle-finding algorithm/ The Tortoise and the Hare approach
time- O(n)
space- O(1)
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
    bool findCycle(ListNode *root)
    {
        ListNode *slow_pointer=root,*fast_pointer=root;
        while(slow_pointer && fast_pointer && fast_pointer->next)
        {
            slow_pointer=slow_pointer->next;
            fast_pointer=fast_pointer->next->next;
            if(slow_pointer==fast_pointer) return true;
        }
        return false;
    }
    bool hasCycle(ListNode *head)
    {
        return findCycle(head);
    }
};
