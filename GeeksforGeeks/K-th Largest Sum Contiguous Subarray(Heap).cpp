/*
Problem:
Given an array of integers.
Write a program to find the K-th largest sum of contiguous subarray within the array of numbers which has negative and positive numbers.

https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/
Resources:
https://stackoverflow.com/questions/35032787/kth-maximum-sum-of-a-contiguous-subarray-of-ve-integers-in-onlogs
https://discuss.codechef.com/t/kth-max-subarrays-using-kadanes-algorithm/13736/5

*/

#include<bits/stdc++.h>
using namespace std;

#define MX 100

bool _cmp(int parVal, int childVal)
{
    if(parVal<childVal) return true;
    return false;
}

void _insertIntoMinHeap(int heap[], int &heapSz, int value)
{
    heap[++heapSz] = value;
    int currInd = heapSz, parInd;
    while(currInd>1)
    {
        parInd = currInd>>1;
        if(!_cmp(heap[parInd], heap[currInd]))
        {
            swap(heap[currInd], heap[parInd]);
            currInd = parInd;
        }
        else break;
    }
}
void _deleteTopValueFromHeap(int heap[], int &heapSz)
{
    int topValue = heap[1];
    heap[1] = heap[heapSz];
    heapSz--;
    int parInd = 1;
    while( (parInd<<1)<=heapSz )
    {
        int lChild = parInd<<1, rChild = lChild+1, smallerValInd = parInd;

        if(!_cmp(heap[smallerValInd], heap[lChild])) smallerValInd = lChild;
        if(rChild<=heapSz && !_cmp(heap[smallerValInd], heap[rChild])) smallerValInd = rChild;

        if(smallerValInd!=parInd)
        {
            swap(heap[parInd], heap[smallerValInd]);
            parInd = smallerValInd;
        }
        else break;
    }
}

void _calculateCumulativeSum(int arr[], int arrSz, int cumulativeSum[])
{
    cumulativeSum[0] = 0;
    cumulativeSum[1] = arr[0];
    for(int i=2; i<=arrSz; i++)
    {
        cumulativeSum[i] = arr[i-1]+cumulativeSum[i-1];
        cout<<cumulativeSum[i]<<" ";
    }
    cout<<endl;
}

int _getKthLargestSum(int cumulativeSum[],int arrSz, int k)
{
    // build min heap with k elements
    // after that insert value in heap, only if the value is less than top element of the heap
    int heap[k+1], heapSz = 0;

    for(int i=1; i<=arrSz; i++)
    {
        for(int j=i; j<=arrSz; j++)
        {
            int s = cumulativeSum[j] - cumulativeSum[i-1];
            //cout<<"s: "<<s<<endl;
            if(heapSz<k)
            {
                _insertIntoMinHeap(heap, heapSz, s);
            }
            else
            {
                if(heap[1]<s)
                {
                    _deleteTopValueFromHeap(heap, heapSz);
                    _insertIntoMinHeap(heap, heapSz, s);
                }
            }
        }
    }
    return heap[1];
}

int main()
{
    int arr[MX], arrSz, k;
    cin>>arrSz;
    for(int i=0; i<arrSz; i++) cin>>arr[i];
    cin>>k;

    int cumulativeSum[arrSz+1];
    _calculateCumulativeSum(arr, arrSz, cumulativeSum);

    cout<<_getKthLargestSum(cumulativeSum, arrSz, k)<<endl;
}

/*
4
10 -10 20 -40
6

3
20 -5 -1
4
Explanation:
All sum of contiguous
subarrays are (20, 15, 14, -5, -6, -1)
so the 4th largest sum is -1.
*/


