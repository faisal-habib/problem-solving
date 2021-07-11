class Solution {
public:
    bool sumGame(string num) {
        bool bobWins = false;
        bool aliceWins = true;

        int leftQ = 0, rightQ = 0, diff = 0;
        int numSz = num.size();

        for(int i=0; i<numSz; i++) {
            if(i < numSz/2) {
                if(num[i] == '?') leftQ++;
                else diff += (num[i] - '0');
            }
            else {
                if(num[i] == '?') rightQ++;
                else diff -= (num[i] - '0');
            }
        }

        if(leftQ+rightQ == 0 || leftQ == rightQ) {
            if(diff == 0) return bobWins;
            else return aliceWins;
        }

        if( (leftQ+rightQ) % 2 == 1) return aliceWins;

        int ans = diff + (leftQ/2)*9 - (rightQ/2)*9;

        if(ans == 0) return bobWins;

        return aliceWins;
    }
};
