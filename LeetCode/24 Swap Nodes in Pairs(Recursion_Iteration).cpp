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

/*
Iterative solution
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *newHead = head;
		ListNode *currNode = head;
		ListNode *prevNode = NULL;
		
        while(currNode && currNode->next) {
			ListNode *tempCurrNode = currNode;
			ListNode *nextNode = currNode->next;
			ListNode *nextNode2 = currNode->next->next;
			
			if (!prevNode) {
				newHead = nextNode;
			}
			else {
				prevNode->next = nextNode;
			}
			
			nextNode->next = tempCurrNode;
			tempCurrNode->next = nextNode2;
			prevNode = tempCurrNode;	// initial current node of this iteration will be prevNode of next iteration
			currNode = nextNode2;
		}
        return newHead;
    }
};


/*
Recursive solution
*/
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *nxt = head->next;
        head->next = swapPairs(nxt->next);
        nxt->next = head;
        
        return nxt;
    }
};
*/