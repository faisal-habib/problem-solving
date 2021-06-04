/*
Problem link:
https://leetcode.com/problems/construct-string-from-binary-tree/
Resources:
https://leetcode.com/problems/construct-string-from-binary-tree/solution/
*/

/* ------------------------------------------------------------------------ */
/*
Solution 1: using recursion
Time: O(N)
Space: O(N)
*/
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";

        if(root->left == NULL && root->right == NULL) return to_string(root->val) + "";

        if(root->right == NULL) return to_string(root->val) + "(" + tree2str(root->left) + ")";

        if(root->left == NULL) return to_string(root->val) + "()" + "(" + tree2str(root->right) + ")";

        return to_string(root->val) + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";
    }
};

// another approach using recursion

class Solution {
public:
	void _preOrder(TreeNode* root, string &output) {
		if(!root) {
			return ;
		}

		output += to_string(root->val);

		if(root->left) {
			output += "(";
			_preOrder(root->left, output);
			output += ")";
		}
		else if(root->right) output += "()";

		if(root->right) {
			output += "(";
			_preOrder(root->right, output);
			output += ")";
		}
	}
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";

        string output = "";
		_preOrder(root, output);

		return output;
    }
};

/* ------------------------------------------------------------------------ */

/*
Solution 2: using Stack (Iterative Method)
Time: O(N)
Space: O(N)
*/
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";

		stack<TreeNode*>stk;
		stk.push(root);
		string output = "";
		unordered_map<TreeNode*, bool>vis;

		while(!stk.empty()) {
			TreeNode *top = stk.top();
			if(vis[top]) {
				stk.pop();
				output += ")";
			}
			else {
				vis[top] = true;
				output += "(" + to_string(top->val);

				if(top->left == NULL && top->right) output += "()";

				if(top->right) stk.push(top->right);

				if(top->left) stk.push(top->left);
			}
		}

		output = output.substr(1, output.size()-2);	// 1 extra '(' & ')' was added at the beginning & end of the string
		return output;
    }
};
