/*
Problem:
Given a Binary Tree, write a function to populate next pointer for all nodes.
The next pointer for every node should be set to point to inorder successor.
https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

Resources:
https://www.geeksforgeeks.org/populate-inorder-successor-for-all-nodes/
*/

/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution
{
public:
	// we'll traverse in reverse inorder style
	void _populateInorderSuccessor(Node *root, Node *&nextNode)
	{
		if(root)
		{
			_populateInorderSuccessor(root->right, nextNode);
			root->next = nextNode;
			nextNode = root;
			_populateInorderSuccessor(root->left, nextNode);
		}
	}

    void populateNext(Node *root)
    {
		Node *nextNode = NULL;
        _populateInorderSuccessor(root, nextNode);
    }
};
