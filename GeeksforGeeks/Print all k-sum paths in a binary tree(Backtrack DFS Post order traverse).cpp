/*
Resources:
https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/
https://www.geeksforgeeks.org/count-all-k-sum-paths-in-a-binary-tree/
*/
/**
Time: O(N^2) , Considering the case for skewed trees
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

void _printSumPath(vector<int>sumPath, int stInd)
{
    int sz = sumPath.size();
    cout<<"---------------------------"<<endl;
    for(int i=stInd; i<sz; i++) cout<<sumPath[i]<<" ";
    cout<<endl;
    cout<<"---------------------------"<<endl;
}

void _kSumPath(Node *root, int targetSum, vector<int>&sumPath)
{
    if(!root) return ;

    sumPath.push_back(root->data);

    _kSumPath(root->left, targetSum, sumPath);
    _kSumPath(root->right, targetSum, sumPath);

    int currSum = 0;
    for(int i=sumPath.size()-1; i>=0; i--)
    {
        currSum+=sumPath[i];
        if(currSum==targetSum)
        {
            _printSumPath(sumPath, i);
        }
    }
    // backtrack (removing current element)
    sumPath.pop_back();
}

void _printAllKSumPath(Node *root, int k)
{
    vector<int>sumPath;
    _kSumPath(root, k, sumPath);
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
    _printAllKSumPath(root, k);

    return 0;
}

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
