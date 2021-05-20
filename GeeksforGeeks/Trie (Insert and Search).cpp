/*
Problem link:
https://practice.geeksforgeeks.org/problems/trie-insert-and-search0651/1
Resources:
*/

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *currNode = root;
    for(int i=0; key[i]; i++) {
        int charId = key[i] - 'a';
        if(currNode->children[charId] == NULL) currNode->children[charId] = getNode();
        currNode = currNode->children[charId];
    }
    currNode->isLeaf = true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *currNode = root;
    for(int i=0; key[i]; i++) {
        int charId = key[i] - 'a';
        if(currNode->children[charId] == NULL) return false;
        currNode = currNode->children[charId];
    }
    return currNode->isLeaf;
}
