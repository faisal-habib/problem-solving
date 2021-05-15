/*
Recursive DP (Top Down approach)
*/

class Solution {
public:
    int _go(string &s, int &sSz, int currPos, vector<int>& dp) {

        if(currPos >= sSz) return 1;

        if(dp[currPos] != -1) return dp[currPos];

        if(s[currPos] == '0') {
            dp[currPos] = 0;
            return dp[currPos];
        }

        int ways = _go(s, sSz, currPos+1, dp);

        if(currPos < sSz-1) {
            if(s[currPos] == '1' || (s[currPos] == '2' && s[currPos+1] <= '6')) ways += _go(s, sSz, currPos+2, dp);
        }

        dp[currPos] = ways;
        return dp[currPos];
    }

    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int sz = s.size();
        vector<int> dp(sz+1, -1);

        return _go(s, sz, 0, dp);
    }
};

/*
Iterative DP (Top Down approach)
*/

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int sz = s.size();
        if(sz==1) return 1;
        vector<int> dp(sz+1, 0);

        dp[0] = 1;
        if(s[0] == '1' || (s[0] == '2' && s[1] <= '6')) dp[1] = 1;
        if(s[1] != '0') dp[1]++;    // considering s[1] as individual answer

        for(int i=2; i<sz; i++) {
            // 130, 100
            if(s[i] == '0' && (s[i-1] >= '3' || s[i-1] == '0')) return 0;

            if(s[i] != '0') dp[i] = dp[i-1];

            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) dp[i] += dp[i-2];
        }

        return dp[sz-1];
    }
};

/*
Iterative DP (Bottom Up approach)
*/

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int sz = s.size();
        if(sz==1) return 1;
        vector<int> dp(sz+1, 0);

        dp[sz] = 1;

        for(int i=sz-1; i>=0; i--) {
            if(s[i] == '0') dp[i] = 0;
            else {
                dp[i] = dp[i+1];

                if( i < sz-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) ) dp[i] += dp[i+2];
            }
        }

        return dp[0];
    }
};

