/*
Resources:
https://www.geeksforgeeks.org/count-all-k-sum-paths-in-a-binary-tree/
https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
/*
void _printSumPath(vector<int>sumPath, int stInd)
{
    int sz = sumPath.size();
    cout<<"---------------------------"<<endl;
    for(int i=stInd; i<sz; i++) cout<<sumPath[i]<<" ";
    cout<<endl;
    cout<<"---------------------------"<<endl;
}

void _kSumPath(Node *root, int targetSum, vector<int>&sumPath, int &totalPathCount)
{
    if(!root) return ;

    sumPath.push_back(root->data);

    _kSumPath(root->left, targetSum, sumPath, totalPathCount);
    _kSumPath(root->right, targetSum, sumPath, totalPathCount);

    int currSum = 0;
    for(int i=sumPath.size()-1; i>=0; i--)
    {
        currSum+=sumPath[i];
        if(currSum==targetSum)
        {
            //_printSumPath(sumPath, i);
            totalPathCount++;
        }
    }
    // backtrack (removing current element)
    sumPath.pop_back();
}

int _countAllKSumPath(Node *root, int k)
{
    vector<int>sumPath;
    int totalPathCount = 0;
    _kSumPath(root, k, sumPath, totalPathCount);
    return totalPathCount;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    cout<<"Path count: "<<_countAllKSumPath(root, k)<<endl;

    return 0;
}*/

/*

Input : k = 5
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5
        /   / \     \
       1   1   2     6

*/

/** -------------------------------------------------------------------------------

Solution 2:
As we don't need print path here, it can be done more efficiently using backtracking and unordered maps

------------------------------------------------------------------------------- */


void _kSumPath(Node *root, int targetSum, int currSum, unordered_map<int, int>&sumCount, int &totalPathCount)
{
    if(!root) return ;

    if(root->data+currSum==targetSum) totalPathCount++;

    // Add those values which differences by the current sum and root data by k
    totalPathCount+= sumCount[root->data+currSum-targetSum];

    sumCount[root->data+currSum]++;

    _kSumPath(root->left, targetSum, root->data+currSum, sumCount, totalPathCount);
    _kSumPath(root->right, targetSum, root->data+currSum, sumCount, totalPathCount);

    // backtrack
    sumCount[root->data+currSum]--;
}

int _countAllKSumPath(Node *root, int k)
{
    unordered_map<int, int>sumCount;    // if code doesn't compile because of unordered_map, use map instead of unordered_map
    int totalPathCount = 0;
    _kSumPath(root, k, 0, sumCount, totalPathCount);
    return totalPathCount;
}
