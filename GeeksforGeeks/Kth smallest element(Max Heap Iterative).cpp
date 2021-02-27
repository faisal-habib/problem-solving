/*
Problem link:
https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

Resources:
https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
*/

bool _cmp(int parVal, int childVal) {
    if(parVal>childVal) return true;
    return false;
}
void _insertIntoMaxHeap(int heap[], int &heapSz, int value) {
    heap[++heapSz] = value;
    int currInd = heapSz, parInd;
    while(currInd>1) {
        parInd = currInd>>1;
        if(!_cmp(heap[parInd], heap[currInd])) {
            swap(heap[currInd], heap[parInd]);
            currInd = parInd;
        }
        else break;
    }
}
void _topDownHeapify(int heap[], int heapSz, int parInd) {
    while((parInd<<1)<=heapSz) {
        int lChild = parInd<<1, rChild = lChild+1, smallerValInd = parInd;

        if(!_cmp(heap[smallerValInd], heap[lChild])) smallerValInd = lChild;
        if(rChild<=heapSz && !_cmp(heap[smallerValInd], heap[rChild])) smallerValInd = rChild;

        if(smallerValInd!=parInd) {
            swap(heap[parInd], heap[smallerValInd]);
            parInd = smallerValInd;
        }
        else break;
    }
}

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function

int kthSmallest(int arr[], int l, int r, int k) {
    // build a maxHeap with size k
    int heap[k+1], heapSz = 0;

    for(int i=0; i<k; i++) {
        _insertIntoMaxHeap(heap, heapSz, arr[i]);
    }

    for(int i=k; i<=r; i++) {
        if(arr[i]<heap[1]) {
            heap[1] = arr[i];
            _topDownHeapify(heap, heapSz, 1);
        }
    }
    return heap[1];
}
