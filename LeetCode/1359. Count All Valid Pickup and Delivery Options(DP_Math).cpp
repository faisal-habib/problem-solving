class Solution {
public:
    const int MOD = 1000000007; //1e9 + 7
    int _totalWays(int unpicked, int undelivered, vector<vector<int>> &dp) {
        if (unpicked == 0 && undelivered == 0) return 1;
        if (unpicked < 0 || undelivered < 0 || undelivered < unpicked) return 0;
        if (dp[unpicked][undelivered]) return dp[unpicked][undelivered];
        
        long ways = 0;
        // all choices of picking up an order.
        ways += (long)unpicked * _totalWays(unpicked - 1, undelivered, dp);
        ways %= MOD;
        
        // all choices of delivering a picked order
        ways += (long)(undelivered - unpicked) * _totalWays(unpicked, undelivered - 1, dp);
        ways %= MOD;
        
        return dp[unpicked][undelivered] = ways;
    }
    
    int countOrders(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return _totalWays(n, n, dp);
    }
};