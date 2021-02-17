/*
Problem link:
https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Resources:
https://www.educative.io/edpresso/what-is-zigzag-tree-traversal
*/

/**
Solution 1: using 2 stacks
*/

vector <int> zigZagTraversal(Node* root)
{
	vector<int>v;
	if(!root) return v;

	stack<Node*>currStack;
	stack<Node*>stk2;

	currStack.push(root);
	bool leftToRight = true;

	while(!currStack.empty())
	{
	    int currStackSz = currStack.size();
	    for(int i=1; i<=currStackSz; i++)
	    {
	        Node *curr = currStack.top();
	        currStack.pop();
	        v.push_back(curr->data);
	        if(leftToRight)
	        {
	            if(curr->left) stk2.push(curr->left);
	            if(curr->right) stk2.push(curr->right);
	        }
	        else
	        {
	            if(curr->right) stk2.push(curr->right);
	            if(curr->left) stk2.push(curr->left);
	        }
	    }

	    leftToRight = !leftToRight;
	    currStack = stk2;
	    while(!stk2.empty()) stk2.pop();
	}

	return v;
}


/**
Solution 2: using deque
------Spiral Traversal------
idea is, when we'll traverse tree from left to right, we'll push in back of the deque.
Then when we'll traverse tree from right to left, we'll push in front of the deque.
*/

vector <int> zigZagTraversal(Node* root)
{
	vector<int>v;
	if(!root) return v;

	deque<Node*>dq;
	dq.push_front(NULL);    // this NULL will be used as divider. It will help us to solve the problem using 1 deque instead of 2
	dq.push_front(root);
	bool leftToRight = true;

	while(dq.size()>1)
	{
	    while(dq.front())
	    {
	        Node *curr = dq.front();
	        dq.pop_front();
	        v.push_back(curr->data);

	        //leftToRight
	        if(curr->left) dq.push_back(curr->left);
	        if(curr->right) dq.push_back(curr->right);
	    }

	    while(dq.back())
	    {
	        Node *curr = dq.back();
	        dq.pop_back();
	        v.push_back(curr->data);

	        //rightToLeft
	        if(curr->right) dq.push_front(curr->right);
	        if(curr->left) dq.push_front(curr->left);
	    }
	}

	return v;
}
