/*
Problem link:
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
*/

class Solution {
public:
    struct TrieNode {
        TrieNode *left;     // bit = 0
        TrieNode *right;    // bot = 1
        
        TrieNode() {
            left = NULL;
            right = NULL;
        }
    };
    
    void _insertIntoTrie(TrieNode *root, int &currVal) {
        TrieNode *curr = root;
        int currBit;
        for(int i = 31; i >= 0; i--) {
            currBit = (currVal & (1 << i)); // get current value's i'th bit
            
            if (currBit) {
                // if bit = 1, go to right child
                if (curr -> right == NULL) curr -> right = new TrieNode();
                curr = curr -> right;
            }
            else {
                // if bit = 0, go to left child
                if (curr -> left == NULL) curr -> left = new TrieNode();
                curr = curr -> left;
            }
        }
    }
    
    int _findMaximumXOR(TrieNode *root, vector<int>& nums) {
        TrieNode *curr;
        int currBit;
        int currXor;
        int maximumXor = 0;
        
        for(auto &currVal: nums) {
            currXor = 0;
            curr = root;
            
            for(int i = 31; i >= 0; i--) {
                currBit = (currVal & (1 << i)); // get current value's i'th bit
            
                /*
                    we'll see if node that represents the negation of current bit exists or not. If exists, go to that way.
                    if current bit is 1, then we want to go to left (which represents 0).
                    if current bit is 0, then we want to go to right (which represents 1).
                */

                if (currBit) {
                    if (curr -> left) {
                        currXor += (1 << i);
                        curr = curr -> left;
                    }
                    else curr = curr -> right;
                }
                else {
                    if (curr -> right) {
                        currXor += (1 << i);
                        curr = curr -> right;
                    }
                    else curr = curr -> left;
                }
            }
            
            maximumXor = currXor > maximumXor ? currXor : maximumXor;
        }
        
        return maximumXor;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *trieRoot = new TrieNode();
        
        for(auto &val : nums) {
            _insertIntoTrie(trieRoot, val);
        }
        
        return _findMaximumXOR(trieRoot, nums);
    }
};