class Solution {
public:
    long long valueAr[100005];
    bool segInd[100005];

    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>> output;
        int segSz = segments.size();
        int maxInd = 0, currStart = 1;

        for(int i=0; i<segSz; i++) {
            int st = segments[i][0], en = segments[i][1], v = segments[i][2];
            valueAr[st] += v;
            valueAr[en] -= v;
            segInd[st] = segInd[en] = true; // there's a segement in this pos

            maxInd = en > maxInd ? en : maxInd;
        }

        long long currSum = 0;
        for(int i=1; i<=maxInd; i++) {
            if(segInd[i] && currSum) {
                output.push_back({currStart, i, currSum});
            }

            currStart = segInd[i] ? i : currStart;
            currSum += valueAr[i];
        }
        return output;
    }
};
