/*
Problem link:
https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

Resources:
https://www.codingninjas.com/blog/2020/09/09/floyds-cycle-detection-algorithm/
https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
*/

/**
Approach - Floyd’s Cycle-Finding Algorithm
*/

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    Node *n1 = head1, *n2 = head2;
    while(n1!=n2)
    {
        n1 = n1->next;
        n2 = n2->next;

        if(!n1) n1 = head2;
        if(!n2) n2 = head1;
    }
    return n1->data;
}
