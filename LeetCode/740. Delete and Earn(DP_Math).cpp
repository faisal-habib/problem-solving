/*
Problem link:
https://leetcode.com/problems/delete-and-earn/
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber = nums[0];
        int maxPoints[10002] = {0};
        unordered_map<int, int> points;
        
        for(auto curr : nums) {
            maxNumber = maxNumber >= curr ? maxNumber : curr;
            points[curr] += curr;
        }
        
        maxPoints[1] = points[1];   // if we come to 1, that means we didn't take 2. so we'll always take 1, hence maxPoints = it's own point
        
        for(int currNum = 2; currNum <= maxNumber; currNum++) {
            int pointsAfterTakingCurrNumber = points[currNum];
            maxPoints[currNum] = max(pointsAfterTakingCurrNumber + maxPoints[currNum-2], maxPoints[currNum-1]);
        }
        
        return maxPoints[maxNumber];
    }
};

/*
//  Time complexity: O(N+k)
//  Space complexity: O(N+k)

class Solution {
public:
    int _getMaxPoints(int currNumber, map<int, int> &dp, unordered_map<int, int> &points) {
        if (currNumber == 0) return 0;
        if (currNumber == 1) return points[1];  // if we come to 1, that means we didn't take 2. so we'll always take 1, hence returning it's point
        if (dp.find(currNumber) != dp.end()) return dp[currNumber];
        
        int pointsAfterTakingCurrNumber = points[currNumber];
        dp[currNumber] = max(pointsAfterTakingCurrNumber + _getMaxPoints(currNumber - 2, dp, points), _getMaxPoints(currNumber - 1, dp, points));
        return dp[currNumber];
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber = nums[0];
        map<int, int> dp;
        unordered_map<int, int> points;
        
        for(auto curr : nums) {
            maxNumber = maxNumber >= curr ? maxNumber : curr;
            points[curr] += curr;
        }
        
        return _getMaxPoints(maxNumber, dp, points);
    }
};
*/