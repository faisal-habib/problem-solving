/*
Problem link:
https://leetcode.com/problems/is-subsequence/
*/

class Solution {
public:
    bool _go(string &s, int currIndS, int &sSz, string &t, int currIndT, int &tSz, vector<vector<int>> &dp) {
        if (currIndS >= sSz) return true;
        if (currIndT >= tSz) return false;
        
        if (dp[currIndS][currIndT] != -1) return dp[currIndS][currIndT];
        
        int match = 0;
        int notMatch = 0;
        if (s[currIndS] == t[currIndT]) match = _go(s, currIndS + 1, sSz, t, currIndT + 1, tSz, dp);
        notMatch = _go(s, currIndS, sSz, t, currIndT + 1, tSz, dp);
        
        return dp[currIndS][currIndT] = match + notMatch;
    }
    
    bool isSubsequence(string s, string t) {
        int sSz = s.size();
        int tSz = t.size();
        vector<vector<int>> dp(sSz + 1, vector<int> (tSz + 1, -1));
        
        return _go(s, 0, sSz, t, 0, tSz, dp);
    }
};

/*
class Solution {
public:
    bool _isSubsequence(string &queryString, string &mainString) {
        // return true if queryString presents in mainString
        int queryStringLen = 0;
        while(queryString[queryStringLen]) queryStringLen++;
        
        if (!queryStringLen) return true;
        
        for(int i = 0, j = 0; mainString[i]; i++) {
            if (queryString[j] == mainString[i]) {
                j++;
                if (j == queryStringLen) return true;
            }
        }
        return false;
    }
    bool isSubsequence(string s, string t) {
        return _isSubsequence(s, t);
    }
};

*/