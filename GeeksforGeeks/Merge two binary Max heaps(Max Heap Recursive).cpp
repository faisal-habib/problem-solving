/*
Problem link:
https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap/0#

Resources:
https://www.geeksforgeeks.org/merge-two-binary-max-heaps/

Note:
Problem's i/o is little sloppy. Couldn't pass test cases using priority queue, iterative approach.
Got AC only in this recursive solution!
*/

#include <iostream>
using namespace std;

int leftChild(int n) {
    return (n<<1);  // n*(2^1)
}
int rightChild(int n) {
    return (n<<1)+1;  // n*(2^1)+1
}

void _maxHeapify(int heap[],int sz,int pos) {
    int largestValInd=pos;
    int l=leftChild(pos);
    int r=rightChild(pos);

    if(l<=sz && heap[l]>heap[largestValInd]) largestValInd=l;
    if(r<=sz && heap[r]>heap[largestValInd]) largestValInd=r;

    if(largestValInd!=pos) {
        int tmp=heap[pos];
        heap[pos]=heap[largestValInd];
        heap[largestValInd]=tmp;
        // right now value of largestValInd = value of pos, our target is to place this value in right place. So call maxHeapify from largestValInd again
        _maxHeapify(heap,sz,largestValInd);
    }
}
void __buildMaxHeapify(int heap[], int heapSz) {
    for(int i=heapSz>>1; i>=1; i--) {
        _maxHeapify(heap, heapSz, i);
    }
}

int main() {
	int sz1, sz2, testCase;
	cin>>testCase;
	while(testCase--) {
	    cin>>sz1>>sz2;
	    int heapSz = 0, heap[sz1+sz2+1];
	    for(int i=0; i<sz1; i++) {
	        ++heapSz;
	        cin>>heap[heapSz];
	    }
	    for(int i=0; i<sz2; i++) {
	        ++heapSz;
	        cin>>heap[heapSz];
	    }

	    __buildMaxHeapify(heap, heapSz);

	    for(int i=1; i<=heapSz; i++) cout<<heap[i]<<" ";
	    cout<<endl;
	}

	return 0;
}
