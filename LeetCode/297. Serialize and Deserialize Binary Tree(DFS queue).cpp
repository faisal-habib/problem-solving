class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "n";

        return (to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right) );
    }

    TreeNode *_deserializeTree(queue<string>&q) {
        string curr = q.front();
        q.pop();

        if(curr=="n") return NULL;

        TreeNode *node = new TreeNode(stoi(curr));
        node->left = _deserializeTree(q);
        node->right = _deserializeTree(q);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="n") return NULL;

        queue<string>q;
        string s = "";
        int dataSz = data.size();
        // extracting nodes from data string
        for(int i=0; i<dataSz; i++) {
            if(data[i]==',') {
                q.push(s);
                s="";
            }
            else s+=data[i];
        }
        if(s.size()) q.push(s);

        return _deserializeTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
