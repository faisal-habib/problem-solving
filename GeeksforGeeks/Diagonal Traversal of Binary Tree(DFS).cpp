/*
Resources:
https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/
*/

/**
Solution 1: DFS
*/

void _printDiagonal(Node *root, int verticalDis, vector<vector<int>>&output)
{
    if(!root) return ;

    output[verticalDis].push_back(root->data);

    // Increase the vertical distance if left child
    _printDiagonal(root->left, verticalDis+1, output);
    // Vertical distance remains same for right child
    _printDiagonal(root->right, verticalDis, output);
}

void printDiagonal(Node *root)
{
    int verticalDis = 0;
    vector<vector<int>>output;
    _printDiagonal(root, verticalDis, output);

    int i = 0;
    while(true)
    {
        int sz = output[i].size();
        if(!sz) break;

        for(int j=0; j<sz; j++) cout<<output[i][j]<<" ";
        cout<<endl;
    }
}
