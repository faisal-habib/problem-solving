/*
Problem link:
https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1
Resources:
https://www.quora.com/What-is-the-best-way-to-check-if-all-the-leaf-nodes-are-at-the-same-level-or-not-in-a-binary-tree
https://www.geeksforgeeks.org/check-leaves-level/

Time: O(N)
*/

bool check(Node *root)
{
    if(!root || (!root->left && !root->right)) return true;

    queue<Node*>q;
    q.push(root);
    int currLevel = 0, prevLevel = -1;

    while(!q.empty())
    {
        int qSz = q.size();
        for(int i=1; i<=qSz; i++)
        {
            Node *curr = q.front();
            q.pop();

            if(!curr->left && !curr->right) // this is leaf node
            {
                if(prevLevel==-1) prevLevel = currLevel;  // means, we didn't find any leaf previously
                else
                {
                    if(currLevel!=prevLevel) return false;   // means, last founded leaf was not in same level
                }
            }
            else
            {
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        currLevel++;
    }
    return true;
}
