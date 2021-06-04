/*
Problem link:
https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/

/*
Solution 1: using Trie
Time: In worst case, time complexity will be size of the trie
*/

/* ----------------------------------- Trie code ----------------------------------------- */
typedef struct TRIE {
    bool endFlag;
    struct TRIE *child[26];
}TRIE_NODE;

TRIE_NODE *root;

TRIE_NODE *_createTrieNode()
{
    TRIE_NODE *newNode = (TRIE_NODE*)malloc(sizeof(TRIE_NODE));
    newNode->endFlag = false;
    for(int i=0; i<26; i++) newNode->child[i] = NULL;

    return newNode;
}

void _insertIntoTrie(TRIE_NODE *currRoot, char *str) {
    for(int i=0; str[i]; i++) {
        int id = str[i] - 'a';

        if(currRoot->child[id] == NULL) currRoot->child[id] = _createTrieNode();

        currRoot = currRoot->child[id];
    }
    currRoot->endFlag = true;
}

bool _searchInTrie(TRIE_NODE *currRoot, char *str, int strSz, int currPos) {

    if(currPos == strSz) return currRoot->endFlag;

    if(str[currPos] == '.') {
        for(int j=0; j<26; j++) {
            if(currRoot->child[j] && _searchInTrie(currRoot->child[j], str, strSz, currPos+1)) return true;
        }
    }
    else {
        int id = str[currPos] - 'a';

        if(currRoot->child[id] == NULL) return false;

        currRoot = currRoot->child[id];
        return _searchInTrie(currRoot, str, strSz, currPos+1);
    }
    return false;
}

/* ---------------------------------------------------------------------------- */

typedef struct {

} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
    root = _createTrieNode();
    return NULL;
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    _insertIntoTrie(root, word);
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
    return _searchInTrie(root, word, strlen(word), 0);
}

void wordDictionaryFree(WordDictionary* obj) {
    root = NULL;
}

/*
Solution 2: using vector
*/

class WordDictionary {
public:
    /** Initialize your data structure here. */

    vector<string>allWords[505];    // max word length will be 500

    bool _match(string &inputWord, string &queryWord) {
        // length of inputWord & queryWord is same
        for(int i=0; inputWord[i]; i++) {
            if(queryWord[i] != '.' && inputWord[i] != queryWord[i]) return false;
        }
        return true;
    }

    WordDictionary() {

    }

    void addWord(string word) {
        int wordSz = word.size();
        allWords[wordSz].push_back(word);
    }

    bool search(string word) {
        int wordSz = word.size();
        int vecSz = allWords[wordSz].size();

        for(int i=0; i<vecSz; i++) {
            if( _match(allWords[wordSz][i], word) ) return true;
        }

        return false;
    }
};
