/*
Problem link:
https://leetcode.com/problems/stone-game-iv/
*/

/**
Iterative dp:
Time: O (N * sqrt(N))
Space: O(N)
*/

class Solution {
public:
    bool winnerSquareGame(int n) {
        int dp[n + 2];
        for(int i = 0; i <= n; i++) dp[i] = 0;

        for(int i = 0; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                if (dp[i - (j * j)] == 0) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n];
    }
};

/**
Recursive dp:
Time: O (N * sqrt(N))
Space: O(N)
*/

/**
class Solution {
public:
    bool _go(int dp[], int remainingStone) {
        if (dp[remainingStone] != -1) return dp[remainingStone];

        int sq = sqrt(remainingStone);
        for(int i = 1; i <= sq; i++) {
            //current player will win if next player can not win with remaining stones
            if (_go(dp, remainingStone - (i * i)) == false) {
                dp[remainingStone] = 1;
                return true;
            }
        }
        return dp[remainingStone] = false;
    }
    bool winnerSquareGame(int n) {
        int dp[n + 2];
        for(int i = 0; i <= n; i++) dp[i] = -1;

        dp[0] = 0;
        bool canAliceWin = _go(dp, n);

        return canAliceWin;
    }
};
*/
