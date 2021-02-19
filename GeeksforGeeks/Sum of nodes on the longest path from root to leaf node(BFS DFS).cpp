/*
Problem link:
https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
Resources:
https://www.geeksforgeeks.org/sum-nodes-longest-path-root-leaf-node/
https://www.techiedelight.com/find-maximum-sum-root-to-leaf-path-binary-tree/

Time: O(N)
*/

/**
Solution 1: BFS
*/

int sumOfLongRootToLeafPath(Node* root)
{
	int sum = 0;
	if(!root) return sum;

	queue<Node*>q;
	q.push(root);
	queue<int>qSum;
	qSum.push(root->data);

	while(!q.empty())
	{
	    int qSz = q.size();
	    sum = 0;

	    for(int i=1; i<=qSz; i++)
	    {
	        Node *curr = q.front();
	        q.pop();
	        int currSum = qSum.front();
	        qSum.pop();
	        sum = currSum>sum?currSum:sum;

	        //cout<<curr->data<<" currSum: "<<currSum<<endl;

	        if(curr->left)
	        {
	            q.push(curr->left);
	            qSum.push( currSum + curr->left->data );
	        }
	        if(curr->right)
	        {
	            q.push(curr->right);
	            qSum.push( currSum + curr->right->data );
	        }
	    }
	}
	return sum;
}

/**
Solution 2: DFS
*/

void _getLongestPathMaxSumFromRootToLeaf(Node *root, int currSum, int currLevel, int &maxLevel, int &maxSum)
{
    if(!root)
    {
        if(currLevel>maxLevel)
        {
            maxLevel = currLevel;
            maxSum = currSum;
        }
        else if(currLevel==maxLevel && currSum>maxSum)
        {
            maxSum = currSum;
        }
        return ;
    }

    _getLongestPathMaxSumFromRootToLeaf(root->left, currSum+root->data, currLevel+1, maxLevel, maxSum);
    _getLongestPathMaxSumFromRootToLeaf(root->right, currSum+root->data, currLevel+1, maxLevel, maxSum);
}

int sumOfLongRootToLeafPath(Node* root)
{
	int maxSum = 0;
	if(!root) return maxSum;
	int maxLevel = 0;
	_getLongestPathMaxSumFromRootToLeaf(root, 0, 0, maxLevel, maxSum);
	return maxSum;
}
