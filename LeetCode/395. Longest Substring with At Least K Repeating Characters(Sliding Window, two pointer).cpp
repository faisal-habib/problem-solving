class Solution {
public:
    int _getCountOfUniqueCharacter(string s) {
        int count = 0;
        bool vis[26] = {0};

        for(int i=0; s[i]; i++) {
            if(vis[s[i]-'a']==false) count++;
            vis[s[i]-'a'] = true;
        }
        return count;
    }

    int longestSubstring(string s, int k) {

        int sz = s.size();
        if(k==1) return sz;

        int totalUniqueChar = _getCountOfUniqueCharacter(s);

        if(totalUniqueChar==1 && k<=sz) return sz;

        int currUniqueCount, countAtLeastK, outputLen = 0;

        for(int targetUniqueCount=1; targetUniqueCount<=totalUniqueChar; targetUniqueCount++) {

            int charFreq[26] = {0};
            currUniqueCount = 0;
            countAtLeastK = 0;
            int leftInd = 0, rightInd = 0;

            while(rightInd < sz) {
                int charId = s[rightInd] - 'a';

                if(currUniqueCount <= targetUniqueCount) {
                    if(charFreq[charId] == 0) currUniqueCount++;
                    charFreq[charId]++;

                    if(charFreq[charId] == k) countAtLeastK++;
                    rightInd++;
                }
                else {
                    charId = s[leftInd]-'a';
                    if(charFreq[charId] == k) countAtLeastK--;
                    charFreq[charId]--;

                    if(charFreq[charId] == 0) currUniqueCount--;
                    leftInd++;
                }

                if(currUniqueCount == targetUniqueCount && countAtLeastK==currUniqueCount) outputLen = max(rightInd-leftInd, outputLen);
            }
        }
        return outputLen;
    }
};
