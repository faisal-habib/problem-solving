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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(!head || !head->next) return head;

        int val=( head->val==0 ? 1:0 );

        ListNode *out=new ListNode(val); // keeping a dummy value, which is not equal to the value of head

        ListNode *curr=head,*prev=out,*tmp=out;

        while(curr!=NULL && curr->next!=NULL)
        {
            if(curr->val!=prev->val && curr->val!=curr->next->val)
            {
                tmp->next=curr;
                tmp=tmp->next;
            }

            prev=curr;
            curr=curr->next;
        }

        if(curr!=NULL && curr->val!=prev->val)
        {
            tmp->next=curr;
            tmp=tmp->next;
        }

        tmp->next=NULL;

        return out->next;
    }
};
