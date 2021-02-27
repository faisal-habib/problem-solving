/*
Problem:
https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#

Similar as Leetcode 23
Resources:
*/

/*Linked list Node structure

struct Node
{
	int data;
	Node* next;

	Node(int x){
	    data = x;
	    next = NULL;
	}

};
*/

void _insertIntoHeap(int heap[], int &heapSz, int val)
{
    heap[++heapSz] = val;
    int curr = heapSz, par;
    while(curr>1)
    {
        int par = curr/2;
        if(heap[curr]<heap[par])
        {
            swap(heap[par], heap[curr]);
            curr = par;
        }
        else break;
    }
}

void _deleteFromHeap(int heap[], int &heapSz)
{
    heap[1] = heap[heapSz];
    heapSz--;
    int par = 1, child;
    while(par*2<=heapSz)
    {
        int l = par*2, r = l+1;
        if(heap[l]<heap[par] || heap[r]<heap[par])
        {
            if(heap[l]<heap[r]) child = l;
            else child = r;

            swap(heap[par], heap[child]);
            par = child;
        }
        else break;
    }
}


/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node * mergeKLists(Node *arr[], int N)
{
    int heap[100005], heapSz = 0;
    for(int i=0; i<N; i++)
    {
        Node *l = arr[i];
        while(l)
        {
            _insertIntoHeap(heap, heapSz, l->data);
            l = l->next;
        }
    }
    Node *head, *curr;
    head = curr = new Node(0);
    while(heapSz)
    {
        curr->next = new Node(heap[1]);
        curr = curr->next;
        _deleteFromHeap(heap, heapSz);
    }

    return head->next;
}
