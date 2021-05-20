/*
Problem link:
https://practice.geeksforgeeks.org/problems/trie-delete/1
Resources:
https://www.geeksforgeeks.org/trie-delete/
*/

struct trie_node
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};
class Solution{
  public:
  bool _isLeaf(trie_node_t *root)
  {
      for(int i=0; i<ALPHABET_SIZE; i++)
      {
          if(root->children[i] != NULL) return false;
      }
      return true;
  }

  trie_node_t *_remove(trie_node_t *root, char key[], int &keyLen, int currPos)
  {
      if(root == NULL) return NULL;

      if(currPos == keyLen)
      {
          // This node is no more end of word after removal of given key
          root->value = 0;

          // If given key is not prefix of any other word
          if(_isLeaf(root)) root = NULL;

          return root;
      }

      int charId = key[currPos] - 'a';
      root->children[charId] = _remove(root->children[charId], key, keyLen, currPos+1);

      // If root does not have any child (its only child got deleted), and it is not end of another word.
      if( _isLeaf(root) && root->value == 0 ) root = NULL;

      return root;
  }
  void deleteKey(trie_node_t *root, char key[])
  {
      if(!root) return ;
      int keyLen = strlen(key);
      root = _remove(root, key, keyLen, 0);
  }
};
