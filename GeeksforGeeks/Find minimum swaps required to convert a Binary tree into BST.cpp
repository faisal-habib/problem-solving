/**
Idea:
The idea is to use the fact that inorder traversal of Binary Search Tree is in increasing order of their value.
- find the inorder traversal of the Binary Tree and store it in the array
- sort the array
The minimum number of swap required to get the array sorted will be the answer.

https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/
https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
*/

#include<bits/stdc++.h>
using namespace std;

int _getMinSwapToSortArray(int ar[], int arSz)
{
    int sortedAr[arSz+1];
    map<int,int>originalIndex;

    for(int i=0; i<arSz; i++)
    {
        sortedAr[i] = ar[i];
        originalIndex[ar[i]] = i;
    }

    sort(sortedAr, sortedAr+arSz);

    int minSwap = 0;
    for(int i=0; i<arSz; i++)
    {
        if(ar[i]!=sortedAr[i])
        {
            minSwap++;

            int currVal = ar[i];
            int val2 = sortedAr[i];
            int ind2 = originalIndex[sortedAr[i]];

            // swapping value in given array
            ar[i] = val2;
            ar[ind2] = currVal;

            // updating index in the mapping
            originalIndex[ar[ind2]] = ind2;
            originalIndex[ar[i]] = i;
        }
    }

    return minSwap;
}

void _inOrderTraverse(int ar[], int currInd, int arSz, int inOrder[], int &inOrderInd)
{
    if(currInd>=arSz) return ;

    // go to left child which is in index currInd*2+1
    _inOrderTraverse(ar, currInd*2+1, arSz, inOrder, inOrderInd);
    inOrder[inOrderInd++] = ar[currInd];
    _inOrderTraverse(ar, currInd*2+2, arSz, inOrder, inOrderInd);
}

void _minSwapToCreateBstFromBt(int tree[], int treeSz)
{
    int inOrder[treeSz+1], currInd = 0, inOrderInd = 0;
    _inOrderTraverse(tree, currInd, treeSz, inOrder, inOrderInd);

    //for(int i=0; i<treeSz; i++) cout<<inOrder[i]<<" ";

    cout<<"Min "<<_getMinSwapToSortArray(inOrder, treeSz)<<" swaps are required to convert the binary tree into BST"<<endl;
}
int main()
{
    int tree[100], treeSz;
    cin>>treeSz;

    for(int i=0; i<treeSz; i++)
    {
        cin>>tree[i];
    }

    _minSwapToCreateBstFromBt(tree, treeSz);
}

/*
5
4 5 2 1 5

4
4 3 2 1

5
1 5 4 3 2

8
101 758 315 730 472 619 460 479
-----------
7
5 6 7 8 9 10 11
8 6 9 5 10 7 11
*/
