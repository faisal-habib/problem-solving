/**
Solution 1:
Time: O(n)
Space: Constant
*/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curr = head, *left = NULL, *right = NULL;
        int count = 0, listLen = 0;
        while(curr!=NULL) {
            listLen++;
            curr = curr->next;
        }
        curr = head;
        while(curr!=NULL) {
            count++;
            if(count==k) left = curr;
            if(count==listLen-k+1) right = curr;
            curr = curr->next;
        }

        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;

        return head;
    }
};

/**
Solution 2: using stack
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curr = head, *left = NULL, *right = NULL;
        stack<ListNode*>stk;
        int count = 0;

        while(curr!=NULL) {
            count++;
            if(count==k) left = curr;
            stk.push(curr);
            curr = curr->next;
        }
        count = 0;
        while(!stk.empty()) {
            count++;
            if(count==k) {
                right = stk.top();
                break;
            }
            stk.pop();
        }
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;

        return head;
    }
};
