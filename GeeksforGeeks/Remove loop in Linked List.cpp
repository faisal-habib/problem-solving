/*
Problem: Remove loop in Linked List
You are given a linked list of N nodes. Remove the loop from the linked list, if present.
Link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
Tutorial: https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
*/
void removeLoop(Node *head, Node *slow, Node *fast)
{
    slow = head;
    if(slow==fast)  // for case where head node is included in loop
    {
        while(fast->next!=slow) fast = fast->next;  // go to last node from where loop started
    }
    else
    {
        while(slow->next!=fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = NULL;  //remove loop
}
void removeLoop(Node* head)
{
    Node *slow = head, *fast = head;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            removeLoop(head, slow, fast);
            return ;
        }
    }
}


/// another approach (using hash/map)
void removeLoop(Node* head)
{
    unordered_map<Node*, bool>mp;
    Node *lastNode = NULL, *curr = head;
    while(curr)
    {
        if(!mp[curr])
        {
            mp[curr] = true;
            lastNode = curr;
            curr = curr->next;
        }
        else
        {
            lastNode->next = NULL;
            break;
        }
    }
}
