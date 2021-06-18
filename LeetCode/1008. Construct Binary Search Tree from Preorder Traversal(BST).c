/*
Problem:
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

References:
https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
*/

/*	--------------------------------------------
Approach 1:
The first element of preorder traversal is always root.
We first construct the root. Then we find the index of the first element
which is greater than the root. Let the index be ‘i’. The values between root
and ‘i’ will be part of the left subtree, and the values between ‘i+1’ and ‘n-1’
will be part of the right subtree.

Time: O(N^2)
--------------------------------------------	*/

struct TreeNode *_createBstNode(int val) {
	struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	newNode->val = val;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct TreeNode *_createBstFromPreorder(int preorderAr[], int startInd, int endInd) {
	if(startInd > endInd) return NULL;

	struct TreeNode *newNode = _createBstNode(preorderAr[startInd]);

	int i = startInd;
	for( ; i<=endInd; i++) {
		if(preorderAr[i] > preorderAr[startInd]) break;
	}

	newNode->left = _createBstFromPreorder(preorderAr, startInd+1, i-1);
	newNode->right = _createBstFromPreorder(preorderAr, i, endInd);

	return newNode;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
	return _createBstFromPreorder(preorder, 0, preorderSize-1);
}

/*	--------------------------------------------
Approach 2:
Set a range {min .. max} for every node. Initialize the range as {INT_MIN .. INT_MAX}.
The first node will definitely be in range, so create a root node.
To construct the left subtree, set the range as {INT_MIN …root->data}.
If a value is in the range {INT_MIN .. root->data}, the values are part of the left subtree.
To construct the right subtree, set the range as {root->data..max .. INT_MAX}.

Time: O(N)
--------------------------------------------	*/

struct TreeNode *_createBstNode(int val) {
	struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	newNode->val = val;
	newNode->left = newNode->right = NULL;
	return newNode;
}

int currInd;
struct TreeNode *_createBstFromPreorder(int preorderAr[], int preorderArSize, int minVal, int maxVal) {
	if(currInd >= preorderArSize) return NULL;

	if(preorderAr[currInd]<minVal || preorderAr[currInd]>maxVal) return NULL;

	struct TreeNode *newNode = _createBstNode(preorderAr[currInd]);
	currInd++;

	newNode->left = _createBstFromPreorder(preorderAr, preorderArSize, minVal, newNode->val);

	newNode->right = _createBstFromPreorder(preorderAr, preorderArSize, newNode->val, maxVal);

	return newNode;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
	currInd = 0;
    return _createBstFromPreorder(preorder, preorderSize, INT_MIN, INT_MAX);
}
