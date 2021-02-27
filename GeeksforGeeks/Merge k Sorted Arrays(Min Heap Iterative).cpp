/*
Problem link:
https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1#

Resources:
https://www.geeksforgeeks.org/merge-k-sorted-arrays/
https://medium.com/outco/how-to-merge-k-sorted-arrays-c35d87aa298e
*/

void _insertIntoHeap(int heap[], int &heapSz, int val)
{
    heap[++heapSz] = val;
    int curr = heapSz, par;
    while(curr>1)
    {
        int par = curr>>1;
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
    while( (par<<1)<=heapSz )
    {
        int l = par<<1, r = l+1;
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

// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
int *mergeKArrays(int arr[][N], int k)
{
    int sz = k*k;
    int *output = new int[sz], ind = 0;
    int heap[sz+1], heapSz = 0;

    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++)
        {
            _insertIntoHeap(heap, heapSz, arr[i][j]);
        }
    }

    while(heapSz)
    {
        //cout<<"top: "<<heap[1]<<endl;
        output[ind++] = heap[1];
        _deleteFromHeap(heap, heapSz);
    }

    return output;
}
