/*
Problem link:
https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

Resources:
https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
*/


class Solution{
public:
    bool _cmp(int parVal, int childVal) {
        if(parVal<childVal) return true;
        return false;
    }
    void _insertIntoMinHeap(int heap[], int &heapSz, int value) {
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

	vector<int> kLargest(int arr[], int n, int k) {
	    // build a minHeap with size k
	    int heap[k+1], heapSz = 0;
	    for(int i=0; i<k; i++) {
	        _insertIntoMinHeap(heap, heapSz, arr[i]);
	    }

	    for(int i=k; i<n; i++) {
	        if(arr[i]>heap[1]) {
	            heap[1] = arr[i];
	            _topDownHeapify(heap, heapSz, 1);
	        }
	    }

	    vector<int>output(heapSz, 0);
	    for(int i=heapSz; i>=1; i--) {
	        output[i-1] = heap[1];
	        heap[1] = heap[i];
	        _topDownHeapify(heap, i-1, 1);
	    }
	    return output;
	}

};
