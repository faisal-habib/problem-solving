/*
https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/
Resources:
https://www.youtube.com/watch?v=BH_btihSwVM
*/

struct Node
{
    int val;
    Node *left, *right;
    Node(int v)
    {
        val = v;
        left = right = NULL;
    }
};
Node *_getTreeFromString(string str, int strSz, int currInd)
{
    if(currInd>=strSz) return NULL;

    // considering string will have negative number
    bool negative = false;
    if(str[currInd]=='-')
    {
        negative = true;
        currInd++;
    }

    int num = 0;
    while( currInd<strSz && (str[currInd]>='0' && str[currInd]<='9') )
    {
        num = (num*10) + (str[currInd]-'0');
        currInd++;
    }
    if(negative) num = -num;
    Node *root = new Node(num);

    if(currInd>=strSz) return root;

    if(currInd<strSz && str[currInd]=='(')
    {
        currInd++;
        root->left = _getTreeFromString(str, strSz, currInd);
    }
    if(currInd<strSz && str[currInd]==')')
    {
        currInd++;
        return root;
    }

    if(currInd<strSz && str[currInd]=='(')
    {
        currInd++;
        root->right = _getTreeFromString(str, strSz, currInd);
    }
    if(currInd<strSz && str[currInd]==')')
    {
        currInd++;
        return root;
    }

    return root;
}

Node *treeFromString(string s)
{
    int sz = s.size();
    if(sz==0) return NULL;

    return _getTreeFromString(s, sz, 0);
}
