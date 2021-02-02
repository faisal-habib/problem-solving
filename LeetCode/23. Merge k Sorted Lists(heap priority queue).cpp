/**
Solution 1: implementing heap
*/
class Solution {
public:
    void _insertIntoHeap(int heap[], int &heapSz, int val) {
        heap[++heapSz] = val;
        int curr = heapSz, par;
        while(curr>1) {
            int par = curr/2;
            if(heap[curr]<heap[par]) {
                swap(heap[par], heap[curr]);
                curr = par;
            }
            else break;
        }
    }

    void _deleteFromHeap(int heap[], int &heapSz) {
        heap[1] = heap[heapSz];
        heapSz--;
        int par = 1, child;
        while(par*2<=heapSz) {
            int l = par*2, r = l+1;
            if(heap[l]<heap[par] || heap[r]<heap[par]) {
                if(heap[l]<heap[r]) child = l;
                else child = r;

                swap(heap[par], heap[child]);
                par = child;
            }
            else break;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz = lists.size();
        int heap[100005], heapSz = 0;

        for(int i=0; i<sz; i++) {
            ListNode *l = lists[i];
            while(l) {
                _insertIntoHeap(heap, heapSz, l->val);
                l = l->next;
            }
        }

        ListNode *head, *curr;
        head = curr = new ListNode(0);

        while(heapSz) {
            curr->next = new ListNode(heap[1]);
            curr = curr->next;
            _deleteFromHeap(heap, heapSz);
        }

        return head->next;
    }
};

/**
Solution 2: using STL priority queue
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz = lists.size();
        priority_queue<int, vector<int>, greater<int>>pq;   //reverse priority_queue
        for(int i=0; i<sz; i++) {
            ListNode *l = lists[i];
            while(l) {
                pq.push(l->val);
                l = l->next;
            }
        }

        ListNode *head, *curr;
        head = curr = new ListNode(0);   // dummy node
        while(!pq.empty()) {
            curr->next = new ListNode(pq.top());
            curr = curr->next;
            pq.pop();
        }

        return head->next;
    }
};

/**
Solution 2: using merge sort
*/


void merge(int ar[],int l,int m,int r)
{
    int i=l,j=m+1,k=0;
    int tmp[r-l+1];
    while(i<=m && j<=r)
    {
        if(ar[i]<ar[j]) tmp[k]=ar[i],i++,k++;
        else tmp[k]=ar[j],j++,k++;
    }

    while(i<=m) tmp[k]=ar[i],k++,i++;
    while(j<=r) tmp[k]=ar[j],k++,j++;

    for(i=l;i<=r;i++) ar[i]=tmp[i-l];
}

void mergeSort(int ar[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(ar,l,m);
        mergeSort(ar,m+1,r);
        merge(ar,l,m,r);
    }
}
struct ListNode *create(int v)
{
    struct ListNode *tmp=(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp->val=v;
    tmp->next=NULL;
    return tmp;
}

struct ListNode *insert(struct ListNode *root,int v)
{
    if(root==NULL) return create(v);
    struct ListNode *tmp=(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp->val=v;
    tmp->next=root;
    return tmp;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    int ar[100005],sz=0;
    for(int i=0;i<listsSize;i++)
    {
        while(lists[i]!=NULL)
        {
            ar[++sz]=lists[i]->val;
            lists[i]=lists[i]->next;
        }
    }

    mergeSort(ar,1,sz);

    struct ListNode* out=NULL;
    for(int i=sz;i>=1;i--)
    {
        out=insert(out,ar[i]);
    }

    return out;
}
