/*
Problem link:
https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
*/

vector<int> rightView(Node *root)
{
   vector<int>output;
   if(!root) return output;

   queue<Node*>q;
   q.push(root);

   while(!q.empty()) {
       int sz = q.size();
       for(int i=1; i<=sz; i++) {
           Node *curr = q.front();
           q.pop();
           if(i==sz) output.push_back(curr->data);

           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
       }
   }
   return output;
}
