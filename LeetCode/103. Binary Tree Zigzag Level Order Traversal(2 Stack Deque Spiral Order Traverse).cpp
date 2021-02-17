/**
Solution 1: using deque
------Spiral Traversal------
idea is, when we'll traverse tree from left to right, we'll push in back of the deque.
Then when we'll traverse tree from right to left, we'll push in front of the deque.

Time:  O(N)
space: O(N)

video tutorial: https://www.youtube.com/watch?v=vjt5Y6-1KsQ
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode *>dq;

        vector<vector<int>>output;
        if(!root) return output;

        dq.push_front(NULL);
        dq.push_front(root);

        while( dq.size() > 1 ) {
            vector<int>v1,v2;

            while( dq.front() ) {
                TreeNode *frontNode=dq.front();
                dq.pop_front();
                v1.push_back(frontNode->val);

                if(frontNode->left) dq.push_back(frontNode->left);
                if(frontNode->right) dq.push_back(frontNode->right);
            }

            if(v1.size()) output.push_back(v1);

            while( dq.back() ) {
                TreeNode *backNode=dq.back();
                dq.pop_back();
                v2.push_back(backNode->val);

                if(backNode->right) dq.push_front(backNode->right);
                if(backNode->left) dq.push_front(backNode->left);
            }

            if(v2.size()) output.push_back(v2);
        }

        return output;
    }
};



/**
Solution 2: using 2 stack
------Spiral Traversal------
assume there're 2 stacks.
in one stack, we'll first push the left child (if there's any), then push the right child (if there's any).
in another stack, we'll first push the right child (if there's any), then push the left child (if there's any).
we'll pop the top element of current stack. Then push it's child following above way.

Let's push the root in stk1.
Now pop it (print it/store it). First push it's left child to stack 2, then push it's right child to stack 2.
Now stack 1 is empty, so move to stack 2.

Now pop top element of stack 2. Push it's right child to stack 1, then left child to stack 1. Then do the same for other element of this stack.
Now stack 2 is empty, so move to stack 1.
Do such as long as any of the two stack has element.
Time:  O(N)
space: O(N)

video tutorial: https://www.youtube.com/watch?v=vjt5Y6-1KsQ
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode *>stk1;
        stack<TreeNode *>stk2;

        vector<vector<int>>output;
        if(!root) return output;
        stk1.push(root);

        while( !stk1.empty() || !stk2.empty() ) {
            vector<int>v1,v2;

            while( !stk1.empty() ) {
                TreeNode *top=stk1.top();
                stk1.pop();
                v1.push_back(top->val);

                if(top->left) stk2.push(top->left);
                if(top->right) stk2.push(top->right);
            }
            if(v1.size()) output.push_back(v1);

            while( !stk2.empty() ) {
                TreeNode *top=stk2.top();
                stk2.pop();
                v2.push_back(top->val);

                if(top->right) stk1.push(top->right);
                if(top->left) stk1.push(top->left);
            }
            if(v2.size()) output.push_back(v2);
        }

        return output;
    }
};
