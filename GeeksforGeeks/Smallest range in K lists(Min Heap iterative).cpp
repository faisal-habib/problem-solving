/*
Problem:
https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1#
https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
Resources:
https://www.geeksforgeeks.org/find-smallest-range-containing-elements-from-k-lists/
*/
typedef struct
{
    int val, nextInd, listNum;
}Info;

bool _cmp(int parVal, int currVal)
{
    if(parVal<currVal) return true;
    return false;
}
void _insertIntoMinHeap(Info heap[], int &heapSz, Info info)
{
    heap[++heapSz] = info;
    int currInd = heapSz;
    while(currInd>1)
    {
        int parInd = currInd>>1;
        if(!_cmp(heap[parInd].val, heap[currInd].val))
        {
            Info tmp = heap[parInd];
            heap[parInd] = heap[currInd];
            heap[currInd] = tmp;
            currInd = parInd;
        }
        else break;
    }
}

void _topDownHeapify(Info heap[], int &heapSz)
{
    int parInd = 1;
    while((parInd<<1)<=heapSz)
    {
        int lChild = (parInd<<1);
        int rChild = lChild+1;
        int childInd = parInd;

        if(!_cmp(heap[childInd].val, heap[lChild].val))
        {
            childInd = lChild;
        }
        if(rChild<=heapSz && !_cmp(heap[childInd].val, heap[rChild].val))
        {
            childInd = rChild;
        }

        if(childInd!=parInd)
        {
            Info tmp = heap[parInd];
            heap[parInd] = heap[childInd];
            heap[childInd] = tmp;
            parInd = childInd;
        }
        else break;
    }
}

// you are required to complete this function
// function should print the required range
pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
      pair<int,int>ansRange;
      int maxVal = INT_MIN, minVal = INT_MAX, range = INT_MAX, startVal, endVal;

      Info heap[k+1];
      int heapSz = 0;
      for(int i=0; i<k; i++)
      {
          Info info;
          info.val = arr[i][0];
          info.listNum = i;
          info.nextInd = 1;

          if(info.val>maxVal) maxVal = info.val;

          _insertIntoMinHeap(heap, heapSz, info);
      }

      while(true)
      {
          Info top = heap[1];

          minVal = top.val;
          if((maxVal-minVal+1)<range)
          {
              range = maxVal-minVal+1;
              startVal = minVal;
              endVal = maxVal;
          }

          if(top.nextInd<n)
          {
              top.val = arr[top.listNum][top.nextInd];
              top.nextInd++;

              if(top.val>maxVal) maxVal = top.val;
          }
          else break;

          heap[1] = top;
          _topDownHeapify(heap, heapSz);
      }
      return ansRange={startVal, endVal};
}
